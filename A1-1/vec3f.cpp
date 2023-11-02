#include "vec3f.h"

Vec3f::Vec3f(float x, float y, float z)
    : myArray_{x, y, z}
{}

float& Vec3f::operator[] (int idx)
{
    return myArray_[idx];
}

float Vec3f::operator[] (int idx) const
{
    return myArray_[idx];
}

bool Vec3f::operator== (const Vec3f& rhs) const
{
    return
        myArray_[0] == rhs[0] &&
        myArray_[1] == rhs[1] &&
        myArray_[2] == rhs[2];
}

bool Vec3f::operator!= (const Vec3f& rhs) const
{
    return !(*this == rhs);
}