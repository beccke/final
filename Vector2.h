#pragma once
class Vector2
{
public:

    float x;
    float y;
    float z;

    void SetX(float x);
    void SetY(float y);
    void SetZ(float z);

    float GetX();
    float GetY();
    float GetZ();

    Vector2 operator+(Vector2 a);
    Vector2 operator-(Vector2 a);
    Vector2 operator*(float a);
    float  operator*(Vector2 b2);
    float Norm();

    Vector2();
    Vector2(float x, float y);
    Vector2(float x, float y, float z);
    Vector2 Unit();
};

