/*
 * =====================================================================================
 *
 *       Filename:  examplewindow.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/25/2017 09:50:40 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "examplewindow.h"
#include <iostream>

ExampleWindow::ExampleWindow():m_button("something")
{
	set_title("checkbutton example");
	set_border_width(10);

	m_button.signal_clicked().connect(sigc::mem_fun(*this, &ExampleWindow::on_button_clicked));

	add(m_button);

	m_button.set_active();

	show_all_children();
}

ExampleWindow::~ExampleWindow()
{

}

void ExampleWindow::on_button_clicked()
{
	std::cout<< "The Button was clicked:state = " << (m_button.get_active() ? "true":"false") <<std::endl;
}

