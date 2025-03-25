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
        printf("6. Afficher liste d'amis\n");
        printf("7. Afficher publications\n");
        printf("8. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);
        getchar();
        printf("\n");

        switch (choix)
        {
            case 1:
            {
                char pseudo[50];
                printf("Pseudo: ");
                fgets(pseudo, 50, stdin);
                pseudo[strlen(pseudo) - 1] = '\0';
                nbrUsers++;
                listeUsers[nbrUsers - 1] = creerUser(nbrUsers, pseudo);
                break;
            }

            case 2:
            {
                int idUser, idAmi;
                printf("ID de l'utilisateur: ");
                scanf("%d", &idUser);
                printf("ID de l'ami: ");
                scanf("%d", &idAmi);
                ajouterAmi(listeUsers[idUser - 1], listeUsers[idAmi - 1]);
                break;
            }

            case 3:
            {
                int idUser, idAmi;
                printf("ID de l'utilisateur: ");
                scanf("%d", &idUser);
                printf("ID de l'ami: ");
                scanf("%d", &idAmi);
                supprimerAmi(listeUsers[idUser - 1], listeUsers[idAmi - 1]);
                break;
            }

            case 4:
            {
                int idUser;
                char titre[50], contenu[500];
                printf("ID de l'utilisateur: ");
                scanf("%d", &idUser);
                getchar();
                printf("Titre: ");
                fgets(titre, 50, stdin);
                titre[strlen(titre) - 1] = '\0';
                printf("Contenu: ");
                fgets(contenu, 500, stdin);
                contenu[strlen(contenu) - 1] = '\0';
                ajouterPublication(listeUsers[idUser - 1], creerPublication(titre, contenu));
                break;
            }

            case 5:
            {
                afficherUtilisateurs(listeUsers, nbrUsers);
                break;
            }

            case 6:
            {
                int idUser;
                printf("ID de l'utilisateur: ");
                scanf("%d", &idUser);
                afficherListeAmis(listeUsers[idUser - 1], listeUsers, nbrUsers);
                break;
            }

            case 7:
            {
                int idUser;
                printf("ID de l'utilisateur: ");
                scanf("%d", &idUser);
                afficherPublications(listeUsers[idUser - 1]);
                break;
            }

            case 8:
            {
                printf("Fermeture de ISEN MEDIA !\n");
                break;
            }

            default:
            {
                printf("Choix invalide\n");
                break;
            }
        }


    } while (choix != 8);
    
    return 0;
}