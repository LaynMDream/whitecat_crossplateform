/*-------------------------------------------------------------------------------------------------------------
                                 |
          CWWWWWWWW              | Copyright (C) 2009-2013  Christoph Guillermet
       WWWWWWWWWWWWWWW           |
     WWWWWWWWWWWWWWWWWWW         | This file is part of White Cat.
    WWWWWWWWWWWWWWWWWCWWWW       |
   WWWWWWWWWWWWWWWWW tWWWWW      | White Cat is free software: you can redistribute it and/or modify
  WWWW   WWWWWWWWWW  tWWWWWW     | it under the terms of the GNU General Public License as published by
 WWWWWt              tWWWWWWa    | the Free Software Foundation, either version 2 of the License, or
 WWWWWW               WWWWWWW    | (at your option) any later version.
WWWWWWWW              WWWWWWW    |
WWWWWWWW               WWWWWWW   | White Cat is distributed in the hope that it will be useful,
WWWWWWW               WWWWWWWW   | but WITHOUT ANY WARRANTY; without even the implied warranty of
WWWWWWW      CWWW    W WWWWWWW   | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
WWWWWWW            aW  WWWWWWW   | GNU General Public License for more details.
WWWWWWWW           C  WWWWWWWW   |
 WWWWWWWW            CWWWWWWW    | You should have received a copy of the GNU General Public License
 WWWWWWWWW          WWWWWWWWW    | along with White Cat.  If not, see <http://www.gnu.org/licenses/>.
  WWWWWWWWWWC    CWWWWWWWWWW     |
   WWWWWWWWWWWWWWWWWWWWWWWW      |
    WWWWWWWWWWWWWWWWWWWWWW       |
      WWWWWWWWWWWWWWWWWWa        |
        WWWWWWWWWWWWWWW          |
           WWWWWWWWt             |
                                 |
---------------------------------------------------------------------------------------------------------------*/

/**

* \file splashscreen_visu.cpp
* \brief Slash screen - Ecran de démarrage
* \author Christoph Guillermet
* \version {0.8.6}
* \date {28/04/2014}

 White Cat {- categorie} {- sous categorie {- sous categorie}}

*   Gère la plupart des fonctions global du coeur de whitecat
*
*   Global fonctions for the core of whitecat
*
 **/

void show_title()
{

	int x_left_ref = (largeur_ecran/2)-195 ;
	int y_bott_ref = (hauteur_ecran/2)-120 ;

	Rect background_splashscreen( Vec2D(x_left_ref-50,y_bott_ref-180), Vec2D(525,650));
	background_splashscreen.SetRoundness(15);
	//background_splashscreen.SetLineWidth(epaisseur_ligne_fader);
	//background_splashscreen.DrawOutline(CouleurLigne);
	background_splashscreen.Draw(CouleurFond);

    logo.Blit(x_left_ref+60,(hauteur_ecran/2));

    neuromoyen.Print(nickname_version                 , x_left_ref-25, y_bott_ref-130, 445, RIGHT);
    neuroTitle.Print("WHITE CAT"                      , x_left_ref-18, y_bott_ref- 80, 445,CENTER);

    neuro.Print("http://www.le-chat-noir-numerique.fr", x_left_ref   , y_bott_ref- 50, 415,CENTER);
    petitchiffre.Print(" (c) christoph guillermet"    , x_left_ref   , y_bott_ref- 30, 415,CENTER);
    petitpetitchiffre.Print(versionis                 , x_left_ref   , y_bott_ref    , 415,CENTER);

}

void save_load_print_to_screen(const std::string label)
{
    const std::string string_print_to_screen = label.substr (0,64);
    int x_ref = (largeur_ecran/2) ;
    int y_ref = (hauteur_ecran/2) ;

    if(index_do_quick_save==0)
    {
        show_title();
    }
    Rect nameAera( Vec2D(x_ref-195,y_ref-100), Vec2D(415,70));
    nameAera.SetRoundness(15);
    nameAera.SetLineWidth(epaisseur_ligne_fader*3);
    nameAera.Draw(CouleurSurvol);
    nameAera.DrawOutline(CouleurLigne);

    neuro.Print(string_print_to_screen,(x_ref-150),(y_ref-60),325,CENTER);

    Canvas::Refresh();

}

