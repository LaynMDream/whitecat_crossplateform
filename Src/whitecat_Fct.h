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

* \file whitecat_Fct.h
* \brief {Declaration of global functions of White Cat}
* \author Rui Serge Azevedo Brooks from Christoph Guillermet's original sources
* \version {0.8.?.? - work in progress}
* \date {04/04/2014}

 White Cat - main

*   Déclaration des fonctions globales de White Cat
*
*   Declaration of global functions of White Cat
*
*/

#ifndef WHITECAT_FCT_H_INCLUDED
#define WHITECAT_FCT_H_INCLUDED

//currently in main
//{
    int time_doing();
    void ticker_dmxIn();
    void ticker();
    void do_mouse_right_click_menu();
    void my_callback(int);
    void dixiemes_de_secondes();
    void ticker_full_loop();
    void ticker_artnet();
    void Load_Fonts();
    int main_actions_on_screen();
//}
//currently in arduino UNO
//{
    int arduino_decode_array_method(char *);
    int read_arduino_data(int);
    int arduino_read();
    int do_arduino_config(int,int);
//}
//currently in arduino core UNO
//{
    void ticker_arduino();
    int arduino_do_analog_in_whitecat();
    int arduino_do_digital_in_whitecat();
    int arduino_do_pwm_out_whitecat();
    int arduino_do_digital_out_whitecat();
    int arduino__send_config();
//}
//currently in arduino device core
//{
    int arduino_init(int);
    int arduino_close(int);
//}
//currently in audio core
//{
    int Load_audiofiles_cues();
    int AffectSoundFile(int);
    int sound_core_processing();
    int Control_Audio_thruth_faders(int,int,int);
    void ShowSupportedAudioDevices();
    int InitSound();
    int do_logical_fader_niveau_son(int,int,int);
    int do_logical_lecteur_audio(int,int,int);
    int do_logical_fenetre_audio(int,int);
    int do_audio_midi_function_next_prev_track();//Ajouté dans la branche de christoph 22/04/14
//}
//currently in audio visu
//{
    int fader_niveau_son(int,int,int);
    int lecteur_audio(int,int,int);
    int fenetre_audio(int,int);
//}
//currently in banger core
//{
    int Chrono_Reset();
    int store_state_of_fader_before_bang(int);
    int restore_state_of_fader_before_bang(int);
    int Bang_event_back(int,int);
    int back_up_fader_if_a_fader_inside(int);
    int do_send_bang();
    int Bang_event(int,int);
    int do_loop_bang(int);
    int do_bang(int);
    int do_go_back_bang(int);
    int do_logical_feedback_banger(int,int);
    int do_logical_fenetre_banger(int,int);
    int refresh_banger_wx();
//}
//currently in banger visu
//{
    int alarm_window();
    int feedback_banger(int,int);
    int fenetre_banger(int,int);
//}
//currently in Call everybody
//{
    int reset_other_index_cfg();
    int do_logical_FunctionBoxChannel(int,int,int,int,int);
    int FunctionBoxChannel(int,int,int,int,int);
    int do_logical_Menus(int,int);
    int Menus(int,int);
//}
//currently in CFG config panel
//{
    int init_kbd_custom();
    int do_keyboard_config(int,int,int,int);
    int do_keyboard_conf(int,int);
    int do_core_config(int,int,int,int);
    int Box_artnet_udpport(int,int);
    int do_network_config(int,int,int,int);
    int do_main_config(int,int,int,int);
    int SelectDmxDevice(int);
    int affect_dmx_in(int,int);
    int do_dmx_config(int,int,int,int);
    int save_network_settings();
    int load_network_conf();
    int do_panel_config(int,int);
    int config_general_menu();
//}
//currently in CFG_screen
//{
    int reload_window_positions();
    int store_window_positions();
    int do_screen_config(int,int,int,int);
//}
//currently in channels visu
//{
    int ChannelScroller(int,int);
    int ClassicalChannelSpace(int,int,int);
    int Draw_Channel_Preset_Title(int,int,int);
    int Draw_Channel_Preset_View(int,int,int);
    int ChannelsMenuSelection(int,int);
//}
//currently in channels core
//{
    int snap_channels_selection_array();//pour saisie continue des circuits,au click button
    int channel_copy();
    int channel_paste();
    int reset_blind();
    int Channel_select_all();
    int Channel_select_inv();
    int Channel_select_thruth(int,int);
    int Channel_at_level();
    int DoMouseLevel();
    int do_logical_ChannelScroller(int,int);
    int do_logical_Draw_Channel_Preset_View(int,int,int);
    int do_logical_Draw_Channel_Preset_Title(int,int,int);
    int do_logical_ClassicalChannelSpace(int,int,int);//les 512 circuits
    int do_logical_ChannelsMenuSelection(int,int);
//}
//currently in chasers core
//{
    int refresh_chaser_midi_out();
    int set_refresh_mode_for_chaser(bool);
    int refresh_launchpad_on_chaser();
    int chaser_calcul_time_joint(int);
    int chaser_calcul_step(int,float);
    int do_chaser();
    int chaser_clear_preset(int,int);
    int DoClearChaserTrack(int,int);
    int DoClearAChaser(int);
    int DoDockChaserTrack(int,int);
    int chaser_load_from_preset(int,int);
    int chaser_store_in_preset(int,int);
    int DoModifyChaserTrack(int,int);
    int DoReportChaserTrack(int,int);
    int chaser_seek_at_beg(int);
    int chaser_select_all_track(int);
    int chaser_select_off_all_track(int);
    int chaser_select_inv_track(int);
    int chaser_select_no_track(int);
    int bouton_view_track_downup_core(int,int,bool);
    int bouton_view_launchpad_pos_core(int,int,bool);
    int Track_draw_logical(int,int,int);
    int do_logical_fenetre_chasers(int,int);
    int set_chaser_tempo_unit(int);
    int do_autolaunch();
    int refresh_chaser_window_timeline_for_midi_out();
