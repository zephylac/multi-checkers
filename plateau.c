// realisé par BRINON Baptiste 
#include <stdio.h> 
#include <stdlib.h>
#include "include/liste_ptr.h"
#include "include/struct.h"
#include "include/jeu.h"
#include "include/joueur.h"

//fonction permettant de changer la valeur joueur d'une case
void ChangeJoueur(int l, int c,t_joueur nouv){
  plateau[l][c].joueur=nouv;
}
//fonction qui renvoie la valeur joueur de la case aux coordonnées saisies
int litJoueur(int l,int c){
    return(plateau[l][c].joueur);
}
//Ajoute à la liste la case aux coordonnées l,c       
void DeplaAjout(int l, int c,t_liste ls_coup){
   t_case cell_dispo; // creation d'un case à empiler
  //assignation des infos de la cellule à celle qui va empiler
   cell_dispo.coordonnees.x=c;
   cell_dispo.coordonnees.y=l;
   cell_dispo.contenu.joueur=plateau[l][c].joueur;
   cell_dispo.contenu.piece=plateau[l][c].piece;
   if(plateau[l][c].joueur==1 || plateau[l][c].joueur==3 ) cell_dispo.contenu.equipe=1;
   if(plateau[l][c].joueur==2 || plateau[l][c].joueur==4 ) cell_dispo.contenu.equipe=2;
   ajout_droit(&ls_coup,cell_dispo); // ajout dans la liste de la case
} 

//fonction servant à lister les emplacements ou un pion peut se deplacer
int dispoPion(t_coordonnees coor,t_liste ls_coup_d){
  int l,c,coup_dispo;
  vider_liste(&ls_coup_d);
  l=coor.y;
  c=coor.x;
  
   // cas des deplacements pour Pion du joueur 
    if(l+c>16 && (c<=l)){ // si la reference est le triangle de depart du joueur
      if(litJoueur(l-1,c-1)==0){ 
         DeplaAjout(l,c,ls_coup_d); // ajout de la case dans la liste des coups dispo
         coup_dispo=1; // donne 1 a la valeur des coup_dispos, designant la piece comme jouable
       }
       if(litJoueur(l-1,c+1)==0){ // même schema que la boucle precedante
         DeplaAjout(l,c,ls_coup_d);
         coup_dispo=1;
       } 
    }
    else if(l+c<16 && (c<=l)){//si la reference est le triangle de gauche
       if(litJoueur(l-1,c-1)==0){
         DeplaAjout(l,c,ls_coup_d); 
         coup_dispo=1;
       }
       if(litJoueur(l+1,c-1)==0){
         DeplaAjout(l,c,ls_coup_d);
         coup_dispo=1;
       }
    }
    else if(l+c>16 &&(c>=l)){//si la reference est le triangle de droite
      if(litJoueur(l+1,c+1)==0){
         DeplaAjout(l,c,ls_coup_d);
         coup_dispo=1;
       }
     if(litJoueur(l-1,c+1)==0){
         DeplaAjout(l,c,ls_coup_d);
         coup_dispo=1;
       }
   }
  return coup_dispo; //fin de la fonction, delivre vrai si coup dispo
}

int dispoDame(t_coordonnees coor,t_liste ls_coup_d){
  int l,c,coup_dispo,fin;
  vider_liste(&ls_coup_d);
  l=coor.y;
  c=coor.x;
  
   // cas des deplacements pour Dame du joueur 
  for(c=c+1,l=l+1;plateau[l][c].joueur==0;l++,c++){ // Traitement des differentes diagonales
    DeplaAjout(l,c,ls_coup_d);// Ajout des cases vides de la diagonale jusqu'a la rencontre d'une piece
    coup_dispo=1; // Piece pouvant etre jouée
  } 
  for(c=c-1,l=l+1;plateau[l][c].joueur==0;l++,c--){// même schéma
    DeplaAjout(l,c,ls_coup_d);
    coup_dispo=1; 
  }
  for(c=c+1,l=l-1;plateau[l][c].joueur==0;l--,c++){
    DeplaAjout(l,c,ls_coup_d);
    coup_dispo=1; 
  }
  for(c=c-1,l=l-1;plateau[l][c].joueur==0;l--,c--){
    DeplaAjout(l,c,ls_coup_d);
    coup_dispo=1; 
  }
  return coup_dispo;
}
//transforme le pion indiqué en dame, s'il remplis les conditions pour en devenir une
void creerDame(t_coordonnees coor){
  int c=coor.x;
  int l=coor.y;
  if(c==0 || c==16){ // si la piece est a l'un des extremité adverse
    if(plateau[l][c].piece==1) plateau[l][c].piece=2; // elle devien une dame
  }
}

void viderContenu(t_contenu contenu){
   contenu.joueur=0;
   contenu.piece=0;
   contenu.equipe=0;
}
void InitCase(int l,int c,t_joueur j){
   ChangeJoueur(l,c,j);
   plateau[l][c].piece=1;
   if(j==1 || j==3) plateau[l][c].equipe=1;
   if(j==2 || j==4 ) plateau[l][c].equipe=2;
}
/*____________________________________________________________________________________________________________________________*/
/*--------------------------------------- FONCTIONS MAJEURES----------------------------------------------------------------- */
/*____________________________________________________________________________________________________________________________*/
           
           
            
