#include <iostream>

#include "SmithChartWindow.h"

int main(int argc, char** argv) {
    auto app = Gtk::Application::create(argc, argv, "me.jconley.smith");

    jrc::SmithChartWindow hw;

    return app->run(hw);
}
