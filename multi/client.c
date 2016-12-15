#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "../include/plateau.h"
#include "../include/joueur.h"
#include "../include/jeu.h"
#include "../include/struct.h"
#include "../include/affichage.h"
#include "../include/liste_ptr.h"
#include "../include/fichier.h"
char file[30] ="~/multi-checkers/multi/partie.txt";

fpos_t placerLigne(int ligne){
	FILE * fic;
	fic = fopen(file,"r");
	int i = 0;
	char carac;
	fpos_t position;
	rewind(fic);
	while(i < ligne){
		fscanf(fic,"%c",&carac);
	if(carac == '\n'){
			i++;
		}
	}
	fgetpos(fic, &position);
	fclose(fic);
	return position;
}

void changerStatus(int joueur){
	FILE * fic;
	fpos_t position;
	int present;
	position = placerLigne(joueur); 
	fic = fopen(file,"r+");
	fsetpos(fic,&position);
	fscanf(fic,"joueur_present : %i",&present);
	fsetpos(fic,&position);	
	if(present){
		fprintf(fic,"joueur_present : 0\n");	
	}
	else{
		fprintf(fic,"joueur_present : 1\n");
	}
	fclose(fic);
}

int recupererStatus(int joueur){
	FILE * fic;
	fpos_t position;
	int present;
	position = placerLigne(joueur);
	fic = fopen(file,"r");
	fsetpos(fic,&position);
	fscanf(fic,"joueur_present : %i\n",&present);
	fclose(fic);
	return present;
}

void premiereConnexion(){
	FILE * fic;
	int check = 0;
	int nb_joueur = 0;
	nb_joueur = recupererStatus(1) + recupererStatus(2) + recupererStatus(3) + recupererStatus(4);
	
	if(nb_joueur == 1){
		init();
		sauvPlateau();
		check = 1;
		fic = fopen(file,"r+");
		fprintf(fic,"tour_joueur : 1\n");
		fclose(fic);
	}
	//return check;
}
void quitterPartie(int joueur){
	changerStatus(joueur);	
	printf("Vous avez quittez la partie\n");
}

int placerJoueur(){
	FILE * fic;
	int joueur,present;
	fpos_t position;
	fic = fopen(file,"r");
	position = placerLigne(1);
	fsetpos(fic,&position);
	fscanf(fic,"joueur_present : %i\n",&present); 
	if(!present){
		changerStatus(1);
		joueur = 1;
		
	}
	else{
		fscanf(fic,"joueur_present : %i\n",&present); 
		if(!present){
			changerStatus(2);
			joueur = 2;
		}
		else{
			fscanf(fic,"joueur_present : %i\n",&present); 
			if(!present){
				changerStatus(3);
				joueur = 3;
			}
			else{
				fscanf(fic,"joueur_present : %i\n",&present); 
				if(!present){
					changerStatus(4);
					joueur = 4;
				}
				else{
					printf("La partie est pleine\n");
					joueur = 0;
				}
			}
		}
	}
	fclose(fic);
	return joueur;
}

void afficherPlateau(){
	lirePlateau();
	afficher();
	sleep(3);
}


void attendreTour(int joueur){
	FILE * fic;
	int tour;
	fic = fopen(file,"r");
	fscanf(fic,"tour_joueur : %i",&tour);
	fclose(fic);
	while(tour != joueur){
		afficherPlateau();
		//rewind(fic);
		fic = fopen(file,"r");
		fscanf(fic,"tour_joueur : %i",&tour);
		fclose(fic);
	}
	//fclose(fic);
}

void joueurSuivant(){
	FILE * fic;
	int joueur;
	fic = fopen(file,"r+");
	fscanf(fic,"tour_joueur : %i\n",&joueur);
	joueur++;
	if(joueur >= 5){
		joueur = 1;
	}
	rewind(fic);
	fprintf(fic,"tour_joueur : %i\n",joueur);
	fclose(fic);
}



void main(){
	int joueur;
	int fin = 0;
	joueur = placerJoueur();
	premiereConnexion();	
	if(joueur == 0){
	}
	else{

		init_liste(&ls_coup_dep);
		init_liste(&ls_coup_arr);
		
		printf("Bienvenue, vous jouez en tant que le joueur %i\n",joueur);
		sleep(2);
		while(!fin){
			attendreTour(joueur);
			lireSauv("~/multi-checkers/multi/plateau.txt");
			if(partieFinie(joueur)){
				fin = 1;
				finPartie(partieFinie(joueur));	
			//	quitterPartie(1);
			}
			else{
				jouerTour(joueur);
				tourner();
				sauv("~/multi-checkers/multi/plateau.txt");
				joueurSuivant();
			}
		}
	}
}
	
	
