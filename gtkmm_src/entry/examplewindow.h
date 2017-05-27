/*
 * =====================================================================================
 *
 *       Filename:  examplewindow.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/27/2017 01:12:22 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm.h>

class ExampleWindow : public Gtk::Window
{
	public:
		ExampleWindow();
		virtual ~ExampleWindow();

	protected:
		void on_checkbox_editable_toggled();
		void on_checkbox_visibility_toggled();
		void on_button_close();

		Gtk::Box m_HBox;
		Gtk::Box m_VBox;
		Gtk::Entry m_Entry;
		Gtk::Button m_Button_Close;
		Gtk::CheckButton m_CheckButton_Editable, m_CheckButton_Visible;
};

#endif //GTKMM_EXAMPLEWINDOW_H

