
#include "../std_lib_facilities.h"
#include "Topograph.h"

Topograph::Topograph(string fileName)
{
    //int xcorner;
    //int ycorner;
    //int cellsize;

    ifstream fileOpen;
    fileOpen.open(fileName);
    string temp;
    fileOpen >> temp >> width;
    fileOpen >> temp >> height;
    
    /*fileOpen >> temp >> xcorner;
    fileOpen >> temp >> ycorner;
    fileOpen >> temp >> cellsize;*/

    v.resize(height);
    for(int i = 0; i < height; i++)
    {
        v[i].resize(width);
    }
    fileOpen >> temp;
    for(int index = 0;index<3;index++)
    {
        fileOpen.ignore(2500,'\n');
    }
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            fileOpen >> v[i][j];
        }
    }
    findMax();
    findMin();
    cout << "Height: " << height << endl;
    cout << "Width: " << width << endl;
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;

    
}
void Topograph::findMin()
{
    int Min = 9999;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(v[i][j] < Min)
            {
                Min = v[i][j];
            }
        }
    }
    min = Min;
    cout << min;

}
void Topograph::findMax()
{
     int Max = -9999;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(v[i][j] > Max)
            {
                Max = v[i][j];
            }
        }
    }
    max= Max;
    cout << max;
}

int Topograph::mapRange(int n, int fromLow, int fromHigh, int toLow, int toHigh)
{
    //int df = fromHigh - fromLow;
    //int dt = toHigh - toLow;
    //double p = (n/df) * 100;
    //int value = p * dt;
    
    int value = ((static_cast<double>(n-fromLow))/(fromHigh-fromLow))*(toHigh-toLow) + toLow;
    return value;
    

}
 void Topograph::drawMap(Bmp& bmp)
    {
        int color; 
        for (int i = 0; i < bmp.getHeight(); i++)
        {
            for (int j = 0; j < bmp.getWidth(); j++)
            {
                color = mapRange(v[i][j], min, max, 0, 255);
                bmp(i,j).r = color;
                bmp(i,j).g = color;
                bmp(i,j).b = color;
            }
        }
    }
int Topograph::drawGreedyPath(Bmp& bmp, int startingRow, rgb color)
{
    int j =0;
    int startRow ;
    int elevationChange = 0;
    bmp(startingRow,j).r = color.r;
    bmp(startingRow,j).g = color.g;
    bmp(startingRow,j).b = color.b;
    while( j < bmp.getWidth()-1)
            {
                startRow = v[startingRow][j];
                moveForward(startingRow,j);
                j++;
                elevationChange += fabs(startRow - v[startingRow][j]);
                bmp(startingRow,j).r = color.r;
                bmp(startingRow,j).g = color.g;
                bmp(startingRow,j).b = color.b;
                
            }
    return elevationChange;
}
void Topograph::moveForward(int& i, int& j)
{
        int forward = fabs(v[i][j] - v[i][j + 1]);

        if(i != 0 && i != height-1 && (j!= width-1) )
        {   int down = fabs(v[i][j] - v[i + 1][j]);
            int up = fabs(v[i][j] - v[i - 1][j]);
            if (down < forward && down < up)
            {i += 1;
                }
            else if(up < forward && up < down)
            { i -= 1;
            }
            else if(down == up)
            {i +=1;
            }
        }
    else if(i == 0)
    {     int down = fabs(v[i][j] - v[i + 1][j]);
         if (down < forward)
            {i += 1;
             }
    }
    else if(i == height || i == height - 1)
    { 
        int up = fabs(v[i][j] - v[i - 1][j]);
        if(up < forward)
            {  i -= 1;
            }      
    }
        
}
void Topograph::drawBestPath(Bmp& bmp)
{
    int bestRoute = 99999, bestRow = 0;
    int elevation;
    
    for(int i = 0; i <bmp.getHeight()-1 ; i++)
    {
        elevation = drawGreedyPath(bmp, i, RED_PIXEL);
        if(elevation < bestRoute)
        {
            bestRoute = elevation;
            bestRow = i;
        }
    }
    bestRoute = drawGreedyPath(bmp, bestRow, BLUE_PIXEL);
    cout << "Best route: " << bestRoute << endl;

}