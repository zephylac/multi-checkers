#include <stdio.h>
#include <stdlib.h>
#include "include/plateau.h"
#include "include/joueur.h"
#include "include/liste_ptr.h"
#include "include/fichier.h"
#include "include/affichage.h"
int main(){
	char nom[30];
	int choix=menu();
	init_liste(&ls_coup_dep);
	init_liste(&ls_coup_arr);
	if(choix==1){
		init();
		printf("Veuillez choisir le nom de la sauvegarde");
		scanf("%s",nom);
		sauv(nom);
		deroulementPartie();
	}
	if (choix==2){
		printf("Le mot de passe est \"dame\"");
		system("ssh dame@52.28.201.112");
		//multi
	}
	if (choix==3){
		lireSauv();
		deroulementPartie();
	}
	if (choix==4){
//		manuelDuJeu();
	}
return 1;
}
