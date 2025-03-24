#include "social.h"

User *creerUser(int id, char pseudo[], UserId *userId)
{
    User *nv = malloc(sizeof(User));
    if (nv == NULL)
        return;
    nv->id = id;
    strcpy(nv->pseudo, pseudo);
    nv->amis = NULL;
    nv->publications = NULL;

    userId = malloc(sizeof(UserId));
    if (userId == NULL)
        return;
    userId->id = id;
    userId->suivant = NULL;

    return nv;
}