#pragma once

#include <array>

class Vec3f {
    public: 
        Vec3f(float x = 0, float y = 0, float z = 0);

        float& operator[] (const int& idx);
        float operator[] (int idx) const;
        bool operator==(const Vec3f& rhs) const;
        bool operator!=(const Vec3f& rhs) const;
        Vec3f operator+(const Vec3f& rhs) const;
        Vec3f operator+=(const Vec3f& rhs);
        Vec3f operator-() const;
        std::string toString() const;
        
    private:
        std::array<float, 3> myArray_;
};

float dot(const Vec3f& a, const Vec3f& b);