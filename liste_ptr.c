#include <stdlib.h>

typedef enum {vide, joueur1, joueur2, joueur3, joueur4, invalide}t_joueur;      
typedef enum {vide, pion, dame}t_piece;                                         
typedef enum {equipe1 = 1, equipe2}t_equipe;                                    
typedef enum {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q}t_lettre;                       
                                                                                 
typedef struct {int x; int y;}t_coordonnees;                                     
typedef struct {t_joueur joueur; t_piece piece; t_equipe equipe;} t_contenu;     
typedef struct {t_coordonnees coordonnees; t_contenu contenu;} t_case;           
typedef struct {char nom[20]; int pions_pris; int pions_perdus; int nb_coup;} t_stats;

typedef struct element{t_case valeur; struct element * pred; struct element * succ;}t_element;
typedef struct {t_element * drapeau;t_element * ec;}t_liste;

void init_liste(t_liste * liste ){
	liste -> drapeau = malloc(sizeof(t_element));
	liste -> drapeau -> pred = liste -> drapeau;
	liste -> drapeau -> succ = liste -> drapeau;
	liste -> ec = liste -> drapeau;
}

int liste_vide(t_liste * liste){
	return(liste -> drapeau -> succ == liste -> drapeau);
}

int hors_liste(t_liste * liste){
	return(liste -> ec == liste -> drapeau);
}

void en_tete(t_liste * liste){
	if(!liste_vide(liste)){
		liste -> ec = liste -> drapeau -> succ;
	}
}
void en_queue(t_liste * liste){
	if(!liste_vide(liste)){
		liste -> ec = liste -> drapeau -> pred;
	}
}

void suivant(t_liste * liste){
	if(!hors_liste(liste)){
		liste -> ec = liste -> ec -> succ;
	}
}

void precedent(t_liste * liste){
	if(!hors_liste(liste)){
		liste -> ec = liste -> ec -> pred;
	}
}

void valeur_elt(t_liste * liste, t_case * v){
	if(!hors_liste(liste)){
		*v = liste -> ec -> valeur;
	}
}

void modif_elt(t_liste * liste, t_case v){
	if(!hors_liste(liste)){
		liste -> ec -> valeur = v;
	}
}

void oter_elt(t_liste * liste){
	if(!liste_vide(liste)){
		t_element * inter;
		inter = malloc(sizeof(t_element));
		inter = liste -> ec;
		inter -> succ -> pred = inter -> pred;
		inter -> pred -> succ = inter -> succ;
		liste -> ec = inter -> pred;
		free(inter);
	}
}

void ajout_droit(t_liste * liste, t_case v){
	if(liste_vide(liste) || !hors_liste(liste)){
		t_element * new;
		new = malloc(sizeof(t_element));
		new -> valeur = v;
		new -> succ = liste -> ec -> succ;
		new -> pred = liste -> ec;
		liste -> ec -> succ -> pred = new;
		liste -> ec -> succ = new;
		liste -> ec = new;
	}
}

void ajout_gauche(t_liste * liste, t_case v){
	if(liste_vide(liste) || !hors_liste(liste)){
		t_element * new;
		new = malloc(sizeof(t_element));
		new -> valeur = v;
		new -> pred = liste -> ec -> pred;
		new -> succ = liste -> ec;
		liste -> ec -> pred -> succ = new;
		liste -> ec -> pred = new;
		liste -> ec = new;
	}
}
