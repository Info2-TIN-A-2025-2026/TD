#include <stdio.h>
#include "segment2D.h"

static void test(void) {
    return;
}

Segment2D segment_init(const Vector2D v1, const Vector2D v2) {

    Segment2D s;
    s.v1=v1;
    s.v2=v2;
    return s;
}

void segment_display(const Segment2D s) {

    printf("Segment = (%+6.3lf, %+6.3lf) -> (%+6.3lf, %+6.3lf)\n",
         s.v1.x, s.v1.y, s.v2.x, s.v2.y);
}
