#include <stdio.h>
#include "circle.h"

int main()
{
    circle_t c;
    c.x = 0;
    c.y = 0;
    c.radius = 3;

    printf("%lf\n", area(c));
    move(&c, 1, 2);
    printf("%lf, %lf\n", c.x, c.y);

    circle_t circles[] = { 
        create_circle(0, 0, 1), 
        create_circle(0, 0, 2), 
        create_circle(0, 0, 3)
    };
    printf("%lf\n", sum_area(circles, sizeof(circles) / sizeof(circles[0])));

    return 0;
}