CFLAGS = -g -Wextra 

inc = include/
proto = $(inc)joueur.h $(inc)jeu.h $(inc)plateau.h
fichiers = multi-dames.o joueur.o jeu.o plateau.o 

all : ${fichiers}
	gcc -o exe ${fichiers} -g -Wextra
#Main
multi-dames.o : multi-dames.c ${proto} 
	gcc -c multi-dames.c ${CFLAGS}  

plateau.o : plateau.c $(inc)plateau.h
	gcc -c plateau.c ${CFLAGS}

jeu.o : jeu.c $(inc)jeu.h
	gcc -c jeu.c ${CFLAGS} 

joueur.o : joueur.c $(inc)joueur.h
	gcc -c joueur.c ${CFLAGS} 

clean :
	rm -rf *.o
