/*
 * =====================================================================================
 *
 *       Filename:  examplewindow.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/28/2017 12:38:19 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "examplewindow.h"
#include <gtkmm/messagedialog.h>
#include <iostream>

ExampleWindow::ExampleWindow()
	:m_ButtonBox(Gtk::ORIENTATION_VERTICAL),
	m_Button_Info("Show Info MessageDialog"),
	m_Button_Question("Show Question MessageDialog"),
	m_Button_File("Choose File"),
	m_Button_Folder("Choose Folder")
{
	set_title("Gtk::MessageDialog example");

	add(m_ButtonBox);

	m_ButtonBox.pack_start(m_Button_Info);
	m_Button_Info.signal_clicked().connect(sigc::mem_fun(*this, &ExampleWindow::on_button_info_clicked));

	m_ButtonBox.pack_start(m_Button_Question);
	m_Button_Question.signal_clicked().connect(sigc::mem_fun(*this, &ExampleWindow::on_button_question_clicked));

	m_ButtonBox.pack_start(m_Button_File);
	m_Button_File.signal_clicked().connect(sigc::mem_fun(*this, &ExampleWindow::on_button_file_clicked));

	m_ButtonBox.pack_start(m_Button_Folder);
	m_Button_Folder.signal_clicked().connect(sigc::mem_fun(*this, &ExampleWindow::on_button_folder_clicked));

	show_all_children();

}

ExampleWindow::~ExampleWindow()
{

}

void ExampleWindow::on_button_info_clicked()
{
	Gtk::MessageDialog dialog(*this, "This is an INFO MessageDialog");
	dialog.set_secondary_text("And this is the secondary text that explains things.");

	dialog.run();
}

void ExampleWindow::on_button_question_clicked()
{
	Gtk::MessageDialog dialog(*this, "This is a QUESTION MessageDialog", false, Gtk::MESSAGE_QUESTION,
			Gtk::BUTTONS_OK_CANCEL);
	dialog.set_secondary_text("And  this is the secondary text that explains things.");

	int result = dialog.run();

	switch(result)
	{
		case(Gtk::RESPONSE_OK):
			std::cout<<"OK clicked."<<std::endl;
			break;

		case(Gtk::RESPONSE_CANCEL):
			std::cout<<"Cancel clicked."<<std::endl;
			break;

		default:
			std::cout<<"Unexpected button clicked."<<std::endl;
			break;
	}
}

void ExampleWindow::on_button_folder_clicked()
{
	Gtk::FileChooserDialog dialog("Please choose a folder", Gtk::FILE_CHOOSER_ACTION_SELECT_FOLDER);
	dialog.set_transient_for(*this);

	dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
	dialog.add_button("Select", Gtk::RESPONSE_OK);

	int result = dialog.run();

	switch(result)
	{
		case(Gtk::RESPONSE_OK):
			std::cout<<"Select clicked."<<std::endl;
			std::cout<<"Folder selected:"<<dialog.get_filename()<<std::endl;
			break;

		case(Gtk::RESPONSE_CANCEL):
			std::cout<<"Cancel clicked."<<std::endl;
			break;

		default:
			std::cout<<"Unexpected button clicked."<<std::endl;
			break;
	}
}

void ExampleWindow::on_button_file_clicked()
{
	Gtk::FileChooserDialog dialog("Please choose a file",Gtk::FILE_CHOOSER_ACTION_OPEN);
	dialog.set_transient_for(*this);

	dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
	dialog.add_button("_Open", Gtk::RESPONSE_OK);

	auto filter_text = Gtk::FileFilter::create();
	filter_text->set_name("Text files");
	filter_text->add_mime_type("text/plain");
	dialog.add_filter(filter_text);

	auto filter_cpp = Gtk::FileFilter::create();
	filter_cpp->set_name("C/C++ files");
	filter_cpp->add_mime_type("text/x-c");
	filter_cpp->add_mime_type("text/x-c++");
	filter_cpp->add_mime_type("text/x-c-header");
	dialog.add_filter(filter_cpp);

	auto filter_any = Gtk::FileFilter::create();
	filter_any->set_name("Any files");
	filter_any->add_pattern("*");
	dialog.add_filter(filter_any);

	int result = dialog.run();

	switch(result)
	{
		case(Gtk::RESPONSE_OK):
			std::cout<<"Open clicked."<<std::endl;
			//std::string filename = dialog.get_filename();
			std::cout<<"File selected:"<<dialog.get_filename()<<std::endl;
			break;

		case(Gtk::RESPONSE_CANCEL):
			std::cout<<"Cancel clicked."<<std::endl;
			break;

		default:
			std::cout<<"Unexpected button clicked."<<std::endl;
			break;

	}


}
