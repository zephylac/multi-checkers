#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/liste_ptr.h"
#include "include/struct.h"
#include "include/plateau.h"
#include "include/joueur.h"

int hors_plateau(int i, int j){
	if(i > Z-1 || j > Z-1 || j < 0 || i < 0) return 1;
	if(plateau[i][j].joueur == invalide) return 1;
	return 0;
}

int verifierDefaite(){
/* fonction qui sera appelée à chaque tour et retourne le numero du joueur n'ayant plus de pion. si tout le monde a encore au moins un pion, retourne 0 */
    int i, j;
    int a = 1, b = 2, c = 3, d = 4;
    for(i = 0; i < Z; i++){
        for(j = 0; j < Z; j++){
            if(plateau[i][j].joueur == joueur1) a = 0;
            if(plateau[i][j].joueur == joueur2) b = 0;
            if(plateau[i][j].joueur == joueur3) c = 0;
            if(plateau[i][j].joueur == joueur4) d = 0;
        }
    }
    if(a) return a; // Si le joueur a n'a plus de pions, a vaudra toujours 1 et donc la fonction retournera 1
    if(b) return b;
    if(c) return c;
    if(d) return d;
    return 0;       // arrivée ici, si la fonction n'a toujours rien retourné, c'est que personne n'a encore perdu, donc on retourne 0
}

void ajoutListe(t_coordonnees coord, t_joueur joueur, t_piece piece, t_liste* liste){
/* Fonction ajoutant à une liste de t_case les valeurs correspondantes */
	t_case nouv;
	switch(joueur){
		case joueur1: nouv.contenu.joueur = joueur1; nouv.contenu.equipe = equipe1; break;
		case joueur2: nouv.contenu.joueur = joueur2; nouv.contenu.equipe = equipe2; break;
		case joueur3: nouv.contenu.joueur = joueur3; nouv.contenu.equipe = equipe1; break;
		case joueur4: nouv.contenu.joueur = joueur4; nouv.contenu.equipe = equipe2; break;
		default: printf("erreur switch ajoutListe");
	}
	nouv.contenu.piece = piece;
	nouv.coordonnees = coord;
	ajout_gauche(liste, nouv);
}

int peutPrendrepion(t_coordonnees coord_dep, t_joueur joueur,t_liste* ls_coup_arr, t_liste* ls_coup_dep){
/* Fonction ajoutant à une liste toutes les coordonnées où le pion aux coordonnées en paramètre peut arriver après avoir pris un autre pion et renvoie 1 */
        int prise = 0;
        t_coordonnees coord_arr;
        int i = coord_dep.y;
        int j = coord_dep.x;
		if((plateau[i-1][j-1].joueur != joueur)&&(plateau[i-1][j-1].joueur != invalide)&&(plateau[i-1][j-1].joueur != vide)&&(plateau[i-2][j-2].joueur == vide)){
			coord_arr.x = j-2;
			coord_arr.y = i-2;
			ajoutListe(coord_arr, joueur, pion, ls_coup_arr);
			ajoutListe(coord_dep, joueur, pion, ls_coup_dep);
			prise = 1;
		}
		if((plateau[i-1][j+1].joueur != joueur)&&(plateau[i-1][j+1].joueur != invalide)&&(plateau[i-1][j+1].joueur != vide)&&(plateau[i-2][j+2].joueur == vide)){
			coord_arr.x = j+2;
			coord_arr.y = i-2;
			ajoutListe(coord_arr, joueur, pion, ls_coup_arr);
			ajoutListe(coord_dep, joueur, pion, ls_coup_dep);	
			prise = 1;
		}
		if((plateau[i+1][j-1].joueur != joueur)&&(plateau[i+1][j-1].joueur != invalide)&&(plateau[i+1][j-1].joueur != vide)&&(plateau[i+2][j-2].joueur == vide)){
			coord_arr.x = j-2;
			coord_arr.y = i+2;
			ajoutListe(coord_arr, joueur, pion, ls_coup_arr);
			ajoutListe(coord_dep, joueur, pion, ls_coup_dep);
			prise = 1;
		}
		if((plateau[i+1][j+1].joueur != joueur)&&(plateau[i+1][j+1].joueur != invalide)&&(plateau[i+1][j+1].joueur != vide)&&(plateau[i+2][j+2].joueur == vide)){
			coord_arr.x = j+2;
			coord_arr.y = i+2;	
			ajoutListe(coord_arr, joueur, pion, ls_coup_arr);
			ajoutListe(coord_dep, joueur, pion, ls_coup_dep);
			prise = 1;
		}
		return prise;

}

