#include "observateur.h"
#include <gtk/gtk.h>
#include<stdio.h>

#include<string.h>


//////////////////////////////

enum{
ID_OBS,
PRENOM,
NOM,
JOUR,
MOIS,
ANNEE,
GENRE,
NATIONALITE,
NUMPASSEPORT,
APP,
COLUMNS
};


void afficher_observateur(GtkWidget *liste )

{


GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{


renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID_OBS",
                                                            renderer,
                                                            "text", ID_OBS,
                                                            NULL);
        
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        
	
	
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("PRENOM",
                                                            renderer,
                                                            "text", PRENOM,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	

	
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("NOM",
                                                            renderer,
                                                            "text", NOM,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("JOUR",
                                                            renderer,
                                                            "text", JOUR,
                                                            NULL);
        
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("MOIS",
                                                            renderer,
                                                            "text", MOIS,
                                                            NULL);
       
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ANNEE",
                                                            renderer,
                                                            "text", ANNEE,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	 renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("GENRE",
                                                            renderer,
                                                            "text", GENRE,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	 renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("NATIONALITE",
                                                            renderer,
                                                            "text", NATIONALITE,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	 renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("NUMPASSEPORT",
                                                            renderer,
                                                            "text", NUMPASSEPORT,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	 renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("APP",
                                                            renderer,
                                                            "text", APP,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("observateur.txt","r");

    char ID_obs[30];
    char prenom[30];
    char nom[30];
    int jour;
    int mois;
    int annee;
    char genre[10];
    char nationalite[30];
    char NUMPasseport[30];
    char app[30];




{
f=fopen("observateur.txt","a+");
	while(fscanf(f,"%s %s %s %d %d %d %s %s %s %s \n",ID_obs,prenom,nom,&jour,&mois,&annee,genre,nationalite,NUMPasseport,app)!=EOF)
	{ 
gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,ID_OBS,ID_obs,PRENOM,prenom,NOM,nom,JOUR,jour,MOIS,mois,ANNEE,annee,GENRE,genre,NATIONALITE,nationalite,NUMPASSEPORT,NUMPasseport,APP,app,-1);
	}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
//////////////////////

void rechercher_observateur(GtkWidget *liste,char id[30] )
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{


renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID_OBS",
                                                            renderer,
                                                            "text", ID_OBS,
                                                            NULL);
        
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        
	
	
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("PRENOM",
                                                            renderer,
                                                            "text", PRENOM,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	

	
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("NOM",
                                                            renderer,
                                                            "text", NOM,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("JOUR",
                                                            renderer,
                                                            "text", JOUR,
                                                            NULL);
        
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("MOIS",
                                                            renderer,
                                                            "text", MOIS,
                                                            NULL);
       
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ANNEE",
                                                            renderer,
                                                            "text", ANNEE,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	 renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("GENRE",
                                                            renderer,
                                                            "text", GENRE,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	 renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("NATIONALITE",
                                                            renderer,
                                                            "text", NATIONALITE,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	 renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("NUMPASSEPORT",
                                                            renderer,
                                                            "text", NUMPASSEPORT,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	 renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("APP",
                                                            renderer,
                                                            "text", APP,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("observateur.txt","r");

    char ID_obs[30];
    char prenom[30];
    char nom[30];
    int jour;
    int mois;
    int annee;
    char genre[10];
    char nationalite[30];
    char NUMPasseport[30];
    char app[30];




{
f=fopen("observateur.txt","a+");
	while(fscanf(f,"%s %s %s %d %d %d %s %s %s %s \n",ID_obs,prenom,nom,&jour,&mois,&annee,genre,nationalite,NUMPasseport,app)!=EOF)
	{ if((strcmp(id,ID_obs)==0) ){ 
gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,ID_OBS,ID_obs,PRENOM,prenom,NOM,nom,JOUR,jour,MOIS,mois,ANNEE,annee,GENRE,genre,NATIONALITE,nationalite,NUMPASSEPORT,NUMPasseport,APP,app,-1);
	}}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}

/////////////////////
void ajout_observateur(observateur ob)
{
    FILE* f;
f=fopen("observateur.txt","a+");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %d %d %d %s %s %s %s \n",ob.ID_obs,ob.prenom,ob.nom,ob.d.jour,ob.d.mois,ob.d.annee,ob.genre,ob.nationalite,ob.NUMPasseport,ob.app);
        fclose(f);
        
    }
}
   
////////////////////////////////
void supprimer_observateur(char *id)
{

FILE*f=NULL;
FILE*f1=NULL;
observateur ob;
f=fopen("observateur.txt","r");
f1=fopen("ancien.txt","w+"); 
while(fscanf(f,"%s %s %s %d %d %d %s %s %s %s \n",ob.ID_obs,ob.prenom,ob.nom,&ob.d.jour,&ob.d.mois,&ob.d.annee,ob.genre,ob.nationalite,ob.NUMPasseport,ob.app)!=EOF){
if(strcmp(id,ob.ID_obs)!=0)fprintf(f1,"%s %s %s %d %d %d %s %s %s %s \n",ob.ID_obs,ob.prenom,ob.nom,ob.d.jour,ob.d.mois,ob.d.annee,ob.genre,ob.nationalite,ob.NUMPasseport,ob.app);
}
fclose(f);
fclose(f1);
remove("observateur.txt");
rename("ancien.txt","observateur.txt");
}
/////////////////////

void modifier_observateur(observateur ob)
{
FILE*f=NULL;
FILE*f1=NULL;
observateur oba ;
f=fopen("observateur.txt","r");
f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %d %d %d %s %s %s %s \n\n",oba.ID_obs,oba.prenom,oba.nom,&oba.d.jour,&oba.d.mois,&oba.d.annee,oba.genre,oba.nationalite,oba.NUMPasseport,oba.app)!=EOF){
if( strcmp(ob.ID_obs,oba.ID_obs)==0)
{
fprintf(f1,"%s %s %s %d %d %d %s %s %s %s \n \n",ob.ID_obs,ob.prenom,ob.nom,ob.d.jour,ob.d.mois,ob.d.annee,ob.genre,ob.nationalite,ob.NUMPasseport,ob.app);
}
else
{
fprintf(f1,"%s %s %d %d %d %s %s %s \n",oba.ID_obs,oba.prenom,oba.nom,oba.d.jour,oba.d.mois,oba.d.annee,oba.genre,oba.nationalite,oba.NUMPasseport,oba.app);
}

}
fclose(f);
fclose(f1);
remove("observateur.txt");
rename("ancien.txt","observateur.txt");
}

/////////////////////////


