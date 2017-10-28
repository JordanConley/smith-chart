#include <iostream>

#include "SmithChartWindow.h"

int main(int argc, char** argv) {
    auto app = Gtk::Application::create(argc, argv, "me.jconley.smith");

    SmithChartWindow hw;

    return app->run(hw);
}
