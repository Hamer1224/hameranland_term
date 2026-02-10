#include "header.h"

static void on_run_clicked(GtkButton *button, gpointer user_data) {
    AppWidgets *widgets = (AppWidgets *)user_data;
    run_compiler_logic(widgets);
}

void setup_ui(GtkApplication *app, AppWidgets *widgets) {
    widgets->window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(widgets->window), "Hameran IDE");
    gtk_window_set_default_size(GTK_WINDOW(widgets->window), 900, 600);

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(widgets->window), vbox);

    // Toolbar with Run Button
    GtkWidget *toolbar = gtk_action_bar_new();
    GtkWidget *run_btn = gtk_button_new_with_label("▶ Run Code");
    g_signal_connect(run_btn, "clicked", G_CALLBACK(on_run_clicked), widgets);
    gtk_action_bar_pack_start(GTK_ACTION_BAR(toolbar), run_btn);
    gtk_box_pack_start(GTK_BOX(vbox), toolbar, FALSE, FALSE, 0);

    // Source Editor
    GtkSourceLanguageManager *lm = gtk_source_language_manager_get_default();
    GtkSourceLanguage *lang = gtk_source_language_manager_get_language(lm, "c");
    widgets->buffer = GTK_TEXT_BUFFER(gtk_source_buffer_new_with_language(lang));
    widgets->source_view = gtk_source_view_new_with_buffer(GTK_SOURCE_BUFFER(widgets->buffer));
    gtk_source_view_set_show_line_numbers(GTK_SOURCE_VIEW(widgets->source_view), TRUE);

    GtkWidget *scroll = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(scroll), widgets->source_view);
    gtk_box_pack_start(GTK_BOX(vbox), scroll, TRUE, TRUE, 0);

    // Console Output
    widgets->terminal_output = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(widgets->terminal_output), FALSE);
    GtkWidget *term_scroll = gtk_scrolled_window_new(NULL, NULL);
    gtk_widget_set_size_request(term_scroll, -1, 120);
    gtk_container_add(GTK_CONTAINER(term_scroll), widgets->terminal_output);
    gtk_box_pack_start(GTK_BOX(vbox), term_scroll, FALSE, FALSE, 0);

    gtk_widget_show_all(widgets->window);
}