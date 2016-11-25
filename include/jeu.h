#ifndef H_GL_JEU
#define H_GL_JEU
#include "struct.h"

int hors_plateau(int i, int j);
int verifierdefaite();
void ajoutliste(t_coordonnees coord, t_joueur joueur, t_piece piece, t_liste* liste);
int peutPrendrepion(t_coordonnees coord, t_joueur joueur,t_liste* ls_coup_d);
int peutPrendredame(t_coordonnees coord, t_joueur joueur,t_liste* ls_coup_d);
int peutPrendre(t_coordonnees coord, t_joueur joueur,t_liste* ls_coup_d);
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
