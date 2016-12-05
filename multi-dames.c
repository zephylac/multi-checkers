#include <stdio.h>
#include <stdlib.h>
#include "include/plateau.h"
#include "include/joueur.h"
#include "include/liste_ptr.h"
int main(){
	int choix=menu();
	init_liste(&ls_coup_dep);
	init_liste(&ls_coup_arr);
	if(choix==1){
		init();
		deroulementPartie();
	}
	if (choix==2){
	}
	if (choix==3){
	}
	if (choix==4){
	}
return 1;
}
