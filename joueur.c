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
#include "include/fichier.h"

/**
 * \fn int caracValeur(char carac)
 * \brief fonction qui permet de convertir un caractère en chiffre, qu'il soit majuscule ou minuscule
 * \param[in] carac charactère
 * \return Retourne un int qui a pour valeur la lettre entrée
 */
int caracValeur(char carac){
	//Gestion d'une minuscule
	if(carac >= 'a' && carac <= 'z') return carac - 'a';
	//Gestion d'une majuscule
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
	//Si le caractère est un chiffre
	if(isdigit(c_colonne)){                                    
		coord.x = 0;
		coord.y = 0;
	}
	//Sinon
	else{
		colonne = caracValeur(c_colonne);
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
    default : c = 'Z';break;
  }
  return c;
}





/**
* \fn t_coordonnees choisirPrendre(t_liste * ls_coup_dep, t_liste * ls_coup_arr, t_joueur joueur, int mode)
* \brief Fonction qui affiche les choix possibles lorsque le coup est forcé.
* \param[in] ls_coup_dep Liste qui contient les coordonnées de départs des pions qui peuvent prendre un pion
* \param[in] ls_coup_arr Liste qui contient les coordonnées d'arrivées des pions qui peuvent prendre un pion
* \param[in] joueur Le numéro du joueur qui joue
* \param[in] type Permet de différencier un déplacement et une prise
* \param[in] mode Permet de savoir si les pions à prendre sont allié ou enemi
* \param[in] depcoord Coordonnées du pion déplacé lors d'un simple déplacement
* \return coup de type choix qui contient les coordonnées de départ et d'arrivée
*/
t_choix choisir(t_liste* ls_coup_dep, t_liste* ls_coup_arr,t_joueur joueur, int type, int mode, t_coordonnees depcoor){
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
		
		//affichage des possibilitées
		while(!hors_liste(ls_coup_arr)){
			if(type == 0){
				valeur_elt(ls_coup_arr,&arr);
				c1 = afficherLettre(depcoor.x);
				c2 = afficherLettre(arr.coordonnees.x);
				i++;
				printf("%i) Déplacer la pièce %c%i aux coordonnées %c%i\n",i,c1,depcoor.y,c2,arr.coordonnees.y);
				suivant(ls_coup_arr);
			}
			if(type == 1){
				valeur_elt(ls_coup_dep,&dep);
				valeur_elt(ls_coup_arr,&arr);
				c1 = afficherLettre(dep.coordonnees.x);
				c2 = afficherLettre(arr.coordonnees.x);
				i++;
				printf("%i) Déplacer la pièce %c%i aux coordonnées %c%i\n",i,c1,dep.coordonnees.y,c2,arr.coordonnees.y);					
				suivant(ls_coup_dep);
				suivant(ls_coup_arr);
			}
		}
		//Si le c'est une prise qu'il est possible de refuser
		if (mode == 1 && type == 1){
			i++;
			printf("%i) Ne pas prendre le pion allié\n",i);
			
		}
		//Choix de l'utilisateur
		printf("Votre choix : ");
		scanf("%i",&choix);
	}
	while(choix <= 0 || choix > i);
	if (choix == i && mode == 1 && type == 1){	
		coup.dep.x = 99;
		coup.dep.y = 99;
		coup.arr.x = 99;
		coup.arr.y = 99;
	}
	else{	
		//En fonction du choix de l'utilisateur, le programme va chercher les valeurs qu'il a choisi grâce à son rang dans la liste
		if(type == 0){
			en_tete(ls_coup_arr);
			for(i = 1; i < choix; i++){
				suivant(ls_coup_arr);
			}	
			valeur_elt(ls_coup_arr,&arr);
			coup.dep.x = depcoor.x;
			coup.dep.y = depcoor.y;
			coup.arr.x = arr.coordonnees.x;
			coup.arr.y = arr.coordonnees.y;
		}
		if(type == 1){
			en_tete(ls_coup_dep);
			en_tete(ls_coup_arr);
		
			for(i = 1; i < choix; i++){
				suivant(ls_coup_dep);
				suivant(ls_coup_arr);
			}	
			valeur_elt(ls_coup_dep,&dep);
			valeur_elt(ls_coup_arr,&arr);
			coup.dep.x = dep.coordonnees.x;
			coup.dep.y = dep.coordonnees.y;
			coup.arr.x = arr.coordonnees.x;
			coup.arr.y = arr.coordonnees.y;
		}
	}
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
	int ligne=0;
	int choix;
	t_case cellule;
  	t_coordonnees coord_dep;
	t_coordonnees coord_arr;
	t_choix coup;
	coup.dep.x = 0;
    	coup.dep.y = 0;
	//Cette fonction nous retourne des valeurs utiles pour le début de tour d'un joueur
        afficher();
	coup_force = coupForce(joueur,&ls_coup_arr, &ls_coup_dep);

	/* Si le joueur n'a pas de coup obligatoire */
	if(coup_force == 0){
		choix = 1;
    		vider_liste(&ls_coup_dep);
		vider_liste(&ls_coup_arr);			
		
		do{
			printf("Veuillez choisir la case où se trouve votre pion\n");
    			printf("Entrer les coordonnées (ex:A1) : ");
			scanf("%c%i",&c_colonne,&ligne); 
			coup.dep = traiteEntree(c_colonne,ligne);
		}
		while(!coupDispo(coup.dep,joueur,&ls_coup_arr) && !peutPrendre(coup.dep,joueur, &ls_coup_arr, &ls_coup_dep,1));
		vider_liste(&ls_coup_dep);
		vider_liste(&ls_coup_arr);
		if(peutPrendre(coup.dep,joueur, &ls_coup_arr, &ls_coup_dep,1)){
			do{	
				printf("1) Deplacer un pion\n");
				printf("2) Prendre un pion allié\n");
				printf("Votre choix : ");
				scanf("%i",&choix);
			}
			while(choix < 1 || choix > 2);
			
			if (choix == 1){
				coupDispo(coup.dep,joueur,&ls_coup_arr); 
				coup = choisir(&ls_coup_dep, &ls_coup_arr, joueur, 0, 0, coup.dep);
				deplacerPiece(coup.dep,coup.arr);
			
			}
			if(choix == 2){
				coup = choisir(&ls_coup_dep, &ls_coup_arr,joueur,1,0,coup.dep);
				prendrePiece(coup.dep, coup.arr);
				afficher();
				coup.dep = coup.arr;

				vider_liste(&ls_coup_dep);
				vider_liste(&ls_coup_arr);			

				while(coup.dep.x != 99 && peutPrendre(coup.dep, joueur, &ls_coup_arr, &ls_coup_dep,2)){
					vider_liste(&ls_coup_dep);
					vider_liste(&ls_coup_arr);			
					if(peutPrendre(coup.dep, joueur, &ls_coup_arr, &ls_coup_dep,0)){
						coup = choisir(&ls_coup_dep, &ls_coup_arr,joueur,1,0,coup.dep);
						prendrePiece(coup.dep, coup.arr);
						afficher();
						coup.dep = coup.arr;
					}
					else if(peutPrendre(coup.dep, joueur, &ls_coup_arr, &ls_coup_dep,1)){
						coup = choisir(&ls_coup_dep, &ls_coup_arr,joueur,1,1,coup.dep);
						if(coup.dep.x != 99){
							prendrePiece(coup.dep, coup.arr);
							afficher();
							coup.dep = coup.arr;
						}
					}
				}

			}
		}
		else{
			coupDispo(coup.dep,joueur,&ls_coup_arr);
			coup = choisir(&ls_coup_dep,&ls_coup_arr,joueur,0,0,coup.dep);
			deplacerPiece(coup.dep,coup.arr);	
		}
	}
	else{
		coup = choisir(&ls_coup_dep, &ls_coup_arr,joueur,1,0,coup.dep);
		prendrePiece(coup.dep, coup.arr);
		coup.dep = coup.arr;
		afficher();
		vider_liste(&ls_coup_dep);
		vider_liste(&ls_coup_arr);			
		while( coup.dep.x != 99 && peutPrendre(coup.dep,joueur, &ls_coup_arr, &ls_coup_dep,2)){	
			vider_liste(&ls_coup_dep);
			vider_liste(&ls_coup_arr);
			if(peutPrendre(coup.dep, joueur, &ls_coup_arr, &ls_coup_dep,0)){
				coup = choisir(&ls_coup_dep, &ls_coup_arr,joueur,1,0,coup.dep);
				prendrePiece(coup.dep, coup.arr);
				afficher();
				coup.dep = coup.arr;
			}
			else if(peutPrendre(coup.dep, joueur, &ls_coup_arr, &ls_coup_dep,1)){
				coup = choisir(&ls_coup_dep, &ls_coup_arr,joueur,1,1,coup.dep);
				printf("test : %i",coup.dep.x); 
				if(coup.dep.x != 99){
					prendrePiece(coup.dep, coup.arr);
					afficher();
					coup.dep = coup.arr;
				}
			}
			vider_liste(&ls_coup_dep);
			vider_liste(&ls_coup_arr);			
		}

	}
}
/**
 * \fn void deroulementPartie(void)
 * \brief Fonction qui s'occupe de la gestion des tours entre différents joueur
 * \param[in] nom Le nom du fichier de sauvegarde
 */

