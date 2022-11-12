#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION

#include <stb_image.h>

#include "macro.h"


namespace Image {
    ALIAS_FUNCTION(stbi_set_flip_vertically_on_load, FlipVertically);
    ALIAS_FUNCTION(stbi_load, Load);
    ALIAS_FUNCTION(stbi_image_free, FreeBuffer);
}

#endif