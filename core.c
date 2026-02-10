#include <gtk/gtk.h>
#include <stdio.h>

char startup_text[] = "Booting Up Hameranland...\n";

// The callback signature must match what GTK expects. 
// 'user_data' is used to pass our title string.
static void activate(GtkApplication* app, gpointer user_data)
{
    GtkWidget *window;
    char *title = (char *)user_data;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), title);
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
    
    // In GTK3, we show the window. In GTK4, this would be gtk_window_present.
    gtk_widget_show_all(window);
}

int main(int argc, char **argv) 
{
    printf("%s", startup_text);
    
    GtkApplication *app;
    int status;

    // Note: Application IDs usually follow a reverse-DNS style (e.g., "org.hameranland.app")
    app = gtk_application_new("org.hameranland.app", G_APPLICATION_DEFAULT_FLAGS);
    
    // We pass "Hameranland" as the last argument here, which becomes 'user_data' in the callback.
    g_signal_connect(app, "activate", G_CALLBACK(activate), "Hameranland");
    
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    
    return status;
}