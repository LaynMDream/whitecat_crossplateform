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

* \file save_show_load.cpp
* \brief {save and load fonctions}
* \author Christoph Guillermet
* \version {0.8.6.1}
* \date {16/06/2014}
 White Cat {- categorie} {- sous categorie {- sous categorie}}

*   Fonctions de lecture des données d'un spectacle
*
*   Load show functions
*
**/

//sab 06/09/2014 DEB
void Read_Data_from_File(const char * data_filename, void * data_ptr, size_t singledata_size, unsigned int data_size)
{
    FILE *fp;

    if ((fp=fopen( data_filename, "rb"))==NULL)
    {
        sprintf(string_save_load_report[idf],"Error opening file %s", data_filename);
        b_report_error[idf]=1;
    }
    else
    {
        //sprintf(string_save_load_report[idf],"Opening file %s",  filename);
        if (fread(data_ptr, sizeof(bool),data_size, fp) !=data_size)
        {
            sprintf(string_save_load_report[idf],"Size Error from %s", data_filename);
            b_report_error[idf]=1;
        }
        else
            sprintf(string_save_load_report[idf],"Data Loaded from %s", data_filename);
        fclose(fp);
    }

    idf++;
}
//sab 06/09/2014 FIN

int load_midipreset()
{
    char temp_folder_midi[256];
    sprintf(temp_folder_midi,"%s\\midi_presets\\%s",mondirectory,midipreset_name);
    chdir(temp_folder_midi);

	Read_Data_from_File(file_midi_affectation, miditable,     sizeof(int), midi_affectation_size);
	Read_Data_from_File(file_midi_send_out,    midi_send_out, sizeof(bool),midi_send_out_size);

    load_Fader_state_to_midi_array();

	//REROLL
    strcpy(rep,"");
    sprintf(rep,"%s",mondirectory);
    chdir (rep);

    return(0);
}

int load_onstart_config()
{
    FILE *cfg_file = NULL ;
    char read_buff_winfil[ 512 ] ;
    //sab 02/03/2014 unused var int it=0;
    cfg_file = fopen("user/config_onstart.txt", "rt" );
    if( !cfg_file )
    {
        sprintf(string_save_load_report[idf],"!config_onstart.txt");
    }
    else
    {
        //premiere ligne les args
        if( !fgets( read_buff_winfil , sizeof( read_buff_winfil ) ,cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"! config_onstart.txt");
        }

        fscanf( cfg_file , "%d / %d / %d / %d /\n" ,  &load_camera_on_start, &open_arduino_on_open , &enable_iCat, &expert_mode);

        fclose( cfg_file );
    }
    return(0);
}

int load_screen_config()
{
    FILE *cfg_file = NULL ;
    char read_buff_winfil[ 512 ] ;
    //sab 02/03/2014 unused var int it=0;
    cfg_file = fopen("user/config_screens.txt", "rt" );
    if( !cfg_file )
    {
        sprintf(string_save_load_report[idf],"!config_screens.txt");
    }
    else
    {
        //premiere ligne les args
        if( !fgets( read_buff_winfil , sizeof( read_buff_winfil ) ,cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"! config_screens.txt");
        }

        fscanf( cfg_file , "%d / %d %d / %d %d /\n" ,  &index_fullscreen, &largeur_ecran, &hauteur_ecran, &posX_mainwindow, &posY_mainwindow);

        fclose( cfg_file );
    }

    return(0);
}

int load_core_config()
{
    FILE *cfg_file = NULL ;
    char read_buff_winfil[ 512 ] ;
    //sab 02/03/2014 unused var int it=0;
    cfg_file = fopen("user/config_core.txt", "rt" );
    if( !cfg_file )
    {
        sprintf(string_save_load_report[idf],"!config_core.txt");
    }
    else
    {
        //premiere ligne les args
        if( !fgets( read_buff_winfil , sizeof( read_buff_winfil ) ,cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"! config_core.txt");
        }
        else
        {
            fscanf( cfg_file , "%d / %d / %d / %d / %d / %d / %d /\n"  , &core_user_define_nb_faders, &core_user_define_nb_docks , &core_user_define_nb_chasers, &core_user_define_nb_tracks_per_chasers, &core_user_define_nb_gridplayers, &core_user_define_nb_bangers, &core_user_define_nb_echo);
        }
        //deuxieme ligne les args
        if( !fgets( read_buff_winfil , sizeof( read_buff_winfil ) ,cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"! config_core.txt");
        }
        else
        {
            fscanf( cfg_file , "%d / %d / %d / %d / %d / %d / %d / %d / %d /\n"  ,&core_do_calculations[0],&core_do_calculations[1],&core_do_calculations[2],
                    &core_do_calculations[3],&core_do_calculations[4],&core_do_calculations[5],&core_do_calculations[6],&core_do_calculations[7],&core_do_calculations[8]  );
        }
        //troisieme ligne les args
        if( !fgets( read_buff_winfil , sizeof( read_buff_winfil ) ,cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"! config_core.txt");
        }
        else
        {
            fscanf( cfg_file , "%d / %d /\n",&BPS_RATE,&dmxINrate);
        }

        fclose( cfg_file );
    }
    return(0);
}

int Load_Launchpad_RetroLight()
{
    FILE *cfg_file = NULL ;
    char read_buff_winfil[ 512 ] ;
    //sab 02/03/2014 unused var int it=0;
    cfg_file = fopen("user/launchpad_lighting.txt", "rt" );
    if( !cfg_file )
    {
        sprintf(string_save_load_report[idf],"! launchpad_lighting.txt");
    }
    else
    {
        //premiere ligne les args
        if( !fgets( read_buff_winfil , sizeof( read_buff_winfil ) ,cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"! launchpad_lighting.txt");
        }

        fscanf( cfg_file ,  "%d / %d / %d / %d / %d / %d /\n" ,  &lch_orange, &lch_green, &lch_yellow, &lch_red, &lch_ambre, &lch_orange_fonce);

        fclose( cfg_file );
    }

    launchpad_color[0]=lch_orange;//63;
    launchpad_color[1]=lch_green;//60;
    launchpad_color[2]=lch_yellow;//62;
    launchpad_color[3]=lch_red;//15;
    launchpad_color[4]=lch_ambre;//31;
    launchpad_color[5]=lch_orange_fonce;//30;
    return(0);
}

int load_draw_preset_config()
{
    FILE *cfg_file = NULL ;
    char read_buff_winfil[ 512 ] ;
    cfg_file = fopen("draw_presets_states.txt", "rt" );
    if( !cfg_file )
    {
        sprintf(string_save_load_report[idf],"!draw_presets_states.txt");
    }

    else
    {

        if( !fgets( read_buff_winfil , sizeof( read_buff_winfil ) ,cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"! draw_presets_states.txt");
        }

        for(int i=0; i<6; i++)
        {

            if( !fgets( read_buff_winfil , sizeof( read_buff_winfil ) ,cfg_file ) )
            {
                sprintf(string_save_load_report[idf],"! draw_presets_states.txt");
            }

            if( !fgets( read_buff_winfil , sizeof( read_buff_winfil ) ,cfg_file ) )
            {
                sprintf(string_save_load_report[idf],"! draw_presets_states.txt");
            }

            fscanf( cfg_file , "M %d / %f / %f / %f / %d /\n" , &draw_mode[i], &draw_level_to_do[i], &draw_tilt_to_do[i] ,&draw_ghost_to_do[i], &draw_brush_type[i]);

            fscanf( cfg_file , "G %d / %d / %d / %d / %d /\n" ,&draw_get_gpl[i],&draw_offset_gpl[i], &index_case[i], &draw_centre_x[i], &draw_centre_y[i]);

            previous_draw_mode[i]=draw_mode[i];
            draw_get_gpl[i]=constrain_int_data_to_this_range(draw_get_gpl[i],1,4);
            draw_offset_gpl[i]=constrain_int_data_to_this_range(draw_offset_gpl[i],1,512);

            if(draw_level_to_do[i]>1.0)
            {
                draw_level_to_do[i]=1.0;
            }
            if(draw_tilt_to_do[i]>1.0)
            {
                draw_tilt_to_do[i]=1.0;
            }
            if(draw_ghost_to_do[i]>1.0)
            {
                draw_ghost_to_do[i]=1.0;
            }

        }
        fclose( cfg_file );
    }

    return(0);
}

