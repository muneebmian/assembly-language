#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;  // use our graphics interface library

int main()
{
    Point x {0, 0};
    Simple_window win {x,1000,800,"Image Grid"};
    int x_size = win.x_max();                                    // get the size of our window
    int y_size = win.y_max();
    int x_grid = 100;
    int y_grid = 100;
    Rectangle rect1 {x,100,100};
    Rectangle rect2 {Point{100,100},100,100};
    Rectangle rect3 {Point{200,200},100,100};
    Rectangle rect4 {Point{300,300},100,100};
    Rectangle rect5 {Point{400,400},100,100};
    Rectangle rect6 {Point{500,500},100,100};
    Rectangle rect7 {Point{600,600},100,100};
    Rectangle rect8 {Point{700,700},100,100};
    
    rect1.set_fill_color(Color::red);
    rect2.set_fill_color(Color::red);
    rect3.set_fill_color(Color::red);
    rect4.set_fill_color(Color::red);
    rect5.set_fill_color(Color::red);
    rect6.set_fill_color(Color::red);
    rect7.set_fill_color(Color::red);
    rect8.set_fill_color(Color::red);
    win.attach(rect1);
    win.attach(rect2);
    win.attach(rect3);
    win.attach(rect4);
    win.attach(rect5);
    win.attach(rect6);
    win.attach(rect7);
    win.attach(rect8);


    Lines grid;
    for (int x=x_grid; x<=800; x+=x_grid)
        grid.add(Point{x,0},Point{x,800});       // vertical line
    for (int y = y_grid; y<=800; y+=y_grid)
        grid.add(Point{0,y},Point{800,y});       // horizontal line                                // display!

    
    win.attach(grid);                                      // attach the lines to the window
    
    Image img1 {Point{600,0},"img1.jpg"};
    Image img2 {Point{0,400},"img2.jpg"};
    Image img3 {Point{0,600},"img3.jpg"};
    Image img4 {Point{0,0},"img4.jpg"};

    win.attach(img1);
    win.attach(img2);
    win.attach(img3);
    win.attach(img4);

    win.wait_for_button();

    int counter = 1;
    while(true)
    {
        if(counter % 64 == 0 && counter != 0)
        {
            counter = 0;
            img4.move(-700, -700);
        }
        else if(counter % 8 == 0 && counter != 0)
        {
            img4.move(-700, 100);
        }
        else
        {
            img4.move(100, 0);
        }
        counter++;
        win.wait_for_button();
    }

    win.wait_for_button(); 

}