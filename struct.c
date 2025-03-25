#define EXERCICE
#ifdef EXERCICE

typedef struct
{
    int identifiant;
    char pseudo[50];
    int nbr_amis;
    int amis[50];
    char posts[50][50];
    int nbr_posts;
} Utilisateur;

void afficher_utilisateur(Utilisateur *u, int nbr_ui);
void ajouterAmi(Utilisateur *u, int nbr_ui, int id, int id_ami);
void afficher_amis(Utilisateur * u, int nbr_ui, int id);
void afficherPosts(Utilisateur * u, int nbr_ui, int id);
void ajouterPost(Utilisateur * u, int nbr_ui, int id, char * post);
void ajouterAmi(Utilisateur * u, int nbr_ui, int id, int id_ami);


#endif