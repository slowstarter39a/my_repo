/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  j
 *
 *        Version:  1.0
 *        Created:  05/25/2017 11:22:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "examplewindow.h"
#include <gtkmm/application.h>

int main(int argc, char *argv[])
{
	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
	ExampleWindow window;

	return app->run(window);
}

