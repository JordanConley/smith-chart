/**
 * @file HelloWorld.cpp
 */

#include <gtkmm/button.h>
#include <gtkmm/window.h>


#include <iostream>
#include <gtkmm/messagedialog.h>

#include "Conversions.h"
#include "SmithChartWindow.h"

namespace jrc {

SmithChartWindow::SmithChartWindow() : smith() {
    set_default_size(500, 500);

    add(smith);
    smith.show();
}

void SmithChartWindow::on_button_clicked() {

    std::cout << "Ayylmao" << std::endl;
}

bool SmithChartWindow::on_button_press_event(GdkEventButton* button_event) {
    std::complex<double> gamma = smith.translate_screen(button_event->x, button_event->y);
    std::cout << "Gamma = " << gamma << ", y = " << + y_from_gamma(gamma) << ", z = " << z_from_gamma(gamma)
              << std::endl;

    return Gtk::Widget::on_button_press_event(button_event);
}

}
