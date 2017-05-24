/*
 * =====================================================================================
 *
 *       Filename:  helloworld.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/24/2017 10:36:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef GTKMM_EXAMPLE_HELLOWORLD_H
#define GTKMM_EXAMPLE_HELLOWORLD_H

#include <gtkmm/button.h>
#include <gtkmm/window.h>

class HelloWorld : public Gtk::Window
{
	public:
		HelloWorld();
		virtual ~HelloWorld();

	protected:
		//Signal handlers:
		void on_button_clicked();

		//Member widgets:
		Gtk::Button m_button;
};

#endif //GTKMM_EXAMPLE_HELLOWORLD_H
