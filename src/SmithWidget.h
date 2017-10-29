//
// Created by jordan on 28/10/17.
//

#pragma once

#include <gtkmm/drawingarea.h>
#include <complex>

namespace jrc {

class SmithWidget : public Gtk::DrawingArea {
    public:
        SmithWidget();

        virtual ~SmithWidget() = default;

        std::complex<double> translate_screen(double mouse_x, double mouse_y);

    protected:
        bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
        

        bool on_timeout();

        bool impedance_mode;

    private:
        double re_min, re_max, im_min, im_max;

};

};
