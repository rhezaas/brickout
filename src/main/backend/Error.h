#ifndef OBJECT_H
#define OBJECT_H

#include <vector>

#include <types/aliases/opengl.h>
#include <types/structs/Vertex.h>


class Error {
    public:
        Error();
        void listen();

        ~Error();
};

#endif