# Checkers-
A game developped under C library

Jeux de dames++

I- Introduction

	Le jeux de dames++ consiste à adapter un jeu de dames afin de pouvoir y jouer à 4 joueurs. Pour pouvoir permettre  la réalisation de ce jeux nous devrons adapter le tableaux ainsi que certaines règles.

II- Règles

1 – Le matériel

- Le plateau sera modifié, il contiendra 225 cases.
-Chaque joueurs disposera de 18 pions.
- La partie se joue en deux contre deux.
- Il y a deux types de pièce : les pions et les dames
	
2 – La marche des pièces

-Une fois le pion sélectionné, le joueur a alors l’obligation de le jouer si cela est possible
- Un coup ne peut être annulé.
	Les pions :
	- Un pion se déplace obligatoirement vers l’avant, en diagonale, sur un case vide.
	-Lorsqu’un pion atteint la dernière rangé, le pion devient dame.

	Les dames :
	- Une dame rentre en action après que l’adversaire ait joué au moins une fois depuis 		sa création.
	- Une dame peut se déplacer en arrière ou en avant sur toute la longueurs de ses deux 		diagonales
3 – La prise
		
-La prise des pièces adverses est obligatoire dans cette version du jeux sauf pour les pions alliés

-Lorsqu’un pion se trouve en présence, diagonalement, d’une pièce adverse derrière laquelle se trouve une case libre, il doit obligatoirement sauter par-dessus cette pièce et occuper la case libre. Cette pièce adverse est alors enlevée du damier. Cette opération complète est la prise par un pion.

-Lorsqu’une dame se trouve en présence sur la même diagonale, directement ou à distance, d’une pièce adverse derrière laquelle se trouvent une ou plusieurs cases libres, elle doit obligatoirement passer par-dessus cette pièce et occuper, au choix, une des cases libres. Cette pièce est alors enlevée du damier. Cette opération complète est la prise par une dame.

-Lorsqu’au cours d’une prise par un pion, celui-ci se trouve à nouveau en présence, diagonalement, d’une pièce adverse derrière laquelle se trouve une case libre, il doit obligatoirement sauter par-dessus cette seconde pièce, voire d’une troisième et ainsi de suite, et occuper la case libre se trouvant derrière la dernière pièce capturée. Les pièces adverses ainsi capturées sont ensuite enlevées du damier dans l’ordre de la prise. Cette opération complète est une rafle par un pion.
 
Lorsqu’au cours d’une prise par une dame, celle-ci se trouve à nouveau en présence, sur une même diagonale, d’une pièce adverse derrière laquelle se trouve une ou plusieurs cases libres, elle doit obligatoirement sauter par-dessus cette seconde pièce, voire d’une troisième et ainsi de suite, et occuper au choix une case libre se trouvant derrière et sur la même diagonale que la dernière pièce capturée. Les pièces adverses ainsi capturées sont ensuite enlevées du damier dans l’ordre de la prise. Cette opération complète est une rafle par une dame.

Au cours d’une rafle, il est interdit de passer au-dessus de ses propres pièces. Mais il est possible de passer au-dessus des pièces de son allié cependant les pièces seront prise aussi.

Au cours d’une rafle, il est permis de passer plusieurs fois sur une même case libre mais il est interdit de passer plus d’une fois au-dessus d’une même pièce adverse.

4 – Fin de partie

Une partie est considérée comme fini lorsque l’un des deux joueurs adverses n’a plus de pion.
Lorsqu’un joueur ne peut plus jouer, alors son équipe perd.

III – Mode d’interaction

-Le jeux se joue au tour par tour, le programme indiquera quelle joueur doit jouer. 
 
-Les coordonnées seront repéré grâce à une lettre et un chiffre.

-L’utilisateur entrera les coordonnées du pion qu’il veut déplacer. En fonction de cette saisie, le programme affichera si oui ou non le déplacement est possible. Si oui, les possibilités de déplacement.

- On identifiera les pions et les dames de chaque joueurs de manière unique.

-Les cases vides seront identifiés par des points (‘.’). 

IV – Les contraintes

-Le jeux sera développé sous l'environnement  C.

-Le jeux doit être rendu avant le 16 décembre.

IV – La conception


1 -  Structure de données


Un enum permettant de savoir quel joueur est concerné :
	typedef enum t_joueur(vide, joueur_1, joueur_2, joueur_3, joueur_4, invalide);

Un enum permettant de savoir à quelle type de pièce nous faisons face.
	typedef enum t_piece(sans , pion , dame) ;

Un enum permettant de savoir l'équipe d'un joueur et donc de connaître le statut en 2 joueur 
	typedef enum t_equipe(aucune, equipe_1, equipe_2) ;

Un enum regroupant les lettres servant à L'affichage.
	typedef enum {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q}t_lettre;

Une structure gerant la position des cases et pieces
	typedef struct {int x; int y}t_coordonnees;
	
Une structure contenant les infos du contenu de chaque case
	typedef struct {t_joueur joueur; t_piece piece; t_equipe equipe} t_contenu;
	
Une structure case, établie à partir des coordonnées et du contenue. Elle compose le plateau
	typedef struct {t_coordonnees coordonnees; t_contenu contenu} t_case;
	
Une structure Stats, permettant le retour des statistiques en fin de partie
	typedef struct {char nom[20]; int pions_pris; int pions_perdus; int nb_coup} t_stats;
	
