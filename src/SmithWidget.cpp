//
// Created by jordan on 28/10/17.
//

#include <gtkmm/drawingarea.h>
#include <giomm.h>

#include "SmithWidget.h"

SmithWidget::SmithWidget() {
    impedance_mode = true;

    Glib::signal_timeout().connect(sigc::mem_fun(*this, &SmithWidget::on_timeout), 100);
    
}

bool SmithWidget::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    Gtk::Allocation allocation = get_allocation();
    const int w = allocation.get_width();
    const int h = allocation.get_height();

    cr->scale(w/2.5, h/2.5);
    cr->translate(2.5/2, 2.5/2);
    cr->set_line_width(0.005);

    cr->set_source_rgb(0.0, 0.0, 0.0);

    cr->save();
    cr->set_line_width(cr->get_line_width()/2);
    std::vector<float> rings{ 0.f, 0.1f, 0.2f, 0.4f, 0.6f, 0.8f, 1, 1.5, 2, 3, 4, 5, 6 };
    for (const float i : rings) {
        const float cx = i / (1 + i);
        const float r = 1 / (1 + i);

        cr->arc(cx, 0, r, 0, 2*M_PI);
        cr->stroke();

        if (i > 0) {
            cr->arc(impedance_mode ? 1 : -1, 1 / i, 1 / std::abs(i), 0, 2 * M_PI);
            cr->stroke();


            cr->arc(impedance_mode ? 1 : -1, -1/i, 1/std::abs(i), 0, 2*M_PI);
            cr->stroke();
        }

//        rt->DrawEllipse(circle(impedance_mode ? cx : -cx, 0, r), blackbrush, i ? stroke_width : 2*stroke_width);

//        rt->DrawEllipse(circle(impedance_mode ? 1 : -1, 1/i, 1/std::abs(i)), blackbrush, stroke_width);
//        rt->DrawEllipse(circle(impedance_mode ? 1 : -1, -1/i, 1/std::abs(i)), blackbrush, stroke_width);
    }

    cr->move_to(1, 0);
    cr->line_to(-2.5, 0);
    cr->stroke();

    cr->set_font_size(0.1);
    cr->move_to(-2.5/2, (-2.5/2) + 0.1);
    cr->text_path("Hello!\rSomebody");
    cr->fill();

    cr->restore();
//
//    cr->set_source_rgb(0.0, 0.0, 0.0);
//    cr->arc(0, 0, 0.5, 0, 2*M_PI);

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

