#pragma once

#include <array>
// #include <string>

template<typename T, int N = 3>
class Vec {
    private:
        std::array<T, N> myArray_;

    public:
        // Constructor
        Vec(std::array<T,N> const& v)
            : myArray_(v)
        {}

        T& operator[] (const int& idx) {
            return myArray_[idx];
        }
        // float operator[] (int idx) const;
        // bool operator==(const Vec3f& rhs) const;
        // bool operator!=(const Vec3f& rhs) const;
        // Vec3f operator+(const Vec3f& rhs) const;
        // Vec3f operator+=(const Vec3f& rhs);
        // Vec3f operator-() const;
        // std::string toString() const;
};

// float dot(const Vec& a, const Vec& b);

// Vec<T,N>::Vec(std::array<T,N> const& v) : myArray_(v) {}