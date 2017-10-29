/**
 * @file HelloWorld.h
 */

#pragma once

#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include "SmithWidget.h"

namespace jrc {

class SmithChartWindow : public Gtk::Window {
    public:
        SmithChartWindow();

        virtual ~SmithChartWindow() = default;

    protected:
        void on_button_clicked();

        bool on_button_press_event(GdkEventButton* button_event) override;


        Gtk::Button button;
        SmithWidget smith;
};

};
