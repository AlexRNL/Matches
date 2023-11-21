/*
Copyright (C) 2008 Barféty Alex

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

/*Fonctions qui gère les commandes du jeu*/

//Fonction qui gère l'intelligence artificielle du jeu :
int intelligence_artificielle (int allumettes, int difficulte)
{
    int res = 0 ;
    do
    {
        switch (difficulte)
        {
               case 0 : res = rand()%(3) + 1 ;
                        break ;
               case 1 : if (allumettes > 8) {res = rand()%(3) + 1 ;}
                        else {res = ia_parfaite (allumettes) ;}
                        break ;
               case 2 : if (allumettes > 12) {res = rand()%(3) + 1 ;}
                        else {res = ia_parfaite (allumettes) ;}
                        break ;
               case 3 : res = ia_parfaite (allumettes) ;
                        break ;
        }
    } while (res>=allumettes) ;
    return res ;
}

int ia_parfaite (int allumettes)
{
    int res = 0 ;
    switch (allumettes%4)
    {
           case 0 : res = 3 ;
                    break ;
           case 1 : res = rand()%(3) + 1 ;
                    break ;
           case 2 : res = 1 ;
                    break ;
           case 3 : res = 2 ;
                    break ;
    }
    return res ;
}

int choix_joueur(int nb_All, int *cont, SDL_Surface *ecran, SDL_Surface *allumette, SDL_Rect posAllumette[], int nb_t, int nb_j, int info_ia[3])
{
    SDL_Event event ;
    int cont2 = 1, nb_enl = 40 ;
    while ((cont2 || (nb_All<=nb_enl)) && *cont)
    {
        afficher_jeu(ecran, nb_All, allumette, posAllumette, nb_t, nb_j, info_ia) ;
        SDL_WaitEvent(&event) ;
        switch (event.type)
        {
            case SDL_QUIT : quitter(cont, ecran) ;
                            break ;
            case SDL_KEYDOWN : switch (event.key.keysym.sym)
                               {
                                    case SDLK_ESCAPE : quitter(cont, ecran) ;
                                                       break ;
                                    case SDLK_KP1 : nb_enl = 1 ;
                                                    cont2 = 0 ;
                                                    break ;
                                    case SDLK_KP2 : nb_enl = 2 ;
                                                    cont2 = 0 ;
                                                    break ;
                                    case SDLK_KP3 : nb_enl = 3 ;
                                                    cont2 = 0 ;
                                                    break ;
                                    case SDLK_1 : nb_enl = 1 ;
                                                  cont2 = 0 ;
                                                  break ;
                                    case SDLK_2 : nb_enl = 2 ;
                                                  cont2 = 0 ;
                                                  break ;
                                    case SDLK_3 : nb_enl = 3 ;
                                                  cont2 = 0 ;
                                                  break ;
                                    default : break ;
                                }
                                break ;
            default : break ;
        }
    }
    return nb_enl ;
}
