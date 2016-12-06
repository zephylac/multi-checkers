#ifndef H_GL_STRUCT
#define H_GL_STRUCT

///\define 
#define Z 17

/**
 * \enum t_joueur
 * \brief Enum contenant la valeur du joueur
 */
typedef enum {
	vide,	/*!< Si la case est vide */
       	joueur1,/*!< Si c'est le joueur 1 */
       	joueur2,/*!< Si c'est le joueur 2 */
       	joueur3,/*!< Si c'est le joueur 3 */
       	joueur4,/*!< Si c'est le joueur 4 */
       	invalide/*!< Si la case est invalide */
}
t_joueur;


/**
 * \enum t_piece
 * \brief Enum contenant le type de la pièce
 */
typedef enum {
	sans,	/*!< Si la case est vide */
       	pion,	/*!< Si c'est un pion */
       	dame	/*!< Si c'est une dame */
}
t_piece;


/**
 * \enum t_equipe
 * \brief Enum contenant la valeur de l'équipe
 */
typedef enum {
	aucune,	/*!< Si la case est vide */
       	equipe1,/*!< Si le pion appartient à l'équipe 1 */
       	equipe2	/*!< Si le pion appartient à l'équipe 2 */
}
t_equipe;


/**
 * \enum t_lettre
 * \brief Enum contenant la valeur lié à une lettre
 */
typedef enum {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q}t_lettre;


/**
 * \struct t_coordonnees	
 * \brief Structure de coordonnées 
 */
typedef struct {
	int x;	/*< Valeur contenu sur l'axe x */
       	int y;	/*< Valeur contenu sur l'axe y */ 
}
t_coordonnees;


/**
 * \struct t_choix
 * \brief Structure de coordonnées de départ et d'arrivée
 */ 
typedef struct {
	t_coordonnees dep;	/*< Valeur contenant les coordonnées de départs */ 
       	t_coordonnees arr;	/*< Valeur contenant les coordonnées de d'arrivées */
}				
t_choix;


/**
 * \struct t_contenu	
 * \brief Structure d'une case contenant un joueur, une pièce ainsi qu'une équipe
 */
typedef struct {
	t_joueur joueur;	/*< Valeur du joueur */
       	t_piece piece;		/*< Valeur de la pièce */
       	t_equipe equipe;	/*< Valeur de l'équipe */
}
t_contenu;


/**
 * \struct t_case	
 * \brief Structure contenant les coordonnées d'une cases ainsi que sa valeur
 */
typedef struct {
	t_coordonnees coordonnees;	/*< Coordonnées de la case */
       	t_contenu contenu;		/*< Valeur contenu dans la case */
}
t_case;


/*
 * \struct t_stats struct.h	
 * \brief Structure contenant les statistique d'un joueur
 */
typedef struct {
	char nom[20];		/*< Nom du joueur */
       	int pions_pris;		/*< Le nombre de pion pris */
       	int pions_perdus;	/*< Le nombre de pion perdu */
       	int nb_coup;		/*< Le nombre de coup effectué */
}
t_stats;


/**
 * \struct t_element struct.h	
 * \brief Structure contenant une case ainsi que le lien pour connaître la suivante de même que la précédente.Utile pour l'utilisation d'une liste
 */
typedef struct element{
	t_case valeur;		/*< Coordonnées et contenu de la case */
       	struct element * pred;	/*< Lien vers la case précédente */
       	struct element * succ;	/*< Lien vers la case suivante */
}
t_element;


/**
 * \struct t_liste struct.h	
 * \brief Structure contenant le drapeau et l'élément courant. Utile pour l'utilisation d'une liste
 */
typedef struct {
	t_element * drapeau;	/*< Element du drapeau */
	t_element * ec;		/*< Element de l'élément courant */
}
t_liste;


t_stats statsj1;
t_stats statsj2;
t_stats statsj3;
t_stats statsj4;


t_contenu plateau[Z][Z];
t_liste ls_coup_dep;
t_liste ls_coup_arr;

#endif
