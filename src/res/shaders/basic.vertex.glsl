#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;
layout (location = 2) in vec2 texture;

out vec4 vertexOutputColor;
out vec2 vertexOutputTexture;

uniform mat4 mvp;

void main() {
    // position
    gl_Position = mvp * vec4(position, 1.0);
    
    // color
    vertexOutputColor = color;

    // texture
    vertexOutputTexture = texture;
}