#include <stdio.h> 
#include <stdlib.h>
#define N 17

typedef enum {vide,joueur1,joueur2,joueur3,joueur4,invalide}t_joueur;
typedef enum {vide,pion,dame}t_piece;
typedef enum {equipe1=1,equipe2}t_equipe;
typedef struct {t_joueur joueur;t_piece piece;t_equipe equipe}t_case;
typedef struct {char nom[20]; int pions_pris; int prions_perdus;int nb_coups}t_stats;

t_case plateau[N][N];

void init(t_case plateau[N][N])
  void afficher(t_case plateau[N][N]) 
  int jouerTour() 
  void deplacerPion()
  void deplacerDame() 
  void prendrePiece() 
  void creerDame() 
  void finPartie()
  int partieFini() 
 int peutPrendre()
