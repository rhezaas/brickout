#version 330 core

in vec3 shaderOutputColor;

out vec4 fragmentColor;

void main() {
   fragmentColor = vec4(shaderOutputColor, 1.0);
};