#ifndef SOCIAL_H
#define SOCIAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char titre[50];
    char contenu[500];
    struct Publication *suivant;
} Publication;

typedef struct
{
    Publication *premier;
} ListePublications;

typedef struct
{
    int id;
    char pseudo[50];
    int idAmis[50];
    ListePublications *publications;
} User;

User *creerUser(int id, char pseudo[]);
Publication *creerPublication(char titre[], char contenu[]);

void ajouterAmi(User *user, int idAmi);
void supprimerAmi(User *user, int idAmi);
void ajouterPublication(User *user, Publication *publication);

char *userSelonId(User *users[], int taille, int id);
int idSelonUser(User *users[], int taille, char pseudo[]);

void afficherAmis(User *user, User *usersLst[], int taille);
void afficherUtilisateurs(User *users[], int taille, int choix);
void afficherPublications(User *users[], int taille, int choix);

#endif