/*-------------------------------------------------------------------------------------------------------------
                                 |
          CWWWWWWWW              | Copyright (C) 2009-2014  Christoph Guillermet
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

* \file spline.h
* \brief support for short splines : creating and drawing them
* \author Georges Khaznadar
* \version 0.8.6
* \date 24/06/2014
**/

#include "spline.h"
#include <OpenLayer.hpp>
using namespace ol;
#include "colors_fonts.h"

/* static variables */
bool Spline::index_writing=0;
int Spline::selected=0;
bool Spline::index_enable_editing=0;
bool Spline::index_reset=0;
bool Spline::index_square=0;
bool Spline::index_fluo=0;
bool Spline::index_preheat=0;


/**
 * calculates a series of curve_node tangents 
 * @param node_count an index, which is incremented once during the call
 **/
void Spline::calc_tangents(int & node_count)
{
  //pas touche prepa tangentes OK pour sens en avant
  int i;

  nodes[0] = nodes[1].dummy(nodes[2]);
  nodes[node_count] = nodes[node_count-1].dummy(nodes[node_count-2]);

  node_count++;

  for (i=1; i<node_count-1; i++)
    nodes[i].tangent = fixatan2(itofix(nodes[i+1].y - nodes[i-1].y),
				itofix(nodes[i+1].x - nodes[i-1].x));
}




/** calculates the control points for a spline segment 
 * @param i1 index of the first point
 * @param i2 index of the second point
 * @param points (output parameter) a table of 8 integers 
 **/
void Spline::get_control_points(int i1, int i2, int points[8])
{
  curve_node n1=nodes[i1];
  curve_node n2=nodes[i2];

  fixed dist = fixmul(n1.dist(n2), curviness);

  points[0] = n1.x;
  points[1] = n1.y;

  points[2] = n1.x + fixtoi(fixmul(fixcos(n1.tangent), dist));
  points[3] = n1.y + fixtoi(fixmul(fixsin(n1.tangent), dist));

  points[4] = n2.x - fixtoi(fixmul(fixcos(n2.tangent), dist));
  points[5] = n2.y - fixtoi(fixmul(fixsin(n2.tangent), dist));

  points[6] = n2.x;
  points[7] = n2.y;
}


/**
 * function to do something
 * @param gc graphic context
 * @param node_count an index to a node (in/out parameter)
 **/
int Spline::write_curve(const graphic_context& gc, int & node_count)
{
  index_writing=1;
  int points[MAX_CNODES ];// etait [8] le 24 aout


  curviness = ftofix(spline_level);
  calc_tangents(node_count);

  for(int nio=1; nio < (node_count-1); nio++)
    {
      get_control_points(nio,nio+1,points);

      int resolu= (this->nodes[nio+1].x) - (this->nodes[nio].x);
      int temp_curve_x[resolu];
      int temp_curve_y[resolu];
      calc_spline(points,resolu, temp_curve_x, temp_curve_y);

      int index_sp=0;

      for(int cuv=0;cuv<resolu;cuv++)
	{
	  index_sp=(this->nodes[nio].x+cuv)-(gc.xpatch_window+30+455);

	  if(index_sp>255){index_sp=255;}
	  if(index_sp<0){index_sp=0;}

	  report[selected][index_sp]=temp_curve_y[cuv]-(gc.ypatch_window+50);

	  if(report[selected][index_sp]<0){report[selected][index_sp]=0;}
	  if(report[selected][index_sp]>255){report[selected][index_sp]=255;}

	}
    }
  index_writing=0;
  return(0);
}




/**
 * Function to draw a spline near a given point
 * @param n number of point to draw
 * @param gc graphic context
 * param node_count an index to a node (i/o)
 **/
