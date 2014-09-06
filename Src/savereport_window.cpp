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

* \file saveload_report_visu.cpp
* \brief {save and load fonctions}
* \author Christoph Guillermet
* \version {0.8.6.1}
* \date {16/06/2014}
 White Cat {- categorie} {- sous categorie {- sous categorie}}

*   Rapport des fonctions de sauvegarde et de rappel (VISU et LOGIQUE)
*
*   Report from Save and Load fonctions
*
**/

////////////////////////////// DATA window W_SAVEREPORT //////////////////////////////
int report_SL_X=30 ;
int report_SL_Y=40 ;
int default_report_SL_X=30 ;
int default_report_SL_Y=30 ;
bool there_is_an_error_on_save_load=0;
bool index_show_save_load_report=0;
bool b_report_error[256];
char string_save_load_report[256][64];//256 slot de report de 64 char
int position_view_line=0; //pour defilement affichage


////////////////////////////// LOGIC window W_SAVEREPORT //////////////////////////////
bool mouseover_Show_report_save_load ()
{
    return (   mouse_x>= report_SL_X && mouse_x<= report_SL_X+490
               && mouse_y>= report_SL_Y && mouse_y<= report_SL_Y+320);
}

void Show_report_save_load_logic ()
{
    if ((window_focus_id==W_SAVEREPORT)
            && (mouse_x>report_SL_X+440 && mouse_x<report_SL_X+490)
            && (mouse_button==1 &&  mouse_released==0 ))
    {

        //-
        if ( mouse_y>report_SL_Y+76 && mouse_y<report_SL_Y+96)
        {
            mouse_released=1;
            position_view_line-=25;
            if(position_view_line<0)
            {
                position_view_line=0;
            }
        }

        //+
        if( mouse_y>report_SL_Y+106 && mouse_y<report_SL_Y+136)
        {
            position_view_line+=25;
            mouse_released=1;
            if(position_view_line>229)  //(255-25))
            {
                position_view_line=229 ; //(255-25);
            }
        }
        //there is error(s) - on clic on the message : scroll to next page reporting error(s)
        if ((there_is_an_error_on_save_load==1)
		&& ( mouse_y>report_SL_Y+136 && mouse_y<report_SL_Y+166))
        {
			if (position_view_line>=229) {position_view_line=0;}

			for(int it=position_view_line+25; it<255; it++)
			{
				if(b_report_error[it]==1)
				{
					position_view_line = it ;
					break;
				}
				if (it==254){it=0;}
			}
		}
    }
}

