#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>

GtkBuilder *builder;
GtkWidget *window;
GtkWidget *stack;

// About section
GtkWidget *nameEntry;
GtkWidget *titleEntry;
GtkWidget *filechooser;
GtkWidget *emailEntry;
GtkWidget *phoneEntry;
GtkWidget *addressEntry;
GtkWidget *birthdateEntry;
GtkWidget *aboutEntry;

struct about {

    char name[30];
    char title[30];
    char email[50];
    char phone[20];
    char dob[15];
    char location[30];
    char image[400];
    char about[250];
};

// Education Section
GtkWidget *degreeEntry;
GtkWidget *collegeEntry;
GtkWidget *degreedateEntry;

struct education {

    char degree[100];
    char college[100];
    char date[15];

};

// Experience Section
GtkWidget *jobEntry;
GtkWidget *entityEntry;
GtkWidget *jobdateEntry;
GtkWidget *jobdesEntry;


struct experience {

    char job[50];
    char entity[50];
    char date[15];
    char description[250];

};

// Skills section
GtkWidget *skillsEntry;

// Language Section
GtkWidget *langEntry;
GtkWidget *combobox;

struct language {

    char name[20];
    char prof[30];

};

// Option buttons
GtkWidget *addbutton;
GtkWidget *deletebutton;

// Data label Section
GtkWidget *datalabel[4];

// Generating button
GtkWidget *generatebutton;

// Main Code variables
struct about user;
struct education eduitems[4];
struct experience expitems[4];
struct language lngitems[4];
FILE *html, *css;
int eduCounter=0, expCounter=0, lngCounter=0;
char skills[200], itemLabel[400];
char current_stack_selection[2];

// Defining the functions
// Add Button Function
void on_addButton_clicked(){
    sprintf(current_stack_selection,"%s",gtk_stack_get_visible_child_name(GTK_STACK(stack)));
    printf("%s", gtk_stack_get_visible_child_name(GTK_STACK(stack)));

    switch (current_stack_selection[0]){
    case 'a':
        strcpy(user.name, gtk_entry_get_text(GTK_ENTRY(nameEntry)));
        strcpy(user.title, gtk_entry_get_text(GTK_ENTRY(titleEntry)));
        strcpy(user.email, gtk_entry_get_text(GTK_ENTRY(emailEntry)));
        strcpy(user.phone, gtk_entry_get_text(GTK_ENTRY(phoneEntry)));
        strcpy(user.location, gtk_entry_get_text(GTK_ENTRY(addressEntry)));
        strcpy(user.about, gtk_entry_get_text(GTK_ENTRY(aboutEntry)));
        strcpy(user.dob, gtk_entry_get_text(GTK_ENTRY(birthdateEntry)));
        strcpy(user.image, gtk_file_chooser_get_uri(GTK_FILE_CHOOSER(filechooser)));
        printf("%s\n %s\n", user.name, user.image);
        sprintf(itemLabel, "Name: %s\nTitle: %s\nEmail: %s\nPhone: %s\nLocation: %s\nDate Of Birth: %s\nAbout Me: %s\n",
                user.name, user.title, user.email, user.phone, user.location, user.dob, user.about);
        gtk_label_set_text(GTK_LABEL(datalabel[0]), itemLabel);
        break;

    case 'b':
        if(eduCounter<4) {

            strcpy(eduitems[eduCounter].degree, gtk_entry_get_text(GTK_ENTRY(degreeEntry)));
            strcpy(eduitems[eduCounter].college, gtk_entry_get_text(GTK_ENTRY(collegeEntry)));
            strcpy(eduitems[eduCounter].date, gtk_entry_get_text(GTK_ENTRY(degreedateEntry)));
            sprintf(itemLabel, "%d)\nDegree/Course: %s\nCollege/School: %s\nDate: %s\n",
            eduCounter+1, eduitems[eduCounter].degree, eduitems[eduCounter].college, eduitems[eduCounter].date);
            gtk_label_set_text(GTK_LABEL(datalabel[eduCounter]), itemLabel);
            eduCounter++;
        }
        //printf("%s", current_stack_selection);
        //printf("Hello OsOs");
        break;
    case 'c':
        if(expCounter<4) {

               strcpy(expitems[expCounter].job, gtk_entry_get_text(GTK_ENTRY(jobEntry)));
               strcpy(expitems[expCounter].entity, gtk_entry_get_text(GTK_ENTRY(entityEntry)));
               strcpy(expitems[expCounter].date, gtk_entry_get_text(GTK_ENTRY(jobdateEntry)));
               strcpy(expitems[expCounter].description, gtk_entry_get_text(GTK_ENTRY(jobdesEntry)));
               sprintf(itemLabel, "%d)\nJob/Project: %s\nEntity: %s\nDate: %s\nDescription: %s\n",
                       expCounter+1, expitems[expCounter].job, expitems[expCounter].entity,  expitems[expCounter].date, expitems[expCounter].description);
               gtk_label_set_text(GTK_LABEL(datalabel[expCounter]), itemLabel);
               expCounter++;

       }
        break;
    case 'd':
        strcpy(skills, gtk_entry_get_text(GTK_ENTRY(skillsEntry)));
        sprintf(itemLabel, "Skills: %s", skills);
        gtk_label_set_text(GTK_LABEL(datalabel[0]), itemLabel);
        break;
    case 'e':
         if(lngCounter<4) {
               strcpy(lngitems[lngCounter].name, gtk_entry_get_text(GTK_ENTRY(langEntry)));
               strcpy(lngitems[lngCounter].prof, gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(combobox)));
               sprintf(itemLabel, "%d)\nLanguage: %s\nProficiency: %s\n", lngCounter+1, lngitems[lngCounter].name, lngitems[lngCounter].prof);
               gtk_label_set_text(GTK_LABEL(datalabel[lngCounter]), itemLabel);
               lngCounter++;

       }
        break;
    default:
            printf("%c", current_stack_selection[0]);
    }

}

