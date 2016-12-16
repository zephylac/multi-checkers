#include <stdlib.h>
#include "include/struct.h"

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
	
	if(!liste_vide(liste)) {
		t_element * temp;
		(liste -> ec -> succ) -> pred = liste -> ec -> pred;
		(liste -> ec -> pred) ->succ = liste -> ec -> succ;
		temp = liste -> ec;
		liste -> ec = liste -> ec-> pred;
		free(temp);
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

void vider_liste(t_liste * liste){
	en_queue(liste);
	while(!liste_vide(liste)){
		oter_elt(liste);
	}
}

