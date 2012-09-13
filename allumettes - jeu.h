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

#ifndef DEF_JEUH
#define DEF_JEUH

//Prototypes des fonctions :
int intelligence_artificielle (int allumettes, int difficulte) ;
int ia_parfaite (int allumettes) ;
int choix_joueur(int nb_All, int *cont, SDL_Surface *ecran, SDL_Surface *allumette, SDL_Rect posAllumette[], int nb_t, int nb_j, int info_ia[3]) ;

#endif
