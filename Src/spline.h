#ifndef spline_h_included
#define spline_h_included
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


#include "curve_node.h"
#include <iostream> 

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
 * @class Spline
 * @brief implements a small spline
 *
 * with 2 points at both ends and three points inbetween.
 **/
class Spline{
 private:
  /**
   * @var curve_node nodes[5]
   * @brief table of nodes to control a spline curve
   * 
   * there should be 5 nodes, 2 at both ends, and 3 inbetween
   * the ancient version of this implementation defined 8 places in the
   * table to prevent overflows, let us begin with this quirk
   **/
  curve_node nodes[MAX_CNODES];
  int ctrl_pt[16][8][2]; //5 pts de controls (  pour caller 1er et dernier dummy)
  int the_spline_level[16];
  int index_spline_level; //pixels de l editeur
 protected:
  static bool index_writing;
  static int selected;
  static bool index_enable_editing;
  static bool index_reset;
  static bool index_square;
  static bool index_fluo;
  static bool index_preheat;
  int diam; //diametre de la poignee pour saisie du curve_node
  fixed curviness;
  float spline_level; //report en float
  int report[16][256];
  friend std::ostream & operator << (std::ostream &o, const Spline & s);

 public:
  /**
   * The constructor
   * @param adiam the diameter of circles to display for nodes (10 by default)
   **/
  inline Spline(int diam=10):
  diam(diam){
  };

  void calc_tangents(int & node_count);
  int write_curve(const graphic_context& gc, int & node_count);
  void get_control_points(int i1, int i2, int points[8]);
  int draw(int n, const graphic_context& gc, int & node_count);
  int draw_splines(const graphic_context& gc, int & node_count);
  int view_after_draw(const graphic_context& gc);
  int SplineCurve(const graphic_context& gc);
  int build_default_curve(int curve, graphic_context& gc);
  int build_square(int curve, const graphic_context& gc);
  int build_fluo(int curve, const graphic_context& gc);
  int build_preheat(int curve, const graphic_context& gc);
  int build_inverse(int curve, const graphic_context& gc);
};

#endif //spline_h_included
