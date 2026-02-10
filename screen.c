#include <gtk/gtk.h>
#include "header.h"

void window_Generator(char* title) {
    GtkWidget *window;
    gtk_init(NULL, NULL);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), title);
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);
    gtk_widget_show_all(window);
}