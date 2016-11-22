#ifndef H_GL_liste
#define H_GL_liste
void init_liste(t_liste * liste);
int liste_vide(t_liste * liste);
int hors_liste(t_liste * liste);
void en_tete(t_liste * liste);
void en_queue(t_liste * liste);
void precedent(t_liste * liste);
void suivant(t_liste * liste);
void valeur_elt(t_liste * liste, t_case * v);
void modif_elt(t_liste * liste, t_case v);
void oter_elt(t_liste * liste);
void ajout_droit(t_liste * liste, t_case v);
void ajout_gauche(t_liste * liste, t_case v);
void vider_liste(t_liste * liste);
#endif
