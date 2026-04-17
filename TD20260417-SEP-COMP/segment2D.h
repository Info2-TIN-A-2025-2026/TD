#pragma once


#include "vector2D.h"

typedef struct {

    Vector2D v1;
    Vector2D v2;

} Segment2D;

Segment2D segment_init(const Vector2D v1, const Vector2D v2);
void segment_display(const Segment2D s);
