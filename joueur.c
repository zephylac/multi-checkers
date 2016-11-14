#include <stdio.h>
#include <stdlib.h>
#define N 17

typedef enum {vide, joueur1, joueur2, joueur3, joueur4, invalide}t_joueur;
typedef enum {vide, pion, dame}t_piece;
typedef enum {equipe1 = 1, equipe2}t_equipe;

typedef struct {t_joueur joueur; t_piece piece; t_equipe equipe} t_case;
typedef struct {char nom[20]; int pions_pris; int pions_perdus; int nb_coup} t_stats;
t_case plateau[N][N] ;


/**
*\fn void jouerTour(t_joueur joueur)
*\brief Fonction qui exécute le tour d'un joueur entré en paramètre
*/
void jouerTour(t_joueur joueur){
  if(!coupForce){
    printf("Veuillez choisir la case où se trouve votre pion
  }
  else{
    //force un joueur à effectuer un coup
  }
}
