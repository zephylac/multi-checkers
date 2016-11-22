#include <stdio.h>
#include <stdlib.h>
#define N 17

typedef enum {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q}t_lettre;
typedef enum {vide, joueur1, joueur2, joueur3, joueur4, invalide}t_joueur;
typedef enum {pvide, pion, dame}t_piece;
typedef enum {equipe1 = 1, equipe2}t_equipe;
typedef struct {int x; int y;}t_coordonnees;
typedef struct {t_joueur joueur; t_piece piece; t_equipe equipe;} t_contenu;
typedef struct {t_coordonnees coordonnees; t_contenu contenu;} t_case;
typedef struct {char nom[20]; int pions_pris; int pions_perdus; int nb_coup;} t_stats;

t_stats statsj1;
t_stats statsj2;
t_stats statsj3;
t_stats statsj4;


t_contenu plateau[N][N];


int verifierdefaite(){
/* fonction qui sera appelée à chaque tour et retourne le numero du joueur n'ayant plus de pion. si tout le monde a encore au moins un pion, retourne 0 */
    int i, j;
    int a = 1, b = 2, c = 3, d = 4;
    for(i = 0; i < N; i++){
        for(j = 0; i < N; j++){
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


int peutPrendrepion(t_coordonnees coord, t_joueur joueur,t_liste* ls_coup_d){
        int prise = 0;
        t_case nouv;	//nouvel élément à insérer dans la liste
        t_coordonnees nouvcoord;
        int i = coord.y;
        int j = coord.x;
		if((plateau[i-1][j-1].joueur != joueur)&&(plateau[i-1][j-1].joueur != invalide)&&(plateau[i-1][j-1].joueur != vide)&&(plateau[i-2][j-2].joueur == vide)){
			nouvcoord.x = j-2;
			nouvcoord.y = i-2;
			nouv.coordonnees = nouvcoord;
			ajout_gauche(ls_coup_d, nouv);
			prise = 1;
		}
		if((plateau[i-1][j+1].joueur != joueur)&&(plateau[i-1][j+1].joueur != invalide)&&(plateau[i-1][j+1].joueur != vide)&&(plateau[i-2][j+2].joueur == vide)){
			nouvcoord.x = j+2;
			nouvcoord.y = i-2;
			nouv.coordonnees = nouvcoord;
			ajout_gauche(ls_coup_d, nouv);
			prise = 1;
		}
		if((plateau[i+1][j-1].joueur != joueur)&&(plateau[i+1][j-1].joueur != invalide)&&(plateau[i+1][j-1].joueur != vide)&&(plateau[i+2][j-2].joueur == vide)){
			nouvcoord.x = j-2;
			nouvcoord.y = i+2;
			nouv.coordonnees = nouvcoord;
			ajout_gauche(ls_coup_d, nouv);
			prise = 1;
		}
		if((plateau[i+1][j+1].joueur != joueur)&&(plateau[i+1][j+1].joueur != invalide)&&(plateau[i+1][j+1].joueur != vide)&&(plateau[i+2][j+2].joueur == vide)){
			nouvcoord.x = j+2;
			nouvcoord.y = i+2;
			nouv.coordonnees = nouvcoord;
			ajout_gauche(ls_coup_d, nouv);
			prise = 1;
		}
		return prise;

}

int peutPrendredame(t_coordonnees coord, t_joueur joueur,t_liste* ls_coup_d){
        int prise = 0;
        t_coordonnees nouvcoord;
        int i;
        int j;
        for(i = coord.y-1, j = coord.x+1; !hors_plateau(i,j); i--, j++){ // en haut à droite
        	if(plateau[i][j].joueur == joueur) break; // le joueur ne peut faire passer sa dame par dessus un de ses pions
        	if(plateau[i][j].joueur == vide && prise == 1){
        		nouvcoord.x = j;
        		nouvcoord.y = i;
        		ajout_gauche(nouvcoord);
        	}
        	else if(prise == 1) break;
        	if(plateau[i][j].joueur != joueur && plateau[i][j].joueur != vide && prise == 0){
        		if(plateau[i-1][j+1].joueur == vide) prise = 1;
        		else break;
        	}
        } 
        for(i = coord.y+1, j = coord.x-1; !hors_plateau(i,j); i++, j--){ // en bas à gauche
        	if(plateau[i][j].joueur == joueur) break; // le joueur ne peut faire passer sa dame par dessus un de ses pions
        	if(plateau[i][j].joueur == vide && prise == 1){
        		nouvcoord.x = j;
        		nouvcoord.y = i;
        		ajout_gauche(nouvcoord);
        	}
        	else if(prise == 1) break;
        	if(plateau[i][j].joueur != joueur && plateau[i][j].joueur != vide && prise == 0){
        		if(plateau[i+1][j-1].joueur == vide) prise = 1;
        		else break;
        	}
        }
        for(i = coord.y+1, j = coord.x+1; !hors_plateau(i,j); i++, j++){ // en bas à droite
        	if(plateau[i][j].joueur == joueur) break; // le joueur ne peut faire passer sa dame par dessus un de ses pions
        	if(plateau[i][j].joueur == vide && prise == 1){
        		nouvcoord.x = j;
        		nouvcoord.y = i;
        		ajout_gauche(nouvcoord);
        	}
        	else if(prise == 1) break;
        	if(plateau[i][j].joueur != joueur && plateau[i][j].joueur != vide && prise == 0){
        		if(plateau[i+1][j+1].joueur == vide) prise = 1;
        		else break;
        	}
        }
        for(i = coord.y-1, j = coord.x-1; !hors_plateau(i,j); i--, j--){ // en haut à gauche
        	if(plateau[i][j].joueur == joueur) break; // le joueur ne peut faire passer sa dame par dessus un de ses pions
        	if(plateau[i][j].joueur == vide && prise == 1){
        		nouvcoord.x = j;
        		nouvcoord.y = i;
        		ajout_gauche(nouvcoord);
        	}
        	else if(prise == 1) break;
        	if(plateau[i][j].joueur != joueur && plateau[i][j].joueur != vide && prise == 0){
        		if(plateau[i-1][j-1].joueur == vide) prise = 1;
        		else break;
        	}
        }
        
	return prise;
}

int PeutPrendre(t_coordonnees coord, t_joueur joueur,t_liste* ls_coup_d){
	viderliste(ls_coup_d);
	int prise = 0;
	t_case nouv;	//nouvel élément à insérer dans la liste
	t_coordonnees nouvcoord;
	en_tete(ls_coup_d);
	int i = coord.y;
	int j = coord.x;
	int x = 0;
	int y = 0;
	if(plateau[i][j].piece == pion){
        	prise = peutPrendrepion(coord, joueur, ls_coup_d);
	}
	if(plateau[i][j].piece == dame){
        	prise = peutPrendredame(coord, joueur, ls_coup_d);
	}
	return prise;
}

int deppossible(t_joueur joueur){
/* Vérifie si le joueur entré en paramètre peut déplacer au moins une pièce, s'il ne peut pas, il perd la partie */
/* retourne 1 si le joueur peut jouer, 0 s'il est bloqué */
	int i, j;
	t_coordonnees coord;
	for(i = 0; i < N; i++){
        	for(j = 0; i < N; j++){
			coord.x = j;
			coord.y = i;
			if((plateau[i][j].joueur == joueur)&&(coupDispo(coord), joueur, liste) return 1;
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
		if(!depposible(testdep)) return joueur;	
	}
	return verifierdefaite();
	
	
}

void afficherstats(){
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
	if(verifierdefaite(joueur)) printf("le joueur n'a plus de pions\n");
	else if((j != vide)&&(!deppossible(j)) printf("le joueur ne peut plus se déplacer\n");
	afficherstats();
}

void reinitstatsjoueur(t_joueur joueur){
	switch(joueur){
		case joueur1: statsj1 = {NULL; 0; 0; 0;};
		case joueur2: statsj2 = {NULL; 0; 0; 0;};
		case joueur3: statsj3 = {NULL; 0; 0; 0;};
		case joueur4: statsj4 = {NULL; 0; 0; 0;};		
	}
}
		
void reinitstats(){
	reinitstatsjoueur(joueur1);
	reinitstatsjoueur(joueur2);
	reinitstatsjoueur(joueur3);
	reinitstatsjoueur(joueur4);
}
		
void statpionpris(t_joueur joueur){
	switch(joueur){
		case joueur1: statsj1.pions_pris++; break;
		case joueur2: statsj2.pions_pris++; break;
		case joueur3: statsj3.pions_pris++; break;
		case joueur4: statsj4.pions_pris++; break;
	}
}

void statpionperdu(t_joueur joueur){
	switch(joueur){
		case joueur1: statsj1.pions_perdus++; break;
		case joueur2: statsj2.pions_perdus++; break;
		case joueur3: statsj3.pions_perdus++; break;
		case joueur4: statsj4.pions_perdus++; break;
	}
}
		
void statdep(t_joueur joueur){
	switch(joueur){
		case joueur1: statsj1.nb_coup++; break;
		case joueur2: statsj2.nb_coup++; break;
		case joueur3: statsj3.nb_coup++; break;
		case joueur4: statsj4.nb_coup++; break;
	}	
}
		
void init(){
/* Initialise la partie */
	initplateau();
	reinitstats();
}
