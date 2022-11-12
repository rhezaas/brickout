#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>

class Texture {
    private:
        int width;
        int height;
        int bitPerPixel;
        unsigned int id;
        unsigned char *buffer;

        std::string path;

    public:
        Texture(std::string path);
        void compile();

        ~Texture();
};

#endif