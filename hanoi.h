/**
 * @file
 * Resolution du problème de Hanoi
 */

#ifndef hanoi_h_
#define hanoi_h_

#include "stack.h"

/**
 * Resoud le problème de Hanoi de taille N de la pile src vers la pile dst en
 * utilisant la pile de passage aux.
 * @param n
 * Taille N
 * @param src
 * Un pointeur vers la pile de départ
 * @param dst
 * Un pointeur vers la pile d'arrivée
 * @param aux
 * Un pointeur vers la pile de passage
 * @pre
 * Les piles pointées par aux et dst sont telles qu'elle peuvent empiler les
 * N premiers éléments de la pile pointée par src.
 * @post
 * Une tour de Hanoi de taille N a été déplacée de la pile pointée par src vers
 * la pile pointée par dst uniquement en utilisant des déplacements valides.
 * Si La tour de départ contient moins de N éléments ou si le déplacement est
 * impossible, une erreur doit interompre le programme
 */
void hanoi(int n, Stack** src, Stack** aux, Stack** dst);

/**
 * Affiche les trois piles en horizontale
 * @param n
 * Le nombre des plateaux
 * @param left
 * La pile à gauche
 * @param middle
 * La pile au milieu
 * @param right
 * La pile à droite
 */
void printStacks(int n, Stack* left, Stack* middle, Stack* right);

#endif
