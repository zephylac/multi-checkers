#include <stdio.h>
#include <unistd.h>
#include <string.h>
char file ="partie.txt";

fpos_t placerLigne(int ligne){
	FILE * fic;
	fic = fopen(file,"r");
	int i = 0;
	char carac;
	fpos_t position;
	rewind(fic);
	while(i < ligne){
		fscanf(file,"%c",&carac);
		if(carac == "\n"){
			i++;
		}
	}
	fgetpos(fic, &position);
	fclose(fic);
	return position;
}

void changerStatus(int joueur){
	fpos_t position;
	int present;
	placerLigne(joueur); 
	fic = fopen(file,"r+");
	fsetpos(fic,&position);
	fscanf(fic,"joueur_present : %i",&present);
	fsetpos(fic,&position);	
	if(present){
		fprintf("joueur_present : 0\n");	
	}
	else{
		fprintf("joueur_present : 1\n");
	}
	fclose(fic);
}

void quitterPartie(int joueur){
	changerStatus(joueur);	
	printf("Vous avez quittez la partie\n");
}

int placerJoueur(){
	int joueur,present;
	fpos_t position;
	fic = fopen(file,"r");
	position = placerLigne(1);
	fsetpos(fic,&position);
	fscanf(fic,"joueur_present : %i",&present); 
	if(present){
		changerStatus(1);
		joueur = 1;
	}
	fscanf(fic,"joueur_present : %i",&present); 
	else if(present){
		changerStatus(2);
		joueur = 2;
	}
	fscanf(fic,"joueur_present : %i",&present); 
	else if(present){
		changerStatus(3);
		joueur = 3;
	}
	fscanf(fic,"joueur_present : %i",&present); 
	else if(present){
		changerStatus(4);
		joueur = 4;
	}
	else{
		printf("La partie est pleine\n");
		joueur = 0;
	}
	return joueur;
}
void attendreTour(int joueur){
	FILE * fic;
	int tour;
	fic = fopen("tour.txt","r");
	fscanf(fic,"tour_joueur : %i",tour);
	while(tour != joueur){}
}

void joueurSuivant(){
	int joueur;
	fic = fopen(file,"r+");
	fscanf(fic,"tour_joueur : %i\n",&joueur);
	joueur++;
	if(joueur >= 5) joueur = 1;
	rewind(fic);
	fprintf(fic,"tour_joueur : %i\n",joueur);
	fclose(fic);
}

void main(){
	int joueur;

	joueur = placerJoueur();
	if(joueur != 0){
		printf("Bienvenue, vous jouez en tant que le joueur %i\n",joueur);
	}
	else{
		while(!finPartie()){
			attendreTour(joueur);
			jouertour(tour);
			joueurSuivant();
		}
	}
//	quitterPartie(1);
}
	
	
