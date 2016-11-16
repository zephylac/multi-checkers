#include <stdlib.h>
typedef struct element{int valeur; struct element * pred; struct element * succ;}t_element;
t_element * drapeau;
t_element * ec;
void init_liste(){
	drapeau = malloc(sizeof(t_element));
	drapeau -> pred = drapeau;
	drapeau -> succ = drapeau;
	ec = drapeau;
}

int liste_vide(){
	return(drapeau -> succ == drapeau);
}

int hors_liste(){
	return(ec == drapeau);
}

void en_tete(){
	if(!liste_vide()){
		ec = drapeau -> succ;
	}
}
void en_queue(){
	if(!liste_vide()){
		ec = drapeau -> pred;
	}
}

void suivant(){
	if(!hors_liste()){
		ec = ec -> succ;
	}
}

void precedent(){
	if(!hors_liste()){
		ec = ec -> pred;
	}
}

void valeur_elt(int * v){
	if(!hors_liste()){
		*v = ec -> valeur;
	}
}

void modif_elt(int v){
	if(!hors_liste()){
		ec -> valeur = v;
	}
}

void oter_elt(){
	if(!liste_vide()){
		t_element * inter;
		inter = malloc(sizeof(t_element));
		inter = ec;
		inter -> succ -> pred = inter -> pred;
		inter -> pred -> succ = inter -> succ;
		ec = inter -> pred;
		free(inter);
	}
}

void ajout_droit(int v){
	if(liste_vide() || !hors_liste()){
		t_element * new;
		new = malloc(sizeof(t_element));
		new -> valeur = v;
		new -> succ = ec -> succ;
		new -> pred = ec;
		ec -> succ -> pred = new;
		ec -> succ = new;
		ec = new;
	}
}

void ajout_gauche(int v){
	if(liste_vide() || !hors_liste()){
		t_element * new;
		new = malloc(sizeof(t_element));
		new -> valeur = v;
		new -> pred = ec -> pred;
		new -> succ = ec;
		ec -> pred -> succ = new;
		ec -> pred = new;
		ec = new;
	}
}
