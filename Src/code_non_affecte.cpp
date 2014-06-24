/**
 * function to do something
 * @param XCurv abscissa of something
 * @param YCurv ordinate of something
 * @param gc a graphic context
 * @param string_Last_Order a buffer to get a formatted message
 **/
int curve_node::do_logical_menu(int XCurv, int YCurv, graphic_context& gc, char* string_Last_Order)
{
  if(gc.mouse_x > (XCurv+30) &&
     gc.mouse_x < (XCurv+30+50) &&
     gc.mouse_y >( YCurv+10) && 
     gc.mouse_y < (YCurv+10+20))
    {
      index_enable_editing=toggle(index_enable_editing);
      gc.mouse_released=1;
    }

  for(int l=0;l<4;l++)
    {
      for (int curvenumber=0;curvenumber<4;curvenumber++)
	{
	  if(gc.mouse_x>(XCurv+20+(curvenumber*70)) &&
	     gc.mouse_x<(XCurv+20+(curvenumber*70)+60) && 
	     gc.mouse_y>(YCurv+370+(30*l)) &&
	     gc.mouse_y<(YCurv+370+(30*l))+20)
	    {
	      selected=curvenumber+(l*4);
	      //courbe droite
	      if(index_reset==1 && 
		 index_enable_editing==1 && 
		 index_square==0 && 
		 index_fluo==0 && index_preheat==0)
		{
		  build_default_curve(selected,gc);
		  index_reset=0;
		  gc.mouse_released=1;
		}
	      //courbe TV
	      else if (index_square==1 &&  
		       index_enable_editing==1 && 
		       index_reset==0 && 
		       index_fluo==0 && 
		       index_preheat==0)
		{
		  build_square(selected,gc);
		  index_square=0;
		  gc.mouse_released=1;
		}
	      //courbe preheat
	      else if (index_preheat==1 && 
		       index_enable_editing==1 && 
		       index_square==0 && 
		       index_reset==0 && 
		       index_fluo==0  )
		{
		  build_preheat(selected,gc);
		  index_preheat=0;
		  gc.mouse_released=1;
		}
	      //courbe fluo
	      else if (index_fluo==1 && 
		       index_enable_editing==1 && 
		       index_square==0 && 
		       index_reset==0 && 
		       index_preheat==0)
		{
		  build_fluo(selected,gc);
		  index_fluo=0;
		  gc.mouse_released=1;
		}

	      else if(index_reset==0 && 
		      index_square==0 && 
		      index_fluo==0 && 
		      index_preheat==0 && 
		      gc.mouse_released==0)//selection du curve
		{
		  load_temp();
		  gc.mouse_released=1;
		}
	    }

	}
    }

  // CHOIX PRESET DE CURVE///////////////////////////////////////////////////////////////////

  for (int act=0;act<4;act++)
    {
      ///ACTIONS
      if(mouse_x>(XCurv+20+(act*70)) && 
	 mouse_x<(XCurv+20+(act*70)+60) && 
	 mouse_y>(YCurv+510) && 
	 mouse_y<(YCurv+510)+20)
	{
	  switch(act)
	    {
	    case 0:
	      if(index_reset==0){
		clear_indexes();
		index_reset=1; 
	      }
	      else if (index_reset==1){
		index_reset=0; 
	      }
	      break;
	    case 1:
	      if(index_square==0){
		clear_indexes();
		index_square=1;
	      }
	      else if (index_square==1){
		index_square=0; 
	      }
	      break;
	    case 2:
	      if(index_preheat==0){
		clear_indexes();
		index_preheat=1; 
	      }
	      else if (index_preheat==1){
		index_preheat=0;
	      }
	      break;
	    case 3:
	      if(index_fluo==0){
		clear_indexes();
		index_fluo=1; 
	      }
	      else if (index_fluo==1){
		index_fluo=0; 
	      }
	      break;
	    }
	  gc.mouse_released=1;
	}
    }
  /////////////////////AFFECTATION AUX DIMERS SELECTIONNES///////////////////////////

  if(mouse_x>XCurv+65 && 
     mouse_x<XCurv+65+200 && 
     mouse_y>YCurv+560 && 
     mouse_y<YCurv+560+30)
    {
      do_affectation();
      unselect_all_dimmers();
      snprintf(string_Last_Order, BUFFER_LENGTH-1, 
	       ">>Affected Curve  %d to Dimmer", selected);
      gc.mouse_released=1;
    }

  return(0);
}

