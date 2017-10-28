/**
 * @file HelloWorld.h
 */

#pragma once

#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include "SmithWidget.h"

class SmithChartWindow : public Gtk::Window {
    public:
        SmithChartWindow();
        virtual ~SmithChartWindow() = default;

    protected:
        void on_button_clicked();
        Gtk::Button button;
        SmithWidget smith;

    private:
};
