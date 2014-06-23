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
* \brief {Curves calcul for each canal in the patch}
* \author Georges Khaznadar
* \version {0.8.6}
* \date {28/0421/06/2014}

 White Cat {- categorie} {- sous categorie {- sous categorie}}

*   Fonction de calcul des courbes dans le patch dmx
*
*   Calcul fonction of the curves in the dmx patch
*
**/

//Curves splines

#define MAX_CNODES    8

class graphic_context{
 public:
  int window_focus_id;
  int W_PATCH;
  int mouse_x;
  int mouse_y;
  int xpatch_window;
  int ypatch_window;
  int dmx_view;

  /**
   * The constructor of a graphic context
   * @param window_focus_id identifier of the windows owning the focus
   * @param W_PATCH identifier of a particular window
   * @param mouse_x abscissa of the mouse cursor
   * @param mouse_y ordinate of the mouse cursor
   * @param xpatch_window abscissa of the patch window
   * @param ypatch_window ordinate of the patch window
   * @param dmx_view an integer code to define the view mode of DMX: 0 means percentage of intensity, 1 means DMX unity (0..255)
   **/
  inline graphic_context(int window_focus_id, int W_PATCH, int mouse_x, int mouse_y, int xpatch_window, int ypatch_window, int dmx_view):
    window_focus_id(window_focus_id),
    W_PATCH(W_PATCH),
    mouse_x(mouse_x),
    mouse_y(mouse_y),
    xpatch_window(xpatch_window),
    ypatch_window(),
    dmx_view(){
  };
};

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
  int build_square(int curve, const graphic_context& gc);
  int build_fluo(int curve, const graphic_context& gc);
  int build_preheat(int curve, const graphic_context& gc);
  int build_inverse(int curve, const graphic_context& gc);

  /* static members */
  static bool index_writing;
  static float spline_level; //report en float
  static int selected;
  static int the_spline_level[16];
  static int report[16][256];
  static int index_spline_level;//pixels de l editeur
  static bool index_enable_editing;
  static int curves[514];//bug ?514 était en 513
  static int ctrl_pt[16][8][2]; //5 pts de controls (  pour caller 1er et dernier dummy)
  static int diam;//diametre de la poignee pour saisie du curve_node
  static curve_node nodes[MAX_CNODES];
  static int node_count;
  static fixed curviness;
};

#endif /* patch_splines_2_h */
