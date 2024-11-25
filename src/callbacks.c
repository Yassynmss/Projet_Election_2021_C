#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "yassineutilisateur.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"
int x=1;
int x2=1;

void
on_MYquitterds_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;

n=lookup_widget(objet_graphique, "dhashbord");
gtk_widget_destroy(n);
}


void
on_gestion_user_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *affiche;
GtkWidget *afficher_y;
afficher_y=lookup_widget(objet_graphique,"dhashbord");
gtk_widget_destroy(afficher_y);
affiche=create_gestion_yassine();
gtk_widget_show (affiche);

}


void
on_treeview_yassine_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar* cin;
gchar* Ntelephone;
gchar* nom;
gchar* prenom;
gint* jour;
gchar* mois;
gint* annee;
gchar* role;
gchar* genre;
gchar* nbvote;

utilisateur L;
GtkTreeIter iter;
GtkTreeModel *model=gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model,&iter,path))
	{ 
	  gtk_tree_model_get(GTK_TREE_MODEL(model),&iter,0,cin,1,Ntelephone,2,nom,3,prenom,4,&jour,5,mois,6,&annee,7,role,8,genre,9,nbvote-1);
strcpy(L.cin,cin);
strcpy(L.Ntelephone,Ntelephone);
strcpy(L.nom,nom);
strcpy(L.prenom,prenom);
strcpy(L.d.mois,mois);
strcpy(L.role,role);
strcpy(L.genre,genre);
strcpy(L.nbvote,nbvote);
L.d.jour=*jour;
L.d.annee=*annee;
afficher_user(treeview);
	}

}


void
on_retour_yassine_clicked              (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *affiche;
GtkWidget *afficher_y;
afficher_y=lookup_widget(objet_graphique,"gestion_yassine");
gtk_widget_destroy(afficher_y);
affiche=create_dhashbord();
gtk_widget_show (affiche);
}


void
on_recherche_yassine_clicked           (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *cherch;
char id[30];
GtkWidget *treeview1_uti;
GtkWidget *afficher_uti;
afficher_uti=lookup_widget(objet_graphique,"gestion_yassine");

treeview1_uti=lookup_widget(afficher_uti,"treeview_yassine");
cherch = lookup_widget (objet_graphique ,"entry_recherche_b");
strcpy(id, gtk_entry_get_text(GTK_ENTRY(cherch)));
 Chercher(treeview1_uti,id);
}


void
on_ajouter_yassine_clicked             (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajouter;
GtkWidget *afficher_yassine;
afficher_yassine=lookup_widget(objet_graphique,"gestion_yassine");
gtk_widget_destroy(afficher_yassine);
ajouter=create_ajout_yassine();
gtk_widget_show (ajouter);
}


void
on_supprime_yassine_clicked            (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "supprimer_yassine");
p=lookup_widget(objet_graphique, "gestion_yassine");
p=create_supprimer_yassine();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_modifie_yassine_clicked             (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "supprimer_yassine");
p=lookup_widget(objet_graphique, "modifier_yassine");
p=create_modifier_yassine ();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_afficher_yassine_clicked            (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *fenetre_afficher, *w1;
GtkWidget *treeview;
w1=lookup_widget(objet_graphique,"gestion_yassine");
fenetre_afficher=create_gestion_yassine ();
gtk_widget_show(fenetre_afficher);
gtk_widget_hide (w1);
treeview=lookup_widget(fenetre_afficher,"treeview_yassine");
afficher_user(treeview);

}


void
on_quitter_yassine_clicked             (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;

n=lookup_widget(objet_graphique, "gestion_yassine");
gtk_widget_destroy(n);
}


/*void
on_radiobutton1_b_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
x=1;
}


void
on_radiobutton3_b_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
x=2;
}*/


