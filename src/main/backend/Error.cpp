#include "Error.h"

#include <iostream>

#include <types/aliases/opengl.h>


Error::Error() {}

void Error::listen() {
    int contextFlag = 0;
    OpenGL::GetIntV(OpenGL::Type::ContextFlag, &contextFlag);

    if (contextFlag && OpenGL::DebugType::DebugFlag) {
        OpenGL::Enable(OpenGL::DebugType::DebugOutput);
        OpenGL::Enable(OpenGL::DebugType::DebugSyncOutput); // makes sure errors are displayed synchronously
        OpenGL::DebugMessageCallback([](
            OpenGL::GLEnum source, OpenGL::GLEnum type, unsigned int id, OpenGL::GLEnum severity, 
            OpenGL::GLSizei length, const char *message, const void *userParam
        ) -> void APIENTRY {
            if(id == 131169 || id == 131185 || id == 131218 || id == 131204) return; // ignore these non-significant error codes

            std::cout << "---------------" << std::endl;
            std::cout << "Debug message (" << id << "): " <<  message << std::endl;

            switch (source) {
                case OpenGL::DebugSource::Api:              std::cout << "Source: API"; break;
                case OpenGL::DebugSource::WindowSystem:     std::cout << "Source: Window System"; break;
                case OpenGL::DebugSource::ShaderCompiler:   std::cout << "Source: Shader Compiler"; break;
                case OpenGL::DebugSource::ThirdParty:       std::cout << "Source: Third Party"; break;
                case OpenGL::DebugSource::Application:      std::cout << "Source: Application"; break;
                case OpenGL::DebugSource::Other:            std::cout << "Source: Other"; break;
            } std::cout << std::endl;

            switch (type) {
                case OpenGL::DebugType::Error:              std::cout << "Type: Error"; break;
                case OpenGL::DebugType::Deprecated:         std::cout << "Type: Deprecated Behaviour"; break;
                case OpenGL::DebugType::Undefined:          std::cout << "Type: Undefined Behaviour"; break; 
                case OpenGL::DebugType::Portability:        std::cout << "Type: Portability"; break;
                case OpenGL::DebugType::Performance:        std::cout << "Type: Performance"; break;
                case OpenGL::DebugType::Marker:             std::cout << "Type: Marker"; break;
                case OpenGL::DebugType::PushGroup:          std::cout << "Type: Push Group"; break;
                case OpenGL::DebugType::PopGroup:           std::cout << "Type: Pop Group"; break;
                case OpenGL::DebugType::Other:              std::cout << "Type: Other"; break;
            } std::cout << std::endl;
    
            switch (severity) {
                case OpenGL::DebugSeverity::High:           std::cout << "Severity: high"; break;
                case OpenGL::DebugSeverity::Medium:         std::cout << "Severity: medium"; break;
                case OpenGL::DebugSeverity::Low:            std::cout << "Severity: low"; break;
                case OpenGL::DebugSeverity::Notification:   std::cout << "Severity: notification"; break;
            } std::cout << std::endl;

            std::cout << std::endl;
        }, nullptr);

        OpenGL::DebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
    }
}

Error::~Error() {}