void deroulementPartie(char nom[30]){
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
			sauv(nom);
		}
	}
	finPartie(partieFinie(i));
}







/**
* \fn t_coordonnees choisirDep(t_liste * ls_coup, t_joueur joueur)
* \brief Fonction qui affiche les choix possibles de déplacement d'un pion. Cette fonction n'est appelé seulement lorsqu'il n'y a pas de coup forcé
* \param[in] ls_coup Liste contenant les déplacements possibles
* \param[in] joueur Le numéro du joueur qui joue
* \return coord de type t_cooordonnees, qui contient les coordonnées du pion choisit
*/
/*t_coordonnees choisirDep(t_liste* ls_coup,t_joueur joueur){
	int choix,i = 0;
	t_case cellule;
	t_coordonnees coord;
	char c1;
	do{
		printf("\n-----------Joueur %i-----------\n",joueur);
		en_tete(ls_coup);
		//Affichage des possibilitées
		while(!hors_liste(ls_coup)){
			valeur_elt(ls_coup,&cellule);
			c1 = afficherLettre(cellule.coordonnees.x);
			printf("%i) Déplacer le pion aux coordonnées %c%i\n",i,c1,cellule.coordonnees.y);
			i++;
			suivant(ls_coup);
		}
		//Choix de l'utilisateur
		printf("Votre choix : ");
		scanf("%i",&choix);
	}
	//En fonction du choix de l'utilisateur, le programme va chercher les valeurs qu'il a choisi grâce à son rang dans la liste
	while(choix < 0 || choix >= i);
		en_tete(ls_coup);
		for(i = 0; i < choix; i++){
			suivant(ls_coup);
		}	
		valeur_elt(ls_coup,&cellule);
		coord.x = cellule.coordonnees.x;
		coord.y = cellule.coordonnees.y;
	return coord;
}
*/

