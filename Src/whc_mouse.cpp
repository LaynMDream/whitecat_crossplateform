#include "whc_mouse.h"

/*Initialisation des variables de classe*/

//Buttons
float whc_button::gapSecond = 0.5; // Default Initialisation of  max time between two clics to be a double clic
whc_eventclic whc_button::mouseLastClic = {none,clock()};
std::vector<whc_eventclic> whc_button::mouseClicHistory;

//Wheels
int whc_wheel::mouse_z_prev = mouse_z;
int whc_wheel::mouse_w_prev = mouse_w;

//
whc_button::whc_button() : m_Down(false), m_Double(false), m_DragDrop(false), m_Processed(true)
{
	//ctor
	m_dragpos.x = mouse_x; m_dragpos.y = mouse_y; m_dragpos.z = mouse_z;
	whc_button::mouseClicHistory.clear();
	whc_button::mouseClicHistory.push_back (whc_button::mouseLastClic);
}

whc_button::~whc_button()
{
	//dtor
}

bool whc_button::IsThisADoubleClic (whc_mousebutton button)
{
	bool result = false ;
	whc_button::mouseLastClic = {button,clock()};

	if (whc_button::mouseClicHistory.size()>0)
	{
		if (whc_button::mouseClicHistory[0].button = whc_button::mouseLastClic.button)
		{
			clock_t present  = whc_button::mouseLastClic.cpu_clock_ticks ; 			// present  down
			clock_t past     = whc_button::mouseClicHistory[0].cpu_clock_ticks ; 	// previous down

			float nbr_ticks_per_sec = CLOCKS_PER_SEC * 1.0 ;
			clock_t gap_in_ticks = (present - past);
			float gap_in_sec = gap_in_ticks / nbr_ticks_per_sec ;

			if (gap_in_sec < whc_button::gapSecond)
			{
				result = true ;
			}
		}
	}

	whc_button::mouseClicHistory.clear();
	whc_button::mouseClicHistory.push_back (whc_button::mouseLastClic);

	return result ;
}

void whc_button::CollectEvent (int& mouseSignal, whc_button& mouseClicLeft, whc_button& mouseClicMiddle, whc_button& mouseClicRight)
{
    switch(mouseSignal)
    {
    	case MOUSE_FLAG_LEFT_DOWN  :
    		mouseClicLeft.SetIsDown();
			mouseClicLeft.SetIsToProcess();
			mouseClicLeft.SetIsDouble(IsThisADoubleClic(left));
			mouseClicLeft.SetIsDragDrop(false);
			mouseClicLeft.SetDragPos();
			break;

		case MOUSE_FLAG_LEFT_UP    :
			mouseClicLeft.SetIsUp();
			mouseClicLeft.SetIsDragDrop((mouseClicLeft.dragPos().x == mouse_x) && (mouseClicLeft.dragPos().y == mouse_y));
			break;

		case MOUSE_FLAG_MIDDLE_DOWN :
    		mouseClicMiddle.SetIsDown();
			mouseClicMiddle.SetIsToProcess();
			mouseClicMiddle.SetIsDouble(IsThisADoubleClic(middle));
			mouseClicMiddle.SetIsDragDrop(false);
			mouseClicMiddle.SetDragPos();
			break;

		case MOUSE_FLAG_MIDDLE_UP   :
			mouseClicMiddle.SetIsUp();
			mouseClicMiddle.SetIsDragDrop((mouseClicMiddle.dragPos().x == mouse_x) && (mouseClicMiddle.dragPos().y == mouse_y));
			break;

		case MOUSE_FLAG_RIGHT_DOWN :
    		mouseClicRight.SetIsDown();
			mouseClicRight.SetIsToProcess();
			mouseClicRight.SetIsDouble(IsThisADoubleClic(right));
			mouseClicRight.SetIsDragDrop(false);
			mouseClicRight.SetDragPos();
			break;

		case MOUSE_FLAG_RIGHT_UP   :
			mouseClicRight.SetIsUp();
			mouseClicRight.SetIsDragDrop((mouseClicRight.dragPos().x == mouse_x) && (mouseClicRight.dragPos().y == mouse_y));
			break;

		default :
			break;
    }
}

//------------------------------------------------------------------------------------------------------------------------------

whc_wheel::whc_wheel() : m_level(0), m_gain(0), m_yield(0), m_speed(0), m_Processed(true)
{
	//ctor
}

