#ifndef RECT_SHAPE_H
#define RECT_SHAPE_H

#include <shapes/Shape.h>


class Rectangle : public Shape {
    private:
        void create();
    
    public:
        Rectangle(std::vector<float> rgbaColor, float width, float height, float x, float y);
        ~Rectangle();
};

#endif