/**
* \fn t_coordonnees choisirPrendre(t_liste * ls_coup_dep, t_liste * ls_coup_arr, t_joueur joueur, int mode)
* \brief Fonction qui affiche les choix possibles lorsque le coup est forcé.
* \param[in] ls_coup_dep Liste qui contient les coordonnées de départs des pions qui peuvent prendre un pion
* \param[in] ls_coup_arr Liste qui contient les coordonnées d'arrivées des pions qui peuvent prendre un pion
* \param[in] joueur Le numéro du joueur qui joue
* \param[in] mode Permet de savoir si les pions à prendre sont allié ou enemi
* \return coup de type choix qui contient les coordonnées de départ et d'arrivée
*/
/*
t_choix choisirPrendre(t_liste* ls_coup_dep, t_liste* ls_coup_arr,t_joueur joueur, int mode){
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
		//affichage des possibilitées
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
		//Si le joueur a le droit de refuser la prise ou pas
		if (mode == 1){
			printf("%i) Ne pas prendre de pion\n",i);
			i++;
		}
		//Choix de l'utilisateur
		printf("Votre choix : ");
		scanf("%i",&choix);
	}
	while(choix < 1 || choix >= i);
	if (choix == i-1 && mode == 1){	
		coup.dep.x = 99;
		coup.dep.y = 99;
		coup.arr.x = 99;
		coup.arr.y = 99;
	}
	else{	
		//En fonction du choix de l'utilisateur, le programme va chercher les valeurs qu'il a choisi grâce à son rang dans la liste
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
	}
	return coup;
}
*/
/**
* \fn void jouerTour(t_joueur joueur)
* \brief Fonction qui exécute le tour d'un joueur entré en paramètre
* \param[in] joueur qui le numéro du joueur à qui c'est le tour
*/
/*
void jouerTour(t_joueur joueur){
	//Déclaration dec s variables
	char c_colonne;
    	int coup_force;
	int ligne=0;
	int choix;
	t_case cellule;
  	t_coordonnees coord_dep;
	t_coordonnees coord_arr;
	t_choix coup;
	coup.dep.x = 0;
    	coup.dep.y = 0;
	//Cette fonction nous retourne des valeurs utiles pour le début de tour d'un joueur
        afficher();
	coup_force = coupForce(joueur,&ls_coup_arr, &ls_coup_dep);
*/
	/* Si le joueur n'a pas de coup obligatoire */
