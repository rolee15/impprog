#ifndef CIRCLE_H
#define CIRCLE_H

struct Circle
{
    double x;
    double y;
    double radius;
};

typedef struct Circle circle_t;

circle_t create_circle(double x, double y, double r);

void print_circle(circle_t c);

double area(circle_t c);

void move(circle_t* c, double x, double y);

double sum_area(circle_t* circles, size_t size);

#endif