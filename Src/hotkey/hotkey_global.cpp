#include "hotkey_global.h"
#include "whc_toolbox.h"
#include <windows.h>

void whc_hk_save() //01 Sauvegarde générale - Quick save
{
    if(index_is_saving==0)
    {
        index_save_global_is=1;
        index_do_quick_save=1;
    }

	whc_toolbox tool;
	std::string path = tool.executablePath();
	std::string user_file  = path + "\\user\\hotkey_user.whc";

	hk_manager.save(user_file);
}

void whc_hk_save_and_quit() //02  Quitter avec sauvegarde - Quit and save
{
    index_ask_confirm=1;
    index_do_quit_with_save=1;
    index_do_quit_without_save=0;

	whc_toolbox tool;
	std::string path = tool.executablePath();
	std::string user_file  = path + "\\user\\hotkey_user.whc";

	hk_manager.save(user_file);
}

void whc_hk_quit() //03 Quitter sans sauvegarde - Quit without save
{
    for (int i=0; i<12; i++)
    {
        specify_who_to_save_load[i]=0;
    }
    reset_save_load_report_string();
    index_ask_confirm=1;
    index_do_quit_without_save=1;
}

void whc_hk_snapshot_close_windows() //04 Snapshot et extinction des fenêtres - Snapshot and closing windows [SHIFT][PRINT SCREEN]
{
        snapshot_windows();
        close_all_windows();
}

void whc_hk_snapshot_open_windows() //05 Rappel du Snapshot des fenêtres - Recall windows snapshot [CTRL][PRINT SCREEN]
{
        recall_windows();
}

void whc_hk_cycle_forward_open_windows() //06 Circulation dans les principales fenêtres - Cycle forward thru open windows	[PGUP]
{
            sprintf(string_key_id,list_keyname[0]);
			back_window_push_to_front();
}

void whc_hk_cycle_backward_open_windows() //07 Circulation dans les principales fenêtres - Cycle backward thru open windows [PGDOWN]
{
            sprintf(string_key_id,list_keyname[0]);
            front_window_push_to_back();
}

void whc_hk_open_forward_solo_windows() //08 Appel solo dans les principales fenêtres - Open windows in solo mode [CTRL][PGDOWN]
{
        pos_focus_window=window_focus_id;
        substract_a_window(pos_focus_window);
        if(pos_focus_window<900)
        {
            pos_focus_window=899;
        }
        pos_focus_window++;
        if(pos_focus_window>max_window_identity_is)
        {
            pos_focus_window=900;
        }
        add_a_window(pos_focus_window);
}

void whc_hk_open_backward_solo_windows() //09 Appel solo dans les principales fenêtres - Open windows in solo mode [CTRL][PGDOWN]
{
        pos_focus_window=window_focus_id;
        substract_a_window(pos_focus_window);
        pos_focus_window--;
        if(pos_focus_window<900)
        {
            pos_focus_window=max_window_identity_is;
        }
        if(pos_focus_window>max_window_identity_is)
        {
            pos_focus_window=900;
        }
        add_a_window(pos_focus_window);
}


void whc_hk_main_init()
{

	whc_toolbox tool;
	std::string path = tool.executablePath();
	std::string user_file  = path + "\\user\\hotkey_user.whc";
	std::string init_file  = path + "\\ressources\\hotkey_init.whc";

    if (tool.fileexist(user_file))
	{
		 hk_manager.init(user_file) ;
	}
	else hk_manager.init(init_file) ;
    hk_manager.inputIsOn_Flag(index_type);
    hk_manager.connect_fct(1,&whc_hk_save);
    hk_manager.connect_fct(2,&whc_hk_save_and_quit);
    hk_manager.connect_fct(3,&whc_hk_quit);
    hk_manager.connect_fct(4,&whc_hk_snapshot_close_windows);
    hk_manager.connect_fct(5,&whc_hk_snapshot_open_windows);
    hk_manager.connect_fct(6,&whc_hk_cycle_forward_open_windows);
    hk_manager.connect_fct(7,&whc_hk_cycle_backward_open_windows);
    hk_manager.connect_fct(8,&whc_hk_open_forward_solo_windows);
    hk_manager.connect_fct(9,&whc_hk_open_backward_solo_windows);
}
