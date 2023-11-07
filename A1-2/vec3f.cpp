#include <string>
#include <sstream>

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

Vec3f Vec3f::operator+ (const Vec3f& rhs) const
{
    Vec3f copy{*this};
    copy += rhs;
    return copy;
}

Vec3f Vec3f::operator+= (const Vec3f& rhs)
{
    myArray_[0] += rhs[0];
    myArray_[1] += rhs[1];
    myArray_[2] += rhs[2];
    return *this;
}

std::string Vec3f::toString() const
{
    std::stringstream ss;
    ss << "{ " << myArray_[0] << ", " << myArray_[1] << ", " << myArray_[2] << " }";
    return ss.str();
}

Vec3f Vec3f::operator-() const
{
    return Vec3f{-myArray_[0], -myArray_[1], -myArray_[2]};
}

float dot(const Vec3f& a, const Vec3f& b)
{
    return a[0] * b[0]
        + a[1] * b[1]
        + a[2] * b[2];
}