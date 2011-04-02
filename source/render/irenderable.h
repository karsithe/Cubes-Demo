#pragma once

struct Vertex
{
    float x, y, z;

    Vertex()
        : x(0.f), y(0.f), z(0.f)
    { }

    Vertex(float _x, float _y, float _z)
        : x(_x), y(_y), z(_z)
    { }
};


class iRenderable
{
public:
    virtual void draw() = 0;
    virtual void update() = 0;

private:

};