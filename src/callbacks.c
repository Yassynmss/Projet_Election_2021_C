#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "observateur.h"

int x=0,y=0;
int validapp1=0,validapp_mdf1=0;
int validapp2=0,validapp_mdf2=0;
int validapp3=0,validapp_mdf3=0;
int validapp4=0,validapp_mdf4=0;
int validapp5=0,validapp_mdf5=0;
observateur e;

void
on_buttonrechercher_obs_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cherch;
char id[20];
GtkWidget *treeview1_ob;
GtkWidget *afficher_ob;
afficher_ob=lookup_widget(button,"Gestion_observateur");

treeview1_ob=lookup_widget(afficher_ob,"treeview7");
cherch = lookup_widget (button ,"entre_rech");
strcpy(id, gtk_entry_get_text(GTK_ENTRY(cherch)));
 rechercher_observateur(treeview1_ob,id);
}


void
on_button_afficher_obs_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1_ob;
GtkWidget *afficher_ob;
afficher_ob=lookup_widget(button,"Gestion_observateur");
treeview1_ob=lookup_widget(afficher_ob,"treeview7");
afficher_observateur(treeview1_ob);
}


void
on_button_ajouter_obs_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *observateur;
observateur=lookup_widget(button,"Gestion_observateur");
gtk_widget_destroy(observateur);
GtkWidget *ajouter;
ajouter = create_Ajouter_observateur();
  gtk_widget_show (ajouter);
}


void
on_button_ok_ajouter_obs_clicked       (GtkButton       *objet,
                                        gpointer         user_data)
{
int o=0;
observateur r;

GtkWidget *entryID_obs, *entryprenom, *entrynom, *entryJour, *entryMois ,*entryAnnee , *entrygenre1 ,*entrynationalite ,*entryNUMPasseport ,*entrygenre2;




entryID_obs=lookup_widget(objet,"entry_id_obs");
entryprenom=lookup_widget(objet,"entry_prenom_obs");
entrynom=lookup_widget(objet,"entry_nom_obs");

entryJour=lookup_widget(objet,"spinbutton38");
entryMois=lookup_widget(objet,"spinbutton39");
entryAnnee=lookup_widget(objet,"spinbutton40");


entrynationalite=lookup_widget(objet,"comboboxentry19");

entryNUMPasseport=lookup_widget(objet,"entry_pass");


entrygenre1=lookup_widget(objet, "radiobutton43");
entrygenre2=lookup_widget(objet, "radiobutton44");






strcpy(r.ID_obs,gtk_entry_get_text(GTK_ENTRY(entryID_obs) ) );
strcpy(r.prenom,gtk_entry_get_text(GTK_ENTRY(entryprenom) ) );
strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(entrynom) ) );

r.d.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryJour));
r.d.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryMois));
r.d.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryAnnee));


 if (x==1){
strcpy(r.genre,"Homme");}
else 
if (x==2){
strcpy(r.genre,"Femme");}

strcpy(r.nationalite, gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrynationalite)) ) ;
strcpy(r.NUMPasseport,gtk_entry_get_text(GTK_ENTRY(entryNUMPasseport) ) );


if (validapp1==1)
strcpy(r.app,"Parti-politique" );


if (validapp2==1)

{
strcpy(r.app,"Organisation-mondial" );

}
if (validapp3==1)

{
strcpy(r.app,"Hote" );

}
if (validapp4==1)

{
strcpy(r.app,"Presse" );

}
if (validapp5==1)

{
strcpy(r.app,"Societe-civille" );

}



	ajout_observateur(r);


GtkWidget *ajouter;
ajouter=lookup_widget(objet,"Ajouter_observateur");
gtk_widget_destroy(ajouter);
GtkWidget *observa;
observa = create_Gestion_observateur();
  gtk_widget_show (observa);

}





void
on_checkbutton1_ajt_obs_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active( (togglebutton)))
{validapp1=1;}
}


void
on_checkbutton2_ajt_obs_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_checkbutton3_ajt_obs_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active( (togglebutton)))
{validapp3=1;}
}


void
on_checkbutton4_ajt_obs_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active( (togglebutton)))
{validapp4=1;}
}


void
on_checkbutton5_ajt_obs_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active( (togglebutton)))
{validapp5=1;}
}


void
on_button_retour_ajouter_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *observateur;
observateur=lookup_widget(button,"Ajouter_observateur");
gtk_widget_destroy(observateur);
GtkWidget *ajouter;
ajouter = create_Gestion_observateur();
  gtk_widget_show (ajouter);
}


void
on_ajouter_observateur_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_radiobutton44_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=2;}
}


void
on_radiobutton43_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=1;}
}


void
on_treeview7_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

GtkTreeIter iter;
	gchar* ID_obs;
	gchar* prenom;
	gchar* nom;
	gint* jour;
	gint* mois;
	gint* annee;
	gchar* genre;
	gchar* nationalite;
	gchar* NUMPasseport;
	gchar* app;


	GtkTreeModel *model =gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter , path))
	{ 
	  gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0 , &ID_obs, 1, &prenom, 2,&nom, 3,&jour, 4,&mois, 5 ,&annee, 6,&genre, 7,&nationalite, 8,&NUMPasseport,9,&app,-1);
	strcpy(e.ID_obs,ID_obs);
	strcpy(e.prenom,prenom);
         strcpy(e.nom,nom);
         strcpy(e.NUMPasseport,NUMPasseport);
          strcpy(e.genre,genre);
	  e.d.jour=jour;
	 e.d.mois=mois;
	 e.d.annee=annee;
        strcpy(e.nationalite,nationalite);
      
	
	}
}

