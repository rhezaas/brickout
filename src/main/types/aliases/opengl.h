#ifndef OPENGL_H
#define OPENGL_H

#include "macro.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace OpenGL {
    // classes | types
    using Monitor = GLFWmonitor;
    using Window = GLFWwindow;
    using GladLoadProc = GLADloadproc;

    // window functions
    ALIAS_FUNCTION(glfwInit, Init);
    ALIAS_FUNCTION(glfwWindowHint, WindowHint);
    ALIAS_FUNCTION(glfwCreateWindow, CreateWindow);
    ALIAS_FUNCTION(glfwMakeContextCurrent, MakeCurrentContext);
    ALIAS_FUNCTION(glfwGetProcAddress, GetProcAddress);
    ALIAS_FUNCTION(glfwTerminate, Terminate);
    ALIAS_FUNCTION(glfwWindowShouldClose, IsWindowClosed);
    ALIAS_FUNCTION(glClear, Clear);
    ALIAS_FUNCTION(glfwSwapBuffers, SwapBuffers);
    ALIAS_FUNCTION(glfwPollEvents, PollEvents);

    // glad functions
    ALIAS_FUNCTION(gladLoadGLLoader, GladLoader);

    // shader functions
    ALIAS_FUNCTION(glCreateProgram, CreateProgram);
    ALIAS_FUNCTION(glCreateShader, CreateShader);
    ALIAS_FUNCTION(glShaderSource, ShaderSource);
    ALIAS_FUNCTION(glCompileShader, CompileShader);
    ALIAS_FUNCTION(glGetShaderiv, GetCompileStatus);
    ALIAS_FUNCTION(glGetShaderInfoLog, ShaderLog);
    ALIAS_FUNCTION(glAttachShader, AttachShader);
    ALIAS_FUNCTION(glUseProgram, UseProgram);
    ALIAS_FUNCTION(glLinkProgram, LinkProgram);
    ALIAS_FUNCTION(glGetUniformLocation, GetUniform);
    ALIAS_FUNCTION(glValidateProgram, ValidateProgram);

    // uniform functions
    ALIAS_FUNCTION(glUniformMatrix4fv, Mat4Uniform);

    // object functions
    ALIAS_FUNCTION(glGenVertexArrays, VertexArrays);
    ALIAS_FUNCTION(glBindVertexArray, BindVertexArray);
    ALIAS_FUNCTION(glGenBuffers, Buffers);
    ALIAS_FUNCTION(glBindBuffer, BindBuffer);
    ALIAS_FUNCTION(glBufferData, BufferData);
    ALIAS_FUNCTION(glVertexAttribPointer, VertexAttribPointer);
    ALIAS_FUNCTION(glEnableVertexAttribArray, EnableVertexAttribArray);
    ALIAS_FUNCTION(glDrawElements, DrawElement);

    // enum
    enum Type {
        VersionMajor = GLFW_CONTEXT_VERSION_MAJOR,
        VersionMinor = GLFW_CONTEXT_VERSION_MINOR,
        OpenGLProfile = GLFW_OPENGL_PROFILE,
        OpenGLCoreProfile = GLFW_OPENGL_CORE_PROFILE,
        ColorBufferBit = GL_COLOR_BUFFER_BIT,
        ArrayBuffer = GL_ARRAY_BUFFER,
        ElementArrayBuffer = GL_ELEMENT_ARRAY_BUFFER,
        DrawStatic = GL_STATIC_DRAW,
        CompileStatus = GL_COMPILE_STATUS,
        InfoLogLength = GL_INFO_LOG_LENGTH,
    };

    enum DataType {
        False = GL_FALSE,
        Float = GL_FLOAT,
        UnsignedInt = GL_UNSIGNED_INT,
    };

    enum ObjectType {
        Triangle = GL_TRIANGLES,
        TriangleFan = GL_TRIANGLE_FAN,
    };

    enum ShaderType {
        VertexShader = GL_VERTEX_SHADER,
        FragmentShader = GL_FRAGMENT_SHADER,
    };
};

#endif