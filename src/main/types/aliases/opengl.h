#ifndef OPENGL_H
#define OPENGL_H

#define GL_GLEXT_PROTOTYPES

#include "macro.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <GL/glext.h>

namespace OpenGL {
    // classes | types
    using Monitor = GLFWmonitor;
    using Window = GLFWwindow;
    using GladLoadProc = GLADloadproc;
    using GLEnum = GLenum;
    using GLSizei = GLsizei;

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
    ALIAS_FUNCTION(glEnable, Enable);
    ALIAS_FUNCTION(glDebugMessageCallback, DebugMessageCallback);
    ALIAS_FUNCTION(glDebugMessageControl, DebugMessageControl);

    // get data functions
    ALIAS_FUNCTION(glGetIntegerv, GetIntV);

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

    // texture functions
    ALIAS_FUNCTION(glTexImage2D, Image2D);
    ALIAS_FUNCTION(glGenTextures, Textures);
    ALIAS_FUNCTION(glBindTexture, BindTexture);
    ALIAS_FUNCTION(glTexParameteri, TextureFilter);
    ALIAS_FUNCTION(glActiveTexture, ActiveTexture);
    ALIAS_FUNCTION(glGenerateMipmap, GenerateMipmap);

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
        ContextFlag = GL_CONTEXT_FLAGS,
        Debug = GLFW_OPENGL_DEBUG_CONTEXT,
    };

    enum DebugType {
        DebugFlag = GL_CONTEXT_FLAG_DEBUG_BIT,
        DebugOutput = GL_DEBUG_OUTPUT,
        DebugSyncOutput = GL_DEBUG_OUTPUT_SYNCHRONOUS,
        Error = GL_DEBUG_TYPE_ERROR,
        Deprecated = GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR,
        Undefined = GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR,
        Portability = GL_DEBUG_TYPE_PORTABILITY,
        Performance = GL_DEBUG_TYPE_PERFORMANCE,
        Marker = GL_DEBUG_TYPE_MARKER,
        PushGroup = GL_DEBUG_TYPE_PUSH_GROUP,
        PopGroup = GL_DEBUG_TYPE_POP_GROUP,
        Other = GL_DEBUG_TYPE_OTHER,
    };

    enum DebugSource {
        Api = GL_DEBUG_SOURCE_API,
        WindowSystem = GL_DEBUG_SOURCE_WINDOW_SYSTEM,
        ShaderCompiler = GL_DEBUG_SOURCE_SHADER_COMPILER,
        ThirdParty= GL_DEBUG_SOURCE_THIRD_PARTY,
        Application = GL_DEBUG_SOURCE_APPLICATION,
        OtherSource = GL_DEBUG_SOURCE_OTHER,
    };

    enum DebugSeverity {
        High = GL_DEBUG_SEVERITY_HIGH,
        Medium = GL_DEBUG_SEVERITY_MEDIUM,
        Low = GL_DEBUG_SEVERITY_LOW,
        Notification = GL_DEBUG_SEVERITY_NOTIFICATION,
    };

    enum DataType {
        False = GL_FALSE,
        Float = GL_FLOAT,
        UnsignedInt = GL_UNSIGNED_INT,
        UnsignedByte = GL_UNSIGNED_BYTE,
    };

    enum ObjectType {
        Triangle = GL_TRIANGLES,
        TriangleFan = GL_TRIANGLE_FAN,
    };

    enum ShaderType {
        VertexShader = GL_VERTEX_SHADER,
        FragmentShader = GL_FRAGMENT_SHADER,
    };

    enum TextureType {
        Texture2D = GL_TEXTURE_2D,
        MinFilter = GL_TEXTURE_MIN_FILTER,
        MagFilter = GL_TEXTURE_MAG_FILTER,
        WrapX = GL_TEXTURE_WRAP_S,
        WrapY = GL_TEXTURE_WRAP_T,
        MipMapLinear = GL_LINEAR_MIPMAP_LINEAR,
        Linear = GL_LINEAR,
        Repeat = GL_REPEAT,
        Unit0 = GL_TEXTURE0,
    };

    enum ColorType {
        RGBA = GL_RGBA,
    };
};

#endif