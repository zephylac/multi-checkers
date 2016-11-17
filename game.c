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

void initplateau(){
/* Initialise le plateau en plaçant les pions*/
	int i, j;
	/* i = lignes, j = colonnes */
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			if((i<4&&j<4)||(i>12&&j<4)||(i<4&&j>12)||(i>12&&j>12)){
			/* si la case est comprise dans un des coins, elle est invalide */
				plateau[i][j].joueur = invalide;
				plateau[i][j].piece = pvide;
				plateau[i][j].equipe = 0;
			}
			else{
               			 if((i<4)&&(j%2 == 1)&&(i%2 == 0)){
                   			plateau[i][j].joueur = joueur1;
                   			plateau[i][j].piece = pion;
                  			plateau[i][j].equipe = 1;
				}
				else if((i<4)&&(j%2 == 0)&&(i%2 == 1)){
                   			plateau[i][j].joueur = joueur1;
                   			plateau[i][j].piece = pion;
                   			plateau[i][j].equipe = 1;
				}
				else if((j<4)&&(j%2 == 1)&&(i%2 == 0)){
                   			plateau[i][j].joueur = joueur2;
                   			plateau[i][j].piece = pion;
                   			plateau[i][j].equipe = 2;
				}
				else if((j<4)&&(j%2 == 0)&&(i%2 == 1)){
                   			plateau[i][j].joueur = joueur2;
                   			plateau[i][j].piece = pion;
                   			plateau[i][j].equipe = 2;
				}
				else if((i>12)&&(j%2 == 1)&&(i%2 == 0)){
                   			plateau[i][j].joueur = joueur3;
                   			plateau[i][j].piece = pion;
                   			plateau[i][j].equipe = 1;
				}
				else if((i>12)&&(j%2 == 0)&&(i%2 == 1)){
                   			plateau[i][j].joueur = joueur3;
                   			plateau[i][j].piece = pion;
                   			plateau[i][j].equipe = 1;
				}
				else if((j>12)&&(j%2 == 1)&&(i%2 == 0)){
                  			plateau[i][j].joueur = joueur4;
                   			plateau[i][j].piece = pion;
                   			plateau[i][j].equipe = 2;
				}
				else if((j>12)&&(j%2 == 0)&&(i%2 == 1)){
                   			plateau[i][j].joueur = joueur4;
                   			plateau[i][j].piece = pion;
                   			plateau[i][j].equipe = 2;
				}
				else {
                    			plateau[i][j].joueur = vide;
                    			plateau[i][j].piece = pvide;
				}
			}

		}

	}
}

void afficher(){
/* Affiche le plateau */
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(plateau[i][j].joueur == invalide) printf("   ");
            else if(plateau[i][j].joueur == joueur1) printf("[1]");
            else if(plateau[i][j].joueur == joueur2) printf("[2]");
            else if(plateau[i][j].joueur == joueur3) printf("[3]");
            else if(plateau[i][j].joueur == joueur4) printf("[4]");
            else if(plateau[i][j].joueur == vide) printf("[ ]");
            else printf("[]");
        }
        printf("\n");
    }

}

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


int PeutPrendre(t_coordonnees coord, t_joueur joueur,t_liste* ls_coup_d){
	int prise = 0;
	t_case nouv;	//nouvel élément à insérer dans la liste
	t_coordonnees nouvcoord;
	en_tete(ls_coup_d);
	int i = coord.y;
	int j = coord.x;
	int x = 0; y = 0;
	if(plateau[i][j].piece == pion){
		if(((plateau[i-1][j-1].joueur != joueur)&&(plateau[i-1][j-1].joueur != invalide))&&plateau[i-2][j-2].joueur == vide)){
			nouvcoord.x = j-2;
			nouvcoord.y = i-2;
			nouv.coordonnees = nouvcoord;
			ajout_gauche(ls_coup_d, nouv);	
			prise = 1;
		}
		if(((plateau[i-1][j+1].joueur != joueur)&&(plateau[i-1][j+1].joueur != invalide))&&plateau[i-2][j+2].joueur == vide)){
			nouvcoord.x = j-2;
			nouvcoord.y = i+2;
			nouv.coordonnees = nouvcoord;
			ajout_gauche(ls_coup_d, nouv);
			prise = 1;
		}
		if(((plateau[i+1][j-1].joueur != joueur)&&(plateau[i+1][j-1].joueur != invalide))&&plateau[i+2][j-2].joueur == vide)){
			nouvcoord.x = j-2;
			nouvcoord.y = i+2;
			nouv.coordonnees = nouvcoord;
			ajout_gauche(ls_coup_d, nouv);
			prise = 1;
		}
		if(((plateau[i+1][j+1].joueur != joueur)&&(plateau[i+1][j+1].joueur != invalide))&&plateau[i+2][j+2].joueur == vide)){
			nouvcoord.x = j+2;
			nouvcoord.y = i+2;
			nouv.coordonnees = nouvcoord;
			ajout_gauche(ls_coup_d, nouv);
			prise = 1;
		}
	}
	if(plateau.piece == dame){
		while(x < 12 && y < 12){
			x++;
			y++;
			if(((plateau[i+y][j+x].joueur != joueur)&&(plateau[i+y][j+x].joueur != invalide))&&plateau[i+y+1][j+x+1].joueur == vide)){
				nouvcoord.x = j+x+1;
				nouvcoord.y = i+y+1;
				nouv.coordonnees = nouvcoord;
				ajout_gauche(ls_coup_d, nouv);
				prise = 1;
				break;
			}
		}
		while(x > -12 && y > -12){
			x--;
			y--;
			if(((plateau[i+y][j+x].joueur != joueur)&&(plateau[i+y][j+x].joueur != invalide))&&plateau[i+y-1][j+x-1].joueur == vide)){
				nouvcoord.x = j+x-1;
				nouvcoord.y = i+y-1;
				nouv.coordonnees = nouvcoord;
				ajout_gauche(ls_coup_d, nouv);
				prise = 1;
				break;
			}
		}
		while(x > -12 && y < 12){
			x--;
			y++;
			if(((plateau[i+y][j+x].joueur != joueur)&&(plateau[i+y][j+x].joueur != invalide))&&plateau[i+y+1][j+x-1].joueur == vide)){
				nouvcoord.x = j+x-1;
				nouvcoord.y = i+y+1;
				nouv.coordonnees = nouvcoord;
				ajout_gauche(ls_coup_d, nouv);
				prise = 1;
				break;
			}
		}
		while(x < 12 && y > -12){
			x++;
			y--;
			if(((plateau[i+y][j+x].joueur != joueur)&&(plateau[i+y][j+x].joueur != invalide))&&plateau[i+y-1][j+x+1].joueur == vide)){
				nouvcoord.x = j+x+1;
				nouvcoord.y = i+y-1;
				nouv.coordonnees = nouvcoord;
				ajout_gauche(ls_coup_d, nouv);
				prise = 1;
				break;
			}
		}
		
	}
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

int partieFini(int joueur){
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


void init(){
/* Initialise la partie */
	initplateau();


}
