#include <stdio.h> 
#include <stdlib.h>
#define Z 17

typedef enum {vide, joueur1, joueur2, joueur3, joueur4, invalide}t_joueur;
typedef enum {sans, pion, dame}t_piece;
typedef enum {equipe1 = 1, equipe2}t_equipe;
typedef enum {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q}t_lettre;

typedef struct {int x; int y;}t_coordonnees;
typedef struct {t_joueur joueur; t_piece piece; t_equipe equipe;} t_contenu;
typedef struct {t_coordonnees coordonnees; t_contenu contenu;} t_case;
typedef struct {char nom[20]; int pions_pris; int pions_perdus; int nb_coup;} t_stats;
t_contenu plateau[Z][Z] ;

void ChangeJoueur(int l, int c,t_contenu plateau[Z][Z],t_joueur nouv){
  plateau[l][c].joueur=nouv;
}
int litJoueur(int l,int c){
    return(plateau[l][c].joueur);
}
       
void DeplaAjout(t_joueur joueur,int l, int c,t_liste* ls_coup_d){
   t_case cell_dispo;
   cell_dispo.coordonnees.x=c;
   cell_dispo.coordonnees.y=l;
   ajout_droit(ls_coup_d,cell_dispo);
} 
int dispoPion(t_coordonnees coor,t_liste *ls_coup_d){
  int l,c;
  l=coor.y;
  c=coor.c;
  if(j==0 || j==5) return(0); // cas si case selectionnée n'appartient à aucun joueur
  
   // cas des deplacements pour joueur en cours
    if(l+c>16 && (c<=l)){ // si la reference est le triangle de depart du joueur
      if(litJoueur(l-1,c-1)==0){ 
         DeplaAjout(j,l,c,ls_coup_d);
         coup_dispo=1;
       }
       if(litjoueur(l-1,c+1)==0){
         DeplaAjout(j,l,c,ls_coup_d);
         coup_dispo=1;
       } 
    }
    else if(l+c<16 && (c<=l){//si la reference est le triangle de gauche
       if(litJoueur(l-1,c-1)==0){
         DeplaAjout(j,l,c,ls_coup_d);
         coup_dispo=1;
       }
       if(litJoueur(l+1,c-1)==0){
         DeplaAjout(j,l,c,ls_coup_d);
         coup_dispo=1;
       }
   else if(l+c>16 &&(c>=l){//si la reference est le triangle de droite
      if(litJoueur(l+1,c+1)==0){
         DeplaAjout(j,l,c,ls_coup_d);
         coup_dispo=1;
       }
     if(litJoueur(l-1,c+1)==0){
         DeplaAjout(j,l,c,ls_coup_d);
         coup_dispo=1;
       }
   }
  return coup_dispo;
}
           
/*____________________________________________________________________________________________________________________________*/
int coupDispo(t_coordonnees coor,t_joueur j/*eviter deplacer pion adverse*/,t_liste* ls_coup_d);
  int coup_dispo,l,c;
  l=coor.y;
  c=coor.c;
  vider_liste(ls_coup_d);// on vide la liste 
  en_tete(ls_coup_d); // on se place en_tete de liste
  if(plateau[l][c].piece==1) coup_dispo=dispoPion(coor,ls_coup_d); // si la piece est un pion, calcul de ses deplacements
  if(plateau[l][c].piece==2) coup_dispo=dispoDame(coor,ls_coup_d);
}
void init(t_contenu plateau[Z][Z]){
  int l,c;
  for(l=0,c=0;l<Z;l++){
    for(c=0;c<Z;c++){ // parcours une seule fois la matrice
      if((c<4 && (l<4 || l>=Z-4))||(c>=Z-4 && (l<4 || l>=Z-4))) ChangeJoueur(l,c,plateau,invalide); // case dans les coins sont invalides
      else if((l+c)%2==0) ChangeJoueur(l,c,plateau,vide);//indique que la case est vide
      else if(c>=4 && c<Z-4 && l>=Z-5 && (l+c)%2==1) ChangeJoueur(l,c,plateau,joueur1);//place les pions du joueur 1
      else if(c>=Z-5 && l>=4 && l<Z-4 && (l+c)%2==1) ChangeJoueur(l,c,plateau,joueur2);//place les pions du joueur 2
      else if(c>=4 && c<Z-4 && l<=4 && (l+c)%2==1) ChangeJoueur(l,c,plateau,joueur3);//place les pions du joueur 3
      else if(c<=4 && l>=4 && l<Z-4 && (l+c)%2==1) ChangeJoueur(l,c,plateau,joueur4);//place les pions du joueur 4  
    }
  }
}
               

void afficher(t_contenu plateau[Z][Z]){
  system("clear");
  int l,c,joueur;
  for(l=0,c=0;l<Z;l++){
    for(c=0;c<Z;c++){ // parcours une seule fois la matrice
      joueur=litJoueur(l,c);
      if(joueur==5) printf("   ");
      else if(joueur==0) printf(" . ");
      else if(joueur==4) printf(" 4 ");
      else if(joueur==3) printf(" 3 ");
      else if(joueur==2) printf(" 2 ");
      else if(joueur==1) printf(" 1 "); 
      
    }  
  printf("\n"); 
  }
}  

  //int coupForce(t_joueur joueur,t_liste* ls_coup_f /* type t_case*/); // retourne 1 si coup forcé ou 0 si pas coup forcé
  //
  //int jouerTour() ;
  //void deplacerPion();
  //void deplacerDame();
  //void prendrePiece(); 
 // void creerDame() ;
 // int peutAvancer();
 //int peutPrendre();*/

int main(){
  init(plateau);
  afficher(plateau);
}
