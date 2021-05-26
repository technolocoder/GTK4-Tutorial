#include <gtk-4.0/gtk/gtk.h>

static void activate(GtkApplication *application, void *callback_data){
    GtkWindow *window = (GtkWindow*)gtk_application_window_new(application);

    gtk_window_set_title(window,"Test-Window");
    gtk_window_set_default_size(window,500,500);

    gtk_widget_show((GtkWidget*)window);
}

int main(int argc, char *argv[]){
    GtkApplication *application = gtk_application_new("gtk.test-window",G_APPLICATION_FLAGS_NONE);
    g_signal_connect(application,"activate",(GCallback)activate,NULL);
    g_application_run((GApplication*)application,argc,argv);
    g_object_unref(application);
    return 0;
}