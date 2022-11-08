#ifndef SHAPE_H
#define SHAPE_H

#include <vector>

#include <backend/Object.h>

#include <types/aliases/math.h>
#include <types/structs/ModelViewProjection.h>

class Shape {
    private:
        float x;
        float y;
        float width;
        float height;

        Object object;

        Math::Mat4 model;
        std::vector<float> rgbColor;

    protected:
        void create(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
        void setModel(Math::Mat4 model);
        Math::Mat4 getModel();

    public:
        Shape(std::vector<float> rgbColor, float width, float height, float x, float y);
        void draw(MVP mvp);
        
        void setX(float x);
        void setY(float y);
        void setWidth(float width);
        void setHeight(float height);
        void setColor(std::vector<float> rgbColor);

        float getX();
        float getY();
        float getWidth();
        float getHeight();

        std::vector<float> getColor();
        ~Shape();
};

#endif