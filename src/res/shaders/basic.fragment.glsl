#version 330 core

in vec4 vertexOutputColor;
in vec2 vertexOutputTexture;

out vec4 fragmentColor;

uniform sampler2D basicTexture;

void main() {
   fragmentColor = texture(basicTexture, vertexOutputTexture);
   // fragmentColor = vertexOutputColor;
};