int load_arduino_config()
{
    FILE *cfg_file = NULL ;
    char read_buff_winfil[ 512 ] ;
    //sab 02/03/2014 unused var int it=0;
    cfg_file = fopen("arduino.txt", "rt" );
    if( !cfg_file )
    {
        sprintf(string_save_load_report[idf],"!arduino.txt");
    }
    else
    {
        //premiere ligne les args
        if( !fgets( read_buff_winfil , sizeof( read_buff_winfil ) ,cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"! arduino.txt");
        }

        fscanf( cfg_file , "%d / %d / %d / %d / %d / %d /\n" ,  &arduino_com0, &arduino_baud_rate0, &ARDUINO_RATE, &arduino_max_digital,  &arduino_max_out_digi, &arduino_max_analog );
        fclose( cfg_file );
    }
    return(0);
}

//user: windows
int Load_Window_Conf()
{
    FILE *cfg_file = NULL ;
    char read_buff_winfil[ 512 ] ;
    //sab 02/03/2014 unused var int it=0;
    cfg_file = fopen("config_windows.txt", "rt" );
    if( !cfg_file )
    {
        sprintf(string_save_load_report[idf],"!config_windows.txt");
    }
    else
    {
//premiere ligne les args
        if( !fgets( read_buff_winfil , sizeof( read_buff_winfil ) ,cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"! config_windows.txt");
        }
        fscanf( cfg_file , "%d %d / %d %d / %d %d / %d %d /\n" ,  &xtrichro_window, &ytrichro_window, &xnum_window,&ynum_window,&videoX,&videoY, &xpatch_window, &ypatch_window);
//2eme ligne
        if( !fgets( read_buff_winfil, sizeof( read_buff_winfil ) ,cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"Error reading config_windows.txt");
        }
        fscanf( cfg_file , "%d %d / %d %d / %d %d /\n" ,  &report_SL_X, &report_SL_Y , &xtime_window, &ytime_window,&xseq_window, &yseq_window);
//3eme ligne
        if( !fgets( read_buff_winfil, sizeof( read_buff_winfil ) ,cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"Error reading config_windows.txt");
        }
        fscanf( cfg_file ,"%d / %d %d / %d %d /\n",&YFader, &XConfirm, &YConfirm, &xsave_window, &ysave_window );
//4eme ligne
        if( !fgets( read_buff_winfil, sizeof( read_buff_winfil ) ,cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"Error reading config_windows.txt");
        }
        fscanf( cfg_file ,"%d %d / %d %d / %d %d / %d %d /\n",&XAlarm,&YAlarm,&XAudio,&YAudio, &window_cfgX, &window_cfgY, &X_banger, &Y_banger);
//5eme ligne
        if( !fgets( read_buff_winfil, sizeof( read_buff_winfil ) ,cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"Error reading config_windows.txt");
        }
        fscanf( cfg_file ,"%d %d / %d %d / %d %d / %d %d / %d %d /\n",&Xwizard,&Ywizard,&xMinifaders,&yMinifaders, &Xlistproj, &Ylistproj, &Xchasers, &Ychasers,&xmover_window, &ymover_window);

//6eme ligne
        if( !fgets( read_buff_winfil, sizeof( read_buff_winfil ) ,cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"Error reading config_windows.txt");
        }
        fscanf( cfg_file ,"%d %d / %d %d / %d %d / %d %d / %d %d / %d %d /\n",&X_gui_iCat,&Y_gui_iCat,&grider_window_x,&grider_window_y, &x_plot, &y_plot, &x_mainmenu, &y_mainmenu , &x_Wdraw, &y_Wdraw, &x_echo, &y_echo);


        fclose( cfg_file );
    }
    return(0);
}

int Load_Sequenciel_Conf()
{
    FILE *cfg_file = NULL ;
    char read_buff_winfil[ 512 ] ;
    //sab 02/03/2014 unused var int it=0;
    cfg_file = fopen("sequenciel.txt", "rt" );
    if( !cfg_file )
    {
        sprintf(string_save_load_report[idf],"Error on opening Sequenciel.txt");
        b_report_error[idf]=1;
    }
    else
    {
        sprintf(string_save_load_report[idf],"Sequenciel.txt opened");
//premiere ligne les args
        if( !fgets( read_buff_winfil , sizeof( read_buff_winfil ) ,cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"Error on reading Sequenciel.txt");
            b_report_error[idf]=1;
        }
        else
        {
            sprintf(string_save_load_report[idf],"Sequenciel.txt readed");
        }
        fscanf( cfg_file , "%d / %d / %d / %d / %d /\n" ,  &position_onstage, &position_preset, &niveauX1, &niveauX2, &crossfade_speed);
        fscanf( cfg_file , "%f /\n" ,  &default_time);
        fscanf( cfg_file , "%d %d /\n" ,  &go_channel_is, &pause_channel_is);
        fclose( cfg_file );
    }
    midi_levels[491]=niveauX1/2;
    midi_levels[492]=127-(niveauX2/2);
    midi_levels[493]=crossfade_speed;
    if(go_channel_is<1 || ( go_channel_is> 512))
    {
        go_channel_is=0;
    }
    if(pause_channel_is<1 || ( pause_channel_is> 512))
    {
        pause_channel_is=0;
    }
    return(0);
}

int Load_setup_conf()
{
    FILE *cfg_file = NULL ;
    char read_buff_winfil[ 512 ] ;
    //sab 02/03/2014 unused var int it=0;
    cfg_file = fopen("user/general_set_up.txt", "rt" );
    if( !cfg_file )
    {
        sprintf(string_save_load_report[idf],"Error on opening user/general_set_up.txt");
        b_report_error[idf]=1;
    }
    else
    {
        sprintf(string_save_load_report[idf],"user/general_set_up.txt opened");
//premiere ligne les args
        if( !fgets( read_buff_winfil , sizeof( read_buff_winfil ) ,cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"Error on reading user/general_set_up.txt");
            b_report_error[idf]=1;
        }
        else
        {
            sprintf(string_save_load_report[idf],"user/general_set_up.txt readed");
        }
        fscanf( cfg_file , "%d / %d / %d / %d / %d / %d / %d / %d / %f /\n" , &default_step_level, &wheellevel_absolutemode, &check_channel_level,
                &dimmer_check_level, &index_blink_change_memories, &index_midi_auto_desaffect, &dmx_view, &index_preloaded_sounds, &default_time_of_the_bang);
//2eme ligne
        if( !fgets( read_buff_winfil, sizeof( read_buff_winfil ) ,cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"Error reading general_set_up.txt");
        }
        fscanf( cfg_file , "%d / %d / %d /\n",&automatic_time_for_save, &index_nbre_players_visibles, &LargeurEspaceFaderSize);

        fclose( cfg_file );
    }

    if(LargeurEspaceFaderSize<1024 )
    {
        LargeurEspaceFaderSize=1024;
    }
    if(LargeurEspaceFaderSize>largeur_ecran)
    {
        LargeurEspaceFaderSize=largeur_ecran;
    }

    return(0);
}

