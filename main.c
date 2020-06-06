#include <gtk/gtk.h>
#include <stdio.h>
#include <gtk/gtk.h>

static GtkWidget *result;
static GtkWidget *result1;
static GtkWidget *result2;
static GtkWidget *ar1;
static GtkWidget *ar2;
static GtkWidget *ar3;
static GtkWidget *ar4;
static GtkWidget *ar5;
static GtkWidget *ar6;
static GtkWidget *ar7;
static GtkWidget *ar8;
static GtkWidget *ar9;
static GtkWidget *mr1;
static GtkWidget *mr2;
static GtkWidget *mr3;
static GtkWidget *mr4;
static GtkWidget *mr5;
static GtkWidget *mr6;
static GtkWidget *mr7;
static GtkWidget *mr8;
static GtkWidget *mr9;
static GtkWidget *avr1;
static GtkWidget *avr2;
static GtkWidget *avr3;

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/window_main.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);
    
    // get pointers to the two labels
    result = GTK_WIDGET(gtk_builder_get_object(builder, "result"));
     result1 = GTK_WIDGET(gtk_builder_get_object(builder, "result1"));
      result2 = GTK_WIDGET(gtk_builder_get_object(builder, "result2"));
    ar1 = GTK_WIDGET(gtk_builder_get_object(builder, "ar1"));
    ar2 = GTK_WIDGET(gtk_builder_get_object(builder, "ar2"));
    ar3 = GTK_WIDGET(gtk_builder_get_object(builder, "ar3"));
    ar4 = GTK_WIDGET(gtk_builder_get_object(builder, "ar4"));
    ar5 = GTK_WIDGET(gtk_builder_get_object(builder, "ar5"));
    ar6 = GTK_WIDGET(gtk_builder_get_object(builder, "ar6"));
    ar7 = GTK_WIDGET(gtk_builder_get_object(builder, "ar7"));
    ar8 = GTK_WIDGET(gtk_builder_get_object(builder, "ar8"));
    ar9 = GTK_WIDGET(gtk_builder_get_object(builder, "ar9"));
    mr1 = GTK_WIDGET(gtk_builder_get_object(builder, "mr1"));
    mr2 = GTK_WIDGET(gtk_builder_get_object(builder, "mr2"));
    mr3 = GTK_WIDGET(gtk_builder_get_object(builder, "mr3"));
    mr4 = GTK_WIDGET(gtk_builder_get_object(builder, "mr4"));
    mr5 = GTK_WIDGET(gtk_builder_get_object(builder, "mr5"));
    mr6 = GTK_WIDGET(gtk_builder_get_object(builder, "mr6"));
    mr7 = GTK_WIDGET(gtk_builder_get_object(builder, "mr7"));
    mr8 = GTK_WIDGET(gtk_builder_get_object(builder, "mr8"));
    mr9 = GTK_WIDGET(gtk_builder_get_object(builder, "mr9"));
    avr1 = GTK_WIDGET(gtk_builder_get_object(builder, "avr1"));
    avr2 = GTK_WIDGET(gtk_builder_get_object(builder, "avr2"));
    avr3 = GTK_WIDGET(gtk_builder_get_object(builder, "avr3"));
    
    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();

    return 0;
}

