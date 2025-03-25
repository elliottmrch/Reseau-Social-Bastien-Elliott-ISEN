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

void supprimerAmi(User *user, int idAmi)
{
    for (int i = 0; i < 50; i++)
    {
        if (user->idAmis[i] == idAmi)
        {
            user->idAmis[i] = -1;
            break;
        }
    }
}

void ajouterPublication(User *user, Publication *publication)
{
    if (user->publications == NULL)
    {
        user->publications = malloc(sizeof(ListePublications));
        user->publications->premier = publication;
    }
    else
    {
        Publication *actuel = user->publications->premier;
        while (actuel->suivant != NULL)
            actuel = actuel->suivant;
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

User *userSelonId2(User *users[], int taille, int id)
{
    for (int i = 0; i < taille; i++)
    {
        if (users[i]->id == id)
        {
            return users[i];
        }
    }
    return NULL;
}

int idSelonUser(User *users[], int taille, char pseudo[])
{
    for (int i = 0; i < taille; i++)
    {
        if (strcmp(users[i]->pseudo, pseudo) == 0)
        {
            return users[i]->id;
        }
    }
    return -1;
}

//--------------------------------------------------------------

void afficherAmis(User *user, User *usersLst[], int taille)
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

void afficherUtilisateurs(User *users[], int taille, int choix)
{
    switch (choix)
    {
    case 1:
        for (int i = 0; i < taille; i++)
        {
            printf("ID: %d  ", users[i]->id);
            printf("Pseudo: %s  ", users[i]->pseudo);
            afficherAmis(users[i], users, taille);
            printf("\n\n");
        }
        break;

    case 2:
    {
        char pseudo[50];
        printf("Pseudo: ");
        fgets(pseudo, 50, stdin);
        pseudo[strlen(pseudo) - 1] = '\0';
        int id = idSelonUser(users, taille, pseudo);
        printf("ID: %d  ", users[id]->id);
        printf("Pseudo: %s  ", users[id]->pseudo);
        afficherAmis(users[id], users, taille);
        break;
    }

    default:
        printf("Choix indisponible\n\n");
        break;
    }
}

void afficherPublications(User *users[], int taille, int choix)
{
    switch (choix)
    {
    case 1:
        for (int i = 0; i < taille; i++)
        {
            printf("Pseudo: %s\n", users[i]->pseudo);
            Publication *actuel = users[i]->publications->premier;
            while (actuel != NULL)
            {
                printf("Titre: %s\n", actuel->titre);
                printf("Contenu: %s\n\n", actuel->contenu);
                actuel = actuel->suivant;
            }
        }
        break;

    case 2:
    {
        char pseudo[50];
        printf("Pseudo: ");
        fgets(pseudo, 50, stdin);
        pseudo[strlen(pseudo) - 1] = '\0';
        int id = idSelonUser(users, taille, pseudo);
        Publication *actuel = users[id]->publications->premier;
        while (actuel != NULL)
        {
            printf("Titre: %s\n", actuel->titre);
            printf("Contenu: %s\n\n", actuel->contenu);
            actuel = actuel->suivant;
        }
        break;
    }

    default:
        printf("Choix indisponible\n\n");
        break;
    }
}