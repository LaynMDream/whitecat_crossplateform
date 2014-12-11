#include "whc_controller.h"

/*Initialisation des variables (statiques) de classe*/
int whc_controller::s_nbrOfMidiCtl = 0;

whc_controller::whc_controller()
{
	//ctor
	whc_controller::s_nbrOfMidiCtl ++;
}

whc_controller::~whc_controller()
{
	//dtor
	whc_controller::s_nbrOfMidiCtl --;
}
