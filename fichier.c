#include <stdlib.h>
#include <string.h>
#include "include/struct.h"

void sauv(t_joueur joueur){
	FILE * fic;
	int i, j;
	char nom[30];

	printf("\nEntrer le nom de la sauvegarde : ");
	scanf("%s",&nom);
	
	fic = fopen(nom,"w");

	fprintf(fic,"%i ",joueur);
	
	for(i = 0; i < Z; i++){
		for( j = 0; j < Z; j++){
			fprintf(fic,"%i %i %i ",plateau[i][j].joueur, plateau[i][j].piece,plateau[i][j].equipe);
		}
	}
	fclose(fic);
}

t_joueur lireSauv(){
	FILE * fic;
	int i, j;
	char nom[30];

	printf("\nEntrer le nom de la sauvegarde à lire");
	scanf("%s",&nom);
	fic = fopen(nom,"r");
	while(

	fic = fopen(save.txt,"r");
	t_joueur joueur;

	fscanf(fic,"%i ",&joueur);
	for(i = 0; i < Z; i++){
		for( j = 0; j < Z; j++){
			fscanf(fic,"%i %i %i ",plateau[i][j].joueur, plateau[i][j].piece,plateau[i][j].equipe);
		}
	}
	return joueur;
}

