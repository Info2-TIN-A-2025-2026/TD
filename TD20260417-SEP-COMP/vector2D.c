#include <stdio.h>
#include "vector2D.h"

static void test(void)
{
    return;
}

Vector2D vector_init(const double x, const double y)
{
    Vector2D u;
    u.x = x;
    u.y = y;
    return u;
}

void vector_display(const Vector2D u)
{
    printf("Vector = (%+6.3lf, %+6.3lf)\n", u.x, u.y);
}

Vector2D vector_add(const Vector2D u, const Vector2D v)
{
    Vector2D r;
    r.x = u.x + v.x;
    r.y = u.y + v.y;
    return r;
}

Vector2D vector_scalar_prod(const double k, const Vector2D u)
{
    Vector2D r;
    r.x = u.x * k;
    r.y = u.y * k;
    return r;
}