#include "../std_lib_facilities.h"
#include "ComplexPlane.h"
#include "ZoomWindow.h"

double mapRange(double n, double fromLow, double fromHigh, double toLow, double toHigh)
 {
     double value = ((static_cast<double>(n-fromLow))/(fromHigh-fromLow))*(toHigh-toLow) + toLow;
     return value;
 }

 void writePixel(unsigned char* buf, int xPixels, int row, int col, unsigned char r, unsigned char g, unsigned char b)
{
    int i,j,k;
    i = (xPixels * row + col) * 3;
    j = (xPixels * row + col) * 3 + 1;
    k = (xPixels * row + col) * 3 + 2;
    buf[i] = r;
    buf[j]= g;
    buf[k] = b;

}

int countIterations(double re, double im, int maxIterations)
{
    complex<double> c (re, im);
    complex<double> z (0,0);
    int i =0;
    while( i < maxIterations && fabs(z) < 2.0)
    {
         z = (z*z) + c;
         i++;
    }
    return i;
}
void ComplexPlane::draw_lines() const
{
    fl_draw_image(buf,0,PLANE_Y_OFFSET,xPixels,yPixels);
   
}
void ComplexPlane::createBuffer()
{
    double real, imaginary;
    int iterations;
    unsigned char r,g,b;
    for(int i = 0; i < yPixels; i++)
    {
        for (int j = 0; j< xPixels; j++)
        {
            real = mapRange(j,0,xPixels,center.real()-(reRange*zoomLevel)/2.0, center.real()+(reRange * zoomLevel)/2.0);
            imaginary = mapRange(i,yPixels ,0,center.imag()-(imRange*zoomLevel)/2.0, center.imag()+(imRange*zoomLevel)/2.0);
            iterations = countIterations(real,imaginary,maxIterations);
            
            if(iterations>=maxIterations)
                Fl::get_color(maxIterations - iterations,r,g,b);

            else
            {
                Fl::get_color(iterations,r,g,b);
            }
            
            writePixel(buf,xPixels,i,j,r,g,b);
                
            
            
        }
    }
}
