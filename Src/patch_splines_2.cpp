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

* \file patch_splines_2.cpp
* \brief Curves calcul for each canal in the patch
* \author Christoph Guillermet
* \author Georges Khaznadar
* \version 0.8.6
* \date 21/06/2014

 White Cat {- categorie} {- sous categorie {- sous categorie}}

*   Fonction de calcul des courbes dans le patch dmx
*
*   Calcul fonction of the curves in the dmx patch
*
**/

#include <allegro.h>         /* => typedef int32_t fixed; */

#include "patch_splines_2.h"  /* headers for definitions coded below */

/**
 * The constructor
 * @param ax abscissa
 * @param ay ordinate
 * @param atangent slope
 **/
curve_node::curve_node(int ax, int ay, fixed atangent):
  x(ax), y(ay), tangent(atangent){
}

/**
 * calculates the distance between this and another curve_node
 * @param other second node
 * @result the distance from this to the other
 **/
fixed curve_node::dist(const curve_node& other) const
{
   #define SCALE  64

   fixed dx = itofix(this->x - other.x) / SCALE;
   fixed dy = itofix(this->y - other.y) / SCALE;

   return fixsqrt(fixmul(dx, dx) + fixmul(dy, dy)) * SCALE;
}


/* constructs nodes to go at the ends of the list, for tangent calculations */
curve_node&  curve_node::dummy(const curve_node& prev)
{
  curve_node * n = new curve_node(this->x - (prev.x - this->x) / 8,
				  this->y - (prev.y - this->y) / 8,
				  itofix(0));
  return *n;
}
