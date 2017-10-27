/**
 * @file
 * Une espèce de pile objet-orientée
 */

#ifndef PILE_H
#define PILE_H

/**
 * Une pile d'entier
 */
typedef struct stack {
  int i;
  struct stack* next;
} Stack;

/**
 * Initialise une pile
 */
Stack* newStack();

/**
 * Ajoute l'élément elem au sommet de la pile pointée par ppile
 * @param stack
 * Un pointeur vers la pile
 * @param i
 * L'élément à rajouter au sommet de pile
 * @result
 * La nouvelle pile si aucune erreur n'est intervenue, NULL sinon
 */
Stack* push(Stack* stack, int i);


/**
 * Retire l'element du sommet de la pile pointée par et copie sa valeur dans i.
 * @param stack
 * Un pointeur vers la pile
 * @result
 * La nouvelle pile si aucune erreur n'est intervenue, NULL sinon
 */
Stack* pop(Stack* stack, int* i);

/**
 * Déplace le sommet de pile d'une pile source (*psource) vers une pile destination (*pdest)
 * @param src
 * Un pointeur vers la pile source
 * @param dst
 * Un pointeur vers la pile destination
 * @pre
 * Les deux piles pointées par src et dst sont des piles de Hanoi valides
 * (chaque élément est plus petit que le suivant dans la pile).
 * La pile pointée par src est non-vide.
 * @post
 * Si le sommet de la pile pointée par src est de plus petite taille que le
 * sommet de la pile pointée par dst les deux piles sont modifiées:
 * Le sommet de pile src est enlevé et rajouté à dest, sinon la fonction
 * affiche une erreur et interrompt le programme.
 */
void move(Stack** src, Stack** dst);

/**
 * Affiche une pile d'entier
 * @param stack
 * Une pile à afficher
 */
void printStack(Stack* stack);

#endif
