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

/*Contient les fonctions qui g�rent l'affichage*/

//Fonction qui cr�e des allumettes dans un tableau :
void creer_Allumettes (SDL_Surface *ecran, int n, SDL_Surface *allumette, SDL_Rect pos[])
{
    int i, esp = 20 ;
    for (i=0 ; i<n ; i++)
    {
        allumette = SDL_CreateRGBSurface(SDL_SWSURFACE, 5, 100, 32, 0, 0, 0, 0) ;
        SDL_FillRect(allumette, NULL, SDL_MapRGB(allumette->format, 175, 147, 7)) ;
    }
    pos[0].x = (ecran->w - n*allumette->w - (n-1)*esp)/2 ;
    pos[0].y = ecran->h/2 - allumette->h/2 ;
    for (i=1 ; i<n ; i++)
    {
        pos[i].x = pos[0].x + i*(allumette->w+esp) ;
        pos[i].y = pos[0].y ;
    }
}


//Fonction qui blitte les allumettes :
void blit_Allumettes (int n, SDL_Surface *allumette, SDL_Rect pos[], SDL_Surface ecran)
{
    int i ;
    for (i=0 ; i<n ; i++)
    {
        SDL_BlitSurface(allumette, NULL, &ecran, &pos[i]) ;
    }
}

//Affiche le menu :
void afficher_menu (SDL_Surface *ecran, Bouton menu[], int nb_joueurs, int difficulte)
{
    int i = 0, esp1, esp2 ;
    SDL_Surface *fond = NULL ;
    SDL_Color noir = {0, 0, 0}, rouge = {255, 0, 0}, vert = {0, 255, 0}, bleu = {0, 0, 255} ;
    SDL_Rect posFond ;

    //Chargement de l'image :
    fond = IMG_Load("images/feu.jpg") ;

    //Cr�ation des polices
    menu[0].police = TTF_OpenFont("polices/firestarter.ttf", 100) ;
    for (i=1 ; i<9 ; i++)
    {
        menu[i].police = TTF_OpenFont("polices/arial.ttf", 48) ;
    }
    menu[9].police = TTF_OpenFont("polices/angelina.ttf", 60) ;
    menu[10].police = TTF_OpenFont("polices/arial.ttf", 14) ;

    //Cr�ation des textes :
    menu[0].texte = TTF_RenderText_Blended(menu[0].police, "ALLUMETTES", noir) ;
    menu[1].texte = TTF_RenderText_Blended(menu[1].police, "Nombre de joueur(s) :", noir) ;
    menu[2].texte = TTF_RenderText_Blended(menu[2].police, "1", noir) ;
    menu[3].texte = TTF_RenderText_Blended(menu[3].police, "2", noir) ;
    menu[4].texte = TTF_RenderText_Blended(menu[4].police, "Niveau IA :", noir) ;
    menu[5].texte = TTF_RenderText_Blended(menu[5].police, "0", vert) ;
    menu[6].texte = TTF_RenderText_Blended(menu[6].police, "1", bleu) ;
    menu[7].texte = TTF_RenderText_Blended(menu[7].police, "2", rouge) ;
    menu[8].texte = TTF_RenderText_Blended(menu[8].police, "3", noir) ;
    menu[9].texte = TTF_RenderText_Blended(menu[9].police, "OK", noir) ;
    menu[10].texte = TTF_RenderText_Blended(menu[10].police, "Besoin d'aide ? F1", noir) ;

    //Calcul des espaces :
    esp1 = (ecran->w - menu[1].texte->w - menu[2].texte->w - menu[3].texte->w) / 5 ;
    esp2 = (ecran->w - menu[4].texte->w - menu[5].texte->w - menu[6].texte->w - menu[7].texte->w - menu[8].texte->w) / 7 ;

    //Assignation des positions :
    posFond.x = 0 ;
    posFond.y = 0 ;
    menu[0].position.x = ecran->w/2 - menu[0].texte->w/2 ; //Erreur !!!
    menu[0].position.y = 5 ;
    menu[1].position.x = esp1 ;
    menu[1].position.y = 175 ;
    menu[2].position.x = 3*esp1 + menu[1].texte->w ;
    menu[2].position.y = menu[1].position.y ;
    menu[3].position.x = 4*esp1 + menu[1].texte->w + menu[2].texte->w ;
    menu[3].position.y = menu[1].position.y ;
    menu[4].position.x = esp2 ;
    menu[4].position.y = 350 ;
    menu[5].position.x = 3*esp2 + menu[4].texte->w ;
    menu[5].position.y = menu[4].position.y ;
    menu[6].position.x = 4*esp2 + menu[4].texte->w + menu[5].texte->w ;
    menu[6].position.y = menu[4].position.y ;
    menu[7].position.x = 5*esp2 + menu[4].texte->w + menu[5].texte->w + menu[6].texte->w ;
    menu[7].position.y = menu[4].position.y ;
    menu[8].position.x = 6*esp2 + menu[4].texte->w + menu[5].texte->w + menu[6].texte->w + menu[7].texte->w ;
    menu[8].position.y = menu[4].position.y ;
    menu[9].position.x = ecran->w - menu[9].texte->w - 20 ;
    menu[9].position.y = ecran->h - menu[9].texte->h - 5 ;
    menu[10].position.x = 5 ;
    menu[10].position.y = ecran->h - menu[10].texte->h -5 ;

    //Blittages :
    SDL_BlitSurface(fond, NULL, ecran, &posFond) ;
    for (i=0 ; i<11 ; i++)
    {
        if (!(nb_joueurs == 2 && i<9 && i>3))
        {
            SDL_BlitSurface(menu[i].texte, NULL, ecran, &menu[i].position) ;
        }
    }
    encadre(&menu[1+nb_joueurs], ecran) ;
    if (nb_joueurs == 1)
    {
        encadre(&menu[5+difficulte], ecran) ;
    }
    SDL_RenderPresent(ecran) ;

    //Lib�ration :
    for (i=0 ; i<11 ; i++)
    {
        TTF_CloseFont(menu[i].police) ;
        SDL_FreeSurface(menu[i].texte) ;
    }
    SDL_FreeSurface(fond) ;
}

