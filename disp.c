#include <stdio.h>
#include <stdlib.h>
#include "include/liste_ptr.h"
#include "include/struct.h"
#include "include/jeu.h"
#include "include/joueur.h"
#include "include/plateau.h"
#include "include/disp.h"
#include "SDL2-2.0.5/i686-w64-mingw32/include/SDL2/SDL.h"
#include "SDL2-2.0.5/i686-w64-mingw32/include/SDL2/SDL_image.h"
#include "SDL2-2.0.5/i686-w64-mingw32/include/SDL2/SDL_ttf.h"

SDL_Window* pWindow;
SDL_Surface *pSprite_menu, *pSprite_bpartielocale, *pSprite_bpartiereseau, *pSprite_bcharger, *pSprite_bregles, *pSprite_bquitter, *pSprite_bquitter2;
SDL_Renderer *pRenderer;
SDL_Texture *pTexture_menu, *pTexture_bpartielocale, *pTexture_bpartiereseau, *pTexture_bcharger, *pTexture_bregles, *pTexture_bquitter, *pTexture_bquitter2;
SDL_Event event;


void bouton_partielocale(SDL_Rect d_menu){
    int i = 1;
    if(event.motion.x >593 && event.motion.x < 800 && event.motion.y >100 && event.motion.y < 150){


        while(event.motion.x >593 && event.motion.x < 800 && event.motion.y >100 && event.motion.y < 150 && i){
            SDL_Rect d_bpartielocale = { 696 - pSprite_bpartielocale->w/2,125 - pSprite_bpartielocale->h/2, pSprite_bpartielocale->w, pSprite_bpartielocale->h};
            SDL_RenderCopy(pRenderer,pTexture_bpartielocale,NULL,&d_bpartielocale);
            SDL_RenderPresent(pRenderer);
            SDL_PollEvent(&event);
            if (event.button.button==1){

                if (event.type==SDL_MOUSEBUTTONDOWN){
                    i = 0;
                }


            }
        }
        if (event.type==SDL_MOUSEBUTTONUP){
            i = 1;
        }
        if(!i){
            menu_afficher(d_menu);
            menu_choix(1);
        }
        menu_afficher(d_menu);
    }
}

void bouton_partiereseau(SDL_Rect d_menu){
    int i = 1;
    if(event.motion.x >593 && event.motion.x < 800 && event.motion.y >200 && event.motion.y < 250){


        while(event.motion.x >593 && event.motion.x < 800 && event.motion.y >200 && event.motion.y < 250 && i){
            SDL_Rect d_bpartiereseau = { 696 - pSprite_bpartiereseau->w/2,225 - pSprite_bpartiereseau->h/2, pSprite_bpartiereseau->w, pSprite_bpartiereseau->h};
            SDL_RenderCopy(pRenderer,pTexture_bpartiereseau,NULL,&d_bpartiereseau);
            SDL_RenderPresent(pRenderer);
            SDL_PollEvent(&event);
            if (event.button.button==1){

                if (event.type==SDL_MOUSEBUTTONDOWN){
                    i = 0;
                }


            }
        }
        if (event.type==SDL_MOUSEBUTTONUP){
            i = 1;
        }
        if(!i){
            menu_afficher(d_menu);
            menu_choix(2);
        }
        menu_afficher(d_menu);
    }
}

void bouton_charger(SDL_Rect d_menu){
    int i = 1;
    if(event.motion.x >593 && event.motion.x < 800 && event.motion.y >300 && event.motion.y < 350){


        while(event.motion.x >593 && event.motion.x < 800 && event.motion.y >300 && event.motion.y < 350 && i){
            SDL_Rect d_bcharger = { 696 - pSprite_bcharger->w/2,325 - pSprite_bcharger->h/2, pSprite_bcharger->w, pSprite_bcharger->h};
            SDL_RenderCopy(pRenderer,pTexture_bcharger,NULL,&d_bcharger);
            SDL_RenderPresent(pRenderer);
            SDL_PollEvent(&event);
            if (event.button.button==1){

                if (event.type==SDL_MOUSEBUTTONDOWN){
                    i = 0;
                }

            }
        }
        if (event.type==SDL_MOUSEBUTTONUP){
            i = 1;
        }
        if(!i){
            menu_afficher(d_menu);
            menu_choix(3);
        }
        menu_afficher(d_menu);
    }
}

