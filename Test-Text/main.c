#include <gtk-4.0/gtk/gtk.h>

void activate(GtkApplication *application, void *user_data){
    GtkWindow *window = (GtkWindow*)gtk_application_window_new(application);
    gtk_window_set_title(window,"Test-Text");
    gtk_window_set_default_size(window,500,500);

    GtkTextView *text = (GtkTextView*)gtk_text_view_new();
    gtk_window_set_child(window,(GtkWidget*)text);

    gtk_widget_show((GtkWidget*)window);
}

int main(int argc, char *argv[]){
    GtkApplication *application = gtk_application_new("gtk.test-text",G_APPLICATION_FLAGS_NONE);
    g_signal_connect(application,"activate",(GCallback)activate,NULL);
    g_application_run((GApplication*)application,argc,argv);
    g_object_unref(application);
    return 0;
}