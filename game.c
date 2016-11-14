#include <stdio.h>
#include <stdlib.h>
#define N 17


typedef enum {vide, joueur1, joueur2, joueur3, joueur4, invalide}t_joueur;
typedef enum {vide, pion, dame}t_piece;
typedef enum {equipe1 = 1, equipe2}t_equipe;
typedef struct {t_joueur joueur; t_piece piece; t_equipe equipe} t_case;
typedef struct {char nom[20]; int pions_pris; int pions_perdus; int nb_coup} t_stats;

t_case plateau[N][N] ;

void initplateau(){
/* Initialise le plateau */
	int i, j;
	/* i = lignes, j = colonnes */
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			if((i<4&&j<4)||(i>12&&j<4)||(i<4&&j>12)||(i>12&&j>12)){
			/* si la case est comprise dans un des coins, elle est invalide */
				plateau[i][j].joueur = invalide;
				plateau[i][j].piece = vide;
				plateau[i][j].equipe = 0;				
			}
			else{
				
			}
		}
		
	}
}

void init(){
/* Initialise la partie */
	initplateau();
	

}
