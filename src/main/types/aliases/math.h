#ifndef MATH_H
#define MATH_H

#include "macro.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>


namespace Math {
    using Vec2 = glm::vec2;
    using Vec3 = glm::vec3;
    using Vec4 = glm::vec4;
    using Mat4 = glm::mat4;

    ALIAS_FUNCTION(glm::translate, Translate);
    ALIAS_FUNCTION(glm::value_ptr, ValuePtr);
    ALIAS_FUNCTION(glm::ortho, Ortho);
};

#endif