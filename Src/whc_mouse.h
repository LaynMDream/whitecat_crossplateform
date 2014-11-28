#ifndef WHC_MOUSE_H
#define WHC_MOUSE_H

//Allegro
#include <allegro/mouse.h>
#include <allegro/keyboard.h>
//C library
#include <time.h>
//Container C compatible
#include <vector>
//Boost
/*
Boost.DateTime offers an additional class named boost::posix_time::microsec_clock
that returns the current time including microseconds in case a higher resolution is required.
#include "boost/date_time/local_time/local_time.hpp"
time_zone_ptr
  zone(new posix_time_zone("MST-07"));
local_date_time
  ldt((ptime(date(2005,Jan,1),hours(0))), zone);
local_time_period ltp(ldt, hours(2));
ltp.length(); // => 02:00:00
*/

class whc_button
{
public:
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

    typedef struct whc_eventclic
    {
        whc_mousebutton button;
        clock_t cpu_clock_ticks;
        //float cpu_clock_ticks;
    } whc_eventclic;

    typedef struct whc_mousepos
    {
        short int x, y ;
    } whc_mousepos;


    float static c_gapSecond ; 	//!< Instance variable - gapSecond : max time between two clics to be a double clic
    whc_eventclic static c_mouseLastClic ;	//!< Instance variable - mouseLastClic :
    std::vector<whc_eventclic> static c_mouseClicHistory; //!< Instance variable - mouseClicHistory :
    bool static c_IsThisADoubleClic (whc_mousebutton);
    void static c_CollectEvent (int& mousesignal, volatile int& mouse_x, volatile int& mouse_y, whc_button& mouseClicLeft, whc_button& mouseClicMiddle, whc_button& mouseClicRight);

    /** Default constructor */
    whc_button();
    /** Default destructor */
    virtual ~whc_button();

