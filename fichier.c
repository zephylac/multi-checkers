/**
 * \author Thibault Brocherieux
 * \date 06/12/2016
 * \file fichier.c
 * \brief Programme contenant les fonctions liées au joueur
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/struct.h"

/**
 * \fn void sauv(char nom[30])
 * \brief 
 * \param[in] carac charactère
 * \return Retourne un int qui a pour valeur la lettre entrée
 */
void sauv(char nom[60]){
	FILE * fic;
	int i, j;
	
	fic = fopen(nom,"w");

	//Seulement utile lorsque l'on sauvegarde au milieu d'un tour, lorsque l tour ne sera pas au joueur 1
	//Il faudra init la variable tour joueur 
	//fprintf(fic,"%i ",joueur);
	
	for(i = 0; i < Z; i++){
		for( j = 0; j < Z; j++){
			fprintf(fic,"%i %i %i ",plateau[i][j].joueur, plateau[i][j].piece,plateau[i][j].equipe);
		}
	}
	fclose(fic);
}

void lireSauv(char nom[60]){
	FILE * fic;
	int i, j;
	
	//Seulement utile lorsque l'on sauvegarde au milieu d'un tour, lorsque l tour ne sera pas au joueur 1
	//Il faudra init la variable tour joueur 
	//fscanf(fic,"%i ",&joueur);	
	fic = fopen(nom,"r");
	for(i = 0; i < Z; i++){
		for( j = 0; j < Z; j++){
			fscanf(fic,"%i %i %i ",&plateau[i][j].joueur, &plateau[i][j].piece, &plateau[i][j].equipe);
		}
	}
	fclose(fic);
}