//}
//currently in chasers visu
//{
    int set_cue_in_view(int,int,bool);
    int set_cue_out_view(int,int,bool);
    int seek_cue_in_view(int,int,bool);
    int set_forward_sens_view(int,int,bool);
    int set_backward_sens_view(int,int,bool);
    int set_back_and_forward_sens_view(int,int,bool);
    int bouton_track_up(int,int,bool);
    int bouton_track_stay(int,int,bool);
    int bouton_track_down(int,int,bool);
    int bouton_view_track_downup(int,int,bool);
    int bouton_view_launchpad_pos(int,int,bool);
    int Track_draw(int,int,int);
    int chaser_window(int,int);
//}
//currently in CORE
//{
    int reset_numeric_entry();
    int return_lowest(int,int);
    int return_highest(int,int);
    int constrain_data_to_dmx_range(int);
    int constrain_data_to_midi_range(int);
    int player1_do_stop();
    int player2_do_stop();
    int player3_do_stop();
    int player4_do_stop();
    bool check_channel_is_patched(int);
    int constrain_int_data_to_this_range(int,int,int);
    int check_echo_bounce_done(int);
    int prepare_bounce(int);
    int recall_channel_state_in_an_echo(int);
    int  snap_fader_state(int,int);
    int snap_kill_and_bounce(int,int);
    int record_channel_ch_state_in_an_echo(int,int);
    int record_channel_state_in_an_echo(int);
    int clear_banger(int);
    int recall_fader_state_echo(int);
    int clear_echo_levels(int);
    int clear_ground_levels(int);
    int clear_echo_preset(int);
    int Draw_point_and_perform_level_on_area_NEW(int,int,int);
    int recalculate_draw_sizes(int);
    int draw_erase_drawing(int);
    int clear_draw_preset(int);
    int copy_banger(int source,int);
    int reset_index_actions();
    int reset_indexs_confirmation();
    int reset_channel_first_dimmer_list();
    int generate_channel_preview_patch_list();
    int check_presence_of_a_channel_in_views(int);
    int check_wich_channel_is_in_view(int);
    int check_presence_of_any_channel_in_A_view(int);
    int check_presence_of_A_channel_in_A_view(int,int);
    int detect_last_activ_channel_in_activ_view(int);
    int toggle (int);
    int bounce(int);
    int count_number_of_channels_in_view(int);
    int refresh_positions_preset_view_poignee();
    int clear_selection_in(int);
    int  build_preset_view_from_mem(int,int);
    int build_preset_view_from_fader(int,int);
    int reorder_channel_view_list_of_channels(int);
    int build_preset_view_from_all_existing_mems(int);
    int build_preset_view_from_all_faders(int);
    int build_preset_view_from_all_existing_mems_and_faders(int);
    int report_selection_in(int);
    int generate_channel_view_list_from_patched_circuits();
    int record_selection_in(int);
    int modify_selection_in(int);
    int clear_plot_legend();
    int affect_mover_to_fader(int,int);
    int clear_xyrelativ_preset(int);
    int affect_preset_xy_to_symbols(int);
    int record_preset_xy_from_symbol(int);
    int clear_completely_the_patch();
    int load_plan_of_theatre(char,bool);
    int set_plot_background_to_default();
    int  refresh_shape_factors(int);
    int set_all_faders_midi_out(bool);
    int reset_window_opened_indexes();
    int constrain_banger_type(int);
    int constrain_banger_param(int);
    int reset_banger_params(int,int);
    int reset_banger_event(int,int);
    int reset_audio_indexs_to_dock();
    bool set_all_saves_indexes_at(bool);
    int reset_modified_levels_in_crossfade();
    int exclude_reinclude_channels_from_grand_master_action();
    int set_new_time_in_tap_tempo();
    int refresh_hauteur_fenetre_grider();
    int reset_window_positions();
    int Get_channels_from_memory(int);
    int search_and_desaffect_previous_midi_signal(int);
    int reset_index_affect_midi();
    void show_type_midi(int control,const std::string);
    int attribute_midi_to_control(int,int,int);
    int attribute_midi_solo_affectation(int,int);
    int process_assign_to_core(int);
    int reset_and_recall_iCat_images();
    int copy_iCatPage(int,int);
    int clear_iCat_sliders(int);
    int clear_iCat_buttons(int);
    int clear_iCat_strings(int);
    int clear_iCat_trackingzone(int);
    int clear_iCat_page (int);
    int detect_actual_master_lock_is();
    void save_load_print_to_screen(const std::string);
    int minifader_selection_record(int);
    int minifader_selection_clear(int);
    int minifader_lockselection_record(int);
    int refresh_stage();
    int reset_indexes_conf();
    int button_midi_out_core(int,int,int);
    int button_midi_out_visu(int,int,int);
    int show_who_is_in_dock (int,int);
    int reset_check_grada_overide_dimmers();
    int reset_all_bangers();
    int reset_save_load_report_string();
    int scan_audiofolder();
    int snapshot_windows();
    void close_all_windows();
    void write_window_indexes_from_list_of_windows();
    int recall_windows();
    int refresh_time_cursor();
    int set_time_cursor_to_time_type(int);
    int read_time_string_entry();
    int reset_midi_receiver_array();
    int detect_master_lock(int);
    int do_lock_preset(int);
    int do_stock_fadersstate(bool,bool,bool,bool,bool);
    int do_recall_fadersstate(bool,bool,bool,bool,bool);
    int dessafect_index_curves();
    int reconstruct_plot_dimmer_list_from_patch();
    int patch_straight();
    int patch_select_all_dimmers();
    int  patch_clear_selected();
    int patch_to_default_selected();
    int set_channel_scroll(int);
    int set_patch_scroll(int);
    int load_Fader_state_to_midi_array();
    int send_my_midi_note(int,int,int,int,int);
    int send_my_midi_note_delayed(int,int,int,int,int,int);
    int send_immidiateley_my_midi_cc(int,int,int,int);
    int emit_midi_out();
    int load_etat_picker_dans_dockcolor(int);
    int refresh_ocv_settings();
    int refresh_decay();
    int LoadWhiteCatColorProfil();
    int record_memory(int);
    int refresh_mem_onstage(int);
    int record_memory_plus_faders(int);
    int overrecord_memory_plus_faders(int);
    int snap_mem_to_copy();
    int copy_mem_in(int);
    int prepare_crossfade();
    int detect_mem_before_one();
    int detect_mem_preset();
    int detect_mem_preset_previous();
    int detect_next_preset();
    int refresh_mem_onpreset(int);
    int create_memory(int);
    int create_memory_plus_faders(int);
    int delete_memory(int);
    int refresh_integrated_gridplayer1();
    int do_load_mem_preset_while_crossfade(int);
    int do_double_go_function();
    int do_go_back_function();
    int do_go_function();
    int patch_unselect_all_dimmers();
    int build_default_curve(int);
    int set_to_default_my_roi(int,int);
    int set_to_default_my_trackers();
    int set_to_default_this_tracker(int);
    int write_show_coming_from();
    int scan_for_free_dock();
    int detect_dock_used(int);
    int refresh_minifader_state_view_core(int);
    int do_action_on_selected_minifaders(int);
    int match_minifaders();
    int affect_time_entry_to_mem(int,int);
    int do_sprintf_job();
    int remember_config_page();
    int window_who_is_on_top();
    void substract_a_window(int);
    int GlobInit();
    int reset_show();
