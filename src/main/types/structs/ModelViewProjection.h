#ifndef MVP_STRUCT_H
#define MVP_STRUCT_H

#include <types/aliases/math.h>

struct MVP {
    unsigned int mvpUniform;
    Math::Mat4 projection;
    Math::Mat4 view;
};

#endif