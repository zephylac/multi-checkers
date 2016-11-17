#include <stdio.h>
#include <stdlib.h>
#define Z 17

typedef enum {vide, joueur1, joueur2, joueur3, joueur4, invalide}t_joueur;
typedef enum {sans, pion, dame}t_piece;
typedef enum {equipe1 = 1, equipe2}t_equipe;
typedef enum {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q}t_lettre;

typedef struct {int x; int y}t_coordonnees;
typedef struct {t_joueur joueur; t_piece piece; t_equipe equipe} t_contenu;
typedef struct {t_coordonnees coordonnees; t_contenu contenu} t_case;
typedef struct {char nom[20]; int pions_pris; int pions_perdus; int nb_coup} t_stats;
t_contenu plateau[Z][Z] ;

/**
*\fn void jouerTour(t_joueur joueur)
*\brief Fonction qui exécute le tour d'un joueur entré en paramètre
*/
void afficherLettre (t_lettre lettre){
  switch(lettre){
    case A : printf("A");break;
    case B : printf("B");break;
    case C : printf("C");break;
    case D : printf("D");break;
    case E : printf("E");break;
    case F : printf("F");break;
    case G : printf("G");break;
    case H : printf("H");break;      
    case I : printf("I");break;
    case J : printf("J");break;      
    case K : printf("K");break;
    case L : printf("L");break;      
    case M : printf("M");break;
    case N : printf("N");break;      
    case O : printf("O");break;
    case P : printf("P");break;
    case Q : printf("Q");break;
  }
}

/**
*\fn void jouerTour(t_joueur joueur)
*\brief Fonction qui exécute le tour d'un joueur entré en paramètre
*/
void choisir(t_liste * ls_coup, t_joueur joueur){
	int choix;
	t_case cellule;
	t_coordonnees coord;

	printf("-----------Menu-----------");
	en_tete(&ls_coup);
	while(!hors_liste(&ls_coup)){
		valeur_elt(&ls_coup,&cellule);
		printf("%i) Déplacer le pion se trouvant aux coordonnées ",i);
		afficherLettre(cellule.coordonnees.y);
		printf(" %i",cellule.coordonnees.x);
		i++;
		suivant(&ls_coup);
	}
	
	switch(choix){
		case i:
		en_tete(&ls_coup);
		for(j = 0;j < i; j++){
	  		suivant(&ls_coup);
		}	
		valeur_elt(&ls_coup,&cellule);
		coord.x = cellule.coordonnees.x;
		coord.y = cellule.coordonnees.y
		deplacer(coord,joueur);

		break; //break out of the switch
		}
	}
}

/**
*\fn void jouerTour(t_joueur joueur)
*\brief Fonction qui exécute le tour d'un joueur entré en paramètre
*/
void jouerTour(t_joueur joueur){
	//Déclaration dec s variables
	char c_colonne;
    	int debut_tour;
	int colonne;
	int ligne;
  	int i = 0;
	int choix;
	t_case cellule;
  	t_coordonnees = coord;
	//Cette fonction nous retourne des valeurs utiles pour le début de tour d'un joueur
	debut_tour = coupForce(joueur,ls_coup_f);
	/* Si le joueur n'a pas de coup obligatoire */
	if(debut_tour == 0){
    		printf("Veuillez choisir la case où se trouve votre pion");
    		scanf("Entrer les coordonnées %c%i",&c_colonne,&ligne); 
		/* transfert char -> int
		 */

		coord.x = ligne;
		coord.y = colonne;
		while(!coupDispo(coord,joueur,&ls_coup_d)){
			printf("Veuillez choisir la case où se trouve votre pion");
    			scanf("Entrer les coordonnées %c%i",&c_colonne,&ligne); 
			/* transfert char -> int
			 */
	
			coord.x = ligne;
			coord.y = colonne;
		}

	}	
	choisir(&ls_coup_d,joueur)
	while(peutPrendre(/****/)){
		choisir(&ls_coup_d,joueur)
	
	}
}

/**
 * \fn void jouertour()
 * brief Fonction qui s'occupe de la gestion du tour
 */

void deroulementPartie(){
	//Déclaration des variables
	int i=1;
	while(!finPartie()){
		jouerTour(i);
		i++;
		if(i == 5){
			i = 1;
		}
	}
}
