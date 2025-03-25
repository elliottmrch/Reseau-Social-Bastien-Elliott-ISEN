#include "social.h"

int main()
{
    int choix = 0;
    int nbrUsers = 0;
    User *listeUsers[50];

    printf("--- ISEN MEDIA ---\n\n");

    do
    {
        printf("1. Creer un utilisateur\n");
        printf("2. Ajouter un ami\n");
        printf("3. Supprimer un ami\n");
        printf("4. Creer une publication\n");
        printf("5. Afficher utilisateurs\n");
        printf("6. Afficher publications\n");
        printf("7. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);
        getchar();
        printf("\n");

        switch (choix)
        {
        case 1:
        {
            int id;
            printf("ID: ");
            scanf("%d", &id);
            getchar();

            char pseudo[50];
            printf("Pseudo: ");
            fgets(pseudo, 50, stdin);
            pseudo[strlen(pseudo) - 1] = '\0';

            User *nv = creerUser(id, pseudo);
            listeUsers[nbrUsers] = nv;
            nbrUsers++;
            break;
        }

        case 2:
        {
            char pseudo1[50];
            printf("Votre pseudo: ");
            fgets(pseudo1, 50, stdin);
            pseudo1[strlen(pseudo1) - 1] = '\0';

            char pseudo2[50];
            printf("Pseudo de votre ami: ");
            fgets(pseudo2, 50, stdin);
            pseudo2[strlen(pseudo2) - 1] = '\0';

            int id = idSelonUser(listeUsers, nbrUsers, pseudo1);
            int idAmi = idSelonUser(listeUsers, nbrUsers, pseudo2);
            ajouterAmi(listeUsers[id], idAmi);
            break;
        }

        case 3:
        {
            char pseudo1[50];
            printf("Votre pseudo: ");
            fgets(pseudo1, 50, stdin);
            pseudo1[strlen(pseudo1) - 1] = '\0';

            char pseudo2[50];
            printf("Pseudo de votre ami: ");
            fgets(pseudo2, 50, stdin);
            pseudo2[strlen(pseudo2) - 1] = '\0';

            int id = idSelonUser(listeUsers, nbrUsers, pseudo1);
            int idAmi = idSelonUser(listeUsers, nbrUsers, pseudo2);
            supprimerAmi(listeUsers[id], idAmi);
            break;
        }

        case 4:
        {
            char pseudo[50];
            printf("Votre pseudo: ");
            fgets(pseudo, 50, stdin);
            pseudo[strlen(pseudo) - 1] = '\0';

            char titre[50];
            printf("Titre: ");
            fgets(titre, 50, stdin);
            titre[strlen(titre) - 1] = '\0';

            char contenu[500];
            printf("Contenu: ");
            fgets(contenu, 500, stdin);
            contenu[strlen(contenu) - 1] = '\0';

            int id = idSelonUser(listeUsers, nbrUsers, pseudo);
            Publication *nv = creerPublication(titre, contenu);
            ajouterPublication(listeUsers[id], nv);
            break;
        }

        case 5:
        {
            int choixV1 = 0;
            printf("Afficher 1. All  2. Pseudo : ");
            scanf("%d", &choixV1);
            getchar();
            afficherUtilisateurs(listeUsers, nbrUsers, choixV1);
            break;
        }

        case 6:
        {
            int choixV2 = 0;
            printf("Afficher 1. All  2. Pseudo : ");
            scanf("%d", &choixV2);
            getchar();
            afficherPublications(listeUsers, nbrUsers, choixV2);
            break;
        }

        case 7:
        {
            printf("Fermeture de ISEN MEDIA\n");
            break;
        }

        default:
        {
            printf("Choix indisponible\n\n");
            break;
        }
    }

} while (choix != 7);
    
    return 0;
}