////////////////////////////// DRAW window W_SAVEREPORT //////////////////////////////
void Show_report_save_load_draw()
{
    //Rect Report_Save_Load(Vec2D(report_SL_X, report_SL_Y), Vec2D( 350,160));
    Rect Report_Save_Load(Vec2D(report_SL_X, report_SL_Y), Vec2D( 500,360));
    Report_Save_Load.SetRoundness(15);
    Report_Save_Load.SetLineWidth(epaisseur_ligne_fader*3);
    Report_Save_Load.Draw(CouleurFond);
    Report_Save_Load.DrawOutline(CouleurLigne);

    if(window_focus_id==W_SAVEREPORT)
    {
        Report_Save_Load.DrawOutline(CouleurFader);
    }

    //+ minus debug
    //Plus Minus buttons debug show
    Rect MinusPosMyRep(Vec2D(report_SL_X+440,report_SL_Y+76),Vec2D(50,20));
    MinusPosMyRep.SetRoundness(7.5);
    MinusPosMyRep.SetLineWidth(epaisseur_ligne_fader);

    Rect PlusPosMyRep(Vec2D(report_SL_X+440,report_SL_Y+106),Vec2D(50,20));
    PlusPosMyRep.SetRoundness(7.5);
    PlusPosMyRep.SetLineWidth(epaisseur_ligne_fader);

    //for(int co=0; co<10; co++)
    for(int co=0; co<25; co++)
    {
        Rect AlarmFile(Vec2D((report_SL_X+10),(report_SL_Y+92+(10*co))),Vec2D(450,12));
        AlarmFile.SetRoundness(5);
        if(b_report_error[co+position_view_line]==1)
        {
            AlarmFile.Draw(Rgba::RED.WithAlpha(alpha_blinker));
        }
        petitchiffre.Print( ol::ToString(co+position_view_line),(report_SL_X+10), (report_SL_Y+100+(10*co)), 20, RIGHT);
        petitchiffre.Print( string_save_load_report[co+position_view_line],(report_SL_X+35), (report_SL_Y+100+(10*co)));
    }

    MinusPosMyRep.Draw(CouleurFond);
    PlusPosMyRep.Draw(CouleurFond);

    if ((window_focus_id==W_SAVEREPORT)
            && (mouse_x>report_SL_X+440 && mouse_x<report_SL_X+490))
    {
        //-
        if( mouse_y>report_SL_Y+76 && mouse_y<report_SL_Y+96)
        {
            MinusPosMyRep.Draw(CouleurSurvol);
            if(mouse_button==1 &&  mouse_released==0 )
            {
                MinusPosMyRep.Draw(CouleurFader);
            }
        }

        //+
        if( mouse_y>report_SL_Y+106 && mouse_y<report_SL_Y+136)
        {
            PlusPosMyRep.Draw(CouleurSurvol);
            if(mouse_button==1 &&  mouse_released==0 )
            {
                PlusPosMyRep.Draw(CouleurFader);
            }
        }
    }

    MinusPosMyRep.DrawOutline(CouleurLigne);
    PlusPosMyRep.DrawOutline(CouleurLigne);
    petitchiffre.Print("line -",       report_SL_X+450, report_SL_Y+90);
    petitchiffre.Print("line +",       report_SL_X+450, report_SL_Y+120);

    {
        int nbr_error = 0;
        for(int it=0; it<255; it++)
        {
            if(b_report_error[it]==1)
            {
                ++nbr_error ;
            }

            if (nbr_error > 0)
            {
                Rect AlarmFile(Vec2D(report_SL_X+440,report_SL_Y+136),Vec2D(50,20));
                AlarmFile.SetRoundness(5);
                AlarmFile.Draw(Rgba::RED.WithAlpha(alpha_blinker));

                petitchiffre.Print( ol::ToString(nbr_error),report_SL_X+430, report_SL_Y+150, 20, RIGHT);
                if (nbr_error==1)
                {
                    petitchiffre.Print( " error", report_SL_X+450, report_SL_Y+150, 150, LEFT);
                }
                else
                {
                    petitchiffre.Print( " errors",report_SL_X+450, report_SL_Y+150, 150, LEFT);
                }
            }
        }
    }

    neuro.Print( "Save-Load Report",   report_SL_X+100,  report_SL_Y+30);
    petitchiffre.Print( "Directory",   report_SL_X+15,   report_SL_Y+60,  45,RIGHT);
    petitchiffre.Print( mondirectory,  report_SL_X+65,   report_SL_Y+60, 300,LEFT);
    petitchiffre.Print( "Show",        report_SL_X+15,   report_SL_Y+75,  45,RIGHT);
    petitchiffre.Print( nomduspectacle,report_SL_X+65,   report_SL_Y+75, 300,LEFT);


}

////////////////////////////// Traitement window W_SAVEREPORT //////////////////////////////
void reset_error_on_save_load()
{
    for (int f=0; f<256; f++)
    {
        b_report_error[f]=0;
    }
    there_is_an_error_on_save_load=0;
}

void detect_error_on_save_load()
{
    for (int f=0; f<256; f++)
    {
        if( b_report_error[f]==1)
        {
            there_is_an_error_on_save_load=1;
            break;
        }
    }
}

void clear_report_string()
{
    for(int i=0; i<256 ; i++)
    {
        sprintf(string_save_load_report[i],"-");
    }
    reset_error_on_save_load();
}

void Show_report_save_load()
{
    Show_report_save_load_draw();
    Show_report_save_load_logic();
}
