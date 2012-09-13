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

#ifndef DEF_AFFICHAGEH
#define DEF_AFFICHAGEH

//Prototypes des fonctions :
void creer_Allumettes (SDL_Surface *ecran, int n, SDL_Surface *allumette, SDL_Rect pos[]) ;
void blit_Allumettes (int n, SDL_Surface *allumette, SDL_Rect pos[], SDL_Surface ecran) ;
void afficher_menu (SDL_Surface *ecran, Bouton menu[], int nb_joueurs, int difficulte) ;
int souris_dans_surface (SDL_Event event, Bouton *bout) ;
void encadre (Bouton *bout, SDL_Surface *ecran) ;
void afficher_jeu (SDL_Surface *ecran, int nb_All, SDL_Surface *allumette, SDL_Rect posAll[], int nb_tours, int nb_joueurs, int info_ia[3]) ;
void afficher_choix_ia (int n, SDL_Surface *ercan, int info_ia[3]) ;
void afficher_gagnant(int nb_joueurs, int nb_tours, SDL_Surface *ecran, int cont) ;
void quitter (int *cont, SDL_Surface *ecran) ;
void aide (SDL_Surface *ecran, int *cont) ;
void printTexte (SDL_Surface *ecran, char texte[], SDL_Rect *pos) ;

#endif