//}
//currently in dmx functions #include <dmx_enttec_pro.cpp>
//{
	int Enttec_Pro_SetCommParams();
	int Enttec_Pro_SendData(int,unsigned char *,unsigned int,LPOVERLAPPED);
	int Enttec_Pro_SetCommParamsIN();
	uint16_t Enttec_Pro_ReceiveData(uint16_t,uint8_t *,uint32_t);
	int Detect_EnttecProOut();
	int Open_EnttecProOut();
	int Close_EnttecProOut();
	int Detect_EnttecProIn();
	int Open_ProIn();
	int Close_ProIn();
//}
//currently in dmx functions #include <dmx_sunlite.cpp>
//{
    int open_sunlite();
    int close_sunlite();
    int sunlite_send_data();
    int Receive_sunlite_dmxIN();
    int reset_dmx_out();
//}
//currently in dmx functions
//{
    int Init_dmx_interface();
    int Close_dmx_interface();
    int check_if_dmx_change();
    int SendData_to_interface();
    int Attribute_ArtNet(int aff,int ddok);
    int refresh_modified_levels_in_crossfade();
    int do_crossfade();
    int do_goback();
    int prepare_lfos(int cmptfader,int dksel);
    int do_lfos();
    int Merger_Faders();
    int calculs_etats_faders_et_contenus();
    int Merger_Sequenciel();
    int Merger();
    int load_dmx_conf();
    int Save_my_dmx_conf();
    int Receive_DMX_IN();
//}
//currently in Draw
//{
    int snap_state_of_draw_grid(int);
    int merge_draw_and_grid_player(int);
    int Draw_TrackingAera(int,int);
    int Draw_Window(int,int);
    int do_logical_Draw_TrackingAera(int,int);
    int do_logical_Draw_Window(int,int);
//}
//currently in echo
//{
    int do_bouncing_levels(int);
    int do_echo();
    int do_logical_Echo_Aera(int,int);
    int do_logical_echo_window(int,int);
    int Echo_Aera(int,int);
    int echo_window(int,int);
//}
//currently in faders core
//{
    int indicate_wich_fader_is_the_highest();
    int asservissement_gridplayer(int,int);
    int DoLock(int,int);
    int do_logical_Lock_Preset_Call(int,int);
    int do_logical_lfo_fader_functions (int,int,int,int,int);
    int do_logical_MoveFaderSpace(int);
    int do_scroll_fader_space();
    int do_logical_Touche_Midi_Mute(int,int);
    int do_logical_FaderSpace(int,int,int,int,int);
//}
//currently in faders operations
//{
    int Unselect_other_docks(int,int);
    int  DoTimeToDock(int,int);
    int ClearDock(int,int);
    int affect_echo_to_dock(int,int,int);
    int  affect_draw_preset_to_dock(int,int,int);
    int ClearFader(int);
    int record_minifaders_selected_as_fgroup(int,int);
    int affect_selected_faders_to_fgroup(int,int);
    int DoDock(int,int);
    int DoModify(int,int);
    int DoReport(int,int);
    int affect_color_to_dock(int,int);
    int affect_network_to_dock(int,int);
    int affect_dmxIN_to_dock(int,int);
    int  affect_video_tracking_to_dock(int,int);
    int affect_audio_control_to_dock(int,int);
    int affect_chaser_to_dock(int,int,int);
    int Unselect_all_channels();
    int affect_color_to(int,int);
    int affect_to_tracker(int,int);
    int do_direct_channel(int,int);
//}
//currently in faders visuels
//{
    int lfo_fader_functions (int,int,int,int);
    int MoveFaderSpace(int);
    int Touche_Midi_Mute(int,int);
    int Lock_Preset_Call(int,int);
    int Commandes_faders_generales(int,int);
    int FaderSpace(int,int,int,int);
//}
//currently in gestionaire fenetres
//{
    int reset_config_indexes();
    int clear_non_desired_values_in_window_list();
    int initialisation_tableau_windows();
    int check_nbre_opened_windows();
    int add_a_window(int);
    int initiate_windows();
    int window_bring_to_front(int);
    int check_save_load_report_window();
