#include "social.h"

User *creerUser(int id, char pseudo[])
{
    User *nv = malloc(sizeof(User));
    if (nv == NULL)
        return;
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
        return;
    strcpy(nv->titre, titre);
    strcpy(nv->contenu, contenu);
    nv->suivant = NULL;

    return nv;
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

void ajouterAmi(User *user, int idAmi)
{
    for (int i = 0; i < 50; i++)
    {
        if (user->idAmis[i] == -1)
        {
            user->idAmis[i] = idAmi;
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

void afficherUserSelonId(User *users[], int taille, int id)
{
    for (int i = 0; i < taille; i++)
    {
        if (users[i]->id == id)
        {
            printf("Pseudo: %s  ", users[i]->pseudo);
        }
    }
}

void afficherAmis(User *users[], int taille)
{
    for (int i = 0; i < taille; i++)
    {
        printf("Amis: ");
        for (int j = 0; j < 50; j++)
        {
            if (users[i]->idAmis[j] != -1)
                afficherUserSelonId(users, taille, users[i]->idAmis[j]);
        }
        printf("\n\n");
    }
}

void afficherUtilisateurs(User *users[], int taille, int choix)
{
    switch (choix)
    {
    case 1:
    {
        
        afficherAmis(users, taille);
        break;
    }

    case 2:
    {
        int id;
        printf("ID: ");
        scanf("%d", &id);
        getchar();

        for (int i = 0; i < taille; i++)
        {
            if (users[i]->id == id)
            {
                printf("ID: %d  ", users[i]->id);
                printf("Pseudo: %s  ", users[i]->pseudo);
                printf("Amis: ");
                for (int j = 0; j < 50; j++)
                {
                    if (users[i]->idAmis[j] != -1)
                        printf("%d ", users[i]->idAmis[j]);
                }
                printf("\n\n");
            }
        }
    }

    default:
        break;
    }
}
