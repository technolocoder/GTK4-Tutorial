#include <gtk-4.0/gtk/gtk.h>

static void print(){
    printf("Hello World\n");
}

static void activate(GtkApplication *application, void *callback_data){
    GtkWindow *window = (GtkWindow*)gtk_application_window_new(application);
    GtkButton *button;
    GtkBox *box;

    gtk_window_set_title(window,"Test-Window");
    gtk_window_set_default_size(window,500,500);

    box = (GtkBox*)gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
    gtk_window_set_child(window,(GtkWidget*)box);

    button = (GtkButton*)gtk_button_new_with_label("Print");

    g_signal_connect(button,"clicked",(GCallback)print,NULL);
    g_signal_connect_swapped(button,"clicked",(GCallback)gtk_window_close,window);

    gtk_box_append(box,(GtkWidget*)button);
    gtk_widget_show((GtkWidget*)window);
}

int main(int argc, char *argv[]){
    GtkApplication *application = gtk_application_new("gtk.test-window",G_APPLICATION_FLAGS_NONE);
    g_signal_connect(application,"activate",(GCallback)activate,NULL);
    g_application_run((GApplication*)application,argc,argv);
    g_object_unref(application);
    return 0;
}