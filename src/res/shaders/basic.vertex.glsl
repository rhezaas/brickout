#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;

out vec4 shaderOutputColor;

uniform mat4 mvp;

void main() {
    // position
    gl_Position = mvp * vec4(position, 1.0);
    
    // color
    shaderOutputColor = color;
}