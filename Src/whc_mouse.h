#ifndef WHC_MOUSE_H
#define WHC_MOUSE_H

//Allegro
#include <allegro/mouse.h>
#include <allegro/keyboard.h>
//C library
#include <time.h>
//Container C compatible
#include <vector>

typedef enum
{
	left   = 100,
	middle = 010,
	right  = 001,

	leftmiddle   = 110,
	leftright    = 101,
	middleright  = 011,

	leftmiddleright   = 111,

	none   = 000
} whc_mousebutton ;

typedef struct whc_mousepos
{
   short int x, y , z ;
} whc_mousepos;

typedef struct whc_eventclic
{
   whc_mousebutton button;
   clock_t cpu_clock_ticks;
} whc_eventclic;

class whc_button
{
	public:
		float static gapSecond ; 	//!< Instance variable - gapSecond : max time between two clics to be a double clic
		whc_eventclic static mouseLastClic ;	//!< Instance variable - mouseLastClic :
		std::vector<whc_eventclic> static mouseClicHistory; //!< Instance variable - mouseClicHistory :
		bool static IsThisADoubleClic (whc_mousebutton);
		void static CollectEvent (int& mousesignal, whc_button& mouseClicLeft, whc_button& mouseClicMiddle, whc_button& mouseClicRight);

		/** Default constructor */
		whc_button();
		/** Default destructor */
		virtual ~whc_button();

		/** Evaluate if down over Rectangle
		 * \return bool
		 * \param x_left, y_top, x_size, y_size, set_processed
		 */
		bool toBeProcessed_isDown_isOverRecSize(int x_left, int y_top, int x_size, int y_size, bool set_processed=false)
		{ 	if (not m_Processed)
			{
				bool value = ((mouse_x>=x_left) and (mouse_x<=x_left+x_size) and (mouse_y>=y_top) and (mouse_y<=y_top+y_size));
				m_Processed = (value and set_processed);
				return value;
			}
			return false;
		}
		bool toBeProcessed_isDouble_isOverRecSize(int x_left, int y_top, int x_size, int y_size, bool set_processed=false)
		{ 	if ((not m_Processed) and (m_Double))
			{
				bool value = ((mouse_x>=x_left) and (mouse_x<=x_left+x_size) and (mouse_y>=y_top) and (mouse_y<=y_top+y_size));
				m_Processed = (value and set_processed);
				return value;
			}
			return false;
		}
		bool isOverRecSize(int x_left, int y_top, int x_size, int y_size)
		{
			return ((mouse_x>=x_left) and (mouse_x<=x_left+x_size) and (mouse_y>=y_top) and (mouse_y<=y_top+y_size));
		}
		/** Evaluate if down over Rectangle
		 * \return bool
		 * \param x_left, y_top, x_right, y_bottom, set_processed
		 */
		bool toBeProcessed_isDown_isOverRecPos(int x_left, int y_top, int x_right, int y_bottom, bool set_processed=false)
		{ 	if (not m_Processed)
			{
				bool value = ((mouse_x>=x_left) and (mouse_x<=x_right) and (mouse_y>=y_top) and (mouse_y<=y_bottom));
				m_Processed = (value and set_processed);
				return value;
			}
			return false;
		}
		bool toBeProcessed_isDouble_isOverRecPos(int x_left, int y_top, int x_right, int y_bottom, bool set_processed=false)
		{ 	if ((not m_Processed) and (m_Double))
			{
				bool value = ((mouse_x>=x_left) and (mouse_x<=x_right) and (mouse_y>=y_top) and (mouse_y<=y_bottom));
				m_Processed = (value and set_processed);
				return value;
			}
			return false;
		}
		bool isOverRecPos(int x_left, int y_top, int x_right, int y_bottom)
		{
			return ((mouse_x>=x_left) and (mouse_x<=x_right) and (mouse_y>=y_top) and (mouse_y<=y_bottom));
		}

		/** Access m_Down
		 * \return The current value of m_Down
		 */
		bool isDown() { return m_Down; }
		/** Set m_Down
		 * \param val New value to set
		 */
		void SetIsDown(bool val=true) { m_Down = val; }
		void SetIsUp(bool val=true) { m_Down = (not val); }

