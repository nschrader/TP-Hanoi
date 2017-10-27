#include "pile_type.h"
#include <stdlib.h>


PILE InitPile()
{
    PILE *pile;

    pile = (PILE *)malloc(sizeof(PILE));
    pile->elem = 0;
    pile->suivant = NULL;
    return(pile);
}

PILE Empiler(PILE *pile, int a)
{
    if(pile == NULL)
    {
        pile = initPile();
        pile-> elem = a;
        return(pile);
    }
    else
    {
        PILE *newpile = InitPile();
        newpile->elem = a;
        newpile->suivant = pile;
        return(newpile);
    }
}

PILE* Depiler(PILE *pile, int val)
{
    PILE *tmp = pile;

    if(pile == NULL)
    {
        fprintf(stderr,"You kiddin' me ?");
        return NULL;
    }
    else
    {
        while(pile = pile->suivant != NULL)
        {
            if(pile->element == val)
            {
                tmp->suivant = pile->suivant;
                free(pile);
                break;
            }
            tmp = pile;
        }
        return tmp;
    }
}





    

