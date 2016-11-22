#include <stdio.h>
#include <stdlib.h>
#include "include/plateau.h"
#include "include/jeu.h"
#include "include/joueur.h"
#define Z 17

typedef enum {vide, joueur1, joueur2, joueur3, joueur4, invalide}t_joueur;
typedef enum {sans, pion, dame}t_piece;
typedef enum {aucune, equipe1, equipe2}t_equipe;
typedef enum {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q}t_lettre;

typedef struct {int x; int y}t_coordonnees;
typedef struct {t_joueur joueur; t_piece piece; t_equipe equipe} t_contenu;
typedef struct {t_coordonnees coordonnees; t_contenu contenu} t_case;
typedef struct {char nom[20]; int pions_pris; int pions_perdus; int nb_coup} t_stats;
t_contenu plateau[Z][Z] ;

void main(){

	deroulementPartie();