//}
//currently in grand master
//{
    int do_logical_grand_master(int,int,int);
    int grand_master(int,int);
//}
//currently in graphics rebuild
//{
    int RetourInfos(int,int);
    void Show_test_log(int,int);		  //to do : migrate to whc_report as a test_log object
    void AddToEventLog(whc_log test_log); //to do : part of code of this function should migrate to whc_report as a test_log object function
    int show_windows_list_id(int,int);
    int Boxes();
    void  Procedure(const std::string,const std::string);
    int DoMouse();
//}
//currently in grider
//{
    int TheStepBox(int,int,int);
    int TheGrid_commands (int,int,int);
    int TheGrid_divers(int,int,int);
    int TheGrid_matrix (int,int,int);
    int ThePlayCommands(int,int,int);
    int TheCallGridBox(int,int,int);
    int Grid_player(int,int,int);
    int GlobalGridViewer(int,int);
    int Grider_Box(int,int);
//}
//currently in grider calculs
//{
    int affichage_time_format(float);
    int refresh_step_in_player(int,int,int);
    int clear_a_grid_step(int,int);
    int clear_part_of_a_grid(int,int,int);
    int clear_a_grid(int);
    int copy_grid_partially(int,int,int,int,int);
    int copy_step_to_step(int,int,int,int);
    int insert_steps(int,int,int);
    int gridder_prepare_cross(int,int,int);
    int do_grid();
    int gridplayer_step_minus(int);
    int gridplayer_step_plus(int);
    int gridplayer_seek(int);
//}
//currently in grider core
//{
    int do_logical_TheStepBox(int,int,int);
    int do_logical_TheGrid_commands (int,int,int);
    int do_logical_TheGrid_matrix (int,int,int,int);
    int do_logical_TheGrid_divers(int,int,int);
    int do_logical_ThePlayCommands(int,int,int);
    int do_logical_TheCallGridBox(int,int,int);
    int do_logical_Grid_player(int,int,int);
    int do_logical_GlobalGridViewer(int,int,int);
    int do_logical_Grider_Box(int,int);
//}
//currently in gui boutons rebuild
//{
    int bouton_on_view(int,int,bool);
    void bouton_text_view(int,int,const std::string,bool);
    float do_logical_rotatif(int,int,int);
    int rotatif(int xr,int,int,float);
    int play_button_view(int,int,bool);
    int seek_button_view(int,int,bool);
    int loop_button_view(int,int,bool);
    int playstop_button_view(int,int,bool);
    int autolaunch_button_view(int,int,bool);
    int next_button_view(int,int,bool);
    int previous_button_view(int,int,bool);
    int case_moins_view(int,int,bool);
    int case_plus_view(int,int,bool);
    void toggling_bar_view(int,int,bool,const std::string);
    int pulse_bar_view(int,int,char*);
    int raccrochage_midi_logical_vertical_dmx(int,int,int,int,int);
    int raccrochage_midi_visuel_vertical_dmx (int,int,int,int,int);
    int raccrochage_midi_visuel_vertical_dmx_inverted (int,int,int,int,int);
    int raccrochage_midi_logical_vertical(int,int,int,int,int);
    int raccrochage_midi_visuel_vertical (int,int,int,int,int);
    int raccrochage_midi_logical_horizontal_audio(int,int,int,int,int);
    int raccrochage_midi_visuel_horizontal_audio (int,int,int,int,int);
    int raccrochage_midi_logical_horizontal(int,int,int,int,int);
    int raccrochage_midi_visuel_horizontal (int,int,int,int,int);
    int raccrochage_midi_logical_horizontal_little(int,int,int,int,int);
    int raccrochage_midi_visuel_horizontal_little (int,int,int,int,int);
    int raccrochage_midi_logical_circulaire(int,int,int,int,int);
    int raccrochage_midi_visuel_circulaire (int,int,int,int,int);
    int midi_send_faders_button_logical(int,int,int);
    int midi_send_faders_button_visuel(int,int);
    void command_button_view(int,int,int,const std::string,const std::string,int);
    void command_button_logical(int,int,int,const std::string,const std::string,int,int);
//}
//currently in iCat14
//{
    int init_iphone_fonts();
    int init_iCat_data();
    int fermeture_client_iCat();
    int initialisation_clientserveur_iCat();
    int fermeture_clientserveur_iCat();
    int Menu_edition_iCat_sliders(int,int);
    int Menu_edition_iCat_boutons(int,int);
    int Menu_edition_iCat_strings(int,int);
    int Point_Viewing(int,int);
    int Tablier_GUI_editor(int,int);
    int  Menu_edition_tracking_zone(int,int);
    int BoxGuiBuilder_iCat (int,int);
    int BoxiCat (int,int);
    int reset_button(int,int,int);
    int check_button(int);
    int check_slider(int);
    int check_tracker_zone(int);
    int DoJobFantastickTouch();
    int ReceiveFantastick();
//}
//currently in icat_core
//{
    int recalculate_iCatBuilder_window_size();
    int reset_previous_levels_infos();
    int load_iCat_page (int);
    int refresh_continuously_iCat_trackerzones();
    int refresh_continuously_iCat_sliders();
    int refresh_check_buttons();
    int refresh_continuously_iCat_buttons();
    int To_iCat_DrawSlider(int,int,int,int,int);
    int To_iCat_DrawButton(int,int,int,int,int,int);
    int To_iCat_DrawTrackingZone(int,int,int,int,int);
    int To_iCat_DrawString(int,int,int,int,int);
    int Fantastick_check_string();
    int do_refresh_iCat(int);
