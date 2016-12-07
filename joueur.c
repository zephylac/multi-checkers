/**
 * \author Thibault Brocherieux
 * \date 06/12/2016
 * \file joueur.c
 * \brief Programme contenant les fonctions liées au joueur
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include "include/struct.h"
#include "include/plateau.h"
#include "include/jeu.h"
#include "include/liste_ptr.h"
#include "include/affichage.h"


/**
 * \fn int carac_valeur(char carac)
 * \brief fonction qui permet de convertir un caractère en chiffre, qu'il soit majuscule ou minuscule
 * \param[in] carac charactère
 * \return Retourne un int qui a pour valeur la lettre entrée
 */
int carac_valeur(char carac){
	if(carac >= 'a' && carac <= 'z') return carac - 'a';
	else if ( carac >= 'A' && carac <= 'Z') return carac - 'A';
}


/**
 * \fn t_coordonnees traiteEntree(char c_colonne, int ligne)
 * \brief Fonction qui traite l'entrée.
 * \param[in] c_colonne Charactère indiquant la colonnne
 * \param[in] ligne Nombre indiquant la ligne
 * \return coord De type t_coordonnees contenant les valeurs d'entrées 
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


/**
 * \fn char afficherLettre(int lettre)
 * \brief fonction qui permet de convertir un chiffre en lettre, utile pour l'affichage
 * \param[in] lettre Nombre compris entre 0 et 16
 * \return C de type charn, la lettre associé au nombre entré
 */
char afficherLettre (int lettre){
  char c; 	
  switch(lettre){
    case 0 : c = 'A';break;
    case 1 : c = 'B';break;
    case 2 : c = 'C';break;
    case 3 : c = 'D';break;
    case 4 : c = 'E';break;
    case 5 : c = 'F';break;
    case 6 : c = 'G';break;
    case 7 : c = 'H';break;      
    case 8 : c = 'I';break;
    case 9 : c = 'J';break;      
    case 10 : c = 'K';break;
    case 11 : c = 'L';break;      
    case 12 : c = 'M';break;
    case 13 : c = 'N';break;      
    case 14 : c = 'O';break;
    case 15 : c = 'P';break;
    case 16 : c = 'Q';break;
  }
  return c;
}