int peutPrendredame(t_coordonnees coord_dep, t_joueur joueur,t_liste* ls_coup_arr, t_liste* ls_coup_dep){
        int prise = 0;
        t_coordonnees coord_arr;
        int i;
        int j;
        for(i = coord_dep.y-1, j = coord_dep.x+1; !hors_plateau(i,j); i--, j++){ // en haut à droite
        	if(plateau[i][j].joueur == joueur) break; // le joueur ne peut faire passer sa dame par dessus un de ses pions
        	if(plateau[i][j].joueur == vide && prise == 1){
        		coord_arr.x = j;
        		coord_arr.y = i;
        		ajoutListe(coord_arr, joueur, pion, ls_coup_arr);
			ajoutListe(coord_dep, joueur, pion, ls_coup_dep);
        	}
        	else if(prise == 1) break;
        	if(plateau[i][j].joueur != joueur && plateau[i][j].joueur != vide && prise == 0){
        		if(plateau[i-1][j+1].joueur == vide) prise = 1;
        		else break;
        	}
        } 
        for(i = coord_dep.y+1, j = coord_dep.x-1; !hors_plateau(i,j); i++, j--){ // en bas à gauche
        	if(plateau[i][j].joueur == joueur) break; // le joueur ne peut faire passer sa dame par dessus un de ses pions
        	if(plateau[i][j].joueur == vide && prise == 1){
        		coord_arr.x = j;
        		coord_arr.y = i;
        		ajoutListe(coord_arr, joueur, pion, ls_coup_arr);
			ajoutListe(coord_dep, joueur, pion, ls_coup_dep);

        	}
        	else if(prise == 1) break;
        	if(plateau[i][j].joueur != joueur && plateau[i][j].joueur != vide && prise == 0){
        		if(plateau[i+1][j-1].joueur == vide) prise = 1;
        		else break;
        	}
        }
        for(i = coord_dep.y+1, j = coord_dep.x+1; !hors_plateau(i,j); i++, j++){ // en bas à droite
        	if(plateau[i][j].joueur == joueur) break; // le joueur ne peut faire passer sa dame par dessus un de ses pions
        	if(plateau[i][j].joueur == vide && prise == 1){
        		coord_arr.x = j;
        		coord_arr.y = i;
        		ajoutListe(coord_arr, joueur, pion, ls_coup_arr);
			ajoutListe(coord_dep, joueur, pion, ls_coup_dep);

        	}
        	else if(prise == 1) break;
        	if(plateau[i][j].joueur != joueur && plateau[i][j].joueur != vide && prise == 0){
        		if(plateau[i+1][j+1].joueur == vide) prise = 1;
        		else break;
        	}
        }
        for(i = coord_dep.y-1, j = coord_dep.x-1; !hors_plateau(i,j); i--, j--){ // en haut à gauche
        	if(plateau[i][j].joueur == joueur) break; // le joueur ne peut faire passer sa dame par dessus un de ses pions
        	if(plateau[i][j].joueur == vide && prise == 1){
        		coord_arr.x = j;
        		coord_arr.y = i;
        		ajoutListe(coord_arr, joueur, pion, ls_coup_arr);
			ajoutListe(coord_dep, joueur, pion, ls_coup_dep);
        	}
        	else if(prise == 1) break;
        	if(plateau[i][j].joueur != joueur && plateau[i][j].joueur != vide && prise == 0){
        		if(plateau[i-1][j-1].joueur == vide) prise = 1;
        		else break;
        	}
        }
        
	return prise;
}

int peutPrendre(t_coordonnees coord, t_joueur joueur,t_liste* ls_coup_arr, t_liste* ls_coup_dep){
	int prise = 0;
	t_case nouv;	//nouvel élément à insérer dans la liste
	t_coordonnees nouvcoord;
	en_tete(ls_coup_arr);
	en_tete(ls_coup_arr);
	int i = coord.y;
	int j = coord.x;
	int x = 0;
	int y = 0;
	if(plateau[i][j].piece == pion){
        	prise = peutPrendrepion(coord, joueur, ls_coup_arr, ls_coup_dep);
	}
	if(plateau[i][j].piece == dame){
        	prise = peutPrendredame(coord, joueur, ls_coup_arr, ls_coup_dep);
	}
	return prise;
}

