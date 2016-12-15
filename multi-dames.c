#include <stdio.h>
#include <stdlib.h>
#include "include/plateau.h"
#include "include/joueur.h"
#include "include/liste_ptr.h"
#include "include/fichier.h"
#include "include/affichage.h"
int main(){
	FILE * fic;
	init_liste(&ls_coup_dep);
	init_liste(&ls_coup_arr);
	char nom[30];
	int choix;
	while(choix!=5){
		choix=menu();
		if(choix==1){
			init();
			printf("Veuillez choisir le nom de la sauvegarde: ");
			scanf("%s",nom);
			sauv(nom);
			deroulementPartie(nom);
		}
		if (choix==2){

			system("ssh dame@52.28.201.112");
			//multi
		}
		if (choix==3){
			printf("\nEntrer le nom de la sauvegarde à lire: ");
			scanf("%s",nom);
			fic = fopen(nom,"r");
			while(fic == NULL){
				printf("Erreur, le nom entré n'est pas valide\n");
				printf("\nEntrer le nom de la sauvegarde à lire");
				scanf("%s",nom);
				fic = fopen(nom,"r");
			}
			fclose(fic);
			lireSauv(nom);
			deroulementPartie(nom);
		}
		if (choix==4){
			manuelDuJeu();
		}
		if (choix==5){
		printf("\n merci d'avoir joué! ");
		return 1;
		}
	}
}
