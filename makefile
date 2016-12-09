CFLAGS = -g -Wextra 

inc = include/
proto = $(inc)joueur.h $(inc)jeu.h $(inc)plateau.h $(inc)liste_ptr.h $(inc)affichage.h $(inc)fichier.h $(inc)disp.h
fichiers = multi-dames.o joueur.o jeu.o plateau.o liste_ptr.o affichage.o fichier.o disp.o
LIB = -L $(HOME)/SDL/lib#
INCLUDE = -I $(HOME)/SDL/include#

all : ${fichiers}
	export LD_LIBRARY_PATH=$HOME/SDL/lib#
	gcc -o exe ${fichiers} ${CFLAGS} ${LIB} -lSDL2 -lSDL2_image
	export LD_LIBRARY_PATH=$HOME/SDL/lib#

liste_ptr.o : liste_ptr.c $(inc)liste_ptr.h
	gcc -c liste_ptr.c ${CFLAGS}

multi-dames.o : multi-dames.c ${proto}
	gcc -c multi-dames.c ${CFLAGS}  

plateau.o : plateau.c $(inc)plateau.h
	gcc -c plateau.c ${CFLAGS}

jeu.o : jeu.c $(inc)jeu.h
	gcc -c jeu.c ${CFLAGS} 

joueur.o : joueur.c $(inc)joueur.h
	gcc -c joueur.c ${CFLAGS} 

affichage.o: affichage.c $(inc)affichage.h
	gcc -c affichage.c ${CFLAGS}
	
disp.o: disp.c $(inc)disp.h
	gcc -c disp.c ${CFLAGS} ${INCLUDE}
	
clean :
	rm -rf *.o
	rm exe