//Retourne 1 si la souris est dans le bouton :
int souris_dans_surface (SDL_Event event, Bouton *bout)
{
    int haut = 0, bas = 0, gauche = 0, droite = 0 ;
    haut = bout->position.y - 3 ;
    bas = bout->position.y + bout->texte->h + 3 ;
    gauche = bout->position.x - 6 ;
    droite = bout->position.x + bout->texte->w + 6 ;
    if (gauche<event.motion.x && event.motion.x<droite && haut<event.motion.y && event.motion.y<bas)
    {
         return 1 ;
    }
    else
    {
        return 0 ;
    }
}

//Encadre un bouton :
void encadre (Bouton *bout, SDL_Surface *ecran)
{
    SDL_Surface *larg = NULL, *haut=NULL ;
    SDL_Rect larg1, larg2, haut1, haut2 ;

    //Cr�ation d'une largeur et d'une hauteur :
    larg = SDL_CreateRGBSurface(SDL_SWSURFACE, bout->texte->w + 12, 2, 32, 0, 0, 0, 0) ;
    haut = SDL_CreateRGBSurface(SDL_SWSURFACE, 2, bout->texte->h + 6, 32, 0, 0, 0, 0) ;
    SDL_FillRect(larg, NULL, SDL_MapRGB(larg->format, 255, 255, 255)) ;
    SDL_FillRect(haut, NULL, SDL_MapRGB(haut->format, 255, 255, 255)) ;

    //Calcul des positions :
    larg1.x = bout->position.x - 6 ;
    larg1.y = bout->position.y - 3 ;
    haut1.x = larg1.x ;
    haut1.y = larg1.y ;
    larg2.x = larg1.x ;
    larg2.y = larg1.y + haut->h - 2 ;
    haut2.x = haut1.x + larg->w - 2 ;
    haut2.y = haut1.y ;

    //Blittages :
    SDL_BlitSurface(larg, NULL, ecran, &larg1) ;
    SDL_BlitSurface(larg, NULL, ecran, &larg2) ;
    SDL_BlitSurface(haut, NULL, ecran, &haut1) ;
    SDL_BlitSurface(haut, NULL, ecran, &haut2) ;

    //Lib�rations :
    SDL_FreeSurface(larg) ;
    SDL_FreeSurface(haut) ;
}

