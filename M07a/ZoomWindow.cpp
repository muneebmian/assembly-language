#include "ZoomWindow.h"
#include "ComplexPlane.h"

#include "../std_lib_facilities.h"

ZoomWindow::ZoomWindow(Point xy, int w, int h, const string& title)
    : Simple_window(xy,w,h,title),plane(PLANE_Y_OFFSET,complex<double>(0,0),1.0,w,h-PLANE_Y_OFFSET),next_i(Point(x_max()-140,0),70,20,"Center i:"),next_r(Point(x_max()-275,0),70,20,"Center r:"),next_zoom(Point(x_max()-410,0),70,20,"Zoom Level:")
{
    plane.createBuffer();
    attach(next_i);
    attach(next_r);
    attach(next_zoom);
    attach(plane);
}
double ZoomWindow::getCenter_r() const
{
    return plane.getCenter().real();
}
double ZoomWindow::getCenter_i() const
{
    return plane.getCenter().imag();
}
double ZoomWindow::getZoom() const
{
    return plane.getZoomLevel();
}
bool ZoomWindow::wait_for_button()
{
    Simple_window::wait_for_button();
    double center_i,center_r,zoom;
    istringstream is(next_i.get_string() + " " + next_r.get_string() + " " + next_zoom.get_string());
    is >> center_i;
    is.clear();
    is >> center_r;
    is.clear();
    is >> zoom;
    is.clear();
    plane.setCenter(complex <double>(center_r,center_i));
    plane.setZoomLevel(zoom);
    plane.createBuffer();

 

}