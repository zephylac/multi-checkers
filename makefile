CC = gcc
CFLAGS = -g -Wextra
main = main.c joueur.h game.h plateau.h 

#Joueur1
exo1 : joueur.j game.h plateau.h
	gcc ${joueur} -o joueur -lm $(CFLAGS)