//}
//currently in keyboard functions
//{
    int generation_Tableau_noms_clavier_FR();
    int check_channel_minus();
    int check_channel_plus();
    int select_channel_minus();
    int select_channel_plus();
    int key_switch_window_up();
    int key_switch_window_down();
    int key_affectation();
    int key_add_ch();
    int key_minus_ch();
    int key_up();
    int key_down();
    int key_unselect_ch();
    int key_thruth();
    int key_go();
    int key_presetvideo(int);
    int key_roi(int);
    int key_full();
    int key_time_in();
    int key_time_out();
    int key_time_in_out();
    int key_at_zero();
    int key_select_inv();
    int key_backward();
    int key_forward();
    int key_select_all();
    int key_left();
    int key_right();
    int key_printscreen();
//}
//currently in keyboard routines
//{
    int recall_config_page();
    int commandes_clavier();
//}
//currently in list proj core
//{
    int do_the_macro_of_the_channel(int,int);
    int do_channels_macro();
    int Channel_macros_core(int,int);
    int do_logical_liste_projecteurs(int,int);
//}
//currently in list proj visu
//{
    int Channel_macros_visu(int,int);
    int liste_projecteurs(int,int);
//}
//currently in logicals intres (intres --> entrees)
//{
    int entetes_confirmation();
    int operations_confirmation();
    int fenetre_confirm();
//}
//currently in midi
//{
    int do_midi_call_order(int control);
    int do_midi_job(int control);
    int ventilate_midi_to_midiarray();
    int ventilation_midi_sur_crossfade();
    int simulate_midi(int letype,int,int,int);
    pascal void Display (MidiEvPtr);
    pascal void DisplayTask (short);
    pascal void MSALARMAPI ReceivePolling (long,short,long,long,long);
    pascal void MSALARMAPI ReceiveEvents(short);
    int PrintSlotsInfosDevices(short);
    int midi_change_signal(int,int);
    int midi_list_and_choose_devices();
    int midipage_affectation(int,int,int,int);
    int refresh_launchpad_color_callibration();
    int midi_launchpad_colors(int,int);
    int midipage_preset_and_options(int,int,int,int);
    int midipage_devices(int,int,int,int);
    int do_midi_config(int,int,int,int);
//}
//currently in midi CORE
//{
    pascal void MSALARMAPI ReceiveEvents(short r);
    pascal void MSALARMAPI ReceivePolling (long date,short r,long a,long b,long c);
    int midi_init_sepecial_case_key_on();
    int InitTblLibEv();
    pascal void InstallFilter(short refNum,MidiFilterPtr filter);
    int InitMidi();
    int QuitMidi();
//}
//currently in midi launchpad
//{
    int define_colors();
    int launchpad_set_led(int,int);
    int launchpad_set_bool_value(int,int);
    int launchpad_set_zero_value(int);
    int launchpad_refresh_buffer_led();
    int reset_launchpad();
//}
//currently in minifaders core
//{
    int all_at_zero_panel_core(int,int);
    int mini_faders_panel_core(int,int,int);
//}
//currently in minifaders visu
//{
    int draw_sign_up(int,int);
    int draw_sign_down(int,int);
    int draw_sign_saw(int,int);
    int draw_sign_prev(int,int);
    int draw_sign_next(int,int);
    int draw_sign_up_down(int,int);
    int show_fgroup_in_minifaders_window(int,int,int,int);
    int all_at_zero_panel_visu(int,int);
    int mini_faders_panel_visu(int,int,int);
//}
//currently in mover 2013
//{
    int reset_memoires();
    int ClearGotoStep(int);
    int ClearIntoStep(int);
    int convert_bytes_to_int(BYTE,BYTE);
    int Move_refresh_xy(int);
    int prepare_move_values(int);
    int Clear_the_Move(int);
    int Move_AddStep(int);
    int Move_RecStep(int);
    int Move_DelStep(int);
    int Move_StepBackward(int);
    int Move_StepForward(int);
    int Move_Autostop(int);
    int MoveAffectGoto(int,int);
    int inversion_of_axes();
    int SetAllParams(int);
    int ImportMoveInMyDock(int);
    int TimeShift(int);
    int Print_Points(int);
    int reset_mover_buffer();
    int param_editor(int,int);
    int mover_box(int,int);
    int Move_do_crossfade(int);
    int ventilation_niveaux_mover();
//}
//currently in mover spline
//{
    fixed node_dist(NODE,NODE);
    NODE dummy_node(NODE,NODE);
    void calc_tangents(void);
    void get_control_points(NODE,NODE,int [8]);
    void get_control_points_backward(NODE,NODE,int [8]);
    void draw_spline(NODE,NODE);
    int draw_splines(int);
    int ShowSpline(int);
    int Prepare_Cross_Spline(int);
//}
//currently in my_window file sample
//{
    int do_logical_my_window_Box(int,int);
    int my_window_Box(int,int);
//}
//currently in network artnet
//{
    int diodes_artnet(int,int);
    int light_temoin_universe(int,int,int);
    int light_temoin_emission(int,int,int);
    int reset_poll_list();
    int show_artpoll_reply(int,int);
    int init_artnet_variables();
    int  DoArtPollReply();
    int ReceiveArtDmx();
    int load_artnet_conf();
    int save_artnet_conf();
    int detection_reseaux();
    int initialisation_serveur_artnet();
    int fermeture_serveur_artnet();
    int detection_mise_en_place_carte_reseaux();
    int initialisation_client_artnet();
    int fermeture_client_artnet();
    int ConstructArtPoll();
    int ArtDmx();
    int ConstructArtPollReply ();//size 250
    int  AnalyseArtPollReply();
//}
//currently in network MAC adress
//{
    int Box_IP_routing (int,int);
    int do_artnet_affect_config(int,int);
//}
//currently in numpad core
//{
    int do_wheel_level_job(int);
    int level_wheel_core (int,int,int,float);
    int do_logical_visual_numeric_pad (int,int);
//}
//currently in numpad visuel
//{
    int rafraichissement_padwheel();
    int level_wheel (int,int,int,float);
    int visual_numeric_pad (int,int);
