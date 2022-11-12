#include "Object.h"

#include <types/aliases/opengl.h>
#include <types/structs/Vertex.h>


Object::Object() {};

Object::Object(OpenGL::ObjectType type, std::vector<Vertex> vertices, std::vector<unsigned int> indices) {
    this->type = type;
    this->vertices = vertices;
    this->indices = indices;

    // setup vertex array
    OpenGL::VertexArrays(1, &this->vertexArr);
    OpenGL::BindVertexArray(this->vertexArr);

    // setup array buffer
    OpenGL::Buffers(1, &this->buffer);
    OpenGL::BindBuffer(OpenGL::Type::ArrayBuffer, this->buffer);
    OpenGL::BufferData(OpenGL::Type::ArrayBuffer, this->vertices.size() * sizeof(Vertex), &this->vertices[0], OpenGL::Type::DrawStatic);

    // set element buffer
    OpenGL::Buffers(1, &this->elementBuffer);
    OpenGL::BindBuffer(OpenGL::Type::ElementArrayBuffer, this->elementBuffer);
    OpenGL::BufferData(OpenGL::Type::ElementArrayBuffer, this->indices.size() * sizeof(this->indices), &this->indices[0], OpenGL::Type::DrawStatic);

    // position
    OpenGL::VertexAttribPointer(0, 3, OpenGL::DataType::Float, OpenGL::DataType::False, sizeof(Vertex), (void*)(offsetof(Vertex, position)));
    OpenGL::EnableVertexAttribArray(0);

    // color
    OpenGL::VertexAttribPointer(1, 4, OpenGL::DataType::Float, OpenGL::DataType::False, sizeof(Vertex), (void*)(offsetof(Vertex, rgbaColor)));
    OpenGL::EnableVertexAttribArray(1);

    // texture
    OpenGL::VertexAttribPointer(2, 2, OpenGL::DataType::Float, OpenGL::DataType::False, sizeof(Vertex), (void*)(offsetof(Vertex, texture)));
    OpenGL::EnableVertexAttribArray(2);

    // unbind
    OpenGL::UseProgram(0);
    OpenGL::BindVertexArray(0);
    OpenGL::BindBuffer(OpenGL::Type::ArrayBuffer, 0);
    OpenGL::BindBuffer(OpenGL::Type::ElementArrayBuffer, 0);
}

void Object::draw() {
    OpenGL::BindVertexArray(this->vertexArr);
    OpenGL::DrawElement(this->type, static_cast<unsigned int>(this->indices.size()), OpenGL::DataType::UnsignedInt, (void*) 0);
}

Object::~Object() {};