int Spline::draw(int n, const graphic_context& gc, int & node_count)
{
  if(n<6){
    Circle(nodes[n].x, nodes[n].y, 6).DrawOutline(CouleurBlind);
    petitchiffre.Print(ol::ToString(n),nodes[n].x-7, nodes[n].y-7);
  }


  if( gc.window_focus_id==gc.W_PATCH 
      && mouse_x>=((nodes[n].x)-(diam/2)) && mouse_x<=((nodes[n].x)+(diam/2))
      && mouse_x>=gc.xpatch_window+30+455 && mouse_x<=gc.xpatch_window+30+455+255
      && mouse_x>(nodes[n-1].x+(diam/2)) && mouse_x<(nodes[n+1].x-(diam/2))
      && mouse_y>=gc.ypatch_window+50 && mouse_y<=gc.ypatch_window+255+50    )
    {
      Line( Vec2D( nodes[n].x, gc.ypatch_window+50 ), Vec2D(nodes[n].x,gc.ypatch_window+255+50)).Draw(Rgba::YELLOW);
      Circle(nodes[n].x, nodes[n].y, 6).Draw(CouleurBlind);

      if(mouse_b&1 && index_enable_editing==1 )
	{
	  if(n>1 && n<5)
	    {
	      ctrl_pt[selected][n][0]=mouse_x-(gc.xpatch_window+30+455);
	      ctrl_pt[selected][n][1]=mouse_y-(gc.ypatch_window+50);
	    }
	  if(n==1)
	    {
	      ctrl_pt[selected][n][0]=0;
	      ctrl_pt[selected][n][1]=mouse_y-(gc.ypatch_window+50);
	    }
	  if(n==5)
	    {
	      ctrl_pt[selected][n][0]=255;
	      ctrl_pt[selected][n][1]=mouse_y-(gc.ypatch_window+50);
	    }

	  write_curve(gc, node_count);//ecriture des niveaux
	}

    }

  if (gc.dmx_view==1)//255
    {
      //affichage OUT
      petitpetitchiffrerouge.Print(ol::ToString(255-ctrl_pt[selected][n][1]),gc.xpatch_window+5+455,gc.ypatch_window+50+ctrl_pt[selected][n][1]);
      //affichage IN
      petitpetitchiffre.Print(ol::ToString(ctrl_pt[selected][n][0]),gc.xpatch_window+455+20+ctrl_pt[selected][n][0],gc.ypatch_window+50+270);
    }
  else   if (gc.dmx_view==0)//%
    {
      //affichage OUT
      petitpetitchiffrerouge.Print(ol::ToString((int)((255-ctrl_pt[selected][n][1])/2.55)),gc.xpatch_window+5+455,gc.ypatch_window+50+ctrl_pt[selected][n][1]);
      //affichage IN
      petitpetitchiffre.Print(ol::ToString((int)((ctrl_pt[selected][n][0])/2.55)),gc.xpatch_window+455+20+ctrl_pt[selected][n][0],gc.ypatch_window+50+270);
    }
  return(0);
}

/**
 * draws the spline paths 
 * @param gc graphic context
 * param node_count an index to a node (i/o)
 **/
int Spline::draw_splines(const graphic_context& gc, int & node_count)
{
    int io;
     nodes[0] = nodes[node_count+1].dummy(nodes[node_count]); //curve_node et previous
   for (io=1; io<node_count-1; io++)
   {
      nodes[io].x=(ctrl_pt[selected][io][0]+gc.xpatch_window+30+455);
      nodes[io].y=(ctrl_pt[selected][io][1]+gc.ypatch_window+50);
      draw(io, gc, node_count);
   }

return(0);
}

/**
 * Function to do something
 * @param gc graphic context
 **/
int Spline::view_after_draw(const graphic_context& gc)
//verif du report de ma courbe
{
  for (int d=0; d<255;d++)
    {
      Point(gc.xpatch_window+30+455+d,gc.ypatch_window+50+report[selected][d] ).Draw(Rgba::GREEN);
    }
  return(0);
}

/**
 * draws the spline paths ...
 * @param gc graphic context
 **/
int Spline::SplineCurve(const graphic_context& gc)
{
  curviness = ftofix(spline_level);
  int node_count=6;
  calc_tangents(node_count);
  //allegro_gl_set_allegro_mode(); //melange gl et allegro screen
  draw_splines(gc,node_count);//l attribution des pas est fait dans drawsplines
  //allegro_gl_unset_allegro_mode(); //melange gl et allegro screen
  view_after_draw(gc);
  return(0);
}

/**
 * Function to do something
 * @param curve index of the chosen curve (0..15)
 * @param gc graphic context
 **/
int Spline::build_default_curve(int curve, graphic_context& gc)
{
    gc.mouse_released=1;

//points
    for (int pt=1; pt<MAX_CNODES-1; pt++)
    {
        ctrl_pt[curve][pt][0]=(int)((((float)255)/6) *pt);
        ctrl_pt[curve][pt][1]=255-(int)((((float)255)/6) *pt);
    }
    ctrl_pt[curve][1][0]=0;
    ctrl_pt[curve][1][1]=255;//point 1 en 0 0
    ctrl_pt[curve][5][0]=255;
    ctrl_pt[curve][5][1]=0;//point 5 en 255 255

    ctrl_pt[curve][6][0]=255;
    ctrl_pt[curve][6][1]=0;//point 5 en 255 255

    the_spline_level[curve]=168;
    index_spline_level=168;
    spline_level=(((float)index_spline_level)/127)-1;
    curviness = ftofix(spline_level);
    int node_count=6;
    calc_tangents(node_count);
    draw_splines(gc,node_count);

    spline_level=(((float)index_spline_level)/127)-1;

//write_curve(); //fait planter si debordement de memoire

    view_after_draw(gc);
    return(0);
}


/**
 * Function to do something
 * @param curve index of the chosen curve (0..15)
 * @param gc graphic context
 **/
