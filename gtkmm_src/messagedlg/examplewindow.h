/*
 * =====================================================================================
 *
 *       Filename:  examplewindow.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/28/2017 12:34:43 AM
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
	public : 
		ExampleWindow();
		virtual ~ExampleWindow();

	protected:
		void on_button_info_clicked();
		void on_button_question_clicked();
		void on_button_file_clicked();
		void on_button_folder_clicked();

		Gtk::ButtonBox m_ButtonBox;
		Gtk::Button m_Button_Info, m_Button_Question;
		Gtk::Button m_Button_File, m_Button_Folder;
};


#endif //GTKMM_EXAMPLEWINDOW_H

