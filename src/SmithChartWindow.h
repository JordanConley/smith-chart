/**
 * @file HelloWorld.h
 */

#pragma once

#include <gtkmm/window.h>
#include <gtkmm/button.h>

class SmithChartWindow : public Gtk::Window {
    public:
        SmithChartWindow();
        virtual ~SmithChartWindow() = default;

    protected:
        void on_button_clicked();
        Gtk::Button button;

    private:
};