//Affiche le jeu en cours :
void afficher_jeu (SDL_Surface *ecran, int nb_All, SDL_Surface *allumette, SDL_Rect posAll[], int nb_tours, int nb_joueurs, int info_ia[3])
{
    int i, esp ;
    char all_rest[24] = "" ;
    SDL_Surface *fond = NULL, *triangle[20] ;
    SDL_Rect posFond, posTriangle[20] ;
    Bouton jeu[4] ;
    SDL_Color CouleurTitre = {255, 140, 13}, blanc = {255, 255, 255}, bleu = {0, 0, 255} ;

    //Chargement du fond :
    fond = IMG_Load("images/allumette.jpg") ;
    posFond.x = 0 ;
    posFond.y = 0 ;

    //Chargement des polices :
    jeu[0].police = TTF_OpenFont("polices/firestarter.ttf", 100) ;
    jeu[1].police = TTF_OpenFont("polices/arial.ttf", 38) ;
    for(i=2 ; i<4 ; i++)
    {
        jeu[i].police = TTF_OpenFont("polices/arial.ttf", 28) ;
    }

    //Cr�ation des textes :
    sprintf(all_rest, "Il reste %d allumettes.", nb_All) ;
    jeu[0].texte = TTF_RenderText_Blended(jeu[0].police, "ALLUMETTES", CouleurTitre) ;
    jeu[1].texte = TTF_RenderText_Blended(jeu[1].police, all_rest, blanc) ;
    jeu[2].texte = TTF_RenderText_Blended(jeu[2].police, "Joueur 1", bleu) ;
    switch (nb_joueurs)
    {
        case 1 : jeu[3].texte = TTF_RenderText_Blended(jeu[2].police, "Ordinateur :", bleu) ;
                 break ;
        case 2 : jeu[3].texte = TTF_RenderText_Blended(jeu[3].police, "Joueur 2", bleu) ;
                 break ;
    }

    //Calcul de l'espace (vertical) :
    esp = (ecran->h/2-allumette->h/2-jeu[1].texte->h-jeu[2].texte->h-jeu[3].texte->h)/7 ;

    //Calcul des positions :
    jeu[0].position.x = ecran->w/2 - jeu[0].texte->w/2 ;
    jeu[0].position.y = 5 ;
    jeu[1].position.x = ecran->w/2 - jeu[1].texte->w/2 ;
    jeu[1].position.y = posAll[0].y + allumette->h + 2*esp ;
    jeu[2].position.x = 125 ;
    jeu[2].position.y = jeu[1].position.y + jeu[1].texte->h + 2*esp ;
    jeu[3].position.x = jeu[2].position.x ;
    jeu[3].position.y = jeu[2].position.y + jeu[2].texte->h + esp ;

    //On stocke les valeurs n�cessaire pour afficher plus tard le chiffre de l'ia :
    info_ia[0] = jeu[3].position.y ;
    info_ia[1] = jeu[3].position.x ;
    info_ia[2] = jeu[3].texte->w ;

    //Cr�ation du triangle :
    for (i=0 ; i<20 ; i++)
    {
        triangle[i] = SDL_CreateRGBSurface(SDL_SWSURFACE, 1, 40-2*i, 32, 0, 0, 0, 0) ;
    }
    posTriangle[0].x = jeu[2].position.x - 50 ;
    switch (nb_tours%2)
    {
        case 0 : posTriangle[0].y = jeu[2].position.y + jeu[2].texte->h/2 - triangle[0]->h/2 ;
                 break ;
        case 1 : posTriangle[0].y = jeu[3].position.y + jeu[3].texte->h/2 - triangle[0]->h/2 ;
                 break ;
    }
    for (i=0 ; i<20 ; i++)
    {
        SDL_FillRect(triangle[i], NULL, SDL_MapRGB(triangle[i]->format, 255, 255, 255)) ;
        posTriangle[i].x = posTriangle[0].x + i ;
        posTriangle[i].y = posTriangle[0].y + i ;
    }

    //On r�-efface l'�cran :
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255)) ;

    //Blittage :
    SDL_BlitSurface(fond, NULL, ecran, &posFond) ;
    blit_Allumettes (nb_All, allumette, posAll, *ecran) ;
    for (i=0 ; i<4 ; i++)
    {
        SDL_BlitSurface(jeu[i].texte, NULL, ecran, &jeu[i].position) ;
    }
    for (i=0 ; i<20 ; i++)
    {
        SDL_BlitSurface(triangle[i], NULL, ecran, &posTriangle[i]) ;
    }
    SDL_RenderPresent(ecran) ;

    //Lib�rations :
    for (i=0 ; i<4 ; i++)
    {
        TTF_CloseFont(jeu[i].police) ;
        SDL_FreeSurface(jeu[i].texte) ;
    }
    for (i=0 ; i<20 ; i++)
    {
        SDL_FreeSurface(triangle[i]) ;
    }
    SDL_FreeSurface(fond) ;
}

