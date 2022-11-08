#ifndef OBJECT_H
#define OBJECT_H

#include <vector>

#include <types/aliases/opengl.h>
#include <types/structs/Vertex.h>


class Object {
    private:
        unsigned int vertexArr;
        unsigned int buffer;
        unsigned int elementBuffer;

        OpenGL::ObjectType type;
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;

    public:
        Object();
        Object(OpenGL::ObjectType type, std::vector<Vertex> vertices, std::vector<unsigned int> indices);
        void draw();

        ~Object();
};

#endif