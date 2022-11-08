#include "Shader.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include <types/aliases/opengl.h>
#include <types/enums/WindowConstant.h>


Shader::Shader() {
    this->program = OpenGL::CreateProgram();
};

std::string Shader::readSource(std::string source) {
    std::ifstream file(source);
    std::stringstream shader;
    std::string line;

    if (!file.is_open()) {
        throw std::invalid_argument("File Not Found!!");
    }

    while(getline(file, line)) {
        shader << line << "\n";
    };

    return shader.str();
};

unsigned int Shader::create(OpenGL::ShaderType type, std::string source) {
    unsigned int shader = OpenGL::CreateShader(type);
    const char* src = source.c_str();
    
    OpenGL::ShaderSource(shader, 1, &src, nullptr);
    OpenGL::CompileShader(shader);

    int result;
    OpenGL::GetCompileStatus(shader, OpenGL::CompileStatus, &result);

    if (result == OpenGL::DataType::False) {
        int length;
        OpenGL::GetCompileStatus(shader, OpenGL::CompileStatus, &length);

        char* message = new char[length];
        OpenGL::ShaderLog(shader, length, &length, message);

        std::cout << " Failed to compile " << (type == OpenGL::ShaderType::VertexShader ? "vertex" : "fragment") << " shader" << std::endl;
        std::cout << message << std::endl;
        
        return -1;
    }

    return shader;
}

void Shader::addSource(OpenGL::ShaderType type, std::string source) {
    unsigned int shader = create(type, readSource(source));
    OpenGL::AttachShader(this->program, shader);
}

void Shader::compile() {
    OpenGL::LinkProgram(this->program);
    OpenGL::ValidateProgram(this->program);
    OpenGL::UseProgram(this->program);
}

unsigned int Shader::getUniform(const char *name) {
    return OpenGL::GetUniform(this->program, name);
}

unsigned int Shader::getProgram() {
    return this->program;
}

Shader::~Shader(){}