void bouton_regles(SDL_Rect d_menu){
    int i = 1;
    if(event.motion.x >593 && event.motion.x < 800 && event.motion.y >400 && event.motion.y < 450){


        while(event.motion.x >593 && event.motion.x < 800 && event.motion.y >400 && event.motion.y < 450 && i){
            SDL_Rect d_bregles = { 696 - pSprite_bregles->w/2,425 - pSprite_bregles->h/2, pSprite_bregles->w, pSprite_bregles->h};
            SDL_RenderCopy(pRenderer,pTexture_bregles,NULL,&d_bregles);
            SDL_RenderPresent(pRenderer);
            SDL_PollEvent(&event);
            if (event.button.button==1){

                if (event.type==SDL_MOUSEBUTTONDOWN){
                    i = 0;
                }


            }
        }
        if (event.type==SDL_MOUSEBUTTONUP){
            i = 1;
        }
        if(!i){
            menu_afficher(d_menu);
            menu_choix(4);
        }
        menu_afficher(d_menu);
    }
}

void bouton_quitter(SDL_Rect d_menu,int *i){

    if(event.motion.x >50 && event.motion.x < 235 && event.motion.y >500 && event.motion.y < 550){

                SDL_Rect d_bquitter = { 142 - pSprite_bquitter->w/2,525 - pSprite_bquitter->h/2, pSprite_bquitter->w, pSprite_bquitter->h};
                SDL_RenderCopy(pRenderer,pTexture_bquitter,NULL,&d_bquitter);
                SDL_RenderPresent(pRenderer);

                while((event.motion.x >50 && event.motion.x < 235 && event.motion.y >500 && event.motion.y < 550)&& *cont){

                    SDL_PollEvent(&event);
                    if (event.button.button==1){


                        if (event.type==SDL_MOUSEBUTTONDOWN) *i=0;

                    }
                }
                if (event.type==SDL_MOUSEBUTTONUP) *i=1;
                menu_afficher(d_menu);
        }


}

void menu_afficher(SDL_Rect d_menu){

    SDL_RenderCopy(pRenderer,pTexture_menu,NULL,&d_menu);
    SDL_RenderPresent(pRenderer);
}

void init_image(){


    pWindow = SDL_CreateWindow("multidames", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);


    pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);



    pSprite_menu = IMG_Load("./image/menu.png");
    pTexture_menu = SDL_CreateTextureFromSurface(pRenderer,pSprite_menu);

    pSprite_bpartielocale = IMG_Load("./image/btepartielocale.png");
    pTexture_bpartielocale = SDL_CreateTextureFromSurface(pRenderer,pSprite_bpartielocale);

    pSprite_bpartiereseau = IMG_Load("./image/btepartiereseau.png");
    pTexture_bpartiereseau = SDL_CreateTextureFromSurface(pRenderer,pSprite_bpartiereseau);

    pSprite_bcharger = IMG_Load("./image/btecharger.png");
    pTexture_bcharger = SDL_CreateTextureFromSurface(pRenderer,pSprite_bcharger);

    pSprite_bregles = IMG_Load("./image/bteregles.png");
    pTexture_bregles = SDL_CreateTextureFromSurface(pRenderer,pSprite_bregles);

    pSprite_bquitter = IMG_Load("./image/btequitter.png");
    pTexture_bquitter = SDL_CreateTextureFromSurface(pRenderer,pSprite_bquitter);

    pSprite_bquitter2 = IMG_Load("./image/quitter2.png");
    pTexture_bquitter2 = SDL_CreateTextureFromSurface(pRenderer,pSprite_bquitter2);
}

void detruire_image(){
    SDL_DestroyTexture(pTexture_menu);
    SDL_FreeSurface(pSprite_menu);

    SDL_DestroyRenderer(pRenderer);

    SDL_DestroyTexture(pTexture_bquitter);
    SDL_FreeSurface(pSprite_bquitter);

    SDL_DestroyTexture(pTexture_bpartielocale);
    SDL_FreeSurface(pSprite_bpartielocale);

    SDL_DestroyTexture(pTexture_bquitter2);
    SDL_FreeSurface(pSprite_bquitter2);

    SDL_DestroyWindow(pWindow);
}

int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }
    TTF_Init();
    init_image();



    SDL_Rect d_menu = { 800/2 - pSprite_menu->w/2,600/2 - pSprite_menu->h/2, pSprite_menu->w, pSprite_menu->h};
    menu_afficher(d_menu);


    int i = 1;
    while (i){

        if ( SDL_PollEvent(&event) ){

            bouton_partielocale(d_menu);

            bouton_partiereseau(d_menu);

            bouton_charger(d_menu);

            bouton_regles(d_menu);

            bouton_quitter(d_menu, &i);

        }
    }

    detruire_image();
    TTF_Quit();
    SDL_Quit();
    return 0;
}
