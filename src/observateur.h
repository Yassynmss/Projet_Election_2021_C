#ifndef OBS_H_INCLUDED
#define OBS_H_INCLUDED
#include <stdio.h>
#include <gtk/gtk.h>
typedef struct
{
    int jour;
    int mois;
    int annee;
}DATE;
typedef struct
{   char ID_obs[30];
    char prenom[30];
    char nom[30];
    DATE d;
    char genre[10];
    char nationalite[30];
    char NUMPasseport[30];
    char app[30];
   

}observateur;
//function;
void afficher_observateur(GtkWidget *liste );

void ajout_observateur(observateur ob);

void rechercher_observateur(GtkWidget *liste,char id[30] );

void modifier_observateur(observateur ob);
void supprimer_observateur(char *id);

#endif // OBS_H_INCLUDED
