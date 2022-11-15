#ifndef CIRCLE_SHAPE_H
#define CIRCLE_SHAPE_H

#include <shapes/Shape.h>


class Circle : public Shape {
    private:
        void create();
    
    public:
        Circle(std::vector<float> rgbaColor, float radius, float x, float y);
        ~Circle();
};

#endif