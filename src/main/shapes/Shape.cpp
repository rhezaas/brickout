#include "Shape.h"

#include <vector>

#include <backend/Object.h>

#include <types/aliases/opengl.h>
#include <types/structs/ModelViewProjection.h>


Shape::Shape(std::vector<float> rgbaColor, float width, float height, float x, float y) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->rgbaColor = rgbaColor;

    this->model = Math::Translate(Math::Mat4(1.0), Math::Vec3(((this->width / 2) + this->x), -((this->height / 2) + this->y), 0));
}

void Shape::create(std::vector<Vertex> vertices, std::vector<unsigned int> indices) {
    this->object = Object(OpenGL::ObjectType::TriangleFan, vertices, indices);
}

void Shape::draw(MVP mvp) {
    OpenGL::Mat4Uniform(mvp.mvpUniform, 1, OpenGL::DataType::False, Math::ValuePtr(mvp.projection * mvp.view * this->model));

    this->object.draw();
}

void Shape::setX(float x) {
    this->x = x;
}

void Shape::setY(float y) {
    this->y = y;
}

void Shape::setWidth(float width) {
    this->width = width;
}

void Shape::setHeight(float height) {
    this->height = height;
}

void Shape::setColor(std::vector<float> rgbaColor) {
    this->rgbaColor = rgbaColor;
}

float Shape::getX() {
    return this->x;
}

float Shape::getY() {
    return this->y;
}

float Shape::getWidth() {
    return this->width;
}

float Shape::getHeight() {
    return this->height;
}

std::vector<float> Shape::getColor() {
    return this->rgbaColor;
}

void Shape::setModel(Math::Mat4 model) {
    this->model = model;
}

Math::Mat4 Shape::getModel() {
    return this->model;
}

Shape::~Shape() {}