whc_wheel::~whc_wheel()
{
	//dtor
}

void whc_wheel::CollectEvent (int& mouseSignal, whc_wheel& mouseScroll , whc_wheel& mouseRoll)
{
	if ((key[KEY_LSHIFT]) && (mouseSignal==MOUSE_FLAG_MOVE_Z))
	{
		mouseSignal==MOUSE_FLAG_MOVE_W; //(Left Shift + Scroll Wheel) emulate "Roll" Wheel
	}

	//Mouse wheel event
    switch(mouseSignal)
    {
    	case MOUSE_FLAG_MOVE_Z  :   //Scroll
    		mouseScroll.toBeProcessed();
    		mouseScroll.SetGain(mouse_z - whc_wheel::mouse_z_prev); //Instant mouvement of the wheel : -1, 0, +1 // Yield is updated in the same time
    		mouseScroll.SetLevel( mouseScroll.level() + mouseScroll.gain()); // level is not automatically set to 0 when event processed (mouse_z will be : see case default)
    		whc_wheel::mouse_z_prev = mouse_z;

			if ((key[KEY_LCONTROL]))
			{
				mouseScroll.SetSpeed(mouseScroll.speed() + mouseScroll.gain());	//Instant acceleration
			}
			else
			{
				mouseScroll.SetSpeed(0);
			}
			break;

    	case MOUSE_FLAG_MOVE_W  :   //Roll
    		mouseRoll.toBeProcessed();
    		mouseRoll.SetGain(mouse_w - whc_wheel::mouse_w_prev); //Instant mouvement of the wheel : -1, 0, +1 // Yield is updated in the same time
    		mouseRoll.SetLevel(mouseRoll.level() + mouseRoll.gain()); // level is not automatically set to 0 when event processed (mouse_w will be : see case default)
    		whc_wheel::mouse_w_prev = mouse_w;

			if ((key[KEY_LCONTROL]))
			{
				mouseRoll.SetSpeed(mouseRoll.speed() + mouseRoll.gain());	//Instant acceleration
			}
			else
			{
				mouseRoll.SetSpeed(0);
			}
			break;

		default :
			if (mouseScroll.isProcessed() && (not (mouse_z==0))) {position_mouse_z(0);}
			if (mouseRoll.isProcessed() && (not (mouse_w==0))) {position_mouse_w(0);}
			break;
    }
}

// SANS ACCELERATION
void whc_wheel::leveIncrease(whc_wheel &wheel, int &i_level, int maxlevel, int minlevel)
{
	i_level = i_level + wheel.yield();
	wheel.SetIsProcessed();

	if (i_level > maxlevel)
	{
		i_level=maxlevel;
	}
	if (i_level<minlevel)
	{
		i_level=minlevel ;
	}
}

int whc_wheel::leveIncrease(whc_wheel &wheel, float &f_level, float maxlevel, float minlevel)
{
    f_level = f_level + wheel.yield();
    wheel.SetIsProcessed();

    if (f_level > maxlevel)
    {
        f_level=maxlevel;
    }
    if (f_level<minlevel)
    {
        f_level=minlevel ;
    }
    return (int) f_level;
}

// Modifie la valeur de la variable float fournie par référence : f_level
// et retourne la part entière signée (int)

// AUGMENTATION selon SPEED et le nombre de passage dans la boucle --
// Après un nombre de passage dans la boucle (loopsbystep) le niveau (level) est augmentation/diminué selon (speed) courant
void whc_wheel::leveIncrease(whc_wheel &wheel, int &i_level, int maxlevel, int minlevel, int &i_loops, int loopsbeforeincrease)
{
    i_loops ++;

	if (i_loops>=loopsbeforeincrease)
	{
		i_loops = 1;
		i_level = i_level + wheel.speed();

		if (i_level > maxlevel)
		{
			i_level=maxlevel;
		}
		if (i_level<minlevel)
		{
			i_level=minlevel ;
		}
		wheel.isProcessed();
	}
}

int whc_wheel::leveIncrease(whc_wheel &wheel, float &f_level, float maxlevel, float minlevel, float speedratio)
{
    float f_speedsubdivision = wheel.speed() / speedratio ;
    f_level = f_level + f_speedsubdivision;

    if (f_level > maxlevel)
    {
        f_level=maxlevel;
    }
    if (f_level<minlevel)
    {
        f_level=minlevel ;
    }
    return (int) f_level;
}


