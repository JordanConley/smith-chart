/**
 * @file HelloWorld.cpp
 */

#include <gtkmm/button.h>
#include <gtkmm/window.h>


#include <iostream>

#include "SmithChartWindow.h"


SmithChartWindow::SmithChartWindow() : smith() {
    set_default_size(500, 500);

    add(smith);
    smith.show();
}

void SmithChartWindow::on_button_clicked() {

    std::cout << "Ayylmao" << std::endl;
}
