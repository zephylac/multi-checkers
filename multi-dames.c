#include <stdio.h>
#include <stdlib.h>
#include "include/plateau.h"
#include "include/joueur.h"
#include "include/liste_ptr.h"
int main(){
	init_liste(&ls_coup_d);
	init_liste(&ls_coup_f);
	init();
	deroulementPartie();
return 1;
}