    /** Evaluate if down over Rectangle
     * \return bool
     * \param x_left, y_top, x_size, y_size, set_processed
     */
    bool toBeProcessed_isDown_isOverRecSize(int x_left, int y_top, int x_size, int y_size, bool set_processed=false)
    {
        if (m_Pending)
        {
            bool value = isOverRecSize(x_left, y_top, x_size, y_size);
            if (value and set_processed)
            {
                m_Pending = false ;
            };
            return value;
        }
        return false;
    }
    bool toBeProcessed_isDouble_isOverRecSize(int x_left, int y_top, int x_size, int y_size, bool set_processed=false)
    {
        if (m_Pending and m_Double)
        {
            bool value = isOverRecSize(x_left, y_top, x_size, y_size);
            if (value and set_processed)
            {
                m_Pending = false ;
            };
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
    {
        if (m_Pending)
        {
            bool value = isOverRecPos(x_left, y_top, x_right, y_bottom);
            if (value and set_processed)
            {
                m_Pending = false ;
            };
            return value;
        }
        return false;
    }
    bool toBeProcessed_isDouble_isOverRecPos(int x_left, int y_top, int x_right, int y_bottom, bool set_processed=false)
    {
        if (m_Pending and m_Double)
        {
            bool value = isOverRecPos(x_left, y_top, x_right, y_bottom);
            if (value and set_processed)
            {
                m_Pending = false ;
            };
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
    bool isDown()
    {
        return m_Down;
    }
    bool isUp()
    {
        return (not m_Down);
    }
    bool isDownToBeProcessed()
    {
        return (m_Down && m_Pending);
    }
    /** Set m_Down
     * \param val New value to set
     */
    void SetDown(bool val=true)
    {
        m_Down = val;
    }
    void SetUp(bool val=true)
    {
        m_Down = (not val);
    }

    /** Access m_Double
     * \return The current value of m_Double
     */
    bool isDouble()
    {
        return m_Double;
    }
    bool isSimple()
    {
        return (not m_Double);
    }
    /** Set m_Double
     * \param val New value to set
     */
    void SetDouble(bool val=true)
    {
        m_Double = val;
    }

    /** Access m_DragDrop
     * \return The current value of m_DragDrop
     */
    bool isDragDrop()
    {
        return m_DragDrop;
    }
    bool isNotDrop()
    {
        return (not m_DragDrop);
    }
    /** Set m_DragDrop
     * \param val New value to set
     */
    void SetDragDrop(bool val=true)
    {
        m_DragDrop = val;
    }

    /** Access m_dragpos
     * \param val New value to set
     */
    whc_mousepos dragPos()
    {
        return m_dragpos;
    }
    int  dragPosX()
    {
        return m_dragpos.x;
    }
    int  dragPosY()
    {
        return m_dragpos.y;
    }
    /** Set m_dragpos
     * \param val New value to set
     */
    void SetDragPos(volatile int x, volatile int y)
    {
        m_dragpos.x = x ;
        m_dragpos.y = y ;
    }

    /** Access m_Actor
     * \return The current value of m_Actor
     */
    int lastActor()
    {
        return m_Actor ;
    }

    /** Access m_Pending
     * \return The current value of m_Pending
     */
    bool isProcessed()
    {
        return (not m_Pending);
    }
    bool isToBeProcessed()
    {
        return m_Pending;
    }
    /** Set m_Pending
     * \param val New value to set
     */
    void SetProcessed(int actor=0, bool val=true)
    {
        m_Actor = actor ;
        m_Pending = (not val);
    }
    void SetToBeProcessed(int actor=0, bool val=true)
    {
        m_Actor = actor ;
        m_Pending = val;
    }

protected:
private:
    whc_mousepos m_dragpos; //!< Member variable "m_dragpos"
    bool m_Down; //!< Member variable "m_Down"
    bool m_Double; //!< Member variable "m_Double"
    bool m_DragDrop; //!< Member variable "m_Double"
    bool m_Pending; //!< Member variable "m_Pending"
    int m_Actor;
};


//---------------------------------------------------------------------------------------------------------------------------------------


class whc_wheel
{
public:
    int static c_mouse_z_prev;
    int static c_mouse_w_prev;
    void static c_Init(volatile int& mouse_z, volatile int& mouse_w);
    void static c_CollectEvent (int& mousesignal, volatile int& mouse_z, volatile int& mouse_w, whc_wheel& mouseScroll , whc_wheel& mouseRoll);
    void static c_leveIncrease(whc_wheel &wheel, int &i_level, int maxlevel, int minlevel);
    int  static c_leveIncrease(whc_wheel &wheel, float &f_level, float maxlevel, float minlevel);
    void static c_leveIncrease(whc_wheel &wheel, int &i_level, int maxlevel, int minlevel, int &i_loops, int loopsbeforeincrease);
    int  static c_leveIncrease(whc_wheel &wheel, float &f_level, float maxlevel, float minlevel, float speedratio);

    /** Default constructor */
    whc_wheel();
    /** Default destructor */
    virtual ~whc_wheel();

    /** Access m_level
     * \param val New value to set
     */
    int level()
    {
        return m_level;
    }
    /** Set m_level
     * \param val New value to set
     */
    void SetLevel(int val)
    {
        m_level=val;
    }

    /** Access m_gain
     * \param val New value to set
     */
    int gain()
    {
        return m_gain;
    }
    /** Set m_gain
     * \param val New value to set
     */
    void SetGain(int val)
    {
        m_gain=val;
        m_yield = m_yield + m_gain;
    }

    /** Access m_yield
     * \param val New value to set
     */
    int yield()
    {
        return m_yield;
    }
    /** Set m_yield
     * \param val New value to set
     */
    void SetYield(int val)
    {
        m_yield = val;
    }

    /** Access m_speed
     * \param val New value to set
     */
    int speed()
    {
        return m_speed;
    }
    /** Set m_speed
     * \param val New value to set
     */
    void SetSpeed(int val)
    {
        m_speed = val;
    }

    /** Access m_Pending
     * \return The current value of m_Pending
     */
    bool isProcessed()
    {
        return (not m_Pending);
    }
    bool isToBeProcessed()
    {
        return m_Pending;
    }
    /** Set m_Pending
     * \param val New value to set
     */
    void SetProcessed(bool val=true)
    {
        m_Pending = (not val);
        if (m_Pending == false)
        {
            m_yield = 0;
        }
    }
    void SetToBeProcessed(bool val=true)
    {
        m_Pending = val;
        if (m_Pending == false)
        {
            m_yield = 0;
        }
    }

protected:
private:
    int  m_level;	//!< Member variable m_level
    int  m_gain;	//!< Member variable m_gain (if event quickly catch, gain should be : -1,0, or +1)
    int  m_yield;   //!< Member variable m_yield (sum of gain until event processed : casual use)
    int  m_speed;	//!< Member variable m_speed
    bool m_Pending; //!< Member variable "m_Pending"

};


//---------------------------------------------------------------------------------------------------------------------------------------


class whc_pointer
{
public:
	typedef enum
    {
        arrow   = 1,
        drag    = 2
    } whc_mouselook ;


    /** Default constructor */
    whc_pointer();
    whc_pointer(volatile int& mouse_x, volatile int& mouse_y);
    /** Default destructor */
    virtual ~whc_pointer();

    /** Access m_x
     * \param val New value to set
     */
    int x()
    {
        return m_x;
    }
    /** Set m_x
     * \param val New value to set
     */
    void SetX(int val)
    {
        m_x=val;
    }

    /** Access m_y
     * \param val New value to set
     */
    int y()
    {
        return m_y;
    }
    /** Set m_y
     * \param val New value to set
     */
    void SetY(int val)
    {
        m_y=val;
    }

    /** Draw pointer
    */
	void Draw();

    /** Set m_x m_y
     * \param val New value to set
     */
    void CollectEvent (volatile int& mouse_x, volatile int& mouse_y)
    {
        m_x = mouse_x;
        m_y = mouse_y;
    }

protected:
private:
    int  m_x;	//!< Member variable m_x
    int  m_y;	//!< Member variable m_y
    whc_mouselook m_look;

};

#endif // WHC_MOUSE_H
