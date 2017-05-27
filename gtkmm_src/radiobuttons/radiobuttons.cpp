/*
 * =====================================================================================
 *
 *       Filename:  radiobuttons.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/25/2017 10:10:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "radiobuttons.h"

RadioButtons::RadioButtons() :
	m_Box_Top(Gtk::ORIENTATION_VERTICAL),
	m_Box1(Gtk::ORIENTATION_VERTICAL, 10),
	m_Box2(Gtk::ORIENTATION_VERTICAL, 10),
	m_RadioButton1("button1"),
	m_RadioButton2("button2"),
	m_RadioButton3("button3"),
	m_Button_Close("close")
{
	set_title("radio buttons");
	set_border_width(0);

	m_RadioButton2.join_group(m_RadioButton1);
	m_RadioButton3.join_group(m_RadioButton1);

	add(m_Box_Top);

	m_Box_Top.pack_start(m_Box1);
	m_Box_Top.pack_start(m_Separator);
	m_Box_Top.pack_start(m_Box2);

	m_Box2.set_border_width(10);
	m_Box1.set_border_width(10);

	m_Box1.pack_start(m_RadioButton1);
	m_Box1.pack_start(m_RadioButton2);
	m_Box1.pack_start(m_RadioButton3);

	m_RadioButton2.set_active();

	m_Box2.pack_start(m_Button_Close);

	m_Button_Close.set_can_default();
	m_Button_Close.grab_default();

	m_Button_Close.signal_clicked().connect(sigc::mem_fun(*this, &RadioButtons::on_button_clicked));

	show_all_children();
}
RadioButtons::~RadioButtons()
{

}

void RadioButtons::on_button_clicked()
{
	hide();
}

