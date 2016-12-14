#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/struct.h"

void sauv(char nom[30]){
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

void lireSauv(char nom[30]){
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

void sauvPlateau(){
	FILE * fic;
	int i, j;
	
	fic = fopen("~/multi-checkers/multi/plateau.txt","w");
	
	for(i = 0; i < Z; i++){
		for( j = 0; j < Z; j++){
			fprintf(fic,"%i %i %i ",plateau[i][j].joueur, plateau[i][j].piece,plateau[i][j].equipe);
		}
	}
	fclose(fic);
}

void lirePlateau(){
	FILE * fic;
	int i, j;

	fic = fopen("~/multi-checkers/multi/plateau.txt","r");
	for(i = 0; i < Z; i++){
		for( j = 0; j < Z; j++){
			fscanf(fic,"%i %i %i ",&plateau[i][j].joueur, &plateau[i][j].piece, &plateau[i][j].equipe);
		}
	}
	fclose(fic);
}