int load_indexes()
{
    auto_reset_crossfade_speed_on_link=index_report_customs[0];
    nbre_memoires_visualisables_en_preset=index_report_customs[1];
    index_midi_global_thruth=index_report_customs[2];
    refresh_midi_chasers=index_report_customs[3];
    view_plot_calc_number_is=index_report_customs[4];
    index_menus_lighting_plot=index_report_customs[5];
    symbol_selected_type=index_report_customs[6];
    shape_selected_type=index_report_customs[7];
    legend_view=index_report_customs[8];
    ClassicalChannelView=index_report_customs[9];
    index_config_dmx=index_report_customs[10];
    index_config_midi=index_report_customs[11];
    index_config_arduino=index_report_customs[12];
    midi_page=index_report_customs[13];
    config_color_style_is=index_report_customs[14];
    index_link_is_on=index_report_customs[15];
    index_decay_tracker=index_report_customs[16];
    adapater_is_selected=index_report_customs[17];
    index_build_patch_from_plot=index_report_customs[18];
    index_menu_curve=index_report_customs[19];
    index_show_first_dim=index_report_customs[20];
    cheat_key_off=index_report_customs[21];
    scroll_faderspace=index_report_customs[22];
    draw_preset_selected=index_report_customs[23];
    index_banger_is_on=index_report_customs[24];
    index_banger_selected=index_report_customs[25];
    index_save_mode_export_or_binary=index_report_customs[26];
    index_allow_sunlite_dmxIN=index_report_customs[27];//sunlite
    index_config_general=index_report_customs[28];
    niveauGMaster=index_report_customs[29];//grand master
//tochanDMXIN=index_report_customs[30];//usbdmx512online
//VellemanMaxGradas=index_report_customs[31];//Velleman
    echo_selected=index_report_customs[32];
    index_allow_multicore=index_report_customs[33];
    allow_artnet_in=index_report_customs[34];
    window_focus_id=index_report_customs[35];
    recall_windows_focus_id=index_report_customs[36];
    index_config_network=index_report_customs[37];
    index_setup_gfx=index_report_customs[38];
    core_to_assign=index_report_customs[39];
//index_show_config_window=index_report_customs[40];
//index_grider_window=index_report_customs[41];
    show_global_view_grider=index_report_customs[42];
    enable_launchpad=index_report_customs[43];
//index_show_wizard_window=index_report_customs[44];
    config_page_is=index_report_customs[45];
//index_show_minifaders=index_report_customs[46];
//index_window_chasers=index_report_customs[47];
    nbre_track_visualisables=index_report_customs[48];
    chaser_operator_is=index_report_customs[49];
    chaser_selected=index_report_customs[50];
    index_affichage_digit_time_unit=index_report_customs[51];
    launchpad_chaser_mode=index_report_customs[52];
    index_enable_edit_chaser=index_report_customs[53];
    chaser_midi_rows=index_report_customs[54];
    line_list_is=index_report_customs[55];
//name_will_be_for_annotation=index_report_customs[56];
//index_show_mover_window=index_report_customs[57];
//index_window_gui_iCat=index_report_customs[58];
    iCatPageis=index_report_customs[59];
    surface_type=index_report_customs[60];
    grid_icat_modulo=index_report_customs[61];
    index_midi_auto_demute=index_report_customs[62];
    index_midi_mute_on_lfo=index_report_customs[63];
    index_text_auto_close=index_report_customs[64];
    index_config_core=index_report_customs[65];
    show_gridplayer_in_seq=index_report_customs[66];
    index_auto_mute_cuelist_speed=index_report_customs[67];
    Midi_Force_Go=index_report_customs[68];


//icat
    if(surface_type==0)
    {
        L_tablier_iCat=240;
        H_tablier_iCat=160;
    }
    else
    {
        L_tablier_iCat=512;
        H_tablier_iCat=384;
    }
    if(grid_icat_modulo<1)
    {
        grid_icat_modulo=1;
    }

    if(niveauGMaster<255)
    {
        midi_levels[615]=(niveauGMaster/2);
    }
    else if(niveauGMaster==255)
    {
        midi_levels[615]=127;
    }



    if(index_allow_multicore==1 && core_to_assign>0 && core_to_assign<9 && index_allow_multicore==1)
    {
        process_assign_to_core(core_to_assign);
    }

    switch(config_page_is)
    {
    case 0:
        break;
    case 1:
        index_config_dmx=1;
        break;
    case 2:
        index_config_midi=1;
        break;
    case 3:
        index_config_network=1;
        break;
    case 4:
        index_setup_gfx=1;
        break;
    case 5:
        index_config_arduino=1;
        break;
    case 6:
        index_config_general=1;
        break;
    case 7:
        index_config_core=1;
        break;
    }

//nbre memoires sequenciel
    if(nbre_memoires_visualisables_en_preset<5)
    {
        nbre_memoires_visualisables_en_preset=5;
    }
    hauteur_globale_sequenciel=180+(35*(nbre_memoires_visualisables_en_preset+1))+35;

//chaser midi refresh window
    set_refresh_mode_for_chaser(refresh_midi_chasers);


//draw

    return(0);
}

int load_show_coming_from()
{

    FILE *cfg_file = NULL ;
    //sab 02/03/2014 unused var char read_buff_winfil[ 512 ] ;
    //sab 02/03/2014 unused var int it=0;
    cfg_file = fopen("user/show_coming_from.txt", "rt" );
    if( !cfg_file )
    {
        sprintf(string_save_load_report[idf],"Error on opening user/show_coming_from.txt");
        b_report_error[idf]=1;
    }
    else
    {
        sprintf(string_save_load_report[idf],"user/show_coming_from.txt opened");
    }
    fgets( my_show_is_coming_from , sizeof( my_show_is_coming_from ) ,cfg_file ) ;
    fclose( cfg_file );
    sprintf(string_save_load_report[idf],"loaded show_coming_from.txt");

    return(0);
}

int Load_User_Profile()
{

    FILE *fpA;

    if ((fpA=fopen(file_color_profile, "rb"))==NULL)
    {
        sprintf(string_save_load_report[idf],"Error opening file %s", file_color_profile);
    }
    else
    {
        sprintf(string_save_load_report[idf],"Opening file %s",   file_color_profile);
        if (fread( couleurs_user, sizeof(float), color_profile_size, fpA) !=color_profile_size)
        {
            sprintf(string_save_load_report[idf],"Error Loaded %s", file_color_profile);
        }
        else sprintf(string_save_load_report[idf],"Loaded file %s",file_color_profile);
        fclose(fpA);
    }
    for(int tmp=0; tmp<12; tmp++)
    {
        Rgba TmpColor (couleurs_user[tmp][0],couleurs_user[tmp][1],couleurs_user[tmp][2]);

        switch (tmp)
        {
        case 0:
            CouleurUser1=TmpColor;
            break;
        case 1:
            CouleurUser2=TmpColor;
            break;
        case 2:
            CouleurUser3=TmpColor;
            break;
        case 3:
            CouleurUser4=TmpColor;
            break;
        case 4:
            CouleurUser5=TmpColor;
            break;
        case 5:
            CouleurUser6=TmpColor;
            break;
        case 6:
            CouleurUser7=TmpColor;
            break;
        case 7:
            CouleurUser8=TmpColor;
            break;
        case 8:
            CouleurUser9=TmpColor;
            break;
        case 9:
            CouleurUser10=TmpColor;
            break;
        case 10:
            CouleurUser11=TmpColor;
            break;
        case 11:
            CouleurUser12=TmpColor;
            break;
        }
    }
    return(0);
}

int Load_Audio_Conf()
{
    FILE *cfg_file = NULL ;
    char read_buff_winfil[ 512 ] ;
    //sab 02/03/2014 unused var int it=0;
    cfg_file = fopen("audio_conf.txt", "rt" );
    if( !cfg_file )
    {
        sprintf(string_save_load_report[idf],"Error on opening Sequenciel.txt");
        b_report_error[idf]=1;
    }
    else
    {
        sprintf(string_save_load_report[idf],"audio_conf.txt opened");
//premiere ligne les args
        if( !fgets( read_buff_winfil , sizeof( read_buff_winfil ) ,cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"Error on reading audio_conf.txt");
            b_report_error[idf]=1;
        }
        else
        {
            sprintf(string_save_load_report[idf],"audio_conf.txt readed");
        }
        fscanf( cfg_file , "%s\n" ,  audio_folder);
        fclose( cfg_file );
    }


    return(0);
}

