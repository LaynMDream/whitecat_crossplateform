#include "whc_hotkey.h"

//initialistion des variables statiques communes à tous les objets de la classe
int whc_hotkey::c_nbr = 0;
std::vector<whc_hotkey> whc_hotkey::c_list;

whc_hotkey::whc_hotkey()
{
    //ctor
    c_nbr++;
}

whc_hotkey::whc_hotkey(whc_hk_apply fonctionality, whc_hk_input signature)
{
    //ctor
    m_fonctionality = fonctionality ;
    m_signature = signature;
    c_nbr++;
}

whc_hotkey::~whc_hotkey()
{
    //dtor
    c_nbr--;
}

int whc_hotkey::collect()
{

    if ( keypressed())
    {
        int isreadkey = readkey();
        int tmp_scancode=(isreadkey >> 8);
        while ( keypressed())
        {
            int clearbuff = readkey();
        }

        //update last user keyboard input
        if(not m_user_askconfirm) // except if last input is a hk to link and wait for confirmation
            m_user_signature = whc_hk_input::c_scan(tmp_scancode);

        //if(not m_inputIsOn)  //language de commande actif
        {

            if (not(tmp_scancode == KEY_ESC)) //pas de raccourci clavier si Esc ou si input
            {
                if((m_user_selectfunc >0) && (not m_user_askconfirm))
                {
                    //search if user_signature is allready associate to a fonctionality
                    whc_hk_apply fctlink = search_fct(m_user_signature);

                    if (fctlink.id()==m_user_selectfunc) // this signature is allready associated to the aim fonctionnality
                    {
                        link_fct_hk(m_user_selectfunc,m_user_signature);
                        user_hk_init() ;
                    }
                    else if (fctlink.id()==-1) // this signature is not used by any other fonctionnality
                    {
                        link_fct_hk(m_user_selectfunc,m_user_signature);
                        user_hk_init() ;
                    }
                    else
					{
						m_user_conflictfunc = fctlink ;
						m_user_askconfirm = true ;
                    // if used by alreadyused_byfunction : ask_user = true
                    // in other part test if ask_user = true
                    // and if user_response = true remove old association to new wih user_pointingfunction

					}
                }
                else
                {
                    user_hk_init() ;
                    return shortcutprocess(isreadkey);
                }
            }
            else //ESC
            {
                if(m_user_selectfunc >0)
                {
                    //abandon définition
                    user_hk_init() ;
                    return -1 ; //isreadkey was used - not to be used by command language
                }
            }
        }
        return isreadkey ;
    }
    else return -1 ; //no isreadkey - nothing to be used by command language

}

int whc_hotkey::shortcutprocess(int isreadkey)
{
    //search if signature is known in subscription list
    whc_hk_apply fctlink = search_fct(m_user_signature);
    if (fctlink.id()>0)
    {
        void (*fctptr)(void);       /*déclaration du pointeur*/
        fctptr = fctlink.processOnHotkey();   /*Initialisation*/
        fctptr();  /* Execution de la méthode */
        whc_hk_input neutre ;
        m_user_signature = neutre ;
        return -1 ;
    }
    else
        return isreadkey;
}

whc_hk_apply whc_hotkey::search_fct(whc_hk_input signature)
{
    int i = c_list.size();

    while (i>0)
    {
        i--;
        whc_hk_apply list_fonctionality ;
        whc_hk_input list_signature ;
        whc_hotkey* hotkey;
        hotkey = &whc_hotkey::c_list[i];
        list_fonctionality = hotkey->fonctionality();
        list_signature     = hotkey->signature();

        if ((list_signature.alt()      == signature.alt())
                &&  (list_signature.ctrl()     == signature.ctrl())
                &&  (list_signature.shift()    == signature.shift())
                &&  (list_signature.scancode() == signature.scancode()))
        {
            i=0;
            return list_fonctionality ;
        }
    }
    whc_hk_apply null_fct ;
    return null_fct ;
}

void whc_hotkey::connect_fct(int fctid, ptrMthd fctptr)
{
    int i = c_list.size();

    while (i>0)
    {
        i--;
        whc_hotkey* hotkey ;
        hotkey = &whc_hotkey::c_list[i] ;
        whc_hk_apply fonctionality ;
        whc_hk_input signature ;
        fonctionality = hotkey->fonctionality() ;
        signature = hotkey->signature() ;

        if (fonctionality.id()==fctid)
        {
            fonctionality.SetprocessOnHotkey(fctptr);
            whc_hotkey::c_list[i].Setfonctionality(fonctionality);
            //whc_hotkey::c_list[i].Setsignature(signature);
            i=0;
        }
    }
}

void whc_hotkey::init(std::string fic_name)
{
	std::vector<whc_hotkey> clear_list;
	c_list.swap(clear_list);
	load(fic_name);
}