/**
 * recopie une courbe temporaire
 **/
int curve_node::load_temp()
{
  index_spline_level=the_spline_level[selected];   
  //pixels de l editeur    le float est recalculé dans la boucle
  return(0);
}

/**
 * remet les index des courbes à zéro
 **/
int curve_node::clear_indexes()
{
    index_reset=0;
    index_square=0;
    index_fluo=0;
    index_preheat=0;
    return(0);
}

/**
 * copies the selected setting into the table curves[]
 * according to the boolean vector Dimmers_selected
 **/
int curve_node::do_affectation()
{
  for(int k=0;k<513;k++)
    {
      if(Dimmers_selected[k]==1)
	{curves[k]=selected;}
    }
  return(0);
}

/**
 * reset the boolean vector Dimmers_selected
 **/
int curve_node::unselect_all_dimmers()
{
    for(int i=0; i<513; i++)
    {
        Dimmers_selected[i]=0;
    }
    return(0);
}

/**
 * fills the boolean vector Dimmers_selected with ones
 **/
int curve_node::select_all_dimmers()
{
    for(int i=0; i<513; i++)
    {
        Dimmers_selected[i]=1;
    }
    return(0);
}

/* initialization of index_build_patch_from_plot */
bool curve_node::index_build_patch_from_plot=1;
/* initialization of nbre_gelats_manufact */
int curve_node::nbre_gelats_manufact=3; //0: LEE 1: ROSCO 2: GAMCOLOR 3: Apollo
/* initialization of shape_id_to_select */
int curve_node::shape_id_to_select=0;


/**
 * function to do something
 **/
int  curve_node::clear_selected()
{
  for(int i=0; i<513; i++)
    {
      if(Dimmers_selected[i]==1)
        {
	  Patch[i]=0;
	  curves[i]=0;
	  if(index_build_patch_from_plot==1)
            {
	      for(int c=0; c<4; c++)
                {
		  for(int s=1; s<=nbre_symbols_on_plot[c]; s++)
                    {
		      if(symbol_dimmer_is[c][s]==i)
                        {
			  symbol_dimmer_is[c][s]=0;
                        }
                    }
                }
            }
        }
    }

  return(0);
}

/**
 * function checking whether a channel is patched at least once
 * @param ch channel number
 * @return true if the channel is patched once or more, false 
 * if the channel is not patched
 **/
int  curve_node::check_channel_is_patched(int ch)
{
  bool the_ch_is_patched=0;
  for (int cpatch=1; cpatch<513; cpatch++)
    {
      if(Patch[cpatch]==ch)
        {
	  the_ch_is_patched=1;
        }
    }
  return(the_ch_is_patched);
}

/**
 * function to do someting
 **/
int curve_node::generate_channel_preview_patch_list()
//affichage du premier grada
{
  reset_channel_first_dimmer_list();

  for (int ch=1; ch<513; ch++)
    {
      int index=0;
      for(int d=1; d<513; d++)
        {
	  if(Patch[d]==ch  )
            {
	      bool tem=0;
	      if(index>3)
                {
		  tem=1;
                }
	      switch(tem)
                {
                case 0:
		  show_first_dim_array[ch][index]=d;
		  index++;
		  break;
                case 1:
		  show_more_than_one_dim[ch]=1;
		  break;
                }
            }


        }
    }
  return(0);
}

/**
 * function to do something
 **/
int curve_node::reset_channel_first_dimmer_list()
{
    for (int ch=1; ch<513; ch++)
    {
        for(int d=0; d<4; d++)
        {
            show_first_dim_array[ch][d]=0;
        }
        show_more_than_one_dim[ch]=0;
    }
    return(0);
}