//}
//currently in patch core
//{
    int do_curve_affectation();
    int load_curve_in_temp_curve();
    int check_dimmer_minus_override();
    int check_dimmer_plus_override();
    int do_logical_menu_curve(int,int);
    int do_logical_PatchBox(int,int,float);
//}
//currently in patch splines
//{
    fixed curve_node_dist(curve_node,curve_node);
    curve_node dummy_curve_node(curve_node,curve_node);
    void curve_calc_tangents();
    void curve_get_control_points(curve_node,curve_node,int);
    int write_curve();
    int draw_curve_node(int);
    int curve_draw_splines();
    int view_curve_after_draw();
    int SplineCurve();
    int build_square_curve(int);
    int build_fluo_curve(int);
    int build_preheat_curve(int);
    int build_inverse_curve(int);
//}
//currently in patch visu
//{
    int menu_curve(int,int);
    int PatchBox(int,int,float);
//}
//currently in plot
//{
    int draw_channel_of_symbol(int,int,int,int);
    int draw_gels_of_a_symbol(int,int,int,int);
    int draw_line_to_channel_of_symbol(int,int,int,int,int);
    int plot_draw_symbol_pc(int,int,float,float,int,int);
    int plot_draw_symbol_fresnel(int,int,float,float,int,int);
    int plot_draw_symbol_decoupe_etc_1(int,int,float,float,int,int);
    int plot_draw_symbol_decoupe_etc_2(int,int,float,float,int,int);
    int plot_draw_symbol_decoupe_etc_3(int,int,float,float,int,int);
    int plot_draw_symbol_decoupe_1(int,int,float,float,int,int);
    int plot_draw_symbol_decoupe_2(int,int,float,float,int,int);
    int plot_draw_symbol_decoupe_3(int,int,float,float,int,int);
    int plot_draw_symbol_Par_1(int,int,float,float,int,int);
    int plot_draw_symbol_Par_2(int,int,float,float,int,int);
    int plot_draw_symbol_Par_3(int,int,float,float,int,int);
    int plot_draw_symbol_Par_4(int,int,float,float,int,int);
    int plot_draw_symbol_Horiziode_assym(int,int,float,float,int,int);
    int plot_draw_symbol_Horiziode_sym(int,int,float,float,int,int);
    int plot_draw_symbol_BT(int,int,float,float,int,int);
    int plot_draw_symbol_T8(int,int,float,float,int,int);
    int plot_draw_symbol_Blinder(int,int,float,float,int,int);
    int plot_draw_symbol_Svoboda(int,int,float,float,int,int);
    int plot_draw_symbol_ACL(int,int,float,float,int,int);
    int plot_draw_symbol_fluo_little(int,int,float,float,int,int);
    int plot_draw_symbol_fluo_big(int,int,float,float,int,int);
    int plot_draw_symbol_FollowSpot1(int,int,float,float,int,int);
    int plot_draw_symbol_FollowSpot2(int,int,float,float,int,int);
    int plot_draw_symbol_VP1(int,int,float,float,int,int);
    int plot_draw_symbol_VP2(int,int,float,float,int,int);
    int plot_draw_symbol_slideprojector(int,int,float,float,int,int);
    int plot_draw_symbol_retroprojector(int,int,float,float,int,int);
    int plot_draw_symbol_barndoors(int,int,float,float,int,int);
    int plot_draw_symbol_top_hat(int,int,float,float,int,int);
    int plot_draw_symbol_color_extender(int,int,float,float,int,int);
    int plot_draw_symbol_colorchanger(int,int,float,float,int,int);
    int plot_draw_symbol_jalousie(int,int,float,float,int,int);
    int plot_draw_symbol_iris(int,int,float,float,int,int);
    int plot_draw_symbol_goboholder(int,int,float,float,int,int);
    int plot_draw_symbol_shutter(int,int,float,float,int,int);
    int plot_draw_symbol_motorized_mirror(int,int,float,float,int,int);
    int plot_draw_symbol_platine_de_sol(int,int,float,float,int,int);
    int plot_draw_symbol_littlestand(int,int,float,float,int,int);
    int plot_draw_symbol_bigstand(int,int,float,float,int,int);
    int plot_draw_symbol_barre_de_couplage(int,int,float,float,int,int);
    int plot_draw_symbol_echelle(int,int,float,float,int,int);
    int plot_draw_symbol_pont50_1m(int,int,float,float,int,int);
    int plot_draw_symbol_pont50_3m(int,int,float,float,int,int);
    int plot_draw_symbol_pont50_jonction(int,int,float,float,int,int);
    int plot_draw_symbol_pont30_1m(int,int,float,float,int,int);
    int plot_draw_symbol_pont30_3m(int,int,float,float,int,int);
    int plot_draw_symbol_pont30_jonction(int,int,float,float,int,int);
    int plot_draw_symbol_smokemachine(int,int,float,float,int,int);
    int plot_draw_symbol_fogmachine(int,int,float,float,int,int);
    int plot_draw_symbol_direct(int,int,float,float,int,int);
    int plot_draw_symbol_serviceligth(int,int,float,float,int,int);
    int plot_draw_symbol_dimmerline(int,int,float,float,int,int);
    int plot_print_neutral_symbol(int,int,int);
    int plot_symbol_list(int,int);
    int plot_draw_shape_line(int,int,int,int,float,float,int,bool);
    int plot_draw_shape_stripline(float,float,float,float,float,float,int,int,bool,bool);
    int plot_draw_rectangle(int,int,float,float,float,float,int,bool);
    int plot_draw_shape_curtain(int,int,int,int,float,float,int,bool);
    int plot_draw_circle(int,int,float,float,int,bool);
    int plot_draw_slice(int,int,float,float,float,float,int,bool);
    int plot_draw_polygon(int,int,float,float,int,float,int,bool);
    void plot_draw_text(int,int,int,int,const std::string,float,bool);
    int plot_shape_list(int,int);
    int shape_edition(int,int);
    int symbol_edition_options(int,int);
    int plot_symbol_edition(int,int);
    int plot_menu_bar(int,int);
    void deroule_repertoire_plans(int,int,const std::string);
    int menu_plan(int,int);
    int plot_draw_plan_grid_for_view_point(int,int,int,int);
    int plot_draw_shapes(int,int);
    int plot_draw_plan(int,int,int);
    int plot_draw_levels(int,int,int);
    int plot_draw_plan_bitmap(int,int,float);
    int plot_draw_legend(int,int);
    int plot_legend_menu(int,int);
    int Plot_window(int,int);
