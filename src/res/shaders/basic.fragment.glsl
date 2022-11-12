#version 330 core

in vec4 shaderOutputColor;
in vec2 shaderOutputTexture;

out vec4 fragmentColor;

uniform sampler2D basicTexture;

void main() {
   fragmentColor = texture(basicTexture, shaderOutputTexture) * shaderOutputColor;
};