void init(){
  int l,c;
  for(l=0,c=0;l<Z;l++){
    for(c=0;c<Z;c++){ // parcours une seule fois la matrice
      if((c<4 && (l<4 || l>=Z-4))||(c>=Z-4 && (l<4 || l>=Z-4))) ChangeJoueur(l,c,invalide); // case dans les coins sont invalides
      else if((l+c)%2==0) ChangeJoueur(l,c,vide);//indique que la case est vide
      else if((c>=4 && c<Z-4 ) && l>=Z-4 && (l+c)%2==1) InitCase(l,c,joueur1);//place les pions du joueur 1
      else if(c>=Z-4 && (l>=4 && l<Z-4) && (l+c)%2==1) InitCase(l,c,joueur2);//place les pions du joueur 2
      else if((c>=4 && c<Z-4) && l<=3 && (l+c)%2==1) InitCase(l,c,joueur3);//place les pions du joueur 3
      else if(c<=3 &&(l>=4 && l<Z-4)&& (l+c)%2==1) InitCase(l,c,joueur4);//place les pions du joueur 4  
    }
  }
}
               

void afficher(){
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

int coupForce(t_joueur j,t_liste ls_coup_f /* type t_case*/){ // retourne 1 si coup forcé ou 0 si pas coup forcé          
  int l,c,coup_For;
  t_coordonnees cell_pos;
  t_joueur j_Pos;
  vider_liste(&ls_coup_f);
  coup_For=0;
  for(l=0;l<N;l++){
    for(c=0;c<N;c++){
      cell_pos.x=c;
      cell_pos.y=l;
      j_Pos=litJoueur(l,c);
      if(j==j_Pos && peutPrendre(cell_pos,j,&ls_coup_f) ){ //-----------------------a completer avec fonction willi--------------------
        DeplaAjout(l,c,ls_coup_f);
        coup_For=1;
      }
    }
  }
  return coup_For;
}
/* fonction prenant en coordonnées le pion à jouer. 
Retourne vrai si le joueur peut jouer le pion, et fournit une liste avec les deplacement possibles*/
int coupDispo(t_coordonnees coor,t_joueur j/*pour eviter de deplacer un pion adverse*/,t_liste* ls_coup_d){
  int coup_dispo,l,c;
  l=coor.y;
  c=coor.x;
  vider_liste(ls_coup_d);// on vide la liste 
  en_tete(ls_coup_d); // on se place en_tete de liste
  if(plateau[l][c].joueur==j){ // verification que la piece choisie appartien au joueur 
    if(plateau[l][c].piece==1) coup_dispo=dispoPion(coor,*ls_coup_d); // si la piece est un pion, calcul de ses deplacements
    if(plateau[l][c].piece==2) coup_dispo=dispoDame(coor,*ls_coup_d); // si la piece est une dame, calcul de ses deplacements
  }
  return coup_dispo; //renvoi vrai si la piece est jouable
}

// deplace une piece de son point de depart à son point d'arrivée, que ce soit un pion ou une dame
void deplacerPiece(t_coordonnees dep,t_coordonnees arriv){
  int c_dep=dep.x;
  int l_dep=dep.y;
  int l_arriv= arriv.y;
  int c_arriv= arriv.x;
  //place la piece à son point d'arrivée
  plateau[l_arriv][c_arriv]=plateau[l_dep][c_dep];
  
  //la retire de son point de depart
  viderContenu(plateau[l_dep][c_dep]);
 //verifie si elle devient une dame
  creerDame(arriv);
}
void prendrePiece(t_coordonnees dep,t_coordonnees arriv){
  int c_arr=arriv.x; int l_arr=arriv.y; // preparation des coordonnées de l'arrivée
  int c_dep=dep.x;int l_dep=dep.y;// preparation des coordonnées du depart
  int c_supp,l_supp;
  if(plateau[l_dep][c_dep].piece==1){ // cas si la piece jouée est un pion
    c_supp=c_dep+(c_arr-c_dep)/2; // calcul des coordonnées de la piece supprimée
    l_supp=l_dep+(l_arr-l_dep)/2;
  }
  else if(plateau[l_dep][c_dep].piece==2){
    while(plateau[l_dep][c_dep].joueur==0){ // Traitement des differentes diagonales
      if(l_arr>l_dep) l_dep++;
      else if(l_arr<l_dep) l_dep--;
      if(c_arr>c_dep) c_dep++;
      else if(c_arr<c_dep) l_dep--;
    }
  }
    c_supp=c_dep;// calcul des coordonnées de la piecesupprimé
    l_supp=l_dep;
  deplacerPiece(dep,arriv); // deplacement de la piece
  // suppression du pion pris
  viderContenu(plateau[l_supp][c_supp]);
}


void switchCoord(int x, int y){
  t_contenu inter;
  inter = plateau[x][y];
  plateau[x][y] = plateau[y][Z-1-x];
  plateau[y][Z-1-x] = plateau[Z-1-x][Z-1-y];
  plateau[Z-1-x][Z-1-y] = plateau[Z-1-y][x];
  plateau[Z-1-y][x] = inter;
}

void tourner(){
  int i,j;
  for(i = 4; i < 13 ; i++){
    for(j = 13; j < Z; j++){
      switchCoord( i, j);
    }
  }
  j = 12;
  for( i = 5; i < 12; i++){
    switchCoord( i, j);
  }
  j = 11;
  for(i = 6; i < 11; i++){
    switchCoord( i, j);
  }
  j = 10;
  for(i = 7; i < 10; i++){
    switchCoord( i , j);
  }
  i = 8;
  j = 9;
  switchCoord( i, j);
}
