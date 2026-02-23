#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM_POINTS 1000
#define NUM_POINTS 256

typedef struct {
    double x;
    double y;
} Point2D;

typedef struct {
    Point2D points[MAX_NUM_POINTS];
    size_t num_points;
} Object2D;


double my_rand(const double min, const double max) {
    double a=(max-min)/RAND_MAX;
    double b=min;
    return a*rand()+b;
}

int main(int argc, const char *argv[])
{
    Object2D o1;
    printf("size of Object2D = %lu bytes\n", sizeof(Object2D));


    for(size_t index=0; index<NUM_POINTS; index++) {

        double x = my_rand(50,150);
        double y = my_rand(30,80);

        o1.points[index].x = x;
        o1.points[index].y = y;

        Point2D p;
        p.x = x;
        p.y = y;
        o1.points[index] = p;
    }
    o1.num_points = NUM_POINTS;

    // compute and display the mass center of o1
}