// Delete Button function
void on_deleteButton_clicked() {

   int i;

   for(i=0; i<4; i++) {

       gtk_label_set_text(GTK_LABEL(datalabel[i]), "");

   }
   sprintf(current_stack_selection,"%s",gtk_stack_get_visible_child_name(GTK_STACK(stack)));
    printf("%s", gtk_stack_get_visible_child_name(GTK_STACK(stack)));

    switch (current_stack_selection[0]){
    case 'a':

           strcpy(user.name, "");
           strcpy(user.title, "");
           strcpy(user.email, "");
           strcpy(user.phone, "");
           strcpy(user.location, "");
           strcpy(user.about, "");
           strcpy(user.dob, "");
           strcpy(user.image, "");



   case 'b':

           strcpy(eduitems[eduCounter].degree, "");
           strcpy(eduitems[eduCounter].college, "");
           strcpy(eduitems[eduCounter].date, "");
           eduCounter=0;



   case 'c':

               strcpy(expitems[expCounter].job, "");
               strcpy(expitems[expCounter].entity, "");
               strcpy(expitems[expCounter].date, "");
               strcpy(expitems[expCounter].description, "");
               expCounter=0;

    case 'd':
           strcpy(skills, "");

    case 'e':

               strcpy(lngitems[lngCounter].name, "");
               strcpy(lngitems[lngCounter].prof, "");
               lngCounter=0;
   }

}

