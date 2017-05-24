/*
 * =====================================================================================
 *
 *       Filename:  helloworld.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/24/2017 10:40:33 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "helloworld.h"
#include <iostream>

HelloWorld::HelloWorld() : m_button("Hell_o World", true)
{
	//Sets the border width of the window
	set_border_width(10);

	m_button.signal_clicked().connect(sigc::mem_fun(*this, &HelloWorld::on_button_clicked));

	add(m_button);

	m_button.show(); 
}

HelloWorld::~HelloWorld()
{
}

void HelloWorld::on_button_clicked()
{
	std::cout << "Hello World" << std::endl;
}

