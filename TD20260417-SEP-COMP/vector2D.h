#pragma once

typedef struct {

    double x;
    double y;

 } Vector2D;


Vector2D vector_init(const double x, const double y);
void vector_display(const Vector2D u);
Vector2D vector_add(const Vector2D u, const Vector2D v);
Vector2D vector_scalar_prod(const double k, const Vector2D u);
double vector_norm(const Vector2D u);
double vector_product(const Vector2D u, const Vector2D v);
double vector_angle(const Vector2D u);
Vector2D vector_normalize(const Vector2D u);
double vector_dist(const Vector2D u, const Vector2D v);