//}
//currently in plot core
//{
    int do_a_screen_capture();
    int do_plot_screen_capture(char [25]);
    int right_click_on_plot();
    int plot_reset_list_gelat();
    int plot_reset_list_appareils();
    int plot_generate_gels_list();
    int plot_generate_appareils_list();
    int scan_planfolder();
    int add_channel_selection_to_layers_plot();
    int change_shape_type(int);
    int group_ungroup_selected_shapes();
    int refresh_opening_angle(float);
    int affect_angle_to_shapes(float);
    int affect_polygon_nbr_of_corners(int);
    int clear_shape_slot(int);
    int unselect_all_shapes();
    int affect_size_to_shape(float);
    int affect_font_to_texts(int);
    int affect_color_pattern_to_shape(int);
    int affect_size_to_rect(float,float);
    int copy_shape_to_emply_slot(int,int);
    int rearrange_shapes();
    int snapshot_shapes();
    int delete_selected_shapes();
    int refresh_view_shape_params(int);
    int check_select_deselect_shape(int,int);
    int store_plot_position_of_shapes();
    int add_shape_to_plot(int);
    int exchange_shape_position(int,int);
    int position_down_selected_shapes();
/* CppCheck - unusedFunction    int add_selected_shapes(); */
    int position_on_top_selected_shapes();
    int substract_channel_selection_to_layers_plot();
    int  search_affect_first_dimmer_to_symbole(int,int);
    int reset_symbols_selected(int);
    int change_symbol_type(int,int);
    int repatch_from_plot(int);
    int store_plot_position_of_activ_calc(int);
    int clear_grouped_to_symbols(int,int);
    int clear_symbol_slot(int,int);
    int recount_symbols_on_calc(int);
    int clear_calc(int);
    int add_a_symbol_to_plot(int);
    int duplicate_selected_symbols(int);
    int snapshot_calc(int);
    int copy_symbol_to_emply_slot(int,int,int);
    int reorder_plan(int);
    int delete_selected_symbols(int);
    int add_selected_symbols_to_calc(int);
    int exchange_symbol_position(int,int,int);
    int send_symbols_from_calc_to_calc(int,int);
    int position_down_selected_symbols(int);
    int position_on_top(int);
    int group_symbols_selected(int);
    int duplicate_selected_shapes();
    int store_relativ_xy_position_of_activ_calc(int);
    int store_relativ_xy_position_of_shape();
    int check_select_deselect_symbol(int,int);
    int affect_angle_to_symbols(int,float);
    int edit_symbol_name();
    int edit_shape_name();
    int plot_align_x(int);
    int plot_align_y(int);
    int plot_ventilate_x(int);
    int plot_ventilate_y(int);
    int plot_shapes_align_x();
    int plot_shapes_align_y();
    int plot_shapes_ventilate_x();
    int plot_shapes_ventilate_y();
    int logical_plot_symbol_list(int,int);
    int logical_plot_shape_list(int,int);
    int logical_shape_edition(int,int);
    int logical_symbol_edition_options(int,int);
    int logical_plot_symbol_edition(int,int);
    int logical_plot_menu_bare(int,int);
    void logical_deroule_repertoire_plans(int,int);
    void logical_menu_plan(int,int);
    void PLOT_in_case_of_window_lose_of_focus();
    void case_where_init_plot_menu_background();
    void plan_plot_mouseWheel_graphics_handle();
    bool isMouseOverPlot();
    int do_logical_Plot_window(int,int);
//}
//currently in procs visuels rebuild
//{
    bool wc_askConfirmWindowIsOpen();
    int detection_over_window();
    int move_window(int);
    int MoveCloseBox(int,int,int);
	bool mouseMoveSinceLeftClic ();
	bool mouseMoveSinceRightClic ();
    int do_logical_MoveCloseBox(int,int,int);
    int logical_channelspace();
    void mouseWheel_graphics_handle();
    int check_graphics_mouse_handling();
//}
//currently in save show
//{
    void On_Open_name_of_directory();
    int get_current_time();
    int load_midipreset();
    int load_onstart_config();
    int load_screen_config();
    int load_core_config();
    int Save_Core_Config();
    int Save_onstart_Config();
    int Save_Screen_Config();
    int Save_Launchpad_RetroLight();
    int Load_Launchpad_RetroLight();
    int save_draw_preset_config();
    int load_draw_preset_config();
    int Save_Arduino_Config();
    int load_arduino_config();
    int Load_Window_Conf();
    int Load_Sequenciel_Conf();
    int Load_setup_conf();
    int Save_setup_conf();
    int Save_Plot_Plan_config();
    int Load_Plot_Plan_config();
    int write_indexes();
    int load_indexes();
    int load_show_coming_from();
    int Save_Window_Conf();
    int Load_User_Profile();
    int Save_Sequenciel_Conf();
    int Save_audiofiles_cues();
    int Load_Audio_Conf();
    int Save_Audio_Conf();
    int Save_Show();
    int Load_Show();
    int save_the_show(char [24]);
    int load_the_show(char [24]);
    int do_wizard_reload_from_disk();
