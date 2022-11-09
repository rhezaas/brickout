#version 330 core

in vec4 shaderOutputColor;

out vec4 fragmentColor;

void main() {
   fragmentColor = shaderOutputColor;
};