int Spline::build_square(int curve,const graphic_context& gc)
{
  //points
  ctrl_pt[curve][1][0]=0; ctrl_pt[curve][1][1]=255;//point 1 en 0 0

  ctrl_pt[curve][2][0]=27; ctrl_pt[curve][2][1]=255-89;//point 1 en 0 0
  ctrl_pt[curve][3][0]=55; ctrl_pt[curve][3][1]=255-153;//point 1 en 0 0
  ctrl_pt[curve][4][0]=118; ctrl_pt[curve][4][1]=255-213;//point 1 en 0 0

  ctrl_pt[curve][5][0]=255; ctrl_pt[curve][5][1]=0;//point 5 en 255 255

  the_spline_level[curve]=176;
  index_spline_level=176;
  spline_level=(((float)index_spline_level)/127)-1;
  curviness = ftofix(spline_level);
  int node_count=6;
  calc_tangents(node_count);
  draw_splines(gc,node_count);
  //write_curve(); //fait planter si debordement de memoire
  view_after_draw(gc);
  return(0);
}


/**
 * Function to do something
 * @param curve index of the chosen curve (0..15)
 * @param gc graphic context
 **/
int Spline::build_fluo(int curve,const graphic_context& gc)
{
  //points
  ctrl_pt[curve][1][0]=0; ctrl_pt[curve][1][1]=255;//point 1 en 0 0

  ctrl_pt[curve][2][0]=12; ctrl_pt[curve][2][1]=255-45;//point 1 en 0 0
  ctrl_pt[curve][3][0]=45; ctrl_pt[curve][3][1]=255-103;//point 1 en 0 0
  ctrl_pt[curve][4][0]=157; ctrl_pt[curve][4][1]=255-178;//point 1 en 0 0

  ctrl_pt[curve][5][0]=255; ctrl_pt[curve][5][1]=0;//point 5 en 255 255

  the_spline_level[curve]=176;
  index_spline_level=176;
  spline_level=(((float)index_spline_level)/127)-1;
  curviness = ftofix(spline_level);
  int node_count=6;
  calc_tangents(node_count);
  draw_splines(gc,node_count);
  //write_curve(); //fait planter si debordement de memoire
  view_after_draw(gc);
  return(0);
}

/**
 * Function to do something
 * @param curve index of the chosen curve (0..15)
 * @param gc graphic context
 **/
int Spline::build_preheat(int curve,const graphic_context& gc)
{
  //points
  ctrl_pt[curve][1][0]=0; ctrl_pt[curve][1][1]=255-28;//point 1 en 0 0

  ctrl_pt[curve][2][0]=40; ctrl_pt[curve][2][1]=255-86;//point 1 en 0 0
  ctrl_pt[curve][3][0]=102; ctrl_pt[curve][3][1]=255-163;//point 1 en 0 0
  ctrl_pt[curve][4][0]=187; ctrl_pt[curve][4][1]=255-235;//point 1 en 0 0

  ctrl_pt[curve][5][0]=255; ctrl_pt[curve][5][1]=0;//point 5 en 255 255

  the_spline_level[curve]=176;
  index_spline_level=178;
  spline_level=(((float)index_spline_level)/127)-1;
  curviness = ftofix(spline_level);
  int node_count=6;
  calc_tangents(node_count);
  draw_splines(gc,node_count);
  //write_curve(); //fait planter si debordement de memoire
  view_after_draw(gc);
  return(0);
}


/**
 * Function to do something
 * @param curve index of the chosen curve (0..15)
 * @param gc graphic context
 **/
int Spline::build_inverse(int curve,const graphic_context& gc)
{
  //points
  for (int pt=1;pt<MAX_CNODES-1;pt++)
    {
      ctrl_pt[curve][pt][0]=(int)((((float)255)/6) *pt);
      ctrl_pt[curve][pt][1]=(int)((((float)255)/6) *pt);
    }
  ctrl_pt[curve][1][0]=0; ctrl_pt[curve][1][1]=0;//point 1 en 0 0
  ctrl_pt[curve][5][0]=255; ctrl_pt[curve][5][1]=255;//point 5 en 255 255
  the_spline_level[curve]=168;
  index_spline_level=168;
  spline_level=(((float)index_spline_level)/127)-1;
  curviness = ftofix(spline_level);
  int node_count=6;
  calc_tangents(node_count);
  draw_splines(gc,node_count);
  //write_curve(); //fait planter si debordement de memoire
  view_after_draw(gc);
  return(0);
}

/**
 * Stream dump function
 * @param o an output stream
 * @return the output stream after the dump
 **/
std::ostream & operator << (std::ostream &o, const Spline & s){
  o << "Objet Spline{\n";
  // nodes
  o << "  nodes: " ;
  for (int i= 0; i<MAX_CNODES; i++) o << s.nodes[i] << " ";
  o << "\n";
  o  << "}\n";
  return o;
}
