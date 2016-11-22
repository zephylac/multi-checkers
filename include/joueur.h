#ifndef H_GL_joueur
#define H_GL_joueur
int convertir(char carac); 
t_coordonnees traiteEntree(char c_colonne, int ligne);
void afficherLettre (t_lettre lettre);
t_coordonnees choisir(t_liste * ls_coup, t_joueur joueur);
void jouerTour(t_joueur joueur);
void deroulementPartie(void);
#endif
