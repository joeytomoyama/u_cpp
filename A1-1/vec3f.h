#pragma once

#include <array>

class Vec3f {
    public: 
        Vec3f(float x = 0, float y = 0, float z = 0);

        float& operator[] (int idx);
        float operator[] (int idx) const;
        bool operator== (const Vec3f& rhs) const;
        bool operator!= (const Vec3f& rhs) const;
        
    private:
        std::array<float, 3> myArray_;
};