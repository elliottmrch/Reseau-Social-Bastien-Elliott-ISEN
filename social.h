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
ListePublications *initialise();
Publication *creerPublication(char titre[], char contenu[]);

void ajouterAmi(User *user, User *ami);
void supprimerAmi(User *user, User *ami);
void ajouterPublication(User *user, Publication *publication);
void supprimerToutesPublications(User *user);

char *userSelonId(User *users[], int taille, int id);

void afficherUtilisateurs(User *users[], int taille);
void afficherListeAmis(User *user, User *usersLst[], int taille);
void afficherPublications(User *user);

#endif