//Affiche le choix de l'IA en mode un joueur :
void afficher_choix_ia (int n, SDL_Surface *ecran, int info_ia[3])
{
    Bouton chiffre ;
    SDL_Color blanc = {255, 255, 255} ;
    char nb[1] ;

    sprintf(nb, "%d", n) ;
    chiffre.police = TTF_OpenFont("polices/arial.ttf", 28) ;
    chiffre.texte = TTF_RenderText_Blended(chiffre.police, nb, blanc) ;
    chiffre.position.x = info_ia[1] + info_ia [2] + 5 ;
    chiffre.position.y = info_ia[0] ;

    SDL_BlitSurface(chiffre.texte, NULL, ecran, &chiffre.position) ;
    SDL_RenderPresent(ecran) ;

    TTF_CloseFont(chiffre.police) ;
    SDL_FreeSurface(chiffre.texte) ;
}

//Afficher un �cran de fin :
void afficher_gagnant(int nb_joueurs, int nb_tours, SDL_Surface *ecran, int cont)
{
     int i, j = 1, k = 1, tempsActuel, tempsPrecedant = 0 ;
     char gagnant[10] = "" ;
     SDL_Surface *degrade = NULL, *ligne= NULL ;
     SDL_Rect position ;
     SDL_Color blanc = {255, 255, 255} ;
     Bouton resultat ;
     SDL_Event event ;

     if (cont)
     {
         //Cr�ation du d�grad� :
         ligne = SDL_CreateRGBSurface(SDL_SWSURFACE, ecran->w, 1, 32, 0, 0, 0, 0) ;
         degrade = SDL_CreateRGBSurface(SDL_SWSURFACE, ecran->w, ecran->h, 32, 0, 0, 0, 0) ;
         for(i=0 ; i<550 ; i++)
         {
             SDL_FillRect(ligne, NULL, SDL_MapRGB(degrade->format, i*255/550, 0, 0)) ;
             position.x = 0 ;
             position.y = i ;
             SDL_BlitSurface(ligne, NULL, ecran, &position) ;
             SDL_BlitSurface(ligne, NULL, degrade, &position) ; //On stocke le d�grad� dans une surface pour ne pas la recharger � chaque fois...
             SDL_RenderPresent(ecran) ;
         }
         SDL_FreeSurface(ligne) ;

         //Affichage du r�sulat
         switch (nb_tours%2)
         {
            case 0 : if (nb_joueurs == 1) {sprintf(gagnant, "Vous avez perdu !") ;}
                     else {sprintf(gagnant, "Le joueur 2 gagne !!") ;}
                     break ;
            case 1 : if (nb_joueurs == 1) {sprintf(gagnant, "Vous avez gagn� !!") ;}
                     else {sprintf(gagnant, "Le joueur 1 gagne !!") ;}
                     break ;
         }
         resultat.police = TTF_OpenFont("polices/angelina.ttf", 88) ;
         resultat.texte = TTF_RenderText_Blended(resultat.police, gagnant, blanc) ;
         resultat.position.x = ecran->w/2 - resultat.texte->w/2 ;
         resultat.position.y = ecran->h/2 - resultat.texte->h/2 ;

         ligne = SDL_CreateRGBSurface(SDL_SWSURFACE, 800, 1, 32, 0, 0, 0, 0) ;
         position.x = 0 ;
         position.y = 0 ;
         while (cont && event.type != SDL_KEYDOWN && event.type != SDL_QUIT)
         {
            SDL_PollEvent(&event) ;
            SDL_BlitSurface(degrade, NULL, ecran, &position) ;
            resultat.position.x += j ;
            resultat.position.y += k ;
            if (resultat.position.x >= ecran->w-resultat.texte->w) {j = -1 ;}
            if (resultat.position.x <= 0) {j = 1 ;}
            if (resultat.position.y >= ecran->h-resultat.texte->h) {k = -1 ;}
            if (resultat.position.y <= 0) {k = 1 ;}
            SDL_BlitSurface(resultat.texte, NULL, ecran, &resultat.position) ;

            tempsActuel = SDL_GetTicks() ;
            if (tempsActuel - tempsPrecedant < (int) (float) 1000 / (float) FPS)
            {
                SDL_Delay((Uint32)((float) 1000 / (float) FPS - (tempsActuel - tempsPrecedant))) ;
            }
            else
            {
                tempsPrecedant = tempsActuel ;
            }
            SDL_RenderPresent(ecran) ;
        }

        TTF_CloseFont(resultat.police) ;
        SDL_FreeSurface(resultat.texte) ;
        SDL_FreeSurface(degrade) ;
     }
}