/**
* \fn t_coordonnees choisirDep(t_liste * ls_coup, t_joueur joueur)
* \brief Fonction qui affiche les choix possibles de déplacement d'un pion. Cette fonction n'est appelé seulement lorsqu'il n'y a pas de coup forcé
* \param[in] ls_coup Liste contenant les déplacements possibles
* \param[in] joueur Le numéro du joueur qui joue
* \return coord de type t_cooordonnees, qui contient les coordonnées du pion choisit
*/
t_coordonnees choisirDep(t_liste* ls_coup,t_joueur joueur){
	int choix,i = 0;
	t_case cellule;
	t_coordonnees coord;
	char c1;
	do{
		printf("\n-----------Joueur %i-----------\n",joueur);
		en_tete(ls_coup);
		while(!hors_liste(ls_coup)){
			valeur_elt(ls_coup,&cellule);
			c1 = afficherLettre(cellule.coordonnees.x);
			printf("%i) Déplacer le pion se trouvant aux coordonnées %c%i\n",i,c1,cellule.coordonnees.y);
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
* \fn t_coordonnees choisirPrendre(t_liste * ls_coup_dep, t_liste * ls_coup_arr, t_joueur joueur)
* \brief Fonction qui affiche les choix possibles lorsque le coup est forcé.
* \param[in] ls_coup_dep Liste qui contient les coordonnées de départs des pions qui peuvent prendre un pion
* \param[in] ls_coup_arr Liste qui contient les coordonnées d'arrivées des pions qui peuvent prendre un pion
* \param[in] joueur Le numéro du joueur qui joue
* \return coup de type choix qui contient les coordonnées de départ et d'arrivée
*/
t_choix choisirPrendre(t_liste* ls_coup_dep, t_liste* ls_coup_arr,t_joueur joueur){
	int choix,i = 0;
	t_case dep;
	t_case arr;
	t_choix coup;
	char c1,c2;
	do{
		printf("\n-----------Joueur %i-----------\n",joueur);
		en_tete(ls_coup_dep);
		en_tete(ls_coup_arr);
		i = 0;
		while(!hors_liste(ls_coup_dep)){
			valeur_elt(ls_coup_dep,&dep);
			valeur_elt(ls_coup_arr,&arr);
			c1 = afficherLettre(dep.coordonnees.x);
			c2 = afficherLettre(arr.coordonnees.x);
			printf("%i) Déplacer la pièce %c%i aux coordonnées %c%i\n",i,c1,dep.coordonnees.y,c2,arr.coordonnees.y);
			i++;
			suivant(ls_coup_dep);
			suivant(ls_coup_arr);
		}
		printf("Votre choix : ");
		scanf("%i",&choix);
	}
	while(choix < 0 || choix >= i);
	en_tete(ls_coup_dep);
	en_tete(ls_coup_arr);
	for(i = 0; i < choix; i++){
		suivant(ls_coup_arr);
		suivant(ls_coup_dep);
	}	
	valeur_elt(ls_coup_dep,&dep);
	valeur_elt(ls_coup_arr,&arr);
	coup.dep.x = dep.coordonnees.x;
	coup.dep.y = dep.coordonnees.y;
	coup.arr.x = arr.coordonnees.x;
	coup.arr.y = arr.coordonnees.y;

	return coup;
}


/**
* \fn void jouerTour(t_joueur joueur)
* \brief Fonction qui exécute le tour d'un joueur entré en paramètre
* \param[in] joueur qui le numéro du joueur à qui c'est le tour
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
	t_choix coup;
	//Cette fonction nous retourne des valeurs utiles pour le début de tour d'un joueur
        afficher();
	coup_force = coupForce(joueur,&ls_coup_arr, &ls_coup_dep);

	/* Si le joueur n'a pas de coup obligatoire */
	if(coup_force == 0){
    		do{
			printf("Veuillez choisir la case où se trouve votre pion\n");
    			printf("Entrer les coordonnées (ex:A1) : ");
			scanf("%c%i",&c_colonne,&ligne); 
			coord_dep = traiteEntree(c_colonne,ligne);
		}
		while(!coupDispo(coord_dep,joueur,&ls_coup_dep));
			
		coord_arr = choisirDep(&ls_coup_dep,joueur);
		deplacerPiece(coord_dep,coord_arr);
	}
	else{
		do{
			coup = choisirPrendre(&ls_coup_dep, &ls_coup_arr,joueur);
			vider_liste(&ls_coup_dep);
			vider_liste(&ls_coup_arr);			
			prendrePiece(coup.dep, coup.arr);
			afficher();
			coup.dep = coup.arr;
		}	
		while(peutPrendre(coup.dep,joueur, &ls_coup_arr, &ls_coup_dep));
				
		/*	
		coup = choisirPrendre(&ls_coup_dep, &ls_coup_arr,joueur);
		vider_liste(&ls_coup_dep);
		vider_liste(&ls_coup_arr);
		while(peutPrendre(coup.dep,joueur, &ls_coup_arr, &ls_coup_dep)){
			afficher();
			prendrePiece(coup.dep, coup.arr);
			
			vider_liste(&ls_coup_dep);
			vider_liste(&ls_coup_arr);
		*/
	}
}

/**
 * \fn void deroulementPartie(void)
 * \brief Fonction qui s'occupe de la gestion des tours entre différents joueur
 */

void deroulementPartie(){
	//Déclaration des variables
	int i=1;
	while(!partieFinie(i)){
		jouerTour(i);
		afficher();
		sleep(2);
		tourner();
		i++;
		if(i == 5){
			i = 1;
		}
	}
	finPartie(partieFinie(i));
}
