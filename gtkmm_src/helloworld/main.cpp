/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/24/2017 10:38:14 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "helloworld.h"
#include <gtkmm/application.h>

int main(int argc, char* argv[])
{
	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

	HelloWorld helloworld;

	//helloworld.set_default_size(300, 300);

	return app->run(helloworld);
}
