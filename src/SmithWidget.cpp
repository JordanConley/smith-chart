//
// Created by jordan on 28/10/17.
//

#include <gtkmm/drawingarea.h>
#include <gtkmm/messagedialog.h>
#include <giomm.h>

#include <iostream>

#include "SmithWidget.h"

namespace jrc {

SmithWidget::SmithWidget() {
    impedance_mode = true;

    Glib::signal_timeout().connect(sigc::mem_fun(*this, &SmithWidget::on_timeout), 100);
    signal_button_press_event().connect(sigc::mem_fun(*this, &SmithWidget::on_button_press_event));
}

bool SmithWidget::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    Gtk::Allocation allocation = get_allocation();
    const int w = allocation.get_width();
    const int h = allocation.get_height();

    const double span = 2.5;

    cr->scale(w / span, h / span);
    cr->translate(span / 2, span / 2);
    cr->set_line_width(0.005);

    re_min = im_min = -span / 2;
    re_max = im_max = span / 2;

    cr->set_source_rgb(0.0, 0.0, 0.0);

    cr->save();
    cr->set_line_width(cr->get_line_width() / 2);
    std::vector<float> rings{0.f, 0.1f, 0.2f, 0.4f, 0.6f, 0.8f, 1, 1.5, 2, 3, 4, 5, 6};
    for (const float i : rings) {
        const float cx = i / (1 + i);
        const float r = 1 / (1 + i);

        cr->arc(cx, 0, r, 0, 2 * M_PI);
        cr->stroke();

        if (i > 0) {
            cr->arc(impedance_mode ? 1 : -1, 1 / i, 1 / std::abs(i), 0, 2 * M_PI);
            cr->stroke();


            cr->arc(impedance_mode ? 1 : -1, -1 / i, 1 / std::abs(i), 0, 2 * M_PI);
            cr->stroke();
        }
    }

    cr->move_to(1, 0);
    cr->line_to(-2.5, 0);
    cr->stroke();

    cr->set_font_size(0.1);
    cr->move_to(-span / 2, (-span / 2) + 0.1);
    cr->text_path("Hello!\rSomebody");
    cr->fill();

    cr->restore();

    return true;
}

bool SmithWidget::on_timeout() {
    auto win = get_window();
    if (win) {
        Gdk::Rectangle r(0, 0, get_allocation().get_width(), get_allocation().get_height());
        win->invalidate_rect(r, false);
    }
    return true;
}

/* map (screen_min -> screen_max) to (im_min -> im_max) */
double map(double x, double in_min, double in_max, double out_min, double out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

std::complex<double> SmithWidget::translate_screen(double mouse_x, double mouse_y) {
    const double screen_width = get_allocation().get_width();
    const double screen_height = get_allocation().get_height();


    const double real = jrc::map(mouse_x, 0.0, screen_width, re_min, re_max);
    const double imag = jrc::map(mouse_y, screen_height, 0.0, im_min, im_max);

    return std::complex<double>(real, imag);
}

};