//}
//currently in saves export import
//{
    int do_reset_all_listproj();
    int do_ASCII_import();
    int do_ASCII_export();
    int do_Schwartzpeter_import();
    int do_Alq_import();
//}
//currently in saves export pdf
//type fixé à la compilation pour : error_handler (HPDF_STATUS,HPDF_STATUS,void*);
//{
    void draw_numpage(HPDF_Page page,float,float,const char*);
    int verification_fin_de_page();
    void draw_fleche_link  (HPDF_Page,float,float);
    void draw_title  (HPDF_Page,float,float,const char*);
    void draw_info  (HPDF_Page,float,float,const char*);
    void draw_section (HPDF_Page,float,float,const char*,float,float,float);
    void saut_de_page();
    bool check_there_is_someone_in_grid(int);
    int pdf_draw_little_gridplayer(HPDF_REAL,HPDF_REAL);
    int pdf_draw_channels_on_grid(HPDF_REAL,HPDF_REAL,int,int);
    int pdf_draw_infos_of_step(HPDF_REAL,HPDF_REAL,int,int);
    int draw_pdf_gridayer_state(int);
    int draw_pdf_grid(int,HPDF_REAL,HPDF_REAL);
    int draw_pdf_echo_config();
    int draw_pdf_draw_config();
    int draw_pdf_grid_players_config();
    int draw_pdf_chaser(int,HPDF_Page);
    int generate_list_midi_for_pdf();
    int print_ch_macro(int);
    int print_ch_from_plot(int);
    int print_midi_command(int);
    int draw_pdf_icat_preset(int);
    int do_pdf_export();
//}
//currently in saves menu
//{
    int scan_savesfolder();
    void scan_importfolder(const char*);
    int choose_personnal_preset_binary_save_load(int,int);
    int do_logical_choose_personnal_preset_binary_save_load(int,int);
    int check_import_type();
    void deroule_repertoire_export_import(int,int,const std::string);
    void do_logical_deroule_repertoire_export_import(int,int,const std::string);
    void deroule_repertoire_classical_save(int,int,const std::string);
    void do_logical_deroule_repertoire_classical_save(int,int,const std::string);
    int selecteur_PDF_save_solo_global(int,int);
    int do_logical_selecteur_PDF_save_solo_global(int,int);
    int selecteur_binary_save_solo_global(int,int);
    int do_logical_selecteur_binary_save_solo_global(int,int);
    int Save_Menu(int,int);
    int do_logical_Save_Menu(int,int);
//}
//currently in sequentiel core
//{
    int call_mem_onstage();
    int affect_time_from_chrono_to_mem(int);
    int call_mem_onpreset();
    int next_mem_crossfade_finished(int);
    int do_call_time_and_rec_f1_f2_f3(int);
    int do_logical_refresh_vision_memories(int,int);
    int do_logical_x1_x2(int,int);
    int do_logical_Sequenciel_Window(int,int,int,int);
//}
//currently in sequentiel visu
//{
    int refresh_vision_memories(int,int);
    int x1_x2(int,int);
    int Sequenciel_Window(int,int,int,int);
//}
//currently in time core
//{
    int Chrono_PlayPause();
    int do_logical_Time_Window(int,int,int);
//}
//currently in time visu
//{
    int print_time_reperes(int);//affichage des chiffres sur le tableau de bord
    int Time_Window(int,int,int);
//}
//currently in trichro core
//{
    int stock_etat_picker_dans_dockcolor(int);
    int CounterClockWise (double,double,double,double,double,double);
    int trichro_back_buffer(int,int,int,int);
    int do_colors();
    int show_who_is_in_dock_color(int,int);
    int do_logical_Interface_Trichromie(int,int,int,int);
//}
//currently in trichro visu
//{
    int Interface_Trichromie(int,int,int,int);
//}
//currently in video tracking core
//{
    void ticker_video();
    int Load_Video_Conf();
    int Save_Video_Conf();
    int InitVideo();
    int CloseVideo();
    int Snap_Background();
    int Filter_Image(int,int,int,int);
    int do_logical_Move_Tracker(int,int);
    int do_logical_Edit_Tracker_Size(int,int);
    int ventilation_video_trackers();
    int Trackers();
    int do_logical_Set_Filtering_Image();
    int show_who_is_in_ROI_as_channel(int,int);
    int do_logical_Interface_video_window(int,int);
//}
//currently in video tracking visu
//{
    int ShowTrackers();
    int Set_Filtering_Image();
    int tracking_print_to_screen();
    int Interface_video_window(int,int);
//}
//currently in wizard
//{
    int clear_wizard_store_ch_in();
    int clear_wizard_store_ch_out();
    int wizard_store_channel_in();
    int wizard_store_channel_out();
    int Box_mem_to_mem(int,int);
    int fenetre_wizard(int,int);
//}
//currently in wizard operations
//{
    int wizard_detect_unused_channels(int,int);
    int wizard_calcul_nbre_de_mem();
    int wizard_calcul_nbre_de_mem_deleted();
    int wizard_rebuild(int);
    int wizard_clear_transfert_array();
    int wizard_clear_mem_original();
    int wizard_delete_mem();
    int wizard_restore_mem();
    int wizard_copy_mem();
    int wizard_inspekt_mem();
    int wizard_insert_mems();
    int wizard_move_mems();
    int wizard_reset_to_default_time();
    int do_wizard_mem();
    int do_wizard_ch();
//}

//currently in splashscreen visu
//{
    void show_title();
	void save_load_print_to_screen(const std::string label);
//}

//currently in savereport window
//{
	bool mouseover_Show_report_save_load ();
	void Show_report_save_load_logic ();
	void Show_report_save_load_draw();
	void reset_error_on_save_load();
	void detect_error_on_save_load();
	void clear_report_string();
	void Show_report_save_load();
//}

#endif // WHITECAT_FCT_H_INCLUDED