void whc_hotkey::load(std::string fic_name)
{
    std::ifstream fic_stream(fic_name.c_str(), std::ios::in);

    if (not(fic_stream.fail()))
    {
        std::string ligne ;
        whc_toolbox tool;
        while(getline(fic_stream, ligne))
        {
            int tmp_id;
            std::string tmp_module;
            std::string tmp_description;
            bool tmp_shift;
            bool tmp_ctrl;
            bool tmp_alt;
            int  tmp_scancode;
            std::string tmp_wording;

            std::vector<std::string> tokens = tool.split_string(ligne,';');

            tmp_id               = tool.string_to_int (tokens[0]);
            tmp_module           = tokens[1] ;
            tmp_description      = tokens[2] ;
            tmp_shift            = (tool.string_to_int (tokens[3])==1);
            tmp_ctrl             = (tool.string_to_int (tokens[4])==1);
            tmp_alt              = (tool.string_to_int (tokens[5])==1);
            tmp_scancode         = tool.string_to_int (tokens[6]);
            tmp_wording          = tokens[7] ;

            whc_hk_input signature( tmp_shift,  tmp_ctrl,  tmp_alt,  tmp_scancode) ;
            whc_hk_apply fonctionality(tmp_id, tmp_module, tmp_description, nullptr) ;
            c_list.push_back(whc_hotkey(fonctionality, signature));
        }
        fic_stream.close();
    }
}

void whc_hotkey::save(std::string fic_name)
{
    std::ofstream fic_stream(fic_name.c_str(), std::ios::out | std::ios::trunc);

    if (not(fic_stream.fail()))
    {
        whc_toolbox tool;

		int i = c_list.size();
		int j = i ;

		while (i>0)
		{
			int k = j-i;
			i--;

			whc_hk_apply list_fonctionality ;
			whc_hk_input list_signature ;
			whc_hotkey* hotkey;
			hotkey = &whc_hotkey::c_list[i];
			list_fonctionality = hotkey->fonctionality();
			list_signature     = hotkey->signature();

			std::string ligne ;
			ligne += tool.int_to_string(list_fonctionality.id());
			ligne +=";" ;
			ligne += list_fonctionality.module();
			ligne +=";" ;
			ligne += list_fonctionality.description();
			ligne +=";" ;
			ligne += tool.bool_to_string(list_signature.shift());
			ligne +=";" ;
			ligne += tool.bool_to_string(list_signature.ctrl());
			ligne +=";" ;
			ligne += tool.bool_to_string(list_signature.alt());
			ligne +=";" ;
			ligne += tool.int_to_string(list_signature.scancode());
			ligne +=";" ;
			ligne += list_signature.wording();
			ligne +=";" ;

			fic_stream << ligne << std::endl ;
        }
        fic_stream.close();
    }
}

void whc_hotkey::link_fct_hk(int fctid, whc_hk_input signature)
{
    int i = c_list.size();

    while (i>0)
    {
        i--;
        whc_hotkey* hotkey ;
        hotkey = &whc_hotkey::c_list[i] ;
        whc_hk_apply fonctionality ;
        fonctionality = hotkey->fonctionality() ;

        if (fonctionality.id()==fctid)
        {
            //whc_hotkey::c_list[i].Setfonctionality(fonctionality);
            whc_hotkey::c_list[i].Setsignature(signature);
            i=0;
        }
    }
}

void whc_hotkey::replace_link_fct_hk()
{
    bool oldisclear = false ;
    bool newisset = false ;

    int i = c_list.size();

    while (i>0)
    {
        i--;
        whc_hotkey* hotkey ;
        hotkey = &whc_hotkey::c_list[i] ;
        whc_hk_apply fonctionality ;
        fonctionality = hotkey->fonctionality() ;

        if (fonctionality.id()==m_user_selectfunc)
        {
            //whc_hotkey::c_list[i].Setfonctionality(fonctionality);
            whc_hotkey::c_list[i].Setsignature(m_user_signature);
            newisset = true;
            if (oldisclear) i=0;
        }

        if (fonctionality.id()==m_user_conflictfunc.id())
        {
            //whc_hotkey::c_list[i].Setfonctionality(fonctionality);
            whc_hk_input null_signature;
            whc_hotkey::c_list[i].Setsignature(null_signature);
            oldisclear = true;
            if (newisset) i=0;
        }
    }
}

void whc_hotkey::user_hk_init()
{
    whc_hk_apply null_fct ;

    m_user_selectfunc   = -1 ;    // fonctionality->id()
    m_user_askconfirm   = false ; // on demande confirmation, si signature déjà attribuée à une autre fonction
    m_user_didanswer    = false ; // si la demande de confirmation a été répondue
    m_user_answer       = false ; // la réponse est oui/non
    m_user_conflictfunc = null_fct ;
    //surtout pas réinit m_user_signature
}
