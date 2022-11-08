#ifndef BACKEND_H
#define BACKEND_H

#include <iostream>
#include <functional>

#include <types/aliases/opengl.h>

class Window {
    private:
        OpenGL::Window *window;

    public:
        Window();
        void create(unsigned int width, unsigned int height, std::string title);
        void render(std::function<void(OpenGL::Window *window)> fn);
        void terminate();
        void terminate(std::function<void()> fn);

        ~Window();
};

#endif