/**
 * @file HelloWorld.cpp
 */

#include <gtkmm/window.h>
#include <gtkmm/button.h>

#include <iostream>

#include "SmithChartWindow.h"


SmithChartWindow::SmithChartWindow() : button("Hello World") {
    set_border_width(10);

    button.signal_clicked().connect(sigc::mem_fun(*this, &SmithChartWindow::on_button_clicked));

    add(button);
    button.show();

    set_default_size(500, 500);
}

void SmithChartWindow::on_button_clicked() {

    std::cout << "Ayylmao" << std::endl;
}