//Affiche une fen�tre qui demande si l'on veut vraiment quitter :
void quitter (int *cont, SDL_Surface *ecran)
{
    int cont1 = 1 ;
    SDL_Surface *cadre = NULL ;
    SDL_Rect position ;
    SDL_Color noir = {0, 0, 0}, gris = {188, 188, 188} ;
    Bouton info, ok, annul ;
    SDL_Event event ;

    //Cr�ation du cadre :
    cadre = SDL_CreateRGBSurface(SDL_SWSURFACE, 380, 100, 32, 0, 0, 0, 0) ;
    SDL_FillRect(cadre, NULL, SDL_MapRGB(cadre->format, 188, 188, 188)) ;
    position.x = ecran->w/2 - cadre->w/2 ;
    position.y = ecran->h/2 - cadre->h/2 ;

    //Cr�ation du bouton ok et annuler :
    info.police = TTF_OpenFont("polices/arial.ttf", 24) ;
    ok.police = TTF_OpenFont("polices/arial.ttf", 32) ;
    annul.police = TTF_OpenFont("polices/arial.ttf", 32)  ;
    info.texte = TTF_RenderText_Shaded(info.police, "Voulez-vous vraiment quitter ?", noir, gris) ;
    ok.texte = TTF_RenderText_Shaded(ok.police, "OK", noir, gris) ;
    annul.texte = TTF_RenderText_Shaded(annul.police, "Annuler", noir, gris) ;
    info.position.x = ecran->w/2 - info.texte->w/2 ;
    info.position.y = position.y + 10 ;
    ok.position.x = (cadre->w/2 - ok.texte->w)/2 + ecran->w/2 - cadre->w/2 ;
    ok.position.y = position.y + cadre->h - ok.texte->h - 20 ;
    annul.position.x = (cadre->w/2 - annul.texte->w)/2 + ecran->w/2 ;
    annul.position.y = position.y + cadre->h - annul.texte->h - 20 ;

    SDL_BlitSurface(cadre, NULL, ecran, &position) ;
    SDL_BlitSurface(info.texte, NULL, ecran, &info.position) ;
    SDL_BlitSurface(ok.texte, NULL, ecran, &ok.position) ;
    SDL_BlitSurface(annul.texte, NULL, ecran, &annul.position) ;
    encadre(&ok, ecran) ;
    encadre(&annul, ecran) ;

    SDL_RenderPresent(ecran) ;

    while (cont1)
    {
        SDL_WaitEvent(&event) ;
        switch (event.type)
        {
            case SDL_MOUSEBUTTONUP : if (event.button.button == SDL_BUTTON_LEFT)
                                     {
                                         if (souris_dans_surface(event, &ok))
                                         {
                                             cont1 = 0 ;
                                             *cont = 0 ;
                                         }
                                         if (souris_dans_surface(event, &annul))
                                         {
                                             cont1 = 0 ;
                                             *cont = 1 ;
                                         }
                                     }
                                     break ;
            case SDL_KEYDOWN : if (event.key.keysym.sym == SDLK_RETURN || event.key.keysym.sym == SDLK_KP_ENTER)
                               {
                                   cont1 = 0 ;
                                   *cont = 0 ;
                               }
                               if (event.key.keysym.sym == SDLK_ESCAPE)
                               {
                                   cont1 = 0 ;
                                   *cont = 1 ;
                               }

        }
    }

    //Lib�rations...
    TTF_CloseFont(info.police) ;
    TTF_CloseFont(ok.police) ;
    TTF_CloseFont(annul.police) ;
    SDL_FreeSurface(cadre) ;
    SDL_FreeSurface(info.texte) ;
    SDL_FreeSurface(ok.texte) ;
    SDL_FreeSurface(annul.texte) ;
}