void on_generateButton_clicked() {

   html= fopen("index.html", "w");
   css = fopen("style.css", "w");
   fprintf(html, "<!DOCTYPE html> <html> <head> <meta charset=\"utf-8\"> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> <title>%s</title> <link href=\"style.css\" rel=\"stylesheet\" type=\"text/css\" /> <script src=\"https://kit.fontawesome.com/44a288ac8d.js\" crossorigin=\"anonymous\"></script> </head> <body> <div class=\"cv\"> <div class=\"header\"> <div class=\"pic\"> <img src=\"%s\"/> </div> <div class=\"details\"> <h1>%s</h1> <h3>%s</h3> <div class=\"basic-info\"> <div> <i class=\"fa-solid fa-envelope\"></i>%s</div> <div><i class=\"fa-solid fa-phone\"></i>%s</div> <div><i class=\"fa-solid fa-location-dot\"></i>%s</div> <div><i class=\"fa-solid fa-calendar-days\"></i>%s</div> </div> </div> </div> <div class=\"main\"> <div class=\"half\"> <div> <h2>ABOUT</h2> <p>%s</p> </div> <div> <h2>EDUCATION</h2>",
                   user.name, user.image, user.name, user.title, user.email, user.phone, user.location, user.dob, user.about);

   int i;
   for(i=0; i<eduCounter; i++) {
       fprintf(html, "<div> <h3>%s</h3> <h3 class=\"light\">%s</h3> <p class=\"date\">%s</p> </div>", eduitems[i].degree, eduitems[i].college, eduitems[i].date);

   }

   fprintf(html, "</div><div><h2>EXPERIENCE</h2>");
   for(i=0; i<expCounter; i++) {
       fprintf(html, "<div> <h3>%s</h3> <h3 class=\"light\">%s</h3> <p class=\"date\">%s</p> <p class=\"light\">%s</p> </div>",
                       expitems[i].job, expitems[i].entity, expitems[i].date, expitems[i].description);

   }

   fprintf(html, "</div> </div> <div class=\"half\"> <div> <h2>SKILLS</h2> <p>%s</p> </div> <div> <h2>LANGUAGES</h2>", skills);
   for(i=0; i<lngCounter; i++) {
       fprintf(html, "<div> <h3>%s</h3> <p>%s</p> </div>", lngitems[i].name, lngitems[i].prof);

   }
   fprintf(html, "</div></div></div></div></body></html>");
   fprintf(css, "@import url('https://fonts.googleapis.com/css2?family=Roboto:ital,wght@0,100;0,300;0,400;0,500;0,700;0,900;1,100;1,300;1,400;1,500;1,700;1,900&display=swap'); :root { --theme-color: teal; } body { font-family: \"Roboto\", sans-serif; line-height: 24px; background-color: gray; } * { margin: 0; padding: 0; } .cv { display: flex; flex-direction: column; width: 100vw; max-width: 900px; margin: 50px auto; } .header{ display: flex; flex-direction: row; height: 15vh; min-height: 150px; background-color: var(--theme-color); color: white; padding: 20px; align-items: center; } h3 { color: black; } img { width: 140px; height: 140px; border-radius: 50%%; object-fit: cover; border-style: solid; border-color: white; border-width: 5px; } .details { display: flex; flex-direction: column; margin-left: 20px; width: 90%%; } .basic-info { display: flex; flex-direction: row; justify-content: space-between; flex-wrap: wrap; } i { margin-right: 5px; } .main { display: flex; flex-direction: row; justify-content: space-between; padding: 20px; background-color: white; text-align: justify; } .half { width: 45%%; } .main h2 { color: var(--theme-color); margin-top: 30px; } .light { font-weight: 400; } .date { color: var(--theme-color); font-style: italic; } @media screen and (max-width: 600px) { .main { flex-direction: column; } .half { width: 100%%; } .cv { margin: auto; } }");
   fclose(html);
   fclose(css);

}

int main(){
 gtk_init(NULL, NULL);
 builder = gtk_builder_new_from_file("CvDesign.glade");
 window = gtk_builder_get_object(builder, "window");
 stack = gtk_builder_get_object(builder, "stack");
 // About section
 nameEntry = gtk_builder_get_object(builder, "nameEntry");
 titleEntry = gtk_builder_get_object(builder, "titleEntry");
 filechooser = gtk_builder_get_object(builder, "filechooser");
 emailEntry = gtk_builder_get_object(builder, "emailEntry");
 phoneEntry = gtk_builder_get_object(builder, "phoneEntry");
 addressEntry = gtk_builder_get_object(builder, "addressEntry");
 birthdateEntry = gtk_builder_get_object(builder, "birthdateEntry");
 aboutEntry = gtk_builder_get_object(builder, "aboutEntry");

 // Experience Section
 degreeEntry = gtk_builder_get_object(builder, "degreeEntry");
 collegeEntry = gtk_builder_get_object(builder, "collegeEntry");
 degreedateEntry = gtk_builder_get_object(builder, "degreedateEntry");

 // Experience Section
 jobEntry = gtk_builder_get_object(builder, "jopEntry");
 entityEntry = gtk_builder_get_object(builder, "entityEntry");
 jobdateEntry = gtk_builder_get_object(builder, "jopdateEntry");
 jobdesEntry = gtk_builder_get_object(builder, "jopdesEntry");

 // Skills section
  skillsEntry = gtk_builder_get_object(builder, "skillsEntry");

 // Language Section
 langEntry = gtk_builder_get_object(builder, "langEntry");
 combobox = gtk_builder_get_object(builder, "combobox");

 // Option buttons
 addbutton = gtk_builder_get_object(builder, "addbutton");
 deletebutton = gtk_builder_get_object(builder, "deletebutton");

 // Data label Section
 datalabel[0] = gtk_builder_get_object(builder, "data1label");
 datalabel[1] = gtk_builder_get_object(builder, "data2label");
 datalabel[2] = gtk_builder_get_object(builder, "data3label");
 datalabel[3] = gtk_builder_get_object(builder, "data4label");

 // Generating button
 generatebutton = gtk_builder_get_object(builder, "generatebutton");

 g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
 g_signal_connect(addbutton, "clicked", G_CALLBACK(on_addButton_clicked), NULL);
 g_signal_connect(deletebutton, "clicked", G_CALLBACK(on_deleteButton_clicked), NULL);
 //g_signal_connect(generatebutton, "clicked", G_CALLBACK(on_generateButton_clicked), NULL);

 //gtk_window_maximize(window);

 gtk_widget_show(window);
 gtk_main();

}
