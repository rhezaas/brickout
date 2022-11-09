#include "Circle.h"

#include <shapes/Shape.h>


Circle::Circle(std::vector<float> rgbaColor, float radius, float x, float y) : Shape(rgbaColor, radius, radius, x, y) {
    this->create();
}

void Circle::create() {
    // int triangles = 360;

    // std::vector<Vertex> vertices {
    //     {glm::vec3(0.0, 0.0, 0.0), glm::vec3(this->getColor()[0], this->getColor()[1], this->getColor()[2])},
    //     {glm::vec3(this->getWidth(), 0.0, 0.0), glm::vec3(this->getColor()[0], this->getColor()[1], this->getColor()[2])},
    // };

    // std::vector<std::vector<unsigned int>> indices2d = {
    //     {0, 1, 2},
    // };

    // glm::mat4 id = glm::mat4(1.0);
    // id = glm::rotate(id, glm::radians(1.0f), glm::vec3(0.0, 0.0, 1.0));

    // for (int i = 1; i < triangles; i++) {
    //     Vertex v = {(id * glm::vec4(vertices[i].position, 0.0)), glm::vec3(this->getColor()[0], this->getColor()[1], this->getColor()[2])};
    //     vertices.insert(vertices.end(), v);

    //     indices2d.insert(indices2d.end(), {0, indices2d[i-1][1] + 1, indices2d[i-1][2] + 1});
    // }

    // // debug purposes!!
    // // for (int i = 0; i < vertices.size(); i++) {
    // //     printf("index vertices %i -> ", i);
    // //     printf("{%.2f, %.2f, %.2f}\n", vertices[i].position.x, vertices[i].position.y, vertices[i].position.z);
    // // }

    // std::vector<unsigned int> indices;
    // for (int i = 0; i < indices2d.size() - 1; i++) {
    //     indices.insert(indices.end(), indices2d[i][0]);
    //     indices.insert(indices.end(), indices2d[i][1]);

    //     if (i == indices2d.size() - 1) {
    //         indices.insert(indices.end(), indices2d[i][1]);
    //         // debug purposes!!
    //         // printf("index %i -> ", i);
    //         // printf("{%i, %i, %i}\n", indices2d[i][0], indices2d[i][1], indices2d[i][1]);
    //     } else {
    //         indices.insert(indices.end(), indices2d[i][2]);
    //         // debug purposes!!
    //         // printf("index %i -> ", i);
    //         // printf("{%i, %i, %i}\n", indices2d[i][0], indices2d[i][1], indices2d[i][2]);
    //     }
    // }
    
    // indices.insert(indices.end(), indices2d[indices2d.size() - 1][1]);
    // indices.insert(indices.end(), indices2d[0][1]);

    // Shape::create(vertices, indices);
    // Shape::setModel(Math::Translate(Math::Mat4(1.0), Math::Vec3((this->getWidth() + this->getX()), -(this->getHeight() + this->getY()), 0)));
}

Circle::~Circle() {}