#include "header.h"

void append_to_console(GtkWidget *console, const char *text) {
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(console));
    GtkTextIter end;
    gtk_text_buffer_get_end_iter(buffer, &end);
    gtk_text_buffer_insert(buffer, &end, text, -1);
}