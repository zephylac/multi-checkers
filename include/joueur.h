#ifndef H_GL_JOUEUR
#define H_GL_JOUEUR
#include "struct.h"

int caracValeur(char carac);
t_coordonnees traiteEntree(char c_colonne, int ligne);
char afficherLettre(int lettre);
t_coordonnees choisir(t_liste * ls_coup, t_joueur joueur);
t_choix choisirPrendre(t_liste * ls_coup_dep, t_liste * ls_coup_arr, t_joueur joueur, int mode);
void jouerTour(t_joueur joueur);
void deroulementPartie(char nom[30]);
#endif
