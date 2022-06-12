#include "Matrices.h"
#include "../std_lib_facilities.h"
#include "PolygonMatrix.h"

using namespace Matrices;

namespace Graph_lib
{
double mapRange(double n, double fromLow, double fromHigh, double toLow, double toHigh)
 {
     double value = ((static_cast<double>(n-fromLow))/(fromHigh-fromLow))*(toHigh-toLow) + toLow;
     return value;
 }

PolygonMatrix::PolygonMatrix(int _xPixels, int _yPixels):pointMatrix(2,0)
{
    xPixels = _xPixels;
    yPixels = _yPixels;
}
void PolygonMatrix::add(Point p)
{
    Polygon::add(p); 
    p.x = mapRange(p.x,0, xPixels, (-xPixels/2), (xPixels/2));
    p.y = mapRange(p.y,yPixels, 0, (-yPixels/2), (yPixels/2));
    pointMatrix.addCoordinate(p.x,p.y);
    
 
}
void PolygonMatrix::rotate(double theta)
{
    RotationMatrix R(theta);
    pointMatrix = R * pointMatrix;
    updatePixels();
    
}
void PolygonMatrix::scale(double c)
{
    ScalingMatrix S(c);
    pointMatrix = S * pointMatrix;
    updatePixels();
    
}
void PolygonMatrix::translate(double xShift, double yShift)
{
    TranslationMatrix T(xShift, yShift, pointMatrix.getCols());
    pointMatrix = T + pointMatrix;
    updatePixels();
}
void PolygonMatrix::updatePixels()
{
    Point p;
   
        for(int j = 0 ; j < pointMatrix.getCols(); j++)
        {
            //p.y = mapRange(pointMatrix(0,j), (-yPixels/2), (yPixels/2),0, yPixels);
            //p.x = mapRange(pointMatrix(1,j), (-xPixels/2), (xPixels/2),0, xPixels);

            p.x = mapRange(pointMatrix(0,j),-xPixels/2,xPixels/2,0,xPixels);  
            p.y = mapRange(pointMatrix(1,j),yPixels/2,-yPixels/2,0,yPixels);
          
            Shape::set_point(j,p);
           
        }
}
}
