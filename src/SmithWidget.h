//
// Created by jordan on 28/10/17.
//

#ifndef SMITH_SMITHWIDGET_H
#define SMITH_SMITHWIDGET_H


#include <gtkmm/drawingarea.h>

class SmithWidget : public Gtk::DrawingArea {
    public:
        SmithWidget();
        virtual ~SmithWidget() = default;

    protected:
        bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
        bool on_timeout();

        bool impedance_mode;

};


#endif //SMITH_SMITHWIDGET_H
