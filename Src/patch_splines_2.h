#ifndef patch_splines_2_h
#define patch_splines_2_h
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

* \file patch_splines_2.h
* \brief Functions for each channel in the dmx patch
* \author Georges Khaznadar
* \version {0.8.6}
* \date {28/0421/06/2014}

 White Cat {- categorie} {- sous categorie {- sous categorie}}

*   Fonction de calcul des courbes dans le patch dmx
*
*   Functions to calculate the curves in the dmx patch
*
**/

#include "graphic_context.h"

//Curves splines

/**
 * @class curve_node
 * @brief implements one node of a spline curve
 *
 * the implementation is provisory, it keeps many features of the
 * older non-object implementation, so there are quite a few public
 * static data coming from various parts of whitecat.
 **/
class curve_node
{
 public:
  int x, y;
  fixed tangent;

  curve_node(int ax, int ay, fixed atangent);
  fixed dist(const curve_node& other);
  curve_node& dummy(const curve_node& prev);
  void calc_tangents(void);
  void get_control_points(const curve_node& other, int points[8]);
  int write_curve(const graphic_context& gc);
  int draw(int n, const graphic_context& gc);
  int draw_splines(const graphic_context& gc);
  int view_after_draw(const graphic_context& gc);
  int SplineCurve(const graphic_context& gc);
  int build_default_curve(int curve, graphic_context& gc);
  int build_square(int curve, const graphic_context& gc);
  int build_fluo(int curve, const graphic_context& gc);
  int build_preheat(int curve, const graphic_context& gc);
  int build_inverse(int curve, const graphic_context& gc);
  int do_logical_menu(int XCurv, int YCurv, graphic_context& gc);

  /* static members */
  static bool index_writing;
  static bool index_enable_editing;
  static bool index_reset;
  static bool index_square;
  static bool index_fluo;
  static bool index_preheat;
  static float spline_level; //report en float
  static int selected;
  static int the_spline_level[16];
  static int report[16][256];
  static int index_spline_level;//pixels de l editeur
  static int curves[514];//bug ?514 était en 513
  static int ctrl_pt[16][8][2]; //5 pts de controls (  pour caller 1er et dernier dummy)
  static int diam;//diametre de la poignee pour saisie du curve_node
  static int node_count;
  static fixed curviness;

 private:
  /**
   * @macro
   * @brief number of nodes in a spline curve.
   **/
#define CNODES 5
  /**
   * @macro
   * @brief This quirk should disappear
   *
   * it has been borrowed from the ancient code, where it was necessary
   * to prevent overflows
   **/
#define CNODES_OVERFLOW_QUIRK 3
  /**
   * @macro
   * @brief sum of CNODES and CNODES_OVERFLOW_QUIRK
   **/
#define MAX_CNODES CNODES + CNODES_OVERFLOW_QUIRK
  /**
   * @var static curve_node nodes
   * @brief table of nodes to control a spline curve
   * 
   * there should be 5 nodes, 2 at both ends, and 3 inbetween
   * the ancient version of this implementation defined 8 places in the
   * table to prevent overflows, let us begin with this quirk
   **/
  static curve_node nodes[MAX_CNODES]; 
};

#endif /* patch_splines_2_h */