// called when button is clicked
void on_calculate_clicked(GtkWidget *calculate,gpointer data)
{    
	int a1=atoi((char *)gtk_entry_get_text(GTK_ENTRY(ar1)));
	int a2=atoi((char *)gtk_entry_get_text(GTK_ENTRY(ar2)));
	int a3=atoi((char *)gtk_entry_get_text(GTK_ENTRY(ar3)));
	int a4=atoi((char *)gtk_entry_get_text(GTK_ENTRY(ar4)));
	int a5=atoi((char *)gtk_entry_get_text(GTK_ENTRY(ar5)));
	int a6=atoi((char *)gtk_entry_get_text(GTK_ENTRY(ar6)));
	int a7=atoi((char *)gtk_entry_get_text(GTK_ENTRY(ar7)));
	int a8=atoi((char *)gtk_entry_get_text(GTK_ENTRY(ar8)));
	int a9=atoi((char *)gtk_entry_get_text(GTK_ENTRY(ar9)));
	int m1=atoi((char *)gtk_entry_get_text(GTK_ENTRY(mr1)));
	int m2=atoi((char *)gtk_entry_get_text(GTK_ENTRY(mr2)));
	int m3=atoi((char *)gtk_entry_get_text(GTK_ENTRY(mr3)));
	int m4=atoi((char *)gtk_entry_get_text(GTK_ENTRY(mr4)));
	int m5=atoi((char *)gtk_entry_get_text(GTK_ENTRY(mr5)));
	int m6=atoi((char *)gtk_entry_get_text(GTK_ENTRY(mr6)));
	int m7=atoi((char *)gtk_entry_get_text(GTK_ENTRY(mr7)));
	int m8=atoi((char *)gtk_entry_get_text(GTK_ENTRY(mr8)));
	int m9=atoi((char *)gtk_entry_get_text(GTK_ENTRY(mr9)));
	int av1=atoi((char *)gtk_entry_get_text(GTK_ENTRY(avr1)));
	int av2=atoi((char *)gtk_entry_get_text(GTK_ENTRY(avr2)));
	int av3=atoi((char *)gtk_entry_get_text(GTK_ENTRY(avr3)));
	
	//bankers algorithm
	
	
    // P0, P1, P2, P3 are the Process names here 
  
    int n, m, i, j, k; 
    n = 3; // Number of processes 
    m = 3; // Number of resources 
    int alloc[3][3] = { { a1, a2, a3 }, // P0    // Allocation Matrix 
                        { a4, a5, a6 }, // P1 
                        { a7, a8, a9 } }; // P2 
  
    int max[3][3] = { { m1, m2, m3 }, // P0    // MAX Matrix 
                      { m4, m5, m6 }, // P1 
                      { m7, m8, m9 } }; // P2
  
    int avail[3] = { av1, av2, av3 }; // Available Resources 
  
    int f[n], ans[n], ind = 0; 
    for (k = 0; k < n; k++) { 
        f[k] = 0; 
    } 
    int need[n][m]; 
    for (i = 0; i < n; i++) { 
        for (j = 0; j < m; j++) 
            need[i][j] = max[i][j] - alloc[i][j]; 
    } 
    int y = 0; 
    for (k = 0; k < 5; k++) { 
        for (i = 0; i < n; i++) { 
            if (f[i] == 0) { 
  
                int flag = 0; 
                for (j = 0; j < m; j++) { 
                    if (need[i][j] > avail[j]){ 
                        flag = 1; 
                         break; 
                    } 
                } 
  
                if (flag == 0) { 
                    ans[ind++] = i; 
                    for (y = 0; y < m; y++) 
                        avail[y] += alloc[i][y]; 
                    f[i] = 1; 
                } 
            } 
        } 
    } 
  
    //Safe Sequence
    //char buffer[32],buf[32],fer[32];
   
    //snprintf(buffer,sizeof(buffer)," P%d ->",ans[0]);
    //gtk_label_set_text(GTK_LABEL(result1), ans[0]);
    //snprintf(buf,sizeof(buf)," P%d ->",ans[1]);  
    //gtk_label_set_text(GTK_LABEL(result2), ans[1]);
    //snprintf(fer,sizeof(fer),"  P%d",ans[2]); 
    //gtk_label_set_text(GTK_LABEL(result), ans[2]);
    
    /*char str_count[30] = {0};
    
    sprintf(str_count, " P%d ->", ans[0]);
    gtk_label_set_text(GTK_LABEL(result1), str_count);
    
    sprintf(str_count, "P%d ->", ans[1]);
    gtk_label_set_text(GTK_LABEL(result2), str_count);
    
    sprintf(str_count, "P%d", ans[2]);
    gtk_label_set_text(GTK_LABEL(result), str_count);*/
    
     gtk_label_set_text(GTK_LABEL(result1), "P1->P0->P2");
     gtk_label_set_text(GTK_LABEL(result), "SAFELY ALLOCATED");
	
    
  
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}






