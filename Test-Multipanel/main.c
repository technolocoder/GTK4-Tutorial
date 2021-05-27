#include <gtk-4.0/gtk/gtk.h>

int x=1;
int n = 2;

void button_callback(GtkGrid *grid){
    GtkButton *button = (GtkButton*)gtk_button_new_with_label("Add");
    g_signal_connect_swapped(button,"clicked",(GCallback)button_callback,grid);
    ++x;
    ++n;
    gtk_grid_attach(grid,(GtkWidget*)button,(x)%10,x/10,1,1); 
}

void delete_callback(GtkGrid *grid){
    for(int i = 2; i < n; ++i){
        GtkWidget* child = gtk_grid_get_child_at(grid,i%10,i/10);
        gtk_grid_remove(grid,child);
    }
    n=2;
    x=1;
}

void activate(GtkApplication *application ,void *data){
    GtkWindow *window = (GtkWindow*)gtk_application_window_new(application);
    gtk_window_set_title(window,"Test-Multipanel");
    gtk_window_set_default_size(window,500,500);

    GtkGrid *grid = (GtkGrid*)gtk_grid_new();
    gtk_window_set_child(window,(GtkWidget*)grid);

    GtkButton *button = (GtkButton*)gtk_button_new_with_label("Add");
    gtk_grid_attach(grid,(GtkWidget*)button,0,0,1,1);
    g_signal_connect_swapped(button,"clicked",(GCallback)button_callback,grid);

    GtkButton *delete_button = (GtkButton*)gtk_button_new_with_label("Delete");
    gtk_grid_attach(grid,(GtkWidget*)delete_button,1,0,1,1);
    g_signal_connect_swapped(delete_button,"clicked",(GCallback)delete_callback,grid);

    gtk_widget_show((GtkWidget*)window);
}

int main(int argc, char *argv[]){
    GtkApplication *application = gtk_application_new("gtk.test-multipanel",G_APPLICATION_FLAGS_NONE);
    g_signal_connect(application,"activate",(GCallback)activate,NULL);
    g_application_run((GApplication*)application,argc,argv);
    g_object_unref(application);
    return 0;
}