void
on_confirmer_yassine_clicked           (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
utilisateur L;
GtkWidget *entrycin,*entrytelephone,*entrynom,*entryprenom,*entryjour,*entrymois,*entryannee,*entryrole,*entrygenre,*entrynbvote;

entrycin=lookup_widget(objet_graphique,"ya_cin");
entrytelephone=lookup_widget(objet_graphique,"ya_telephone");
entrynom=lookup_widget(objet_graphique,"ya_nom");
entryprenom=lookup_widget(objet_graphique,"ya_prenom");
entryjour=lookup_widget(objet_graphique,"spinbutton1_ya");
entrymois=lookup_widget(objet_graphique,"combobox1_ya");
entryannee=lookup_widget(objet_graphique,"spinbutton2_ya");
entryrole=lookup_widget(objet_graphique,"combobox2_ya");
entrynbvote=lookup_widget(objet_graphique,"ya_nbvote");

strcpy(L.cin,gtk_entry_get_text(GTK_ENTRY(entrycin)));
strcpy(L.Ntelephone,gtk_entry_get_text(GTK_ENTRY(entrytelephone)));
strcpy(L.nom,gtk_entry_get_text(GTK_ENTRY(entrynom)));
strcpy(L.prenom,gtk_entry_get_text(GTK_ENTRY(entryprenom)));

L.d.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryjour));
strcpy(L.d.mois, gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrymois)));
L.d.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryannee));
strcpy(L.role, gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryrole)));
strcpy(L.nbvote,gtk_entry_get_text(GTK_ENTRY(entrynbvote)));
if (x==1){
strcpy(L.genre,"Homme");}
else 
if (x==2){
strcpy(L.genre,"Femme");}
ajouterUser(L);

}


void
on_annuler_yassine_clicked             (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *affiche;
GtkWidget *afficher_y;
afficher_y=lookup_widget(objet_graphique,"supprimer_yassine");
gtk_widget_destroy(afficher_y);
affiche=create_gestion_yassine();
gtk_widget_show (affiche);
}


void
on_radiobutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
x2=1;
}


void
on_radiobutton7_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
x2=1;
}


void
on_enregistrer_yassine_clicked         (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
utilisateur L;
GtkWidget *entrycin,*entrytelephone,*entrynom,*entryprenom,*entryjour,*entrymois,*entryannee,*entryrole,*entrygenre,*entrynbvote;
int t0=0;
entrycin=lookup_widget(objet_graphique,"y_cin");
entrytelephone=lookup_widget(objet_graphique,"y_telephone");
entrynom=lookup_widget(objet_graphique,"y_nom");
entryprenom=lookup_widget(objet_graphique,"y_prenom");
entryjour=lookup_widget(objet_graphique,"spinbutton12_y");
entrymois=lookup_widget(objet_graphique,"combobox12_y");
entryannee=lookup_widget(objet_graphique,"spinbutton2_y");
entryrole=lookup_widget(objet_graphique,"combobox13_y");
entrynbvote=lookup_widget(objet_graphique,"y_nbvote");

strcpy(L.cin,gtk_entry_get_text(GTK_ENTRY(entrycin)));
strcpy(L.Ntelephone,gtk_entry_get_text(GTK_ENTRY(entrytelephone)));
strcpy(L.nom,gtk_entry_get_text(GTK_ENTRY(entrynom)));
strcpy(L.prenom,gtk_entry_get_text(GTK_ENTRY(entryprenom)));

L.d.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryjour));
strcpy(L.d.mois, gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrymois)));
L.d.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryannee));
strcpy(L.role, gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryrole)));
strcpy(L.nbvote,gtk_entry_get_text(GTK_ENTRY(entrynbvote)));
if (x2==1){
strcpy(L.genre,"Homme");}
else 
if (x2==2){
strcpy(L.genre,"Femme");}
t0=modifierUser(L);
}


void
on_nonb_supprimer_clicked              (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *affiche;
GtkWidget *afficher_y;
afficher_y=lookup_widget(objet_graphique,"supprimer_yassine");
gtk_widget_destroy(afficher_y);
affiche=create_gestion_yassine();
gtk_widget_show (affiche);
}


void
on_button15_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*label;
GtkWidget*e;
char ch[20];
label=lookup_widget(objet_graphique, "label43");
e=lookup_widget(objet_graphique, "entry1");
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(e)));
supprimerUser(ch);
}


void
on_radiobutton1_yas_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
x=1;
}


void
on_radiobutton2_yas_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
x=2;
}


void
on_radiobutton3_y_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
x2=1;
}


void
on_radiobutton4_y_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
x2=1;
}


void
on_annuler2_yassine_clicked            (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *affiche;
GtkWidget *afficher_y;
afficher_y=lookup_widget(objet_graphique,"modifier_yassine");
gtk_widget_destroy(afficher_y);
affiche=create_gestion_yassine();
gtk_widget_show (affiche);
}

