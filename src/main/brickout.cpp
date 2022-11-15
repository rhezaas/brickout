#include <iostream>
#include <vector>

#include <backend/Window.h>
#include <backend/Shader.h>
#include <backend/Texture.h>

#include <shapes/Circle.h>
#include <shapes/Rectangle.h>

#include <types/aliases/opengl.h>
#include <types/enums/WindowConstant.h>
#include <types/structs/ModelViewProjection.h>


int main(int argc, char *argv[]) {
    Window window;

    // setup window
    window.create(WindowConstant::Width, WindowConstant::Height, "Brickout");

    // add shape
    Rectangle block({1.0, 1.0, 1.0, 1.0}, 100.0, 100.0, 0.0, 0.0);

    // setup shader
    Shader shader;
    shader.addSource(OpenGL::ShaderType::VertexShader, "dist/res/shaders/basic.vertex.glsl");
    shader.addSource(OpenGL::ShaderType::FragmentShader, "dist/res/shaders/basic.fragment.glsl");
    shader.compile();

    // setup texture
    Texture brickTexture("dist/res/textures/brick.png");
    brickTexture.compile();

    // setup mvp
    MVP mvp = {
        shader.getUniform("mvp"),
        Math::Ortho(0.0, (double) WindowConstant::Width, (double) -WindowConstant::Height, 0.0, -1.0, 1.0),
        Math::Translate(Math::Mat4(1.0f), Math::Vec3(0.0, 0.0, 0.0))
    };

    // renderer
    window.render([&](OpenGL::Window *window) -> void {
        block.draw(mvp);
    });

    window.terminate();

    return 0;
}