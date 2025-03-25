#include "social.h"

User *creerUser(int id, char pseudo[])
{
    User *nv = malloc(sizeof(User));
    if (nv == NULL)
        exit(1);
    nv->id = id;
    strcpy(nv->pseudo, pseudo);
    for (int i = 0; i < 50; i++)
        nv->idAmis[i] = -1;
    nv->publications = NULL;

    return nv;
}

ListePublications *initialise()
{
    ListePublications *nv = malloc(sizeof(ListePublications));
    if (nv == NULL)
        exit(1);
    nv->premier = NULL;

    return nv;
}

Publication *creerPublication(char titre[], char contenu[])
{
    Publication *nv = malloc(sizeof(Publication));
    if (nv == NULL)
        exit(1);
    strcpy(nv->titre, titre);
    strcpy(nv->contenu, contenu);
    nv->suivant = NULL;

    return nv;
}

//--------------------------------------------------------------

void ajouterAmi(User *user, User *ami)
{
    for (int i = 0; i < 50; i++)
    {
        if (user->idAmis[i] == -1)
        {
            user->idAmis[i] = ami->id;
            break;
        }
    }

    for (int i = 0; i < 50; i++)
    {
        if (ami->idAmis[i] == -1)
        {
            ami->idAmis[i] = user->id;
            break;
        }
    }
}

void supprimerAmi(User *user, User *ami)
{
    for (int i = 0; i < 50; i++)
    {
        if (user->idAmis[i] == ami->id)
        {
            user->idAmis[i] = -1;
            break;
        }
    }

    for (int i = 0; i < 50; i++)
    {
        if (ami->idAmis[i] == user->id)
        {
            ami->idAmis[i] = -1;
            break;
        }
    }
}

void ajouterPublication(User *user, Publication *publication)
{
    if (user->publications == NULL)
    {
        user->publications = initialise();
        user->publications->premier = publication;
    }
    else
    {
        Publication *actuel = user->publications->premier;
        while (actuel->suivant != NULL)
        {
            actuel = actuel->suivant;
        }
        actuel->suivant = publication;
    }
}

//--------------------------------------------------------------

char *userSelonId(User *users[], int taille, int id)
{
    for (int i = 0; i < taille; i++)
    {
        if (users[i]->id == id)
        {
            return users[i]->pseudo;
        }
    }
    return NULL;
}

//--------------------------------------------------------------

void afficherUtilisateurs(User *users[], int taille)
{
    for (int i = 0; i < taille; i++)
    {
        printf("ID: %d  ", users[i]->id);
        printf("Pseudo: %s  \n", users[i]->pseudo);
    }
}

void afficherListeAmis(User *user, User *usersLst[], int taille)
{
    printf("Amis: ");
    for (int i = 0; i < 50; i++)
    {
        if (user->idAmis[i] != -1)
        {
            char *pseudo = userSelonId(usersLst, taille, user->idAmis[i]);
            if (pseudo != NULL)
            {
                printf("%s  ", pseudo);
            }
        }
    }
    printf("\n");
}

void afficherPublications(User *user)
{
    if (user->publications == NULL)
    {
        printf("Aucune publication\n");
    }
    else
    {
        Publication *actuel = user->publications->premier;
        while (actuel != NULL)
        {
            printf("Titre: %s\n", actuel->titre);
            printf("Contenu: %s\n\n", actuel->contenu);
            actuel = actuel->suivant;
        }
    }
}