/*
 * =====================================================================================
 *
 *       Filename:  examplewindow.cpp
 *
 *    Description:  j
 *
 *        Version:  1.0
 *        Created:  05/25/2017 11:23:21 PM
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

ExampleWindow::ExampleWindow():
	m_VBox_Top(Gtk::ORIENTATION_VERTICAL, 0),
	m_VBox2(Gtk::ORIENTATION_VERTICAL, 20),
	m_VBox_HScale(Gtk::ORIENTATION_VERTICAL, 10),
	m_HBox_Scale(Gtk::ORIENTATION_HORIZONTAL, 10),
	m_HBox_Combo(Gtk::ORIENTATION_HORIZONTAL, 10),
	m_HBox_Digits(Gtk::ORIENTATION_HORIZONTAL, 10),
	m_HBox_PageSize(Gtk::ORIENTATION_HORIZONTAL, 10),

	m_adjustment(Gtk::Adjustment::create(0.0, 0.0, 101.0, 0.1, 1.0, 1.0)),
	m_adjustment_digits(Gtk::Adjustment::create(1.0, 0.0, 5.0, 1.0, 2.0)),
	m_adjustment_pagesize(Gtk::Adjustment::create(1.0, 1.0, 101.0)),

	m_VScale(m_adjustment, Gtk::ORIENTATION_VERTICAL),
	m_HScale(m_adjustment, Gtk::ORIENTATION_HORIZONTAL),
	m_Scale_Digits(m_adjustment_digits),
	m_Scale_PageSize(m_adjustment_pagesize),

	m_CheckButton("Display value on scale widgets", 0),

	m_Scrollbar(m_adjustment),

	m_Button_Quit("Quit")
{
	set_title("range controls");
	set_default_size(300, 350);

	m_VScale.set_digits(1);
	m_VScale.set_value_pos(Gtk::POS_TOP);
	m_VScale.set_draw_value();
	m_VScale.set_inverted();

	m_HScale.set_digits(1);
	m_HScale.set_value_pos(Gtk::POS_TOP);
	m_HScale.set_draw_value();

	add(m_VBox_Top);
	m_VBox_Top.pack_start(m_VBox2);
	m_VBox2.set_border_width(10);
	m_VBox2.pack_start(m_HBox_Scale);

	m_HBox_Scale.pack_start(m_VScale);
	m_HBox_Scale.pack_start(m_VBox_HScale);

	m_VBox_HScale.pack_start(m_HScale);

	m_VBox_HScale.pack_start(m_Scrollbar);

	m_CheckButton.set_active();
	m_CheckButton.signal_toggled().connect(sigc::mem_fun(*this, &ExampleWindow::on_checkbutton_toggled));
	m_VBox2.pack_start(m_CheckButton, Gtk::PACK_SHRINK);

	m_refTreeModel = Gtk::ListStore::create(m_Columns);
	m_ComboBox_Position.set_model(m_refTreeModel);
	m_ComboBox_Position.pack_start(m_Columns.m_col_title);

	Gtk::TreeModel::Row row = *(m_refTreeModel->append());
	row[m_Columns.m_col_position_type] = Gtk::POS_TOP;
	row[m_Columns.m_col_title] = "Top";

	row = *(m_refTreeModel->append());
	row[m_Columns.m_col_position_type] = Gtk::POS_BOTTOM;
	row[m_Columns.m_col_title] = "Bottom";

	row = *(m_refTreeModel->append());
	row[m_Columns.m_col_position_type] = Gtk::POS_LEFT;
	row[m_Columns.m_col_title] = "Left";

	row = *(m_refTreeModel->append());
	row[m_Columns.m_col_position_type] = Gtk::POS_RIGHT;
	row[m_Columns.m_col_title] = "Right";

	m_VBox2.pack_start(m_HBox_Combo, Gtk::PACK_SHRINK);
	m_HBox_Combo.pack_start(*Gtk::manage(new Gtk::Label("Scale Value Position:", 0)), Gtk::PACK_SHRINK);
	m_HBox_Combo.pack_start(m_ComboBox_Position);
	m_ComboBox_Position.signal_changed().connect(sigc::mem_fun(*this, &ExampleWindow::on_combo_position));
	m_ComboBox_Position.set_active(0);

	m_HBox_Digits.pack_start(*Gtk::manage(new Gtk::Label("Scale Digits:", 0)), Gtk::PACK_SHRINK);
	m_Scale_Digits.set_digits(0);
	m_adjustment_digits->signal_value_changed().connect(
			sigc::mem_fun(*this, &ExampleWindow::on_adjustment1_value_changed));

	m_HBox_Digits.pack_start(m_Scale_Digits);

	m_HBox_PageSize.pack_start(*Gtk::manage(new Gtk::Label("Scrollbar Page Size:", 0)), Gtk::PACK_SHRINK);
	m_Scale_PageSize.set_digits(0);
	m_adjustment_pagesize->signal_value_changed().connect(
			sigc::mem_fun(*this, &ExampleWindow::on_adjstment2_value_changed));
	m_HBox_PageSize.pack_start(m_Scale_PageSize);

	m_VBox2.pack_start(m_HBox_Digits, Gtk::PACK_SHRINK);
	m_VBox2.pack_start(m_HBox_PageSize, Gtk::PACK_SHRINK);
	m_VBox_Top.pack_start(m_Separator, Gtk::PACK_SHRINK);
	m_VBox_Top.pack_start(m_Button_Quit, Gtk::PACK_SHRINK);

	m_Button_Quit.set_can_default();
	m_Button_Quit.grab_default();
	m_Button_Quit.signal_clicked().connect(sigc::mem_fun(*this, &ExampleWindow::on_button_quit));
	m_Button_Quit.set_border_width(10);



	show_all_children();
}

ExampleWindow::~ExampleWindow()
{

}

void ExampleWindow::on_checkbutton_toggled()
{
	m_VScale.set_draw_value(m_CheckButton.get_active());
	m_HScale.set_draw_value(m_CheckButton.get_active());
}

void ExampleWindow::on_combo_position()
{
	Gtk::TreeModel::iterator iter = m_ComboBox_Position.get_active();
	if(!iter)
		return;

	Gtk::TreeModel::Row row = *iter;
	if(!row)
		return;

	const Gtk::PositionType postype = row[m_Columns.m_col_position_type];

	m_VScale.set_value_pos(postype);
	m_HScale.set_value_pos(postype);

}

void ExampleWindow::on_adjustment1_value_changed()
{
	const double val = m_adjustment_digits->get_value();
	m_VScale.set_digits((int)val);
	m_HScale.set_digits((int)val);
}

void ExampleWindow::on_adjstment2_value_changed()
{
	const double val = m_adjustment_pagesize->get_value();
	m_adjustment -> set_page_size(val);
	m_adjustment->set_page_increment(val);
}

void ExampleWindow::on_button_quit()
{
	hide();
}









