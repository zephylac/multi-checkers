#ifndef H_GL_JEU
#define H_GL_JEU
#include "struct.h"

int hors_plateau(int i, int j);
int verifierDefaite();
void ajoutListe(t_coordonnees coord, t_joueur joueur, t_piece piece, t_liste* liste);
int peutPrendrePion(t_coordonnees coord_dep, t_joueur joueur,t_liste* ls_coup_arr, t_liste* ls_coup_dep, int eq);
int peutPrendreDame(t_coordonnees coord_dep, t_joueur joueur,t_liste* ls_coup_arr, t_liste* ls_coup_dep, int eq);
int peutPrendre(t_coordonnees coord, t_joueur joueur,t_liste* ls_coup_arr, t_liste* ls_coup_dep, int eq);
int depPossible(t_joueur joueur);
int partieFinie(int joueur);
void afficherStats();
void finPartie(int joueur);
void reinitStatsJoueur(t_joueur joueur);
void reinitStats();
void statPionpris(t_joueur joueur);
void statPionperdu(t_joueur joueur);
void statDep(t_joueur joueur);

#endif
