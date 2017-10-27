/**
 * @file
 * Resolution du problème de Hanoi
 */

#ifndef hanoi_h_
#define hanoi_h_

#include "pile.h"

/**
 * Resoud le problème de Hanoi de taille N de la pile src vers la pile dst en
<<<<<<< HEAD
 * utilisant la pile de passage aux.
=======
 * utilisant la pile de passage *help.
>>>>>>> d5d11d2ccf2d1fd22908e936c0cf78ce951a8453
 * @param src
 * Un pointeur vers la pile de départ
 * @param dst
 * Un pointeur vers la pile d'arrivée
<<<<<<< HEAD
 * @param aux
=======
 * @param help
>>>>>>> d5d11d2ccf2d1fd22908e936c0cf78ce951a8453
 * Un pointeur vers la pile de passage
 * @param n
 * Taille N
 * @pre
<<<<<<< HEAD
 * Les piles pointées par aux et dst sont telles qu'elle peuvent empiler les
=======
 * Les piles pointées par help et dst sont telles qu'elle peuvent empiler les
>>>>>>> d5d11d2ccf2d1fd22908e936c0cf78ce951a8453
 * N premiers éléments de la pile pointée par src.
 * @post
 * Une tour de Hanoi de taille N a été déplacée de la pile pointée par src vers
 * la pile pointée par dst uniquement en utilisant des déplacements valides.
 * Si La tour de départ contient moins de N éléments ou si le déplacement est
 * impossible, une erreur doit interompre le programme
 */
<<<<<<< HEAD
void hanoi(Stack *src, Stack* aux, Stack *dst, int n);
=======
void hanoi(Stack *src, Stack* help, Stack *dst, int n);
>>>>>>> d5d11d2ccf2d1fd22908e936c0cf78ce951a8453

#endif
