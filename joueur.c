#include <stdio.h>
#include <stdlib.h>
#define N 17

typedef enum {vide, joueur1, joueur2, joueur3, joueur4, invalide}t_joueur;
typedef enum {vide, pion, dame}t_piece;
typedef enum {equipe1 = 1, equipe2}t_equipe;
typedef enum {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q}t_lettre;

typedef struct {int x; int y}t_coordonnees;
typedef struct {t_joueur joueur; t_piece piece; t_equipe equipe} t_contenu;
typedef struct {t_coordonnees coordonnees; t_contenu contenu} t_case;
typedef struct {char nom[20]; int pions_pris; int pions_perdus; int nb_coup} t_stats;
t_contenu plateau[N][N] ;

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
void jouerTour(t_joueur joueur){
  //Déclaration des variables
  int debut_tour;
  int colonne;
  int ligne;
  int i = 0;
  int choix;
  t_case cellule;
  
  //Cette fonction nous retourne des valeurs utiles pour le début de tour d'un joueur
  debutTour(joueur);
  if(debut_tour == 1){
    printf("Veuillez choisir la case où se trouve votre pion");
    scanf("Entrer les coordonnées %c%i",&colonne,&ligne); 
    switch(choix) {
    	en_tete();
	while(!hors_liste){
        valeur_elt(coupforce,&cellule);
        case i:
          printf("%i) Déplacer le pion se trouvant aux coordonnées ",i);
          afficherLettre(colonne);
          printf(" %i",ligne);
          break; //break out of the switch
          i++;
	  suivant();
      }
    }
  //traitement du choix   
  }
  else{
    //force un joueur à effectuer un coup
  }
}

/**
 * \fn void jouertour()
 * brief Fonction qui s'occupe de la gestion du tour
 */

void deroulementPartie(){
	//Déclaration des variables
	int i;

	i++;
	if(i == 5){
		i = 1;
	}
	while(!finPartie()){
		jouerTour(i);

	}
}     