void Load_Show()
{
    sprintf(rep,"%s\%s\%s",mondirectory,rep_saves,nomduspectacle);
    chdir (rep);
    reset_error_on_save_load();
    reset_all_bangers();
    clear_report_string();
    idf=0;
    //POUR RAFRAICHIR CORRECTEMENT LES VARIABLES DE POSITIONS DE FENETRES ( TIME WHEEL COLOR WHEEL) AVANT CALCULS
    Load_Window_Conf();

    if(specify_who_to_save_load[0]==1)//MEMOIRES/////////////////////////////////
    {
        save_load_print_to_screen("Loading Memories");
        Read_Data_from_File(file_mem_existantes, MemoiresExistantes, sizeof(bool), mem_existantes_size);
        Read_Data_from_File(file_memories, Memoires, sizeof(unsigned char), memories_size);
        Read_Data_from_File(file_text_mems, descriptif_memoires, sizeof(char), text_mems_size);
        Read_Data_from_File(file_text_annots, annotation_memoires, sizeof(char), text_annots_size);
        Read_Data_from_File(file_mem_detruites, MemoiresDetruites, sizeof(bool), mem_deleted_size);
        Read_Data_from_File(file_mem_exclues, MemoiresExclues, sizeof(bool), mem_exclues_size);
        //
        Load_Sequenciel_Conf();
        idf++;
        //rafraichissement potards midi
        index_send_midi_out[491]=1;
        index_send_midi_out[492]=1;
        index_send_midi_out[493]=1;
        //
        emit_midi_out();
        //
        rest(10);
    }

    if(specify_who_to_save_load[1]==1)///////MEMOIRES TIMES/////////////////////////
        Read_Data_from_File(file_times_mem, Times_Memoires, sizeof(float), times_mems_size);

    if(specify_who_to_save_load[2]==1)/////MEMOIRES LINKS///////////////////////////
        Read_Data_from_File(file_link_mem, Links_Memoires, sizeof(bool), link_mem_size);

    if(specify_who_to_save_load[3]==1)/////MEMOIRES BANGER///////////////////////////
        Read_Data_from_File(file_banger_call_in_mem, Banger_Memoire, sizeof(int), bang_mem_size);

    if(specify_who_to_save_load[4]==1)/////MEMOIRES ratio manuel////////////////////
        Read_Data_from_File(file_manual_ratio_mem, ratio_cross_manuel, sizeof(int), ratio_mem_size);


    if(specify_who_to_save_load[5]==1)//channels LIST////////////////////
    {
        Read_Data_from_File(file_spotlist, descriptif_projecteurs, sizeof(char), spotlist_size);
        Read_Data_from_File(file_chan_macro_on, macro_channel_on, sizeof(bool), chan_macro_on_size);
        Read_Data_from_File(file_chan_macro_reaction, channel_macro_reaction, sizeof(int), chan_macro_reaction_size);
        Read_Data_from_File(file_chan_macro_action, channel_macro_action, sizeof(int), chan_macro_action_size);
        Read_Data_from_File(file_chan_macro_val, channel_macro_val, sizeof(int), chan_macro_val_size);
        Read_Data_from_File(file_chview_ch, Channel_View_ROUTING, sizeof(int), chview_ch_size);
        Read_Data_from_File(file_chview_name, channel_view_Name, sizeof(char), chview_name_size);
        Read_Data_from_File(file_chview_linktype, channel_view_link_type, sizeof(int), chview_linktype_size);
        Read_Data_from_File(file_chview_linkref, channel_view_link_ref, sizeof(int), chview_linkref_size);
        Read_Data_from_File(file_chview_view, Channel_View_MODE, sizeof(bool), chview_view_size);

        for(int i=0; i<nbre_de_vues_circuits; i++)
        {
            count_number_of_channels_in_view(i);
        }

    }

    if(specify_who_to_save_load[6]==1)/////Channels Direct Channels/////////////////
    {
        Read_Data_from_File(file_direct_channel, FaderDirectChan, sizeof(int), fader_direct_chan_size);
		//mise à plat d init si souci
		for(int i=0; i<48; i++)
		{
			for (int j=0; j<6; j++)
			{
				if(FaderDirectChan[i][j]<1)
				{
					FaderDirectChan[i][j]=1;
				}
				if(FaderDirectChan[i][j]>512)
				{
					FaderDirectChan[i][j]=512;
				}
			}
		}
    }


    if(specify_who_to_save_load[7]==1)/////Channels Freeze/////////////////////////
    {
        Read_Data_from_File(file_dofreeze, freeze_array, sizeof(bool), dofreeze_size);
        Read_Data_from_File(file_freeze_state, freeze_state, sizeof(unsigned char), freezestate_size);
        Read_Data_from_File(file_excluded_chan, Channels_excluded_from_grand_master, sizeof(bool), excluded_chan_size);
    }

    if(specify_who_to_save_load[8]==1)/////Patch circuits/////////////////////////////////
    {
        save_load_print_to_screen("Loading Patch");
        Read_Data_from_File(file_patch_channels, Patch, sizeof(int),patch_channels_size);
        generate_channel_view_list_from_patched_circuits();
    }


    if(specify_who_to_save_load[9]==1)/////Patch LTP-HTP/////////////////////////////////
        Read_Data_from_File(file_patch_ltp, dimmer_type, sizeof(bool),patch_ltp_size);

    if(specify_who_to_save_load[10]==1)/////Patch curves///////////////////////////
    {
        Read_Data_from_File(file_patch_curves, curves, sizeof(int),patch_curves_size);
        Read_Data_from_File(file_curve_ctrl_pt, curve_ctrl_pt, sizeof(int),curve_ctrl_size);
        Read_Data_from_File(file_curve_spline_level, the_curve_spline_level, sizeof(int),curve_spline_level_size);
        Read_Data_from_File(file_curve_matrix, curve_report, sizeof(int),curve_matrix_size);

        index_curve_spline_level=the_curve_spline_level[curve_selected];
        rest(10);
    }


    if(specify_who_to_save_load[11]==1)/////Banger//////////////////////////////////
    {
        Read_Data_from_File(file_bangers_names, bangers_name, sizeof(char), banger_name_size);
        Read_Data_from_File(file_bangers_types, bangers_type, sizeof(int), banger_types_size);
        Read_Data_from_File(file_bangers_actions, bangers_action, sizeof(int), banger_actions_size);
        Read_Data_from_File(file_bangers_values, bangers_params, sizeof(int), banger_values_size);
        Read_Data_from_File(file_bangers_times, bangers_delay, sizeof(float), banger_times_size);
        Read_Data_from_File(file_bangers_alarms, string_alarm, sizeof(char), banger_alarm_size);
        Read_Data_from_File(file_bangers_loop, do_loop_banger, sizeof(bool), banger_loop_size);
        Read_Data_from_File(file_bangers_looptime, time_loop_banger, sizeof(float), banger_looptime_size);
    }


    if(specify_who_to_save_load[12]==1) ////FADERS CONTENT//////////////////////////
    {
        save_load_print_to_screen("Loading Faders");

        Read_Data_from_File(file_faders_state, Fader, sizeof(unsigned char),faders_saving_size);
        Read_Data_from_File(file_dock_selected, DockIsSelected, sizeof(bool),dock_selected_size);
        Read_Data_from_File(file_dock_type, DockTypeIs, sizeof(unsigned char),dock_type_size);
        Read_Data_from_File(file_dock_net, DockNetIs, sizeof(unsigned char),dock_net_size);
        Read_Data_from_File(file_dock_name, DockName, sizeof(char),dock_name_size);
        Read_Data_from_File(file_dock_channels, FaderDockContains, sizeof(unsigned char),dock_channels_size);
        Read_Data_from_File(file_fader_locked, FaderLocked, sizeof(bool),fader_locked_size);
        Read_Data_from_File(file_fader_locked_full, LockFader_is_FullLevel, sizeof(bool),fader_locked_full_size);
        Read_Data_from_File(file_fader_before_lock, StateOfFaderBeforeLock, sizeof(unsigned char),fader_before_lock_size);
        Read_Data_from_File(file_color_to_dock, colorpreset_linked_to_dock, sizeof(int),fader_color_to_dock_size);

		//Audio dans faders
        int temp_array_audio[48*3][6];
        Read_Data_from_File(file_fader_audio, temp_array_audio, sizeof(int),fader_audio_size);
        if (b_report_error[idf-1]==0)
		{
			//rafraichissement tableau
			for(int u=0; u<48; u++)
			{
				for(int l=0; l<6; l++)
				{
					DockHasAudioVolume[u][l]=temp_array_audio[u][l];
					DockHasAudioPan[u][l]=temp_array_audio[u+48][l];
					DockHasAudioPitch[u][l]=temp_array_audio[u+96][l];
				}
			}
		}

        Read_Data_from_File(file_chaser_to_fader, ChaserAffectedToDck, sizeof(int),fader_chaser_to_fader_size);
        Read_Data_from_File(file_mem_to_dock, DockHasMem, sizeof(int),fader_mem_to_dock_size);
        Read_Data_from_File(file_fader_grid_affect, faders_dock_grid_affectation, sizeof(int),fader_grid_affect_size);
        Read_Data_from_File(file_fader_fx, fader_mode_with_buffers, sizeof(int),fader_fx_size);
        Read_Data_from_File(file_fader_route_fx, fader_fx_route, sizeof(bool),fader_route_fx_size);
        Read_Data_from_File(file_fader_fgroup, fgroup, sizeof(bool),fader_fgroup_size);
        Read_Data_from_File(file_fader_draw, DrawAffectedToDck, sizeof(int),fader_draw_size);

        recalculate_draw_sizes(draw_preset_selected);

        Read_Data_from_File(file_fader_echo, echo_affected_to_dock, sizeof(int),fader_echo_size);
    }


    if(specify_who_to_save_load[13]==1) ////FADERS LFOs//////////////////////////
    {
        save_load_print_to_screen("Loading LFO's");
        Read_Data_from_File(file_dock_times, time_per_dock, sizeof(float),dock_times_size);
        Read_Data_from_File(file_is_for_loop_selected, is_dock_for_lfo_selected, sizeof(bool),size_is_for_loop_selected);
        Read_Data_from_File(file_lfo_speed, lfo_speed, sizeof(int),size_lfo_speed);
        Read_Data_from_File(file_lfo_mode_is, lfo_mode_is, sizeof(int),size_lfo_mode_is);
        Read_Data_from_File(file_lfo_cycle_on, lfo_cycle_is_on, sizeof(bool),size_lfo_cycle_on);
        Read_Data_from_File(file_lfo_do_next_step, lfo_do_next_step, sizeof(bool),size_lfo_do_next_step);
        Read_Data_from_File(file_lfo_loop_step, lfo_cycle_steps, sizeof(bool),size_lfo_loop_step);
        Read_Data_from_File(file_fader_stoppos_levels, LevelStopPos, sizeof(unsigned char),fader_stoppos_size);
        Read_Data_from_File(file_fader_stoppos_is, ActionnateStopOn, sizeof(bool),fader_stopposB_size);
        Read_Data_from_File(file_fader_ston_is, StopPosOn, sizeof(bool),fader_ston_size);
        Read_Data_from_File(file_fader_chas_autolaunch, autolaunch, sizeof(bool),fader_chas_autolaucnh_size);
    }

    if(specify_who_to_save_load[14]==1) ////FADERS Curves/////////////////////////
        Read_Data_from_File(file_fader_curve, FaderCurves, sizeof(int),fader_curve_size);

    if(specify_who_to_save_load[15]==1) ////FADERS Preset and LOCK PST//////////////////////////
    {
        Read_Data_from_File(file_lock_preset_is, lock_preset, sizeof(bool),fader_lock_preset_is_size);
        Read_Data_from_File(file_lock_preset_state, FaderLocked_Preset, sizeof(bool),fader_lock_preset_state_size);
        Read_Data_from_File(file_lock_preset_masteris, LockFader_is_FullLevel_Preset, sizeof(bool),fader_lock_preset_masteris_size);
        Read_Data_from_File(file_lock_preset_levels, StateOfFaderBeforeLock_Preset, sizeof(unsigned char),fader_lock_preset_levels_size);

        for(int d=0; d<8; d++) //detect preset and load state
        {
            if(lock_preset[d]==1)
            {
                do_lock_preset(d);
                break;
            }
        }

        Read_Data_from_File(file_fader_preset_selection, minifaders_preset_selection, sizeof(bool),fader_prst_sel_size);
        rest(10);
    }

    if(specify_who_to_save_load[16]==1)/////////////CHASERS/////////////////////////
    {
        Read_Data_from_File(file_chaser_name, chaser_name, sizeof(char), chaser_name_size);
        Read_Data_from_File(file_chaser_timeunit, time_unit, sizeof(float), chaser_timeunit_size);
        Read_Data_from_File(file_chaser_stepop, chaser_step_operation, sizeof(int),chaser_stepop_size);
        Read_Data_from_File(file_chaser_play, chaser_is_playing, sizeof(bool),chaser_isplaying_size);
        Read_Data_from_File(file_chaser_loop, chaser_is_in_loop, sizeof(bool),chaser_loop_size);
        Read_Data_from_File(file_chaser_way, chaser_way, sizeof(bool), chaser_way_size);
        Read_Data_from_File(file_chaser_allerretour, chaser_aller_retour, sizeof(bool),chaser_allerretour_size);
        Read_Data_from_File(file_chaser_trackon, track_is_on, sizeof(bool), chaser_trackon_size);
        Read_Data_from_File(file_chaser_tracklevel, track_level, sizeof(int), chaser_track_level_size);
        Read_Data_from_File(file_chaser_trackview, position_affichage_track_num, sizeof(int),chaser_trackview_size);
        Read_Data_from_File(file_chaser_tracktype, TrackTypeIs, sizeof(int),chaser_tracktype_size);
        Read_Data_from_File(file_chaser_trackcontent, TrackContains, sizeof(int), chaser_trackcontent_size);
        Read_Data_from_File(file_chaser_stepis, chaser_step_is, sizeof(int), chaser_stepis_size);
        Read_Data_from_File(file_chaser_beginstep, chaser_begin_step_is, sizeof(int),chaser_stepbeg_size);
        Read_Data_from_File(file_chaser_endstep, chaser_end_step_is, sizeof(int),chaser_stepend_size);
        Read_Data_from_File(file_chaser_timemode, chaser_time_mode, sizeof(bool),chaser_timemode_size);
        Read_Data_from_File(file_chaser_lastaffect, view_chaser_affected_to_fader, sizeof(int), chaser_lastaffect_size);
        Read_Data_from_File(file_chaser_trrackname, chaser_track_name, sizeof(char), chaser_tracksname_size);
        Read_Data_from_File(file_chaser_presets, chaser_preset, sizeof(bool), chaser_presets_size);
        Read_Data_from_File(file_chaser_lchpad_pos, chaser_step_launchpad, sizeof(int), chaser_lchpad_pos_size);
        Read_Data_from_File(file_chaser_acceleroslave, index_slave_chaser_to_accelerometre, sizeof(bool), chaser_acceleroslave_size);
        Read_Data_from_File(file_chaser_has_mem,TrackHasMem, sizeof(int), chaser_has_mem_size);
        Read_Data_from_File(file_chaser_has_mem,TrackHasMem, sizeof(int), chaser_has_mem_size);
    }


    if(specify_who_to_save_load[17]==1) /////////////MIDI AFFECTATION///////////////
    {

        save_load_print_to_screen("Loading Midi Config");
        Read_Data_from_File(file_midi_affectation, miditable, sizeof(int),midi_affectation_size);
        Read_Data_from_File(file_midi_send_out, midi_send_out, sizeof(bool),midi_send_out_size);

        load_Fader_state_to_midi_array();//report des valeurs Faders dans le tableau midi_levels
    }

    if(specify_who_to_save_load[18]==1) /////////////MIDI cheat///////////////
    {
        Read_Data_from_File(file_midi_properties, midi_change_vel_type, sizeof(int),midi_properties_size);
        rest(10);
    }

    if(specify_who_to_save_load[19]==1)//////////TRICHRO////////////////////////////
    {
        save_load_print_to_screen("Loading Trichromy");
        Read_Data_from_File(file_dock_color_type, dock_color_type, sizeof(bool), dock_color_type_size);
        Read_Data_from_File(file_dock_color_xy, x_y_picker_par_colordock, sizeof(int), dock_color_xy_size);
        Read_Data_from_File(file_dock_color_angle, angle_hue_par_colordock, sizeof(float), dock_color_angle_size);
        Read_Data_from_File(file_dock_color_picker, picker_trichro, sizeof(int), dock_color_picker_size);
        Read_Data_from_File(file_dock_color_ch, dock_color_channels, sizeof(bool), dock_color_ch_size);
        Read_Data_from_File(file_dock_color_buffer, dock_color_buffer_C, sizeof(unsigned char), dock_color_buffer_size);

        load_etat_picker_dans_dockcolor(0);//rafraichissement du premier dock color
        //puis mise à l afihage ok du curseur hue
        vx = cos(angle_snap)*125;
        vy = sin(angle_snap)*125;
        position_curseur_hue_x= xtrichro_window+vx;
        position_curseur_hue_y=ytrichro_window+vy ;
        rest(10);
    }

	////////////////////////////////////////////////////////////////////////////////
	//////////////VIDEO TRACKING////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////
    if(specify_who_to_save_load[20]==1)/////////////TRACKING VIDEO//////////////////
    {
        save_load_print_to_screen("Loading Video Tracking");
        Read_Data_from_File(file_video_channels, tracking_contents, sizeof(bool),video_channels_size);
        Read_Data_from_File(file_video_xy, tracking_coordonates, sizeof(int),video_xy_size);
        Read_Data_from_File(file_video_spaces_on, tracking_spaces_on_off, sizeof(bool),video_spaces_on_size);
        Read_Data_from_File(file_camera_modes, camera_modes_and_settings, sizeof(int),camera_modes_size);

        refresh_ocv_settings();
    }

	///////////////////TIME////////////////////////////////////////////////////////
	//pour pos curseur
		refresh_time_cursor();

	////////////////////////////////////////////////////////////////////////////////

    if(specify_who_to_save_load[27]==1)/////////////////INDEXES/////////////////////
        Read_Data_from_File(file_divers_index, index_report_customs, sizeof(int), index_size);

    if(specify_who_to_save_load[24]==1)/////POS window user////////////////////////////////////////
    {
        Read_Data_from_File(file_pos_fenetres, windows_position, sizeof(int), index_pos_fenetre_size);
        Read_Data_from_File(file_windows, window_opened, sizeof(int), windows_size);

        write_window_indexes_from_list_of_windows();
        rest(10);
    }
    load_indexes();

    refresh_decay();
    Load_User_Profile();

    if(specify_who_to_save_load[22]==1)//AUDIO CONF//////////////////////////////////
    {

        Load_Audio_Conf();
        idf++;

		//audio autoload autopause
        bool temp_audio_array[8];
        Read_Data_from_File(file_audio_autoloadpause, temp_audio_array, sizeof(bool), audio_autoloadpause_size);
        for(int i=0; i<4; i++)
        {
            audio_autoload[i]=temp_audio_array[i];
            audio_autopause[i]=temp_audio_array[i+4];
        }

		//audio file number
        Read_Data_from_File(file_audio_filenumber, player_has_file_coming_from_pos, sizeof(int), audio_filenumber_size);
		//position player
        Read_Data_from_File(file_audio_playerposition, player_position_on_save, sizeof(int), audio_playerposition_size);
    }

    if(specify_who_to_save_load[21]==1)///ARDUINO////////////////////////////////////
    {
        load_arduino_config();
        Read_Data_from_File(file_arduino_dig_typ, arduino_digital_type, sizeof(int), arduino_dig_typ_size);
        Read_Data_from_File(file_arduino_dig_affect, arduino_digital_function_input, sizeof(int), arduino_dig_aff_size);
        Read_Data_from_File(file_arduino_an_typ, arduino_analog_function_input, sizeof(int), arduino_an_typ_size);
        Read_Data_from_File(file_arduino_an_aff, arduino_analog_attribution_input, sizeof(int),arduino_an_aff_size);
        Read_Data_from_File(file_arduino_dig_out, arduino_digital_function_output, sizeof(int),arduino_dig_out_size);
    }


    if(specify_who_to_save_load[25]==1)  ///USER COLOR PROFILE//////////////////////////////////////////////////
        Read_Data_from_File(file_color_profile, couleurs_user, sizeof(int),color_profile_size);

    if(specify_who_to_save_load[26]==1)//////clavier ascii remaping/////////////////
        Read_Data_from_File(file_kbd_ascii_map, mapping_temporaire, sizeof(int),kbd_ascii_map_size);

    if(specify_who_to_save_load[23]==1)////////ICAT//////////////////////////////////
    {
        Read_Data_from_File(file_icat_nbsliders, iCat_nbre_de_sliders, sizeof(int),icat_nbsliders_size);
        Read_Data_from_File(file_icat_posliders, iCat_pos_slider, sizeof(int),icat_posliders_size);
        Read_Data_from_File(file_icat_orsliders, iCat_orientation_slider, sizeof(bool),icat_orsliders_size);
        Read_Data_from_File(file_icat_typsliders, iCat_affectation_slider_type_is  , sizeof(int),icat_typsliders_size);
        Read_Data_from_File(file_icat_valsliders, iCat_affectation_slider_value_is, sizeof(int),icat_valsliders_size);
        Read_Data_from_File(file_icat_size_sliders, ratio_iCat_slider, sizeof(int),icat_sizesliders_size);
        Read_Data_from_File(file_icat_orientpage, iCat_preset_orientation, sizeof(int),icat_orpage_size);

        if(iCat_preset_orientation[iCatPageis]==0)
        {
            L_tablier_iCat=160;
            H_tablier_iCat=240;
        }
        else
        {
            L_tablier_iCat=240;
            H_tablier_iCat=160;
        }

		//buttons
        Read_Data_from_File(file_icat_nbbutton, iCat_nbre_de_boutons, sizeof(int),icat_nbbutton_size);
        Read_Data_from_File(file_icat_pobutton, iCat_pos_bouton, sizeof(int),icat_pobutton_size);
        Read_Data_from_File(file_icat_size_buttons, ratio_iCat_button, sizeof(int),icat_sizebuttons_size);
        Read_Data_from_File(file_icat_typbutton, iCat_affectation_bouton_type_is, sizeof(int),icat_typbutton_size);
        Read_Data_from_File(file_icat_actbutton, iCat_affectation_bouton_action_is, sizeof(int),icat_actbutton_size);
        Read_Data_from_File(file_icat_valbutton, iCat_affectation_bouton_value_is, sizeof(int),icat_valbutton_size);
		//strings
        Read_Data_from_File(file_icat_nbstr, iCat_nbre_de_strings, sizeof(int),icat_nbstr_size);
        Read_Data_from_File(file_icat_posstr, iCat_pos_string, sizeof(int),icat_posstr_size);
        Read_Data_from_File(file_icat_sizestr, ratio_iCat_string, sizeof(int),icat_sizestr_size);
        Read_Data_from_File(file_icat_typstr, iCat_affectation_string_type_is, sizeof(int),icat_typstr_size);
        Read_Data_from_File(file_icat_actstr, iCat_affectation_string_action_is, sizeof(int),icat_actstr_size);
        Read_Data_from_File(file_icat_valstr, iCat_affectation_string_value_is, sizeof(int),icat_valstr_size);
        Read_Data_from_File(file_icat_nbzon, iCat_nbre_de_tracking_zone, sizeof(int),icat_nbzon_size);
        Read_Data_from_File(file_icat_poszon, iCat_pos_trackzone, sizeof(int),icat_poszon_size);
        Read_Data_from_File(file_icat_sizezon, ratio_iCat_trackzone, sizeof(int),icat_sizezon_size);
        Read_Data_from_File(file_icat_typzon, iCat_trackzone_type_is, sizeof(int),icat_typzon_size);
        Read_Data_from_File(file_icat_valzon, iCat_trackzone_affectation_is, sizeof(int),icat_valzon_size);
        Read_Data_from_File(file_icat_posTRCKzon, pos_iCat_tracker, sizeof(int),icat_posTRCKzon_size);
    }

    if(specify_who_to_save_load[28]==1) //////////MOVER//////////////////////////////
    {
        Read_Data_from_File(file_mover_mem, dock_move_xy, sizeof(int),mover_mem_saving_size);
        Read_Data_from_File(file_mover_mem16b, dock_move_xy_16b, sizeof(int),mover_mem_saving_size);
		//nb steps
        Read_Data_from_File(file_mover_numbersteps, dock_moves_contains_steps, sizeof(int), mover_little_32file_size);
		//actual step is
        Read_Data_from_File(file_mover_stepis, dock_move_actual_step, sizeof(int), mover_little_32file_size);
		//divers
        Read_Data_from_File(file_mover_divers, valeurs_diverses, sizeof(int), mover_little_32file_size);
		//ratio spline
        Read_Data_from_File(file_mover_spline_ratio, spline_ratio, sizeof(float), mover_little_32file_size);
		//iris flous divers parametres asservis
        Read_Data_from_File(file_asservis_mem, dock_asservis, sizeof(float), mover_asservis_saving_size);
		//times
        Read_Data_from_File(file_mover_time, dock_time, sizeof(float), mover_time_size);
		//autostop
        Read_Data_from_File(file_mover_autostop, move_auto_stop, sizeof(bool), mover_autostop_size);
		//gotos
        Read_Data_from_File(file_mover_goto, GotoMoves, sizeof(int), mover_goto_size);
		//intos
        Read_Data_from_File(file_mover_into, Moves_Inpoint, sizeof(int), mover_little_32file_size);
        Read_Data_from_File(file_mover_params, mover_params_adresses, sizeof(int), mover_param_size);

        xadress=mover_params_adresses[0];
        yadress=mover_params_adresses[1];
        irisadress=mover_params_adresses[2];
        focusadress=mover_params_adresses[3];
        zoomadress=mover_params_adresses[4];
        invX_on=valeurs_diverses[0];
        invY_on=valeurs_diverses[1];
        Tracker_speedlevel=valeurs_diverses[2];
        dock_move_selected=valeurs_diverses[3];

        position_defaut[0]=valeurs_diverses[13];
        position_defaut[1]=valeurs_diverses[14];
        index_spline=valeurs_diverses[15];

        Tracker_splinelevel=(int)((spline_ratio[dock_move_selected]+1)*100);
        sprintf(string_zero_point_is,"Offset X %d Y %d",position_defaut[0],position_defaut[1]);

        mover_params[2][0]=dock_asservis[dock_move_selected][(dock_move_actual_step[dock_move_selected])][0];
        mover_params[3][0]=dock_asservis[dock_move_selected][(dock_move_actual_step[dock_move_selected])][1];
        mover_params[4][0]=dock_asservis[dock_move_selected][(dock_move_actual_step[dock_move_selected])][2];


        mover_params[0][0]=dock_move_xy[dock_move_selected][(dock_move_actual_step[dock_move_selected])][0];
        mover_params[1][0]=dock_move_xy[dock_move_selected][(dock_move_actual_step[dock_move_selected])][1];
        rest(10);
    }

	////////////GRID////////////////////////////////////////////////////////////////
    if(specify_who_to_save_load[29]==1)
    {
        Read_Data_from_File(file_grid_levels_1, temp_grid_levels_for_save, sizeof(unsigned char), grid_levels_size);
        for(int i=0; i<32; i++)
        {
            for (int s=0; s<1024; s++)
            {
                for (int c=0; c<513; c++)
                {
                    grid_levels[i][s][c]=temp_grid_levels_for_save[i][s][c];
                }
            }
        }

        Read_Data_from_File(file_grid_levels_2, temp_grid_levels_for_save, sizeof(unsigned char), grid_levels_size);
        for(int i=0; i<32; i++)
        {
            for (int s=0; s<1024; s++)
            {
                for (int c=0; c<513; c++)
                {
                    grid_levels[i+32][s][c]=temp_grid_levels_for_save[i][s][c];
                }
            }
        }

        Read_Data_from_File(file_grid_levels_3, temp_grid_levels_for_save, sizeof(unsigned char), grid_levels_size);
        for(int i=0; i<32; i++)
        {
            for (int s=0; s<1024; s++)
            {
                for (int c=0; c<513; c++)
                {
                    grid_levels[i+64][s][c]=temp_grid_levels_for_save[i][s][c];
                }
            }
        }

        Read_Data_from_File(file_grid_levels_4, temp_grid_levels_for_save, sizeof(unsigned char), grid_levels_size);
        for(int i=0; i<32; i++)
        {
            for (int s=0; s<1024; s++)
            {
                for (int c=0; c<513; c++)
                {
                    grid_levels[i+96][s][c]=temp_grid_levels_for_save[i][s][c];
                }
            }
        }
		//fin du groupe des grids levels

        Read_Data_from_File(file_grid_times, grid_times, sizeof(float), grid_times_size);
        Read_Data_from_File(file_grid_goto, grid_goto, sizeof(int), grid_goto_size);
        Read_Data_from_File(file_grid_seekpos, grid_seekpos, sizeof(int), grid_seekpos_size);
        Read_Data_from_File(file_grid_stoplay, grid_stoplay, sizeof(bool), grid_stoplay_size);
        Read_Data_from_File(file_grid_names, grider_name, sizeof(char), grid_names_size);
		//les grids players
        Read_Data_from_File(file_gridpl_grid, index_grider_selected, sizeof(int),gridpl_size);
        Read_Data_from_File(file_gridpl_step, index_grider_step_is, sizeof(int),gridpl_size);
        Read_Data_from_File(file_gridpl_autost, grider_autostopmode, sizeof(bool),gridpl_size);
        Read_Data_from_File(file_gridpl_goto, grider_goto_mode, sizeof(bool),gridpl_size);
        Read_Data_from_File(file_gridpl_seekto, grider_seekto_mode, sizeof(bool),gridpl_size);
        Read_Data_from_File(file_gridpl_stpl, grider_stoplay_mode, sizeof(bool),gridpl_size);
        Read_Data_from_File(file_gridpl_slave, grid_player_slave, sizeof(bool),gridpl_size);
        Read_Data_from_File(file_gridpl_show, index_show_grid_player, sizeof(bool),gridpl_size);
        Read_Data_from_File(file_gridpl_accel, grid_crossfade_speed, sizeof(int),gridpl_size);
        Read_Data_from_File(file_gridpl_countmod, grider_count_mode, sizeof(bool),gridpl_size);
        Read_Data_from_File(file_gridpl_snapfader, GplSnapFader, sizeof(int),gridpl_snapfader_size);
		//grider conf
        int grider_conf[3];
        Read_Data_from_File(file_grider_conf, grider_conf, sizeof(int),grider_conf_size);
        grider_begin_channel_is=grider_conf[0];
        grider_nb_col=grider_conf[1];
        grider_nb_row=grider_conf[2];
        if(grider_nb_col>24)
        {
            grider_nb_col=8;
        }
        if(grider_nb_row>24)
        {
            grider_nb_row=8;
        }
        if(grider_begin_channel_is>512)
        {
            grider_begin_channel_is=1;
        }
		//
        int grider_report_cross[8];
        Read_Data_from_File(file_gridpl_crosslv, grider_report_cross, sizeof(int),gridpl_croslv_size);
        for(int gr=0; gr<4; gr++)
        {
            grid_niveauX1[gr]=grider_report_cross[gr];
            grid_niveauX2[gr+4]=grider_report_cross[gr+4];
            grid_floatX1[gr]=(float)grid_niveauX1[gr];
            grid_floatX2[gr]=(float)grid_niveauX2[gr];
        }

        Read_Data_from_File(file_grid_count, grid_count, sizeof(int),grid_count_size);
        Read_Data_from_File(file_grided_count, grid_counted_times, sizeof(int),grid_counted_size);

        refresh_hauteur_fenetre_grider();
    }//fin grid

	//GRIDPLAYER 1 in MEMS
    if(specify_who_to_save_load[30]==1)
        Read_Data_from_File(file_grid_in_mems, set_from_seq_gridplayer1_next_step, sizeof(int),grid_in_mems_size);

	//personnal save preset
    if(specify_who_to_save_load[35]==1)
    {
        Read_Data_from_File(file_save_preset, preset_specify_who_to_save_load, sizeof(bool),save_preset_size);
        Read_Data_from_File(file_save_pdf, specify_who_to_save_PDF, sizeof(bool),save_pdf_size);
    }


	//DRAW
    if(specify_who_to_save_load[32]==1)
    {
        Read_Data_from_File(file_draw_presetsz, draw_preset_parameters, sizeof(int),draw_presetsz_size);
        Read_Data_from_File(file_draw_levels, draw_preset_levels, sizeof(float),draw_levels_size);
        Read_Data_from_File(file_draw_chrouting, draw_preset_channel_routing, sizeof(int),draw_chrouting_size);

        load_draw_preset_config();
        idf++;
    }

	//ECHO
    if(specify_who_to_save_load[33]==1)
    {
        Read_Data_from_File(file_echo_pointing_fader, echo_pointing_fader_num, sizeof(int),echo_pointing_fader_size);
        Read_Data_from_File(file_echo_echo_mode, echo_is_echo_mode, sizeof(bool),echo_echo_mode_size);
        Read_Data_from_File(file_echo_global_param, echo_global_params, sizeof(float),echo_global_param_size);
        Read_Data_from_File(file_echo_channel_man_mode, echo_channel_manipulate_mode, sizeof(bool),echo_channel_man_mode_size);
        Read_Data_from_File(file_echo_chan_pos, echo_grid_channel_position, sizeof(int),echo_chan_pos_size);
        Read_Data_from_File(file_echo_levels, echo_levels, sizeof(float),echo_levels_size);
        Read_Data_from_File(file_echo_bounce, do_bounce, sizeof(bool),echo_bounce_size);
        Read_Data_from_File(file_echo_presets, snap_echo_to_recall, sizeof(float),echo_presets_size);
    }

	//////LIGHTING PLOT en dernier because repertoires
    if(specify_who_to_save_load[31]==1)
    {
        Read_Data_from_File(file_lib_sizes_symbol, size_symbol, sizeof(float),lib_sizes_symbol_size);
        Read_Data_from_File(file_lib_names_symbol, symbol_nickname, sizeof(char),lib_names_symbol_size);
        Read_Data_from_File(file_plot_angles, angle_symbol, sizeof(float),plot_angle_size);
        Read_Data_from_File(file_plot_positions, pos_symbol, sizeof(int),plot_positions_size);
        Read_Data_from_File(file_plot_nbr_symbols, nbre_symbols_on_plot, sizeof(int),plot_nbr_symbols_size);
        Read_Data_from_File(file_plot_typ, symbol_type, sizeof(int),plot_typ_size);
        Read_Data_from_File(file_plot_chan, symbol_channel_is, sizeof(int),plot_chan_size);
        Read_Data_from_File(file_plot_dim, symbol_dimmer_is, sizeof(int),plot_dim_size);
        Read_Data_from_File(file_plot_gels, gelat, sizeof(int),plot_gels_size);
        Read_Data_from_File(file_plot_gels_t, gelat_family, sizeof(int),plot_gels_t_size);
        Read_Data_from_File(file_plot_view, show_calc_number, sizeof(bool),plot_view_size);
        Read_Data_from_File(file_plot_options_view, plot_show_options, sizeof(bool),plot_view_options_size);
        Read_Data_from_File(file_plot_opt_xy, relatif_plot_xy, sizeof(int),plot_opt_xy_size);
        Read_Data_from_File(file_plot_shape_type, shape_type, sizeof(int),plot_shape_type_size);
        Read_Data_from_File(file_plot_shape_attr, shape_attributes, sizeof(float),plot_shape_attr_size);
        Read_Data_from_File(file_plot_shape_pos, shape_position, sizeof(int),plot_shape_pos_size);
        Read_Data_from_File(file_plot_shape_legend_name, shape_legend_name, sizeof(char),plot_shape_legend_name_size);
        Read_Data_from_File(file_plot_shape_relativ_xy, shape_relativ_position_legend_name, sizeof(int),plot_shape_relativ_xy_size);
        Read_Data_from_File(file_plot_shape_color_type, shape_color_type, sizeof(int),plot_shape_color_type_size);
        Read_Data_from_File(file_plot_shape_groups, shape_groups, sizeof(int),plot_shape_groups_size);
        Read_Data_from_File(file_plot_symbols_relativgroups, plot_relativxy_preset, sizeof(int),plot_symbols_relativgroups_size);
        Read_Data_from_File(file_plot_symbols_notes, symbol_note, sizeof(char),plot_symbols_notes_size);
        Read_Data_from_File(file_plot_legend, plot_renseignements, sizeof(char),plot_legend_size);
        Read_Data_from_File(file_plot_symb_linked, symbol_is_linked_to, sizeof(int),plot_symb_linked_size);

        plot_generate_appareils_list();

        sprintf(rep,"%s",mondirectory);
        chdir (rep);
        scan_planfolder();
        sprintf(rep,"%s\%s\%s",mondirectory,rep_saves,nomduspectacle);
        chdir (rep);

        Load_Plot_Plan_config();
        if(index_menus_lighting_plot==4 )
        {
            position_plan_x=0;
        }
        idf++;

        load_plan_of_theatre(Name_of_plane_is, 0);

		//plot venant de load_indexes
        if(view_plot_calc_number_is>3)
        {
            view_plot_calc_number_is=3;
        }
        show_calc_number[view_plot_calc_number_is]=1;
    }

    LoadWhiteCatColorProfil();// pas de fichiers, juste raffraichissement
    rest(10);

	//reroll à garder pour pas larguer midishare
    sprintf(rep,"%s",mondirectory);
    chdir (rep);

    Load_Launchpad_RetroLight();

    if(specify_who_to_save_load[22]==1)
    {
        scan_audiofolder();
        Load_audiofiles_cues();
        sprintf(rep,"%s",mondirectory);
        chdir (rep);

        for(int i=0; i<4; i++)
        {
            audiofile_selected=player_has_file_coming_from_pos[i];
            sprintf(audiofile_name,list_audio_files[audiofile_selected]);
            if(strcmp (audiofile_name,"")!=0)
            {
                AffectSoundFile(i);
            }

            rest(10);
        }

    }

    refresh_mem_onstage(position_onstage);
    refresh_mem_onpreset(position_preset);
    detect_mem_before_one();
    detect_error_on_save_load();
    Show_report_save_load();

    initiate_windows();

    if(there_is_an_error_on_save_load==1)
    {
        index_show_save_load_report=1;
        there_is_change_on_show_save_state=1;
    }
    else
    {
        index_show_save_load_report=0;
        there_is_change_on_show_save_state=0;
    }
}

int load_the_show(char name_of_show[24])
{
    index_is_saving=1;
    char vieux_nomduspectacle[24];
    sprintf(vieux_nomduspectacle, nomduspectacle);
    sprintf(nomduspectacle,name_of_show);
    Load_Show();
    sprintf(string_Last_Order,">> Loaded %s  at %s",name_of_show,tmp_time);
    timer_save_tmp=0;
    sprintf(nomduspectacle,vieux_nomduspectacle);
    index_is_saving=0;
    index_show_save_load_report=1;
    sprintf(my_show_is_coming_from,"Loaded from in %s",name_of_show);//pour retracer d ou vient la conduite
    write_show_coming_from();
    return(0);
}

int do_wizard_reload_from_disk()
{
    index_save_global_is=0;
    set_all_saves_indexes_at(0);
    specify_who_to_save_load[0]=1;//memories
    specify_who_to_save_load[1]=1;
    specify_who_to_save_load[2]=1;
    specify_who_to_save_load[3]=1;
    specify_who_to_save_load[4]=1;
    index_is_saving=1;
    Load_Show();
    timer_save_tmp=0;
    index_is_saving=0;
//remise en etat du systeme
    set_all_saves_indexes_at(1);
    index_save_global_is=1;

    return(0);
}

