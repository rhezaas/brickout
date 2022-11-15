#include "Texture.h"

#include <iostream>

#include <types/aliases/image.h>
#include <types/aliases/opengl.h>

Texture::Texture(std::string path) {
    Image::FlipVertically(true);
    this->buffer = Image::Load(path.c_str(), &this->width, &this->height, &this->bitPerPixel, 4);

    OpenGL::Textures(1, &this->id);
    OpenGL::BindTexture(OpenGL::TextureType::Texture2D, this->id);

    OpenGL::TextureFilter(OpenGL::TextureType::Texture2D, OpenGL::TextureType::MinFilter, OpenGL::TextureType::MipMapLinear);
    OpenGL::TextureFilter(OpenGL::TextureType::Texture2D, OpenGL::TextureType::MagFilter, OpenGL::TextureType::Linear);
    OpenGL::TextureFilter(OpenGL::TextureType::Texture2D, OpenGL::TextureType::WrapX, OpenGL::TextureType::Repeat);
    OpenGL::TextureFilter(OpenGL::TextureType::Texture2D, OpenGL::TextureType::WrapY, OpenGL::TextureType::Repeat);

    if (this->buffer) {
        OpenGL::Image2D(OpenGL::TextureType::Texture2D, 0, OpenGL::ColorType::RGBA, this->width, this->height, 0, OpenGL::ColorType::RGBA, OpenGL::DataType::UnsignedByte, this->buffer);
        OpenGL::GenerateMipmap(OpenGL::TextureType::Texture2D);
        OpenGL::BindTexture(OpenGL::TextureType::Texture2D, 0);
        Image::FreeBuffer(this->buffer);
    } else {
        std::cout << "Failed to load texture" << std::endl;
    }
}

void Texture::compile() {
    OpenGL::ActiveTexture(OpenGL::TextureType::Unit0);
    OpenGL::BindTexture(OpenGL::TextureType::Texture2D, this->id);
}

Texture::~Texture() {
    // OpenGL::DeleteTextures(1, &this->id);
}