/*	if(coup_force == 0){
		choix = 1;
    		vider_liste(&ls_coup_dep);
		vider_liste(&ls_coup_arr);			
		if(peutPrendre(coup.dep,joueur, &ls_coup_arr, &ls_coup_dep,1)){
			do{	
				printf("1) Deplacer un pion\n");
				printf("2) Prendre un pion allié\n");
				printf("Votre choix : ");
				scanf("%i",&choix);
			}
			while(choix < 1 || choix > 2);
			
			if (choix == 1){
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
			if(choix = 2){
				coup = choisirPrendre(&ls_coup_dep, &ls_coup_arr,joueur,1);
				prendrePiece(coup.dep, coup.arr);
				afficher();
				coup.dep = coup.arr;

				vider_liste(&ls_coup_dep);
				vider_liste(&ls_coup_arr);			

				while(coup.dep.x != 99 && peutPrendre(coup.dep, joueur, &ls_coup_arr, &ls_coup_dep,2)){
					vider_liste(&ls_coup_dep);
					vider_liste(&ls_coup_arr);			
					if(peutPrendre(coup.dep, joueur, &ls_coup_arr, &ls_coup_dep,0)){
						coup = choisirPrendre(&ls_coup_dep, &ls_coup_arr,joueur,0);
						prendrePiece(coup.dep, coup.arr);
						afficher();
						coup.dep = coup.arr;
					}
					else if(peutPrendre(coup.dep, joueur, &ls_coup_arr, &ls_coup_dep,1)){
						coup = choisirPrendre(&ls_coup_dep, &ls_coup_arr,joueur,1);
						if(coup.dep.x != 99){
							prendrePiece(coup.dep, coup.arr);
							afficher();
							coup.dep = coup.arr;
						}
					}
				}

			}
		}
		else{
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
	}
	else{
		do{
			coup = choisirPrendre(&ls_coup_dep, &ls_coup_arr,joueur, 0);
			vider_liste(&ls_coup_dep);
			vider_liste(&ls_coup_arr);			
			prendrePiece(coup.dep, coup.arr);
			afficher();
			coup.dep = coup.arr;
		}	
		while(peutPrendre(coup.dep,joueur, &ls_coup_arr, &ls_coup_dep, 0));
		
		coup = choisirPrendre(&ls_coup_dep, &ls_coup_arr,joueur,0);
		prendrePiece(coup.dep, coup.arr);
		coup.dep = coup.arr;
		afficher();
		vider_liste(&ls_coup_dep);
		vider_liste(&ls_coup_arr);			
		while( coup.dep.x != 99 && peutPrendre(coup.dep,joueur, &ls_coup_arr, &ls_coup_dep,2)){	
			vider_liste(&ls_coup_dep);
			vider_liste(&ls_coup_arr);
			if(peutPrendre(coup.dep, joueur, &ls_coup_arr, &ls_coup_dep,0)){
				coup = choisirPrendre(&ls_coup_dep, &ls_coup_arr,joueur,0);
				prendrePiece(coup.dep, coup.arr);
				afficher();
				coup.dep = coup.arr;
			}
			else if(peutPrendre(coup.dep, joueur, &ls_coup_arr, &ls_coup_dep,1)){
				coup = choisirPrendre(&ls_coup_dep, &ls_coup_arr,joueur,1);
				printf("test : %i",coup.dep.x); 
				if(coup.dep.x != 99){
					prendrePiece(coup.dep, coup.arr);
					afficher();
					coup.dep = coup.arr;
				}
			}
			vider_liste(&ls_coup_dep);
			vider_liste(&ls_coup_arr);			
		}

	}
}*/
