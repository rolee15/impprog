#include <stdio.h>
#include <math.h>
#include "circle.h"

circle_t create_circle(double x, double y, double r)
{
    circle_t c;
    c.x = x;
    c.y = y;
    c.radius = r;
    return c;
}

void print_circle(circle_t c)
{
    printf("(x=%lf, y=%lf, r=%lf)\n", c.x, c.y, c.radius);
}

double area(circle_t c)
{
    return c.radius * c.radius * M_PI;
}

void move(circle_t *c, double x, double y)
{
    c->x = x;
    c->y = y;
}

double sum_area(circle_t *circles, size_t size)
{
    double sum = 0;
    for (size_t i = 0; i < size; ++i)
    {
        sum += area(circles[i]);
    }

    return sum;
}