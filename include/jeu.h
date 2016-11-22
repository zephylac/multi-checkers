#ifndef H_GL_JEU
#define H_GL_JEU

int verifierdefaite();
int peutPrendrepion(t_coordonnees coord, t_joueur joueur,t_liste* ls_coup_d);
int peutPrendredame(t_coordonnees coord, t_joueur joueur,t_liste* ls_coup_d);
int PeutPrendre(t_coordonnees coord, t_joueur joueur,t_liste* ls_coup_d);
int deppossible(t_joueur joueur);
int partieFinie(int joueur);
void afficherstats();
void reinitstatsjoueur(t_joueur joueur);
void reinitstats();
void statpionpris(t_joueur joueur);
void statpionperdu(t_joueur joueur);
void statdep(t_joueur joueur);

#endif
