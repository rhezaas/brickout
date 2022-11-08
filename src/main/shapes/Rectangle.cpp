#include "Rectangle.h"

#include <shapes/Shape.h>

Rectangle::Rectangle(std::vector<float> rgbColor, float width, float height, float x, float y) : Shape(rgbColor, width, height, x, y) {
    this->create();
}

void Rectangle::create() {
    std::vector<Vertex> vertices = {
        {glm::vec3( (this->getWidth() / 2),  (this->getHeight() / 2), 0.0), glm::vec3(this->getColor()[0], this->getColor()[1], this->getColor()[2])},
        {glm::vec3(-(this->getWidth() / 2),  (this->getHeight() / 2), 0.0), glm::vec3(this->getColor()[0], this->getColor()[1], this->getColor()[2])},
        {glm::vec3(-(this->getWidth() / 2), -(this->getHeight() / 2), 0.0), glm::vec3(this->getColor()[0], this->getColor()[1], this->getColor()[2])},
        {glm::vec3( (this->getWidth() / 2), -(this->getHeight() / 2), 0.0), glm::vec3(this->getColor()[0], this->getColor()[1], this->getColor()[2])},
    };

    std::vector<unsigned int> indices = {
        0, 1, 2,
        2, 3, 0,
    };

    Shape::create(vertices, indices);
}

Rectangle::~Rectangle() {}