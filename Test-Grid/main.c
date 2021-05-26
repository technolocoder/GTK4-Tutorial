#include <gtk-4.0/gtk/gtk.h>

static void print(const char *str){
    printf("%s\n",str);
}

static void activate(GtkApplication *application, void *user_data){
    GtkWindow *window = (GtkWindow*)gtk_application_window_new(application);
    
    gtk_window_set_title(window,"Test Grid");
    gtk_window_set_default_size(window,500,500);

    GtkGrid *grid = (GtkGrid*)gtk_grid_new();
    gtk_window_set_child(window,(GtkWidget*)grid);

    GtkButton *button_1 = (GtkButton*)gtk_button_new_with_label("first button");
    GtkButton *button_2 = (GtkButton*)gtk_button_new_with_label("second button");
    GtkButton *button_3 = (GtkButton*)gtk_button_new_with_label("third button");

    g_signal_connect_swapped(button_1,"clicked",(GCallback)print,"First Button");
    g_signal_connect_swapped(button_2,"clicked",(GCallback)print,"Second Button");
    g_signal_connect_swapped(button_3,"clicked",(GCallback)print,"Third Button");

    gtk_grid_attach(grid,(GtkWidget*)button_1,0,0,2,1);
    gtk_grid_attach(grid,(GtkWidget*)button_2,0,1,1,1);
    gtk_grid_attach(grid,(GtkWidget*)button_3,1,1,1,1);

    gtk_widget_show((GtkWidget*)window);
}

int main(int argc, char *argv[]){
    GtkApplication *application = gtk_application_new("gtk.grid-example",G_APPLICATION_FLAGS_NONE);
    g_signal_connect(application,"activate",(GCallback)activate,NULL);
    g_application_run((GApplication*)application,argc,argv);
    g_object_unref(application);
    return 0;
}