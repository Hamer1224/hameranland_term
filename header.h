#ifndef HEADER_H
#define HEADER_H

#include <gtk/gtk.h>
#include <gtksourceview/gtksource.h>

// Structure to hold our UI widgets
typedef struct {
    GtkWidget *window;
    GtkWidget *source_view;
    GtkTextBuffer *buffer;
    GtkWidget *terminal_output;
} AppWidgets;

// Function prototypes
void setup_ui(GtkApplication *app, AppWidgets *widgets);
void run_compiler_logic(AppWidgets *widgets);
void append_to_console(GtkWidget *console, const char *text);

#endif
