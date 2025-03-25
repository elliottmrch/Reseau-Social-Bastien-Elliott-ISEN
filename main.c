#include <stdio.h>
#include "struct.c"

void afficher_utilisateur(Utilisateur *u, int nbr_ui)
{
    for (int i = 0; i < nbr_ui; i++)
    {
        printf("Utilisateur %d\n", i + 1);
        printf("Identifiant : %d\n", u[i].identifiant);
        printf("Pseudo : %s\n", u[i].pseudo);
    }
}

void ajouterAmi(Utilisateur *u, int nbr_ui, int id, int id_ami)
{
    for (int i = 0; i < nbr_ui; i++)
    {
        if (u[i].identifiant == id)
        {
            u[i].amis[u[i].nbr_amis] = id_ami;
            u[i].nbr_amis++;
        }
    }
}

void afficherListeAmis(Utilisateur *u, int nbr_ui, int id)
{
    for (int i = 0; i < nbr_ui; i++)
    {
        if (u[i].identifiant == id)
        {
            printf("Liste d'amis de %s\n", u[i].pseudo);
            for (int j = 0; j < u[i].nbr_amis; j++)
            {
                printf("%s\n", u[u[i].amis[j]].pseudo);
            }
        }
    }
}

void afficherPosts(Utilisateur *u, int nbr_ui, int id)
{
    for (int i = 0; i < nbr_ui; i++)
    {
        if (u[i].identifiant == id)
        {
            printf("Posts de %s\n", u[i].pseudo);
            for (int j = 0; j < u[i].nbr_posts; j++)
            {
                printf("%s\n", u[i].posts[j]);
            }
        }
    }
}

void ajouterPost(Utilisateur *u, int nbr_ui, int id, char *post)
{
    for (int i = 0; i < nbr_ui; i++)
    {
        if (u[i].identifiant == id)
        {
            strcpy(u[i].posts[u[i].nbr_posts], post);
            u[i].nbr_posts++;
        }
    }
}

int main()
{
    Utilisateur utilisateurs[100];
    int nbr_utilisateurs = 0;
    int choix;

    printf("\n=== Menu Réseau Social ===\n");
    printf("1. Afficher les utilisateurs\n");
    printf("2. Ajouter un ami\n");
    printf("3. Afficher la liste d'amis\n");
    printf("4. Ajouter un post\n");
    printf("5. Afficher les posts\n");
    printf("0. Quitter\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    while (choix != 0)
    {

        switch (choix)
        {
        case 1:
        {
            afficher_utilisateur(utilisateurs, nbr_utilisateurs);
            break;
        }
        case 2:
        {
            int id, id_ami;
            printf("Entrez l'identifiant de l'utilisateur : ");
            scanf("%d", &id);
            printf("Entrez l'identifiant de l'ami à ajouter : ");
            scanf("%d", &id_ami);
            ajouterAmi(utilisateurs, nbr_utilisateurs, id, id_ami);
            break;
        }
        case 3:
        {
            int id;
            printf("Entrez l'identifiant de l'utilisateur : ");
            scanf("%d", &id);
            afficherListeAmis(utilisateurs, nbr_utilisateurs, id);
            break;
        }
        case 4:
        {
            int id;
            char post[256];
            printf("Entrez l'identifiant de l'utilisateur : ");
            scanf("%d", &id);
            printf("Entrez le contenu du post : ");
            fgets(post, sizeof(post), stdin);
            getchar();
            ajouterPost(utilisateurs, nbr_utilisateurs, id, post);
            break;
        }
        case 5:
        {
            int id;
            printf("Entrez l'identifiant de l'utilisateur : ");
            scanf("%d", &id);
            afficherPosts(utilisateurs, nbr_utilisateurs, id);
            break;
        }
        case 0:
        {
            printf("Au revoir !\n");
            break;
        }
        default:
        {
            printf("Choix invalide. Veuillez réessayer.\n");
            break;
        }
        }
    }
}
