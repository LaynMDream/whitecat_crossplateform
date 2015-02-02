#include "hotkey_global.h"
#include "whc_toolbox.h"

void whc_hk_save() //Sauvegarde g�n�rale - Quick save
{
    if(index_is_saving==0)
    {
        index_save_global_is=1;
        index_do_quick_save=1;
    }
}

void whc_hk_save_and_exit() // Quitter avec sauvegarde - Quit and save
{
    index_ask_confirm=1;
    index_do_quit_with_save=1;
    index_do_quit_without_save=0;
}

void whc_hk_exit() //Quitter sans sauvegarde - Quit without save
{
    for (int i=0; i<12; i++)
    {
        specify_who_to_save_load[i]=0;
    }
    reset_save_load_report_string();
    index_ask_confirm=1;
    index_do_quit_without_save=1;
}

void whc_hk_main_init()
{
	std::string user_file = "C:\\whitecat_xplatform_christoph\\whitecatbuild\\appli\\hotkey_user.whc";
	std::string init_file  = "C:\\whitecat_xplatform_christoph\\whitecatbuild\\appli\\hotkey_init.whc";
	whc_toolbox tool;

    if (tool.fileexist(user_file))
	{
		 hk_manager.init(user_file) ;
	}
	else hk_manager.init(init_file) ;

    hk_manager.inputIsOn_Flag(index_type);

    hk_manager.link_fct_ptr(01,&whc_hk_save);
    hk_manager.link_fct_ptr(02,&whc_hk_save_and_exit);
    hk_manager.link_fct_ptr(03,&whc_hk_exit);
}
