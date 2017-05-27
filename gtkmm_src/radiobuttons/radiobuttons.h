/*
 * =====================================================================================
 *
 *       Filename:  radiobuttons.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/25/2017 10:06:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef GTKMM_EXAMPLE_RADIOBUTTONS_H
#define GTKMM_EXAMPLE_RADIOBUTTONS_H

#include <gtkmm/box.h>
#include <gtkmm/window.h>
#include <gtkmm/radiobutton.h>
#include <gtkmm/separator.h>

class RadioButtons : public Gtk::Window
{
	public:
		RadioButtons();
		virtual ~RadioButtons();

	protected:
		void on_button_clicked();

		Gtk::Box m_Box_Top, m_Box1, m_Box2;
		Gtk::RadioButton m_RadioButton1, m_RadioButton2, m_RadioButton3;
		Gtk::Separator m_Separator;
		Gtk::Button m_Button_Close;
};


#endif //GTKMM_EXAMPLE_RADIOBUTTONS_H

