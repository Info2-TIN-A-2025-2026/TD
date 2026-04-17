#include "vector2D.h"
#include "segment2D.h"

int main(int argc, const char *argv[])
{
    Vector2D u;
    Vector2D v;
    Vector2D r;

    u = vector_init(3., 4.);
    v = vector_init(1., 2.);
    vector_display(u);
    vector_display(v);
    r = vector_add(u, v);
    vector_display(r);

    Segment2D s;
    s = segment_init(u, v);
    segment_display(s);

    return 0;
}