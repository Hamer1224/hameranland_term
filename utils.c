#include "header.h"

void append_to_console(GtkWidget *console, const char *text) {
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(console));
    GtkTextIter end;
    gtk_text_buffer_get_end_iter(buffer, &end);
    gtk_text_buffer_insert(buffer, &end, text, -1);
}

void run_compiler_logic(AppWidgets *widgets) {
    append_to_console(widgets->terminal_output, "\n--- System: Building ---\n");
    GtkTextIter start,end;
    gtk_text_buffer_get_bounds(widgets->buffer, &start, &end);
    char *code = gtk_text_buffer_get_text(widgets->buffer, &start, &end, FALSE);

    FILE *fp = fopen("temp.c", "w");
    if (fp) {
        fputs(code, fp);
        fclose(fp);
    }

    int status = system("gcc temp.c -o temp_app 2> build.log");

    if (status == 0) {
        append_to_console(widgets->terminal_output, "Success! Check terminal for output.\n");
    } else {
        append_to_console(widgets->terminal_output, "Build Error. Check build.log\n");
    }

    g_free(code);
}