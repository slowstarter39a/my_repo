/*
 * =====================================================================================
 *
 *       Filename:  sbase.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/22/2017 11:09:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <gtkmm.h>

int main(int argc, char *argv[])
{
	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.exambles.base");

	Gtk::Window window;
	window.set_default_size(200, 200);

	return app->run(window);
}

