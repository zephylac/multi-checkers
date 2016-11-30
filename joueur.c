#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "include/struct.h"
#include "include/plateau.h"
#include "include/jeu.h"
#include "include/liste_ptr.h"

/*
 *\fn int carac_valeur(char carac)
 *\brief fonction qui convertir un caractère en chiffre
 */
int carac_valeur(char carac){
	if(carac >= 'a' && carac <= 'z') return carac - 'a';
	else if ( carac >= 'A' && carac <= 'Z') return carac - 'A';
}

/*
 *\fn t_coordonnees traiteEntree(char c_colonne, int ligne)
 *\brief fonction qui traite ce que l'utilisateur a entré
 */
t_coordonnees traiteEntree(char c_colonne, int ligne){
	int colonne;
	t_coordonnees coord;
	if(isdigit(c_colonne)){                                    
		coord.x = 0;
		coord.y = 0;
	}
	else{
		colonne = carac_valeur(c_colonne);
		coord.y = ligne;
		coord.x = colonne;
	}
	return coord;
}
/*
 *\fn void jouerTour(t_joueur joueur)
 *\brief Fonction qui exécute le tour d'un joueur entré en paramètre
 */
void afficherLettre (int lettre){
  switch(lettre){
    case 0 : printf("A");break;
    case 1 : printf("B");break;
    case 2 : printf("C");break;
    case 3 : printf("D");break;
    case 4 : printf("E");break;
    case 5 : printf("F");break;
    case 6 : printf("G");break;
    case 7 : printf("H");break;      
    case 8 : printf("I");break;
    case 9 : printf("J");break;      
    case 10 : printf("K");break;
    case 11 : printf("L");break;      
    case 12 : printf("M");break;
    case 13 : printf("N");break;      
    case 14 : printf("O");break;
    case 15 : printf("P");break;
    case 16 : printf("Q");break;
  }
}

/**
*\fn t_coordonnees choisir(t_liste * ls_coup)
*\brief Fonction qui affiche les choix possibles et demande à l'utilisateur de choisir un coup
*/
t_coordonnees choisir(t_liste* ls_coup,t_joueur joueur){
	int choix,i = 0;
	t_case cellule;
	t_coordonnees coord;
	
	do{
		printf("\n-----------Joueur %i-----------\n",joueur);
		en_tete(ls_coup);
		while(!hors_liste(ls_coup)){
			valeur_elt(ls_coup,&cellule);
			printf("%i) Déplacer le pion se trouvant aux coordonnées ",i);
			afficherLettre(cellule.coordonnees.x);
			printf(" %i\n",cellule.coordonnees.y);
			i++;
			suivant(ls_coup);
		}
		printf("Votre choix : ");
		scanf("%i",&choix);
	}
	while(choix < 0 || choix > i);
	en_tete(ls_coup);
	for(i = 0; i < choix; i++){
		suivant(ls_coup);
	}	
	valeur_elt(ls_coup,&cellule);
	coord.x = cellule.coordonnees.x;
	coord.y = cellule.coordonnees.y;
	return coord;
}


/**
*\fn void jouerTour(t_joueur joueur)
*\brief Fonction qui exécute le tour d'un joueur entré en paramètre
*/
void jouerTour(t_joueur joueur){
	//Déclaration dec s variables
	char c_colonne;
    	int coup_force;
	int ligne;
	int choix;
	t_case cellule;
  	t_coordonnees coord_dep;
	t_coordonnees coord_arr;
	//Cette fonction nous retourne des valeurs utiles pour le début de tour d'un joueur
        afficher();
	coup_force = coupForce(joueur,&ls_coup_d);

	/* Si le joueur n'a pas de coup obligatoire */
	if(coup_force == 0){
    		printf("Veuillez choisir la case où se trouve votre pion\n");
    		printf("Entrer les coordonnées (ex:A1) : ");
		scanf("%c%i",&c_colonne,&ligne); 
		coord_dep = traiteEntree(c_colonne,ligne);

		while(!coupDispo(coord_dep,joueur,&ls_coup_d)){
			printf("Veuillez choisir la case où se trouve votre pion\n");
    			printf("Entrer les coordonnées (ex:A1) : ");
			scanf("%c%i",&c_colonne,&ligne); 
			coord_dep = traiteEntree(c_colonne,ligne);
		}
		coord_arr = choisir(&ls_coup_d,joueur);
		deplacerPiece(coord_dep,coord_arr);
	}
	else{
		coord_dep = choisir(&ls_coup_d,joueur);
		vider_liste(&ls_coup_f);
		while(peutPrendre(coord_dep,joueur, &ls_coup_f)){
			afficher();
			coord_arr = choisir(&ls_coup_f,joueur);
			prendrePiece(coord_dep, coord_arr);
			coord_dep = coord_arr;
			vider_liste(&ls_coup_f);
		}
	}
}

/**
 * \fn void deroulementPartie(void)
 * brief Fonction qui s'occupe de la gestion des tours entre différents joueur
 */

void deroulementPartie(){
	//Déclaration des variables
	int i=1;
	while(!partieFinie(i)){
		jouerTour(i);
		tourner();
		i++;
		if(i == 5){
			i = 1;
		}
	}
	finPartie(partieFinie(i));
}
