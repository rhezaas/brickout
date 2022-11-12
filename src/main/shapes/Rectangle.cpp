#include "Rectangle.h"

#include <shapes/Shape.h>
#include <types/aliases/math.h>


Rectangle::Rectangle(std::vector<float> rgbaColor, float width, float height, float x, float y) : Shape(rgbaColor, width, height, x, y) {
    this->create();
}

void Rectangle::create() {
    std::vector<Vertex> vertices = {
        {
            Math::Vec3( (this->getWidth() / 2),  (this->getHeight() / 2), 0.0),                                 // position
            Math::Vec4(this->getColor()[0], this->getColor()[1], this->getColor()[2], this->getColor()[3]),     // color
            Math::Vec2(1.0, 1.0),                                                                               // texture
        },
        {
            Math::Vec3(-(this->getWidth() / 2),  (this->getHeight() / 2), 0.0),                                 // position
            Math::Vec4(this->getColor()[0], this->getColor()[1], this->getColor()[2], this->getColor()[3]),     // color
            Math::Vec2(0.0, 1.0),                                                                               // texture
        },
        {
            Math::Vec3(-(this->getWidth() / 2), -(this->getHeight() / 2), 0.0),                                 // position
            Math::Vec4(this->getColor()[0], this->getColor()[1], this->getColor()[2], this->getColor()[3]),     // color
            Math::Vec2(0.0, 0.0),                                                                               // texture
        },
        {
            Math::Vec3( (this->getWidth() / 2), -(this->getHeight() / 2), 0.0),                                 // position
            Math::Vec4(this->getColor()[0], this->getColor()[1], this->getColor()[2], this->getColor()[3]),     // color
            Math::Vec2(1.0, 0.0),                                                                               // texture
        },
    };

    std::vector<unsigned int> indices = {
        0, 1, 2,
        2, 3, 0,
    };

    Shape::create(vertices, indices);
}

Rectangle::~Rectangle() {}