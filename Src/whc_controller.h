#ifndef WHC_CONTROLLER_H
#define WHC_CONTROLLER_H


class whc_controller
{
	public:
	typedef enum
    {
        slider = 1,
        rotary = 2,
        button = 3,
        knob   = 4,

        none   = 0
    } whc_midicontroler ;

		int static s_nbrOfMidiCtl;

		/** Default constructor */
		whc_controller();
		/** Default destructor */
		virtual ~whc_controller();
		/** Access m_Counter
		 * \return The current value of m_Counter
		 */
		unsigned int MidiId() { return m_midiId; }
		/** Set m_Counter
		 * \param val New value to set
		 */
		void SetMidiId(unsigned int val) { m_midiId = val; }
		/** Access m_MaxValue
		 * \return The current value of m_MaxValue
		 */
		unsigned int MaxValue() { return m_MaxValue; }
		/** Set m_MaxValue
		 * \param val New value to set
		 */
		void SetMaxValue(unsigned int val) { m_MaxValue = val; }
		/** Access m_StateValue
		 * \return The current value of m_StateValue
		 */
		unsigned int StateValue() { return m_StateValue; }
		/** Set m_StateValue
		 * \param val New value to set
		 */
		void SetStateValue(unsigned int val) { m_StateValue = val; }
		/** Access m_MinValue
		 * \return The current value of m_MinValue
		 */
		unsigned int MinValue() { return m_MinValue; }
		/** Set m_MinValue
		 * \param val New value to set
		 */
		void SetMinValue(unsigned int val) { m_MinValue = val; }
		/** Access m_Type
		 * \return The current value of m_Type
		 */
		whc_midicontroler GetType() { return m_Type; }
		/** Set m_Type
		 * \param val New value to set
		 */
		void SetType(whc_midicontroler val) { m_Type = val; }
	protected:
	private:
		unsigned int m_midiId; //!< Member variable "m_Counter"
		unsigned int m_MaxValue; //!< Member variable "m_MaxValue"
		unsigned int m_StateValue; //!< Member variable "m_StateValue"
		unsigned int m_MinValue; //!< Member variable "m_MinValue"
		whc_midicontroler m_Type; //!< Member variable "m_Type"
};

#endif // WHC_CONTROLLER_H