Les Stats sont définies en variables globales, pouvant etre reutilisées partout	
	t_stats statsj2;
	t_stats statsj3;
	t_stats statsj4;

Definition du plateau, sur lequel sera basé le programme
	t_contenu plateau[Z][Z];

Definition de deux listes, l'une repertoriant les coups disponibles, l'autre les coups forcés 
	t_liste ls_coup_d;
	t_liste ls_coup_f;
	
2 –  Fonctions

Utilisées dans plateau.c:

void ChangeJoueur(int l, int c,t_joueur nouv); change la valeur de joueur à un emplacement donné
int litJoueur(int l,int c); retourne la valeur de joueur à un emplacement donné
void DeplaAjout(int l, int c,t_liste* ls_coup); Ajoute à la liste prise en parametre le déplacement vers les coordonnées données
int dispoPion(t_coordonnees coor,t_liste *ls_coup_d); retourne 1 si au moin 1 pion peut jouer, et indique à quel endroit 
int dispoDame(t_coordonnees coor,t_liste *ls_coup_d); retourne 1 si au moin 1 dame peut jouer, et indique à quel endroit
void creerDame(t_coordonnees coor); verifie si une dame peut etre créée suite à un deplacement, et la créée si possible 
void viderContenu(t_contenu contenu); Vide le contenu de la case selectionnée
void InitCase(int l,int c,t_joueur j); initialise la case selectionnée
void init(); initialise le plateau à l'aide de InitCase
void afficher(); Affiche le damier 
int coupForce(t_joueur j,t_liste* ls_coup_arr, t_liste* ls_coup_dep); retourne 1 si au moin un coup est obligatoire, et liste leur point de depart ainsi que leur point d'arrivée
int coupDispo(t_coordonnees coor,t_joueur j,t_liste* ls_coup_d);  retourne 1 si au moin un coup est possible, et les liste    
void deplacerPiece(t_coordonnees dep,t_coordonnees arriv); deplace la piece choisie à l'emplacement selectionné
void prendrePiece(t_coordonnees dep,t_coordonnees arriv); prends la piece située entre l'arrivée et le depart 
void switchCoord( int x, int y); transforme deux int en un t_coordonnees
void tourner(); fais tourner le plateau de 90°

utilisées dans joueur.c:

int convertir(char carac); convertis un caractère en entier
t_coordonnees traiteEntree(char c_colonne, int ligne); fonction qui traite ce que l'utilisateur a entré
void afficherLettre (t_lettre lettre); prends en entier le type enum lettre, et affiche la lettre correspondante
t_coordonnees choisir(t_liste * ls_coup, t_joueur joueur); Fonction qui affiche les choix possibles et demande à l'utilisateur de choisir un coup
void jouerTour(t_joueur joueur); Fonction qui exécute le tour d'un joueur entré en paramètre
void deroulementPartie(void); Fonction qui s'occupe de la gestion des tours entre différents joueur

utilisées dans jeu.c:


int hors_plateau(int i, int j); fonction retournant 1 si les coordonnées en paramètre sont hors plateau (dans une case invalide ou non existante)
int verifierDefaite(); fonction qui retourne le numéro du joueur perdant, s'il y en a un
void ajoutListe(t_coordonnees coord, t_joueur joueur, t_piece piece, t_liste* liste); fonction ajoutant les valeurs en paramètre à la liste en paramètre
int peutPrendrepion(t_coordonnees coord, t_joueur joueur,t_liste* ls_coup_arr, t_liste* ls_coup_dep); fonction renvoyant 1 si le pion aux coordonnées passées en paramètre peut prendre un pion adjacent. ajoute ensuite dans la liste toutes les coordonnées d'arrivées possibles
int peutPrendredame(t_coordonnees coord, t_joueur joueur,t_liste* ls_coup_arr, t_liste* ls_coup_dep); fonctionne comme peutPrendrepion, mais avec une dame
int peutPrendre(t_coordonnees coord, t_joueur joueur,t_liste* ls_coup_arr, t_liste* ls_coup_dep); fonction qui appelle les deux fonctions précédentes et renvoie 1 si la pièce aux coordonnées passées en paramètre peut prendre une autre piece
int depPossible(t_joueur joueur); retourne 1 si le joueur en paramètre peut déplacer au moins une pièce, s'il ne peut pas, il perd la partie
int partieFinie(int joueur); retourne le numéro du joueur ayant perdu, s'il y en a un
void afficherStats(); affiche les statistiques pour tous les joueurs
void finPartie(int joueur); affiche à l'écran que la partie est finie, en disant pourquoi, et affiche les stats de fin de partie
void reinitStatsJoueur(t_joueur joueur); réinitialise les statistiques d'un joueur
void reinitStats(); réinitialise les statistiques de tous les joueurs
void statPionpris(t_joueur joueur); incrémente le nombre de pions pris par le joueur en paramètre
void statPionperdu(t_joueur joueur); incrémente le nombre de pions perdus par le joueur en paramètre
void statDep(t_joueur joueur); incrémente le nombre de déplacement effectués par le joueur en paramètre


schéma des fonctions:

3 -  Structure de fichiers

plateau.c / plateau.h
	-plateau's management
	-pion's movement
joueur.c / joueur.h
	-player's interaction
game.c / game.h
	-win / loss condition
	-other game rules
main.c

[gitter](https://gitter.im/multi-checkers/Lobby?utm_source=share-link&utm_medium=link&utm_campaign=share-link)
