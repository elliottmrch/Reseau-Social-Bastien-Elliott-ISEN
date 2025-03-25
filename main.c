#include "social.h"

int main()
{
    int choix = 0;
    int nbrUsers = 0;
    User *listeUsers[100];

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




    } while (choix != 7);
    

    return 0;
}