#include <stdio.h>
#include <math.h>

// here, create the Point2D structure
typedef struct {
    double x;
    double y;
} Point2D;

double norm(const Point2D p) {
    return sqrt( pow(p.x,2) + pow(p.y,2) );
}

double dist(Point2D *p1, Point2D* p2) {
    double dx = p1->x - p2->x;
    double dy = p1->y - p2->y;
    return sqrt( dx*dx + dy*dy );
}


int main(int argc, const char *argv[])
{
    Point2D a = { 4., 3.};
    Point2D b = { 6., 2.};
    // Point2D b = { .x=4., .y=3.};
    // Point2D c = { .y=3., .x=4.};
    // Point2D d = { .y=3. }; // others = 0
    // Point2D e;

    printf("xa = %lf\n", a.x);
    printf("ya = %lf\n", a.y);

    Point2D *pa = &a;
    printf("xa = %lf\n", pa->x);
    printf("ya = %lf\n", pa->y);

    printf("||a||=%lf\n", norm(a));
    printf("dist(a,b)=%lf\n", dist(&a, &b));
}