		/** Access m_Double
		 * \return The current value of m_Double
		 */
		bool isDouble() { return m_Double; }
		/** Set m_Double
		 * \param val New value to set
		 */
		void SetIsDouble(bool val=true) { m_Double = val; }

		/** Access m_DragDrop
		 * \return The current value of m_DragDrop
		 */
		bool isDragDrop() { return m_DragDrop; }
		/** Set m_DragDrop
		 * \param val New value to set
		 */
		void SetIsDragDrop(bool val=true) { m_DragDrop = val; }

		/** Access m_dragpos
		 * \param val New value to set
		 */
		whc_mousepos dragPos() { return m_dragpos; }
		/** Set m_dragpos
		 * \param val New value to set
		 */
		void SetDragPos() { m_dragpos.x = mouse_x ; m_dragpos.y = mouse_y ; m_dragpos.z = mouse_z; }

		/** Access m_Processed
		 * \return The current value of m_Processed
		 */
		bool isProcessed() { return m_Processed; }
		bool toBeProcessed() { return (not m_Processed); }
		/** Set m_Processed
		 * \param val New value to set
		 */
		void SetIsProcessed(bool val=true) { m_Processed = val; }
		void SetIsToProcess(bool val=true) { m_Processed = (not val); }

	protected:
	private:
		whc_mousepos m_dragpos; //!< Member variable "m_dragpos"
		bool m_Down; //!< Member variable "m_Down"
		bool m_Double; //!< Member variable "m_Double"
		bool m_DragDrop; //!< Member variable "m_Double"
		bool m_Processed; //!< Member variable "m_Processed"
};



class whc_wheel
{
	public:
		int static mouse_z_prev;
		int static mouse_w_prev;
		void static CollectEvent (int& mousesignal, whc_wheel& mouseScroll , whc_wheel& mouseRoll);
		void static leveIncrease(whc_wheel &wheel, int &i_level, int maxlevel, int minlevel);
		int  static leveIncrease(whc_wheel &wheel, float &f_level, float maxlevel, float minlevel);
		void static leveIncrease(whc_wheel &wheel, int &i_level, int maxlevel, int minlevel, int &i_loops, int loopsbeforeincrease);
		int  static leveIncrease(whc_wheel &wheel, float &f_level, float maxlevel, float minlevel, float speedratio);

		/** Default constructor */
		whc_wheel();
		/** Default destructor */
		virtual ~whc_wheel();

		/** Access m_level
		 * \param val New value to set
		 */
		int level() { return m_level; }
		/** Set m_level
		 * \param val New value to set
		 */
		void SetLevel(int val) { m_level=val; }

		/** Access m_gain
		 * \param val New value to set
		 */
		int gain() { return m_gain; }
		/** Set m_gain
		 * \param val New value to set
		 */
		void SetGain(int val) { m_gain=val; m_yield = m_yield + m_gain;}

		/** Access m_yield
		 * \param val New value to set
		 */
		int yield() { return m_yield; }
		/** Set m_yield
		 * \param val New value to set
		 */
		void SetYield(int val) { m_yield = val;}

		/** Access m_speed
		 * \param val New value to set
		 */
		int speed() { return m_speed; }
		/** Set m_speed
		 * \param val New value to set
		 */
		void SetSpeed(int val) { m_speed = val;}

		/** Access m_Processed
		 * \return The current value of m_Processed
		 */
		bool isProcessed() { return m_Processed; }
		bool toBeProcessed() { return (not m_Processed); }
		/** Set m_Processed
		 * \param val New value to set
		 */
		void SetIsProcessed(bool val=true) { m_Processed = val; if (m_Processed == true) {m_yield = 0;} }
		void SetIsToProcess(bool val=true) { m_Processed = (not val); if (m_Processed == true) {m_yield = 0;} }

	protected:
	private:
		int  m_level;	//!< Member variable m_level
		int  m_gain;	//!< Member variable m_gain (if event quickly catch, gain should be : -1,0, or +1)
		int  m_yield;   //!< Member variable m_yield (sum of gain until event processed : casual use)
		int  m_speed;	//!< Member variable m_speed
		bool m_Processed; //!< Member variable "m_Processed"

};

#endif // WHC_MOUSE_H
