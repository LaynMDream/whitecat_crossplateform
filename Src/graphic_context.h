#ifndef graphic_context_h
#define graphic_context_h
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
 * @file graphic_context.h
 * @brief Elements of the graphic context, 
 *
 * initially to comply with the 
 * new version of patch_splines_2
 *
 * @author Georges Khaznadar
 * @version 0.8.6
 * @date 23/06/2014
 **/

/**
 * @class graphic_context
 * @brief This class may be provisory.
 *
 * It allows other parts of the program to be compatible with newer parts
 * which are coded with "object" style.
 **/
class graphic_context{
 public:
  /** 
   * @var int window_focus_id
   * identifier of the windows owning the focus 
   * @var int W_PATCH 
   * identifier of a particular window
   * @var int mouse_x
   * abscissa of the mouse cursor
   * @var int mouse_y
   * ordinate of the mouse cursor
   * @var int xpatch_window
   * abscissa of the patch window
   * @var int ypatch_window
   * ordinate of the patch window
   * @var int dmx_view
   * an integer code to define the view mode of DMX: 
   * 0 means percentage of intensity, 1 means DMX unity (0..255)
   **/
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

#endif // graphic_context_h
