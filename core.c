#include "header.h"


static void activate(GtkApplication *app, gpointer user_data) {
    AppWidgets *widgets = g_malloc(sizeof(AppWidgets));
    setup_ui(app, widgets);
}

int main(int argc, char **argv) {
    printf("Booting Up Hameranland IDE...\n");
    GtkApplication *app = gtk_application_new("org.hameran.ide", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}