//Fonction qui affiche un �cran d'aide :
void aide (SDL_Surface *ecran, int *cont)
{
    Bouton pt_int, titre, retour, paragraphe[3] ;
    SDL_Color blanc = {255, 255, 255}, bleu = {0, 0, 255}, noir = {0, 0, 0} ;
    SDL_Event event ;
    SDL_Rect pos ;
    char regles[] = "Des allumettes sont pos�es devant vous. � chaque tour, vous devez en prendre 1, 2 ou 3." ;
    char but[] = "Pour gagner, laissez la derni�re � votre adversaire !" ;
    char jouabilite[] = "Choisissez le nombre de joueur(s) et la difficult� avec la souris ou � l'aide des touches 'j' et 'd'. Pour enlever des allumettes appuyez sur les touches 1, 2 ou 3 du clavier." ;
    int i, cont1 = 1 ;

    //Le point d'interrogation (fond)
    pt_int.police = TTF_OpenFont("polices/freescpt.ttf", 466) ;
    pt_int.texte = TTF_RenderText_Blended(pt_int.police, "?", blanc) ;
    pt_int.position.x = ecran->w/2 - pt_int.texte->w/2 ;
    pt_int.position.y = ecran->h/2 - pt_int.texte->h/2 ;

    //Le titre :
    titre.police = TTF_OpenFont("polices/angelina.ttf", 68) ;
    titre.texte = TTF_RenderText_Shaded(titre.police, "AIDE", blanc, noir) ;
    titre.position.x = ecran->w/2 - titre.texte->w/2 ;
    titre.position.y = 5 ;

    //Le bouton reour au menu :
    retour.police = TTF_OpenFont("polices/arial.ttf", 40) ;
    retour.texte = TTF_RenderText_Shaded(retour.police, "Retour au menu", bleu, noir) ;
    retour.position.x = ecran->w/2 - retour.texte->w/2 ;
    retour.position.y = ecran->h - retour.texte->h - 5 ;

    //Les titres des paragraphes de l'aide :
    for (i=0 ; i<3 ; i++)
    {
        paragraphe[i].police = TTF_OpenFont("polices/arial.ttf", 35) ;
    }
    paragraphe[0].texte = TTF_RenderText_Shaded(paragraphe[0].police, "R�gles du jeu :", bleu, noir) ;
    paragraphe[1].texte = TTF_RenderText_Shaded(paragraphe[1].police, "But du jeu :", bleu, noir) ;
    paragraphe[2].texte = TTF_RenderText_Shaded(paragraphe[2].police, "Comment jouer ?", bleu, noir) ;

    paragraphe[0].position.x = 20 ;
    paragraphe[0].position.y = titre.texte->h + 15 ;
    paragraphe[1].position.x = 20 ;
    paragraphe[1].position.y = 210 ;
    paragraphe[2].position.x = 20 ;
    paragraphe[2].position.y = 310 ;

    while (cont1 && *cont)
    {
        //Blittages :
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0)) ;
        SDL_BlitSurface(pt_int.texte, NULL, ecran, &pt_int.position) ;
        SDL_BlitSurface(titre.texte, NULL, ecran, &titre.position) ;
        SDL_BlitSurface(retour.texte, NULL, ecran, &retour.position) ;
        SDL_BlitSurface(paragraphe[0].texte, NULL, ecran, &paragraphe[0].position) ;
        pos.y = paragraphe[0].position.y + paragraphe[0].texte->h + 5 ;
        pos.x = paragraphe[0].position.x/2 ;
        printTexte(ecran, regles, &pos) ;
        SDL_BlitSurface(paragraphe[1].texte, NULL, ecran, &paragraphe[1].position) ;
        pos.x = paragraphe[0].position.x/2 ;
        pos.y = paragraphe[1].position.y + paragraphe[1].texte->h + 5 ;
        printTexte(ecran, but, &pos) ;
        SDL_BlitSurface(paragraphe[2].texte, NULL, ecran, &paragraphe[2].position) ;
        pos.y = paragraphe[2].position.y + paragraphe[2].texte->h + 5 ;
        pos.x = paragraphe[0].position.x/2 ;
        printTexte(ecran, jouabilite, &pos) ;
        encadre(&retour, ecran) ;
        SDL_RenderPresent(ecran) ;

        SDL_WaitEvent(&event) ;
        switch (event.type)
        {
            case SDL_QUIT : quitter(cont, ecran) ;
                            break ;
            case SDL_KEYDOWN : switch (event.key.keysym.sym)
                               {
                                   case SDLK_ESCAPE : quitter(cont, ecran) ;
                                                      break ;
                                   case SDLK_r : cont1 = 0 ;
                                                 break ;
                                   case SDLK_RETURN : cont1 = 0 ;
                                                      break ;
                                   default : break ;
                               }
                               break ;
            case SDL_MOUSEBUTTONDOWN : if (souris_dans_surface(event, &retour))
                                       {
                                           cont1 = 0 ;
                                       }
                                       break ;
        }
    }

    //Lib�rations
    TTF_CloseFont(pt_int.police) ;
    TTF_CloseFont(titre.police) ;
    TTF_CloseFont(retour.police) ;
    SDL_FreeSurface(pt_int.texte) ;
    SDL_FreeSurface(titre.texte) ;
    SDL_FreeSurface(retour.texte) ;
    for(i=0 ; i<3 ; i++)
    {
        TTF_CloseFont(paragraphe[i].police) ;
        SDL_FreeSurface(paragraphe[i].texte) ;
    }
}


