#ifndef SOCIAL_H
#define SOCIAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    struct UserId *suivant;
} UserId;

typedef struct
{
    UserId *premier;
    int nbrAmis;
} ListeAmis;

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
    ListeAmis *amis;
    ListePublications *publications;
} User;

User *creerUser(int id, char *pseudo);
void inscription(User *user, char *pseudo);

#endif