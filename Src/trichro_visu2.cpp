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

* \file trichro_visu2.cpp
* \brief {GUI fonctions for the color whell}
* \author Christoph Guillermet
* \version {0.8.6.3}
* \date {12/02/2015}

 White Cat {- categorie} {- sous categorie {- sous categorie}}

*   GUI fonctions pour la fenêtre de roue de couleur en trichromie
*
*   GUI fonctions for the color whell window
*
**/


int Interface_Trichromie(int xchroma, int ychroma, int rayon, int largeurchroma)
{

//background window
Rect TrichroBackground(Vec2D (xchroma-158, ychroma-206 ), Vec2D ( 315+(show_gel_list*gel_size_window),550));
TrichroBackground.SetRoundness(15);
TrichroBackground.SetLineWidth(triple_epaisseur_ligne_fader);
TrichroBackground.Draw(CouleurFond);
if(window_focus_id==902)
{
TrichroBackground.DrawOutline(CouleurFader);
}
else
{
TrichroBackground.DrawOutline(CouleurLigne);
}


///////////////////////////////roue de couleur///////////////////////////////////////////
/////////AFFICHEE EN OPENGL CAR PLUS RAPIDE QUE BLIT ECT////////////////////////////////
for (hcl=0; hcl<360; hcl+=0.1)
{
     xcl = cos(hcl*PI/180.0)*(rayon+16);
	 ycl = sin(hcl*PI/180.0)*(rayon+16);

	 hsv_to_rgb(hcl, 1.0, 1.0, &rcl, &gcl, &bcl);
	 Line(Vec2D(xchroma,ychroma),Vec2D(xchroma+xcl,ychroma+ycl)).Draw(Rgba(rcl,gcl,bcl));
}


Circle MasqueNoir(Vec2D(xchroma,ychroma),rayon-16);
MasqueNoir.Draw(CouleurFond);

	V3D_f v1 =
	{
		xchroma+vxd, ychroma+vyd, 0,
		0., 0.,
		makecol(0, 0, 0) // black vertex
	};
	V3D_f v2 =
	{
		xchroma+vxw, ychroma+vyw, 0,
		0., 0.,
		makecol(255, 255, 255) // white vertex
	};
	V3D_f v3 =
	{
		xchroma+vxh, ychroma+vyh, 0,
		0., 0.,
		makecol(r_pick, v_pick, b_pick) // color vertex
	};


	triangle3d_f(screen, POLYTYPE_GCOL, NULL, &v1, &v2, &v3);


//
//AFFECTATION MIDI
if(Midi_Faders_Affectation_Type!=0 && window_focus_id==W_TRICHROMY)//config midi
  {
   if(mouse_x>xchroma-140 && mouse_x<xchroma+140 && mouse_y>ychroma-140 && mouse_y<ychroma+140)
  {
   Circle Color( Vec2D(xchroma-1,ychroma), 140 );
   Color.SetLineWidth(epaisseur_ligne_fader);
   Color.DrawOutline(CouleurBlind);
   }
 }

//affichage du pointeur de hue
 Circle monCurseurHue( Vec2D(position_curseur_hue_x, position_curseur_hue_y), 12 );
 monCurseurHue.SetLineWidth(epaisseur_ligne_fader);
 monCurseurHue.DrawOutline( CouleurLigne );


Circle monCurseurTriangle( Vec2D(xchroma+picker_x,ychroma+picker_y), 6 );
   monCurseurTriangle.SetLineWidth(epaisseur_ligne_fader);
   monCurseurTriangle.DrawOutline( CouleurLigne );



/////////////////TRICHRO / QUADRI CHOOSE//////////////////////////////////////
Rect ChooseTriQuadri( Vec2D(xchroma-60,(ychroma-190)),Vec2D(130,30));
ChooseTriQuadri.SetRoundness(15);
ChooseTriQuadri.SetLineWidth(epaisseur_ligne_fader);
if(window_focus_id==W_TRICHROMY &&  mouse_x>xchroma-60 && mouse_x<xchroma+80 && mouse_y>ychroma-190 && mouse_y<ychroma-160)
{
ChooseTriQuadri.Draw(CouleurSurvol);

}
ChooseTriQuadri.DrawOutline(CouleurLigne);
if(index_quadri==0){petitchiffre.Print("TRICHROMY",xchroma-30, ychroma-172);}
else if(index_quadri==1){petitchiffre.Print("QUADRICHROMY",xchroma-45, ychroma-172);}

/////////////////////Gel LIST CALL///////////////////////////////////////////////////
Rect Show_Gel( Vec2D(xchroma+90,(ychroma-185)),Vec2D(60,20));
Show_Gel.SetRoundness(5);
Show_Gel.SetLineWidth(1);
Show_Gel.Draw(CouleurFader.WithAlpha(show_gel_list));
Show_Gel.DrawOutline(CouleurLigne);
petitchiffre.Print("GEL LIST",xchroma+95, ychroma-172);

/////////////////////AFFECTATION ON / OFF AUX DOCKS FADERS///////////////////////////

Rect AffectTriTo( Vec2D(xchroma+20,(ychroma+300)),Vec2D(130,30));
AffectTriTo.SetRoundness(15);
AffectTriTo.SetLineWidth(epaisseur_ligne_fader);
if (index_affect_color_to_dock==1){AffectTriTo.Draw(CouleurFader);}
AffectTriTo.DrawOutline(CouleurLigne);
petitchiffre.Print("AFFECT TO DOCK",xchroma+35, ychroma+319);

//PASTE ON THE FLY MODE
Rect PasteTriTo( Vec2D(xchroma-150,(ychroma+300)),Vec2D(130,30));
PasteTriTo.SetRoundness(15);
PasteTriTo.SetLineWidth(epaisseur_ligne_fader);
if (index_paste_on_the_fly==1){PasteTriTo.Draw(CouleurBlind);}
PasteTriTo.DrawOutline(CouleurLigne);
petitpetitchiffre.Print("PASTE ON THE FLY",xchroma-135, ychroma+319);



/////////////////////DOCKING DES COULEURS////////////////////////////////////////
//emplacement des box pour actions de storage RVB sur 6 presets
Rect RedBox(Vec2D(xchroma-130,ychroma+165),Vec2D(50,20));
RedBox.SetRoundness(10);
RedBox.SetLineWidth(epaisseur_ligne_fader);
RedBox.Draw(Rgba::RED);
RedBox.DrawOutline(CouleurLigne);

Rect GreenBox(Vec2D(xchroma-65,ychroma+165),Vec2D(50,20));
GreenBox.SetRoundness(10);
GreenBox.SetLineWidth(epaisseur_ligne_fader);
GreenBox.Draw(Rgba::GREEN.WithAlpha(0.7));
GreenBox.DrawOutline(CouleurLigne);

Rect BlueBox(Vec2D(xchroma,ychroma+165),Vec2D(50,20));
BlueBox.SetRoundness(10);
BlueBox.SetLineWidth(epaisseur_ligne_fader);
BlueBox.Draw(Rgba::BLUE);
BlueBox.DrawOutline(CouleurLigne);

Rect YellowBox(Vec2D(xchroma+65,ychroma+165),Vec2D(50,20));
YellowBox.SetRoundness(10);
YellowBox.SetLineWidth(epaisseur_ligne_fader);
if (index_quadri==1){YellowBox.Draw(Rgba::YELLOW);}
YellowBox.DrawOutline(CouleurLigne);

petitchiffre.Print(ol::ToString(my_red),xchroma-115, ychroma+179);
petitchiffre.Print(ol::ToString(my_green),xchroma-55, ychroma+179);
petitchiffre.Print(ol::ToString(my_blue ),xchroma+10, ychroma+179);
petitchiffrerouge.Print(ol::ToString(my_yellow ),xchroma+75, ychroma+179);



//midi out de la roue
Circle BMidiOut( xchroma+140,ychroma+110, 10);//box du fader
BMidiOut.SetLineWidth(epaisseur_ligne_fader);
if(midi_send_out[497]==1)
{
BMidiOut.Draw(CouleurBlind);
}
BMidiOut.DrawOutline(CouleurLigne);

raccrochage_midi_visuel_circulaire (xchroma, ychroma, 497, rayon, rayon);

//liaison visuelle au fader du cercle midi out
Line (Vec2D( xchroma+97,ychroma+100),Vec2D(xchroma+125,ychroma+100)).Draw(CouleurLigne);
Line (Vec2D(xchroma+125,ychroma+100),Vec2D(xchroma+125+8,ychroma+106)).Draw(CouleurLigne);


petitchiffre.Print("COLOR PRESETS",xchroma-65, ychroma+205);

//premiere rangee de dock colors
char string_allocation_col[7];
for (int dock_color=0;dock_color<4;dock_color++)
{
Rect DockBoxColor(Vec2D(xchroma-130+(65*dock_color),ychroma+215),Vec2D(50,20));
DockBoxColor.SetRoundness(10);
DockBoxColor.SetLineWidth(epaisseur_ligne_fader);
if(dock_color==dock_color_selected){DockBoxColor.Draw(CouleurFader); }
sprintf(string_allocation_col,"%d / %d",(colorpreset_linked_to_dock[dock_color][0]+1),(colorpreset_linked_to_dock[dock_color][1]+1));

//////////////////////////////////////////////////////////////////////////////////
petitchiffre.Print(string_allocation_col,xchroma-120+(65*dock_color),ychroma+230);

DockBoxColor.DrawOutline(CouleurLigne);
if(window_focus_id==W_TRICHROMY && mouse_x>xchroma-130+(65*dock_color) && mouse_x<xchroma-80+(65*dock_color) && mouse_y>ychroma+215 && mouse_y<ychroma+235)
{
petitchiffre.Print(string_allocation_col,xchroma-120+(65*dock_color),ychroma+230);
if( Midi_Faders_Affectation_Type!=0)
{DockBoxColor.DrawOutline(CouleurBlind); }
}


}
//deuxième rangee de dockcolors
for (int dock_colortwo=0;dock_colortwo<4;dock_colortwo++)
{
Rect DockBoxColor2(Vec2D(xchroma-130+(65*dock_colortwo),ychroma+255),Vec2D(50,20));
DockBoxColor2.SetRoundness(10);
DockBoxColor2.SetLineWidth(epaisseur_ligne_fader);
if((dock_colortwo+4)==dock_color_selected){DockBoxColor2.Draw(CouleurFader); }
sprintf(string_allocation_col,"%d / %d",(colorpreset_linked_to_dock[dock_colortwo+4][0]+1),(colorpreset_linked_to_dock[dock_colortwo+4][1]+1));
petitchiffre.Print(string_allocation_col,xchroma-120+(65*dock_colortwo),ychroma+270);

DockBoxColor2.DrawOutline(CouleurLigne);
if(window_focus_id==W_TRICHROMY && mouse_x>xchroma-130+(65*dock_colortwo) && mouse_x<xchroma-80+(65*dock_colortwo) && mouse_y>ychroma+255 && mouse_y<ychroma+275)
{
petitchiffre.Print(string_allocation_col,xchroma-120+(65*dock_colortwo),ychroma+270);
if(Midi_Faders_Affectation_Type!=0)
{DockBoxColor2.DrawOutline(CouleurBlind); }
}

}

//GEL LIST
if(show_gel_list==1)
{
//Line (Vec2D( xchroma+170,ychroma-150),Vec2D(xchroma+170,ychroma+260)).Draw(CouleurLigne);

Rect mytype_of_gel(Vec2D((xchroma+180),ychroma-185),Vec2D(70,20));
mytype_of_gel.SetLineWidth(1);
mytype_of_gel.DrawOutline(CouleurLigne);
switch(index_gel_type_selected)
{
case 0:
    petitchiffre.Print("LEE",xchroma+210, ychroma-172);
break;
case 1:
    petitchiffre.Print("ROSCO",xchroma+196, ychroma-172);
break;
case 2:
    petitchiffre.Print("GAMCOLOR",xchroma+182, ychroma-172);
break;
case 3:
    petitchiffre.Print("APOLLO",xchroma+190, ychroma-172);
break;
default:
break;
}


Rect mytype_of_list(Vec2D((xchroma+260),ychroma-185),Vec2D(70,20));
mytype_of_list.SetLineWidth(1);
mytype_of_list.DrawOutline(CouleurLigne);
switch(show_designer_list)
{
case 0:
    petitchiffre.Print("NUMERIC",xchroma+270, ychroma-172);
break;
case 1:
    petitchiffre.Print("DESIGNER",xchroma+267, ychroma-172);
break;
default:
break;
}

//call my gel
Rect call_my_number(Vec2D((xchroma+340),ychroma-185),Vec2D(50,20));
call_my_number.SetRoundness(5);
call_my_number.SetLineWidth(1);
call_my_number.DrawOutline(CouleurLigne.WithAlpha(0.5));
if(window_focus_id==W_TRICHROMY && mouse_x>xchroma+340 && mouse_x<xchroma+390 && mouse_y>ychroma-185 && mouse_y<ychroma-165)
{
call_my_number.DrawOutline(CouleurLigne);
}
petitchiffre.Print(ol::ToString(call_ref_number),xchroma+345,ychroma-172);



//+ - position
//UP DOWN bangers number selected
Circle indexPlus(Vec2D(xchroma+410,ychroma-175),12);
Circle indexMinus(Vec2D(xchroma+440,ychroma-175),12);

petitchiffre.Print("-",xchroma+406,ychroma-173);
petitchiffre.Print("+",xchroma+436,ychroma-173);
indexPlus.DrawOutline(CouleurLigne);
indexMinus.DrawOutline(CouleurLigne);


//petitpetitchiffre.Print(ol::ToString(gel_position[index_gel_type_selected]),xchroma+460,ychroma-173);
Rect Transm(Vec2D(xchroma+510,ychroma-185),Vec2D(40,20));
Transm.SetRoundness(5);
Transm.Draw(CouleurBlind.WithAlpha(index_use_transmission));
Transm.DrawOutline(CouleurLigne.WithAlpha(0.6));
petitchiffre.Print("Trans.",xchroma+512,ychroma-173);

//affichage des gélats
Rect CarreColor(Vec2D(0,0),Vec2D(16,16));
Rect Underline(Vec2D(0,0),Vec2D(310,16));
volatile bool one_line=0;//one line on two

for(int i=0;i<30;i++)
{
one_line=toggle(one_line);//just for data visualisation
Underline.MoveTo(Vec2D(xchroma+175,ychroma-150+(i*16)));
Underline.Draw(CouleurLigne.WithAlpha(0.2*one_line));//une ligne sur deux
if(window_focus_id==W_TRICHROMY && mouse_x>xchroma+175 && mouse_x<xchroma+485 && mouse_y>ychroma-150+(i*16) && mouse_y<ychroma-134+(i*16) )
{
Underline.DrawOutline(CouleurLigne);
}
petitchiffre.Print(ol::ToString(refs_of_gels[index_gel_type_selected][gel_position[index_gel_type_selected]+i]),xchroma+180,ychroma-138+(i*16));
petitchiffre.Print(name_of_gels[index_gel_type_selected][gel_position[index_gel_type_selected]+i],xchroma+215,ychroma-138+(i*16));
petitpetitchiffre.Print(ol::ToString(rvb_of_gels[index_gel_type_selected][gel_position[index_gel_type_selected]+i][0]),xchroma+410,ychroma-138+(i*16));
petitpetitchiffre.Print(ol::ToString(rvb_of_gels[index_gel_type_selected][gel_position[index_gel_type_selected]+i][1]),xchroma+435,ychroma-138+(i*16));
petitpetitchiffre.Print(ol::ToString(rvb_of_gels[index_gel_type_selected][gel_position[index_gel_type_selected]+i][2]),xchroma+460,ychroma-138+(i*16));

CarreColor.MoveTo(Vec2D(xchroma+487,ychroma-150+(i*16)));
CarreColor.Draw(CouleurLigne);
Rgba TmpColor (float(rvb_of_gels[index_gel_type_selected][gel_position[index_gel_type_selected]+i][0])/255,
                       float(rvb_of_gels[index_gel_type_selected][gel_position[index_gel_type_selected]+i][1])/255,
                       float(rvb_of_gels[index_gel_type_selected][gel_position[index_gel_type_selected]+i][2])/255);
petitpetitchiffre.Print(ol::ToString(gel_transimission[index_gel_type_selected][gel_position[index_gel_type_selected]+i]),xchroma+515,ychroma-138+(i*16));

CarreColor.Draw(TmpColor);
CarreColor.DrawOutline(CouleurFond);
}


}

return(0);
}
/////////////////////////////////////////////////////////////////


