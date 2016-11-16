#include <stdio.h>
#include <stdlib.h>
#define N 17


typedef enum {vide, joueur1, joueur2, joueur3, joueur4, invalide}t_joueur;
typedef enum {cvide, pion, dame}t_piece;
typedef enum {equipe1 = 1, equipe2}t_equipe;
typedef struct {t_joueur joueur; t_piece piece; t_equipe equipe} t_case;
typedef struct {char nom[20]; int pions_pris; int pions_perdus; int nb_coup} t_stats;

t_case plateau[N][N] ;

void initplateau(){
/* Initialise le plateau en plaçant les pions*/
	int i, j;
	/* i = lignes, j = colonnes */
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			if((i<4&&j<4)||(i>12&&j<4)||(i<4&&j>12)||(i>12&&j>12)){
			/* si la case est dans un des coins, elle est invalide */
				plateau[i][j].joueur = invalide;
				plateau[i][j].piece = vide;
				plateau[i][j].equipe = 0;
			}
			else{
				if((i<4)&&(j%2 == 1)&&(i%2 == 0)){
                   			plateau[i][j].joueur = joueur1;
                   			plateau[i][j].piece = pion;
                  			plateau[i][j].equipe = 1;
				}
				if((i<4)&&(j%2 == 0)&&(i%2 == 1)){
					plateau[i][j].joueur = joueur1;
					plateau[i][j].piece = pion;
					plateau[i][j].equipe = 1;
				}
				if((j<4)&&(j%2 == 1)&&(i%2 == 0)){
                   			plateau[i][j].joueur = joueur2;
                   			plateau[i][j].piece = pion;
                   			plateau[i][j].equipe = 2;
				}
				if((j<4)&&(j%2 == 0)&&(i%2 == 1)){
                   			plateau[i][j].joueur = joueur2;
                   			plateau[i][j].piece = pion;
                   			plateau[i][j].equipe = 2;
				}
				if((i>12)&&(j%2 == 1)&&(i%2 == 0)){
                   			plateau[i][j].joueur = joueur3;
                   			plateau[i][j].piece = pion;
                   			plateau[i][j].equipe = 1;
				}
				if((i>12)&&(j%2 == 0)&&(i%2 == 1)){
					plateau[i][j].joueur = joueur3;
					plateau[i][j].piece = pion;
					plateau[i][j].equipe = 1;
				}
				if((j>12)&&(j%2 == 1)&&(i%2 == 0)){
     	              			plateau[i][j].joueur = joueur4;
      	             			plateau[i][j].piece = pion;
       		            		plateau[i][j].equipe = 2;
				}
				if((j>12)&&(j%2 == 0)&&(i%2 == 1)){
                   			plateau[i][j].joueur = joueur4;
                   			plateau[i][j].piece = pion;
                   			plateau[i][j].equipe = 2;
				}
			}
		}

	}
}

void afficher(){
/* Affiche le plateau */
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(plateau[i][j].joueur == invalide) printf("   ");
            else if(plateau[i][j].joueur == joueur1) printf("[1]");
            else if(plateau[i][j].joueur == joueur2) printf("[2]");
            else if(plateau[i][j].joueur == joueur3) printf("[3]");
            else if(plateau[i][j].joueur == joueur4) printf("[4]");
            else printf("[ ]");
        }
        printf("\n");
    }

}

void init(){
/* Initialise la partie */
	initplateau();


}