//Fonction qui affiche un texte, lettre par lettre :
void printTexte (SDL_Surface *ecran, char texte[], SDL_Rect *pos)
{
    int i = 0, j = 0, k = 0, stockPos = pos->x ;
    char stock[2] = "", *chaine, lett = ' ' ;
    SDL_Surface *lettre = NULL, *text = NULL ;
    SDL_Color bleu = {0, 0, 255} ;
    TTF_Font *police = NULL ;

    police = TTF_OpenFont("polices/arial.ttf", 23) ;
    chaine = malloc(strlen(texte) * sizeof(char)) ;
    while (k < strlen(texte))
    {
        sprintf(chaine, "%c", '\0') ;
        i=0 ;
        do
        {
            sprintf(stock, "%c", texte[i]) ;
            lettre = TTF_RenderText_Solid(police, stock, bleu) ;
            pos->x += lettre->w ;
            i++ ;
            SDL_FreeSurface(lettre) ;
        } while (i+k<strlen(texte) && pos->x+lettre->w < ecran->w) ;
        if (i+k<strlen(texte)-1) {while (texte[k+--i] != ' ') ;} //Si la phrase s'�tale sur plusieurs lignes, on la coupe au dernier espace.
        for (j=k ; j<k+i ; j++)
        {
            lett = texte[j] ;
            sprintf(chaine, "%s%c", chaine, lett) ;
        }
        pos->x = stockPos ;
        text = TTF_RenderText_Blended(police, chaine, bleu) ;
        SDL_BlitSurface(text, NULL, ecran, pos) ;
        k += i ;
        k++ ; //On "saute" l'espace...
        pos->y += text->h ;
        pos->x = stockPos ;

        SDL_FreeSurface(text) ;
    }

    //Lib�rations :
    free(chaine) ;
    TTF_CloseFont(police) ;
}
