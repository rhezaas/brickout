#ifndef SHADER_H
#define SHADER_H

#include <iostream>

#include <types/aliases/opengl.h>

class Shader {
    private:
        unsigned int program;
        unsigned int create(OpenGL::ShaderType type, std::string source);
        std::string readSource(std::string source);

    public:
        Shader();
        void addSource(OpenGL::ShaderType type, std::string source);
        void compile();

        unsigned int getUniform(const char *name);
        unsigned int getProgram();
        ~Shader();
};

#endif