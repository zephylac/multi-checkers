#ifndef H_GL_PLATEAU
#define H_GL_PLATEAU

void ChangeJoueur(int l, int c,t_joueur nouv)
int litJoueur(int l,int c)
void DeplaAjout(int l, int c,t_liste* ls_coup)  
int dispoPion(t_coordonnees coor,t_liste *ls_coup_d)  
int dispoDame(t_coordonnees coor,t_liste *ls_coup_d)  
void init()  
void afficher()
int coupForce(t_joueur j,t_liste* ls_coup_f)  
int coupDispo(t_coordonnees coor,t_joueur j,t_liste* ls_coup_d)  
void deplacerPiece(t_coordonnees dep,t_coordonnees arriv)
void prendrePiece(t_coor dep,t_coor arriv)  
void creerDame(t_coordonnees coor)  
void switchCoord(t_contenu plateau[Z][Z], int x, int y)
void tourner(t_contenu plateau[Z][Z])
  
#endif
