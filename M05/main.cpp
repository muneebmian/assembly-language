#include "../std_lib_facilities.h"
#include "Bmp.h"
#include "Topograph.h"


int main()
{
    string fileName1 = "map_input.txt";
    string fileName2 = "map.bmp";
    string fileName3 = "map2.bmp";

    Topograph topograph(fileName1);


    Bmp bmp(topograph.getHeight(),topograph.getWidth());
    
    topograph.drawMap(bmp);

    
    bmp.write(fileName2);
    

    system(("eog " + fileName2 + " &").c_str());
    topograph.drawBestPath(bmp);
    bmp.write(fileName3);
    system(("eog " + fileName3 + " &").c_str());

    /*system((VIEWING_APP + fileName1 + " &").c_str()); ///system call to open the image file for viewing
    system((VIEWING_APP + fileName2 + " &").c_str());

    ///create a 100x100 bmp with random pixel colors
    Bmp bmp2(100,100);
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            bmp2(i,j).r = rand() % 256;
            bmp2(i,j).g = rand() % 256;
            bmp2(i,j).b = rand() % 256;
        }
    }
    string fileName3 = "out.bmp";
    bmp2.write(fileName3 + " &");
    system((VIEWING_APP + fileName3).c_str());*/

    return 0;
}
