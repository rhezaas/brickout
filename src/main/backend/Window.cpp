#include "Window.h"

#include <iostream>
#include <functional>

#include <types/aliases/opengl.h>


Window::Window() {
    OpenGL::Init();

    OpenGL::WindowHint(OpenGL::Type::VersionMajor, 4);                                  // required: specify opengl major version
    OpenGL::WindowHint(OpenGL::Type::VersionMinor, 6);                                  // required: specify opengl minor version
    OpenGL::WindowHint(OpenGL::Type::OpenGLProfile, OpenGL::Type::OpenGLCoreProfile);   // required: set opengl profile to core 
}

void Window::create(unsigned int width, unsigned int height, std::string title) {
    this->window = OpenGL::CreateWindow(width, height, title.c_str(), (OpenGL::Monitor*) NULL, (OpenGL::Window*) NULL);

    if (!this->window) {
        OpenGL::Terminate();
    }

    OpenGL::MakeCurrentContext(this->window);

    if (!OpenGL::GladLoader((OpenGL::GladLoadProc) glfwGetProcAddress)) {               // TODO: Need Aliasing!
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }
}

void Window::render(std::function<void(OpenGL::Window *window)> fn) {
    if (!this->window) {
        OpenGL::Terminate();
    }

    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    while (!OpenGL::IsWindowClosed(this->window)) {
        // Render here
        OpenGL::Clear(OpenGL::Type::ColorBufferBit);

        fn(this->window);

        // Swap front and back buffers
        OpenGL::SwapBuffers(this->window);

        // Poll for and process events
        OpenGL::PollEvents();
    }
}

void Window::terminate() {
    OpenGL::Terminate();
}

void Window::terminate(std::function<void()> fn) {
    fn();

    OpenGL::Terminate();
}

Window::~Window(){}