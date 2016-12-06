#include <stdio.h> 
#include <stdlib.h>
#include "include/liste_ptr.h"
#include "include/struct.h"
#include "include/jeu.h"
#include "include/joueur.h"
#include "include/plateau.h"

int LARG=80;
/**
* \file affichage.c
* \brief programme contenant les fonctions utilisées pour l'affichage
* \author BRINON Baptiste
*/

/*____________________________________________________________________________________________________________________*/

/**
* \fn void lignePleine()
* \brief trace une ligne pleine de la largeur du terminal
* \author BRINON Baptiste
*/
void lignePleine(){
	int nb_carac;
	printf("+"); // coin gauche
	for(nb_carac=0;nb_carac<(LARG-2);nb_carac++){
		printf("-");
	}               
	printf("+\n");// coin droit
}
/**
* \fn void ligneVide()
* \brief fonction tracant une ligne vide
* \author BRINON Baptiste
*/
void ligneVide(){
	int nb_carac;
	printf("|"); // bord gauche
	for(nb_carac=0;nb_carac<(LARG-2);nb_carac++){
		printf(" ");
	}               
	printf("|\n");// bord droit
}

/**
* \fn void margeGauche(int larg_plat)
* \brief calcule et "affiche" la marge de gauche
* \param larg_plat entier indiquant la taille du contenu de la ligne
* \author BRINON Baptiste
*/
void margeGauche(int larg_plat){
	int taille;
	printf("|");
	for(taille=0;taille<(LARG-larg_plat-2)/2;taille++){
		printf(" ");
	}
}

/**
* \fn void margeDroite(int larg_plat)
* \brief calcule et "affiche" la marge de droite
* \param larg_plat entier indiquant la taille du contenu de la ligne
* \author BRINON Baptiste
*/
void margeDroite(int larg_plat){
	int taille;
	for(taille=0;taille<(LARG-larg_plat-2)/2;taille++){
		printf(" ");
	}
	printf("|");
}
void margeHaut(){
	lignePleine();
	ligneVide();
	ligneVide();
}
void margeBas(){
	ligneVide();
	ligneVide();
	lignePleine();
}
void afficher(){
	system("clear");
	char carac='A';
	int i=0,l,c,joueur,larg_plat=53;
	margeHaut();
	margeGauche(larg_plat);
	printf("   "); // decallage dut à l'absence de marge chiffrée
	for(l=0,c=0;l<Z;l++){
		printf(" %c ",carac);
		carac++;
	}
	margeDroite(larg_plat);
	printf("\n");
	for(l=0,c=0;l<Z;l++){
		if(i <10){
			margeGauche(larg_plat);
			printf(" %i|",i);
		}
		else{
			margeGauche(larg_plat);
			printf("%i|",i);
		}
		i++;
		for(c=0;c<Z;c++){ // parcours une seule fois la matrice
			joueur=litJoueur(l,c);
			if(joueur==5) printf("   ");
			else if(joueur==0) printf(" . ");
			else if(joueur==4 && plateau[l][c].piece == pion) printf(" 4 ");
			else if(joueur==4 && plateau[l][c].piece == dame) printf("[4]");
			else if(joueur==3 && plateau[l][c].piece == pion) printf(" 3 ");
			else if(joueur==3 && plateau[l][c].piece == dame) printf("[3]");
			else if(joueur==2 && plateau[l][c].piece == pion) printf(" 2 ");
			else if(joueur==2 && plateau[l][c].piece == dame) printf("[2]");
			else if(joueur==1 && plateau[l][c].piece == pion) printf(" 1 ");
			else if(joueur==1 && plateau[l][c].piece == dame) printf("[1]");
		}
		margeDroite(larg_plat);
		printf("\n"); 
	}
	margeBas();
}  
int menu(){
	int choix,nb_carac,nb_ligne=0;
	system("clear");
	margeHaut();
	
	//ecriture de chaque ligne
	nb_carac=24; // nombre de caracteres de la ligne écrite
	margeGauche(nb_carac);
	printf("1-Nouvelle Partie Locale");
	margeDroite(nb_carac);
	
	// saut de ligne
	printf("\n");
	ligneVide();
	
	margeGauche(nb_carac);
	printf("2-Nouvelle Partie Reseau");
	margeDroite(nb_carac);
	
	printf("\n");
	ligneVide();
	
	nb_carac=37;
	margeGauche(nb_carac);
	printf("3-Charger la Partie Locale Précédente ");
	margeDroite(nb_carac);
	// fin ecriture des lignes du menu
	
	printf("\n");
	ligneVide();
	
	nb_carac=16;
	margeGauche(nb_carac);
	printf("4-Manuel du Jeu ");
	margeDroite(nb_carac);
	
	margeBas();
	printf("\n");
	printf(" Effectuez un choix en saisissant 1,2,3 ou 4:");
	scanf("%i",&choix);
	return choix;
}