int depPossible(t_joueur joueur){
/* Vérifie si le joueur entré en paramètre peut déplacer au moins une pièce, s'il ne peut pas, il perd la partie */
/* retourne 1 si le joueur peut jouer, 0 s'il est bloqué */
	int i, j;
	t_coordonnees coord;
	for(i = 0; i < Z; i++){
        	for(j = 0; i < Z; j++){
			coord.x = j;
			coord.y = i;
			if(plateau[i][j].joueur == joueur && coupDispo(coord, joueur, &ls_coup_dep)) return 1;
		}
	}
	return 0;	
}

int partieFinie(int joueur){
/* le paramètre joueur est le numéro du joueur dont c'est le tour de jouer */
/* retourne le numéro du joueur ayant perdu la partie, s'il y en a un, retourne 0 sinon.*/
	t_joueur testdep;
	switch(joueur){
		case 1: testdep = joueur1; break;
		case 2:	testdep = joueur2; break;
		case 3: testdep = joueur3; break;
		case 4: testdep = joueur4; break;
		default: testdep = vide; break;
	}
	if(testdep != vide){
		if(!depPossible(testdep)) return joueur;	
	}
	return verifierDefaite();
	
	
}

void afficherStats(){
	printf("%s: %i pions pris, %i pions perdus\n", statsj1.nom, statsj1.pions_pris, statsj1.pions_perdus);
	printf("%s: %i pions pris, %i pions perdus\n", statsj2.nom, statsj2.pions_pris, statsj2.pions_perdus);
	printf("%s: %i pions pris, %i pions perdus\n", statsj3.nom, statsj3.pions_pris, statsj3.pions_perdus);
	printf("%s: %i pions pris, %i pions perdus\n", statsj4.nom, statsj4.pions_pris, statsj4.pions_perdus);
}
			   
void finPartie(int joueur){
/* prend en paramètre le numéro du joueur ayant perdu la partie, et met fin à la partie */
	t_joueur j;
	switch(joueur){
		case 1: j = joueur1; break;
		case 2:	j = joueur2; break;
		case 3: j = joueur3; break;
		case 4: j = joueur4; break;
		default: j = vide; break;		
	}
	printf("Le joueur%i a perdu: ", joueur);	// affiche le joueur ayant perdu et la raison de sa défaite
	if(verifierDefaite()) printf("le joueur n'a plus de pions\n");
	else if(j != vide && !depPossible(j)) printf("le joueur ne peut plus se déplacer\n");
	afficherStats();
}

void reinitStatsJoueur(t_joueur joueur){
	switch(joueur){
		case joueur1: strcpy(statsj1.nom, "j1"); statsj1.pions_pris = 0; statsj1.pions_perdus = 0; statsj1.nb_coup = 0; break;
		case joueur2: strcpy(statsj2.nom, "j2"); statsj2.pions_pris = 0; statsj2.pions_perdus = 0; statsj2.nb_coup = 0; break;
		case joueur3: strcpy(statsj3.nom, "j3"); statsj3.pions_pris = 0; statsj3.pions_perdus = 0; statsj3.nb_coup = 0; break;
		case joueur4: strcpy(statsj4.nom, "j4"); statsj4.pions_pris = 0; statsj4.pions_perdus = 0; statsj4.nb_coup = 0; break;
		default: printf("erreur switch reinitStatsJoueur");
	}
}
		
void reinitStats(){
	reinitStatsJoueur(joueur1);
	reinitStatsJoueur(joueur2);
	reinitStatsJoueur(joueur3);
	reinitStatsJoueur(joueur4);
}
		
void statPionpris(t_joueur joueur){
	switch(joueur){
		case joueur1: statsj1.pions_pris++; break;
		case joueur2: statsj2.pions_pris++; break;
		case joueur3: statsj3.pions_pris++; break;
		case joueur4: statsj4.pions_pris++; break;
		default: printf("erreur switch statPionpris");
	}
}

void statPionperdu(t_joueur joueur){
	switch(joueur){
		case joueur1: statsj1.pions_perdus++; break;
		case joueur2: statsj2.pions_perdus++; break;
		case joueur3: statsj3.pions_perdus++; break;
		case joueur4: statsj4.pions_perdus++; break;
		default: printf("erreur switch statPionperdu");
	}
}
		
void statDep(t_joueur joueur){
	switch(joueur){
		case joueur1: statsj1.nb_coup++; break;
		case joueur2: statsj2.nb_coup++; break;
		case joueur3: statsj3.nb_coup++; break;
		case joueur4: statsj4.nb_coup++; break;
		default: printf("erreur switch statDep");
	}	
}
