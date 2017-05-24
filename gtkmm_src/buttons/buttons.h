/*
 * =====================================================================================
 *
 *       Filename:  button.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/24/2017 11:17:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef GTKMM_EXAMPLE_BUTTONS_H
#define GTKMM_EXAMPLE_BUTTONS_H

#include <gtkmm/window.h>
#include <gtkmm/button.h>

class Buttons: public Gtk::Window
{
	public:
		Buttons();
		virtual ~ Buttons();

	protected:
		void on_button_clicked();

		Gtk::Button m_button;
};


#endif //GTKMM_EXAMPLE_BUTTON_H
