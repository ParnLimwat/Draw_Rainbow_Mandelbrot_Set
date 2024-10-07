#include "graphics.h"
#include <math.h>

int main(void)
{
    // initialize variables needed
    double x0 = 0;
    double y0 = 0;
    double x = 0;
    double y = 0;
    int iteration = 0;
    int max_it;
    double x_temp = 0;

    // iterate through the page of graphics pixel by pixel
    for (int Px = 0; Px < 499; Px++){
        for(int Py = 0; Py < 299; Py++){
        x0 = Px/499.0 * (0.47 + 2.00) - 2.00;
        y0 = Py/299.0 * (1.12+1.12) - 1.12;

        x = 0;
        y = 0;

        iteration = 0;
        max_it = 1000;
        // mandelbrot set calculation
        while (x*x + y*y <= 4 && iteration < max_it){
            x_temp = x*x - y*y + x0;
            y = 2*x*y + y0;
            x = x_temp;
            iteration++;
        }


        colour col;
            switch (iteration % 6) {
                case 0: col = red; break;
                case 1: col = yellow; break;
                case 2: col = green; break;
                case 3: col = cyan; break;
                case 4: col = blue; break;
                case 5: col = magenta; break;
                default: col = black; 
            }

            // Set the color
            setColour(col);
        // plot point
        drawLine(Px,Py,Px+1,Py);
    }
    }

    return 0;
}



