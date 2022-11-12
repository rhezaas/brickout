#ifndef VERTEX_STRUCT_H
#define VERTEX_STRUCT_H

#include <types/aliases/math.h>


struct Vertex {
    Math::Vec3 position;
    Math::Vec4 rgbaColor;
    Math::Vec2 texture;
};

#endif