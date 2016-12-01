#ifndef H_GL_STRUCT
#define H_GL_STRUCT

#define Z 17

typedef enum {vide, joueur1, joueur2, joueur3, joueur4, invalide}t_joueur;
typedef enum {sans, pion, dame}t_piece;
typedef enum {aucune, equipe1, equipe2}t_equipe;
typedef enum {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q}t_lettre;

typedef struct {int x; int y;}t_coordonnees;
typedef struct {t_coordonnees dep; t_coordonnees arr} t_choix;
typedef struct {t_joueur joueur; t_piece piece; t_equipe equipe;} t_contenu;
typedef struct {t_coordonnees coordonnees; t_contenu contenu;} t_case;
typedef struct {char nom[20]; int pions_pris; int pions_perdus; int nb_coup;} t_stats;

typedef struct element{t_case valeur; struct element * pred; struct element * succ;}t_element;
typedef struct {t_element * drapeau;t_element * ec;}t_liste;

t_stats statsj1;
t_stats statsj2;
t_stats statsj3;
t_stats statsj4;


t_contenu plateau[Z][Z];
t_liste ls_coup_dep;
t_liste ls_coup_arr;

#endif