void
on_button_modifier_obs_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *observ;
observ=lookup_widget(button,"Gestion_observateur");
gtk_widget_destroy(observ);
GtkWidget *modifier;
modifier = create_Modifier_Observateur ();
  gtk_widget_show (modifier);


GtkWidget* msgID=lookup_widget(modifier,"entryid_mdf");
gtk_label_set_text(GTK_LABEL(msgID),e.ID_obs);
                gtk_widget_show(msgID);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier,"entryprenom_mdf")),e.prenom);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier,"entrynom_mdf")),e.nom);
;
gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(modifier,"spinbutton45_mdf")),e.d.jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(modifier,"spinbutton46_mdf")),e.d.mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(modifier,"spinbutton47_mdf")),e.d.annee);
if (strcmp(e.genre,"Homme")==0){
gtk_toggle_button_set_active(GTK_RADIO_BUTTON (lookup_widget(modifier,"radiobutton45_mdf")),TRUE);
}
else if (strcmp(e.genre,"Femme")==0){
gtk_toggle_button_set_active(GTK_RADIO_BUTTON (lookup_widget(modifier,"radiobutton46_mdf")),TRUE);
}


gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier,"entrypass_mdf")),e.NUMPasseport);

}

void
on_button_supprimer_obs_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_ob;
afficher_ob=lookup_widget(button,"Gestion_observateur");
gtk_widget_destroy(afficher_ob);
GtkWidget *supprimer_ob;
supprimer_ob = create_Supprimer_Observateur ();
  gtk_widget_show (supprimer_ob);
}
void
on_button_oui_supp_obs_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
 char r[30];


strcpy(r,e.ID_obs);
supprimer_observateur(r);
GtkWidget *supprimer_ob;
supprimer_ob=lookup_widget(button,"Supprimer_Observateur");
gtk_widget_destroy(supprimer_ob);
GtkWidget *afficher;
afficher = create_Gestion_observateur();
  gtk_widget_show (afficher);
}
void
on_button_non_sup_obs_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *supprimer_ob;
supprimer_ob=lookup_widget(button,"Supprimer_Observateur");
gtk_widget_destroy(supprimer_ob);
GtkWidget *afficher;
afficher = create_Gestion_observateur();
  gtk_widget_show (afficher);
}


void
on_buttonretour_modif_ob_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modifier_ob;
modifier_ob=lookup_widget(button,"Modifier_Observateur");
gtk_widget_destroy(modifier_ob);
GtkWidget *afficher_ob;
afficher_ob = create_Gestion_observateur();
  gtk_widget_show (afficher_ob);
}


void
on_button_ok1_modif_obs_clicked        (GtkButton       *objet,
                                        gpointer         user_data)
{
observateur r;

GtkWidget *entryID_obs, *entryprenom, *entrynom, *entryJour, *entryMois ,*entryAnnee , *entrygenre1 ,*entrynationalite ,*entryNUMPasseport,*entrygenre2;



entryID_obs=lookup_widget(objet,"entryid_mdf");
entryprenom=lookup_widget(objet,"entryprenom_mdf");
entrynom=lookup_widget(objet,"entrynom_mdf");

entryJour=lookup_widget(objet,"spinbutton45_mdf");
entryMois=lookup_widget(objet,"spinbutton46_mdf");
entryAnnee=lookup_widget(objet,"spinbutton47_mdf");


entrynationalite=lookup_widget(objet,"comboboxentry20_mdf");

entryNUMPasseport=lookup_widget(objet,"entrypass_mdf");


entrygenre1=lookup_widget(objet, "radiobutton45_mdf");
entrygenre2=lookup_widget(objet, "radiobutton46_mdf");




strcpy(r.ID_obs,e.ID_obs);
strcpy(r.prenom,gtk_entry_get_text(GTK_ENTRY(entryprenom) ) );
strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(entrynom) ) );

r.d.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryJour));
r.d.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryMois));
r.d.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryAnnee));


 if (y==1){
strcpy(r.genre,"Homme");}
else 
if (y==2){
strcpy(r.genre,"Femme");}

strcpy(r.nationalite, gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrynationalite)) ) ;
strcpy(r.NUMPasseport,gtk_entry_get_text(GTK_ENTRY(entryNUMPasseport) ) );


if (validapp_mdf1==1)
{
strcpy(r.app,"Parti-politique" );
}

if (validapp_mdf2==1)

{
strcpy(r.app,"Organisation-mondial" );

}
if (validapp_mdf3==1)

{
strcpy(r.app,"Hote" );

}
if (validapp_mdf4==1)

{
strcpy(r.app,"Presse" );

}
if (validapp_mdf5==1)

{
strcpy(r.app,"Societe-civille" );

}

 modifier_observateur(r);


GtkWidget *modifier;
modifier=lookup_widget(objet,"Modifier_Observateur");
gtk_widget_destroy(modifier);

GtkWidget *obss;
obss = create_Gestion_observateur ();
gtk_widget_show (obss);

}


void
on_radiobutton45_mdf_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=1;}
}


void
on_radiobutton46_mdf_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=2;}
}


void
on_checkbutton52_mdf_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active( (togglebutton)))
{validapp_mdf5=1;}
}


void
on_checkbutton51_mdf_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active( (togglebutton)))
{validapp_mdf4=1;}
}


void
on_checkbutton50_mdf_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active( (togglebutton)))
{validapp_mdf3=1;}
}


void
on_checkbutton49_mdf_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_checkbutton48_mdf_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active( (togglebutton)))
{validapp_mdf1=1;}
}


void
on_checkbuttonOrganisationmondial_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active( (togglebutton)))
{validapp2=1;}
}


void
on_checkbutton2Organisationmondial_mdf_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active( (togglebutton)))
{validapp_mdf2=1;}
}

