/*
Copyright (C) 2008 Barf�ty Alex

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "main.h"

/*Jeu des alumettes : un nombre (al�atoire ou pas) d'alumettes est disponible, le joueur peut prendre
entre 1 et 3 alumettes par tours. Celui qui prend la derni�re perd !!*/

/*A ajouter :
    - am�liorer le graphismes des allumettes.
    - VERIFIER LES LIBERATIONS DE MEMOIRE !!
    - un "g�nerique".
    - une installation.
    - des sons ?
*/

int main(int argc, char *argv[])
{
    //      DECLARATION DES VARIABLES
    int nb_joueurs = 1, info_ia[3], nb_Allumettes = 0, nb_All_enlever = 0, nb_tours = 0, difficulte = 1, cont = 1, cont1 = 1 ;
    SDL_Surface *ecran = NULL, *allumette = NULL ;
    SDL_Rect *posAllumette = NULL ;
    SDL_Event event ;
    Bouton menu[11] ;


    //      INITIALISATION
    srand(time(NULL)) ;
    SDL_Init(SDL_INIT_VIDEO) ;
    SDL_WM_SetIcon(SDL_LoadBMP("images/icone.bmp"), NULL) ;
    SDL_WM_SetCaption("Allumettes", NULL) ;
    SDL_EnableKeyRepeat(30, 20) ;
    TTF_Init() ;

    //D�termination du nombre d'allumettes
    if (NB_ALLUMETTES <= 0 || NB_ALLUMETTES > 32) {nb_Allumettes = rand()%(17) + 16 ;}
    else {nb_Allumettes = NB_ALLUMETTES ;}

    //Allocation dynamique du tableau d'allumettes
    posAllumette = malloc(nb_Allumettes * sizeof(SDL_Rect)) ;

    //Initialisation de l'�cran
    ecran = SDL_SetVideoMode(800, 550, 32, SDL_SWSURFACE) ;
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0)) ;

    //Initialisation des allumettes
    allumette = SDL_CreateRGBSurface(SDL_SWSURFACE, 5, 100, 32, 0, 0, 0, 0) ;
    SDL_FillRect(allumette, NULL, SDL_MapRGB(allumette->format, 175, 147, 7)) ;
    //allumette = IMG_Load("images\allumettes 1.jpg") ;

    //      MENU PRINCIPAL
    while (cont && cont1)
    {
        afficher_menu(ecran, menu, nb_joueurs, difficulte) ;
        SDL_WaitEvent(&event) ;
        switch (event.type)
        {
            case SDL_QUIT : quitter(&cont, ecran) ;
                            break ;
            case SDL_KEYDOWN : switch (event.key.keysym.sym)
                               {
                                   case SDLK_ESCAPE : quitter(&cont, ecran) ;
                                                      break ;
                                   case SDLK_RETURN : cont1 = 0 ;
                                                      encadre(&menu[9], ecran) ;
                                                      SDL_Flip(ecran) ;
                                                      SDL_Delay(128) ;
                                                      break ;
                                   case SDLK_KP_ENTER : cont1 = 0 ;
                                                        encadre(&menu[9], ecran) ;
                                                        SDL_Flip(ecran) ;
                                                        SDL_Delay(128) ;
                                                        break ;
                                   case SDLK_j : nb_joueurs = 1 + nb_joueurs%2 ; //Changer le nombre de joueurs au clavier
                                                 break ;
                                   case SDLK_d : difficulte = (1 + difficulte)%4 ; //Changer la difficult� au clavier
                                                 break ;
                                   case SDLK_F1 : aide(ecran, &cont) ;
                                                  break ;
                                   default : break ;
                               }
            case SDL_MOUSEBUTTONUP : if (event.button.button == SDL_BUTTON_LEFT)
                                     {
                                         if (souris_dans_surface(event, &menu[9]))
                                         {
                                             cont1 = 0 ;
                                             encadre(&menu[9], ecran) ;
                                             SDL_Flip(ecran) ;
                                             SDL_Delay(350) ;
                                         }
                                         if (souris_dans_surface(event, &menu[2]))
                                         {
                                            nb_joueurs = 1 ;
                                         }
                                         if (souris_dans_surface(event, &menu[3]))
                                         {
                                             nb_joueurs = 2 ;
                                         }
                                         if (souris_dans_surface(event, &menu[5]))
                                         {
                                             difficulte = 0 ;
                                         }
                                         if (souris_dans_surface(event, &menu[6]))
                                         {
                                             difficulte = 1 ;
                                         }
                                         if (souris_dans_surface(event, &menu[7]))
                                         {
                                             difficulte = 2 ;
                                         }
                                         if (souris_dans_surface(event, &menu[8]))
                                         {
                                             difficulte = 3 ;
                                         }
                                         if (souris_dans_surface(event, &menu[10]))
                                         {
                                             aide(ecran, &cont) ;
                                         }
                                     }
        }
    }


    //      JEU
    SDL_EnableKeyRepeat(0,0) ;
    while (cont && (nb_Allumettes != 1))
    {
          creer_Allumettes(ecran, nb_Allumettes, allumette, posAllumette) ;
          switch (nb_tours%2)
          {
              case 0 : nb_All_enlever = choix_joueur(nb_Allumettes, &cont, ecran, allumette, posAllumette, nb_tours, nb_joueurs, info_ia) ;
                       break ;
              case 1 : afficher_jeu(ecran, nb_Allumettes, allumette, posAllumette, nb_tours, nb_joueurs, info_ia) ;
                       if (nb_joueurs == 1) //Selon le nombre de joueur(s)...
                       {
                           nb_All_enlever = intelligence_artificielle(nb_Allumettes, difficulte) ;
                           event.type = SDL_MOUSEBUTTONDOWN ;
                           afficher_choix_ia(nb_All_enlever, ecran, info_ia) ;
                           SDL_Delay(500) ;
                           /*while (event.type != SDL_KEYDOWN && cont)
                           {
                                SDL_WaitEvent(&event) ;
                                if (event.type == SDL_QUIT) {quitter(&cont, ecran) ;}
                           }*/
                           break ;
                       }
                       else
                       {
                           nb_All_enlever = choix_joueur(nb_Allumettes, &cont, ecran, allumette, posAllumette, nb_tours, nb_joueurs, info_ia) ;
                       }
          }
          nb_Allumettes -= nb_All_enlever ;
          nb_tours++ ;
    }
    if (cont)
    {
        afficher_jeu(ecran, nb_Allumettes, allumette, posAllumette, nb_tours, nb_joueurs, info_ia) ;
        afficher_gagnant(nb_joueurs, nb_tours, ecran, cont) ;
    }

    //Lib�rations...
    free(posAllumette) ;
    SDL_FreeSurface(allumette) ;
    TTF_Quit() ;
    SDL_Quit() ;
    return EXIT_SUCCESS ;
}
