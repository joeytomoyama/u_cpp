#pragma once

#include <array>
// #include <string>

template<typename T, int N = 3>
class Vec {
    private:
        std::array<T, N> myArray_;

    public:
        // Constructor
        Vec(std::array<T,N> const& v = std::array<T,N>{})
            : myArray_(v)
        {}

        T& operator[] (const int& idx) {
            return myArray_[idx];
        }

        T operator[] (const int& idx) const {
            return myArray_[idx];
        }
        
        bool operator==(const Vec& rhs) const {
            bool isEqual = false;
            for (int i = 0; i < N; i++) {
                if (myArray_[i] == rhs[i]) {
                    isEqual = true;
                }
                else {
                    return false;
                }
            }
            return isEqual;
        }

        bool operator!=(const Vec& rhs) const {
            return !(*this == rhs);
        }

        Vec operator+=(const Vec& rhs) {
            for (int i = 0; i < N; i++) {
                myArray_[i] += rhs[i];
            }
            return *this;
        }

        Vec operator+(const Vec& rhs) const {
            Vec copy{*this};
            copy += rhs;
            return copy;
        }

        Vec operator-() const {
            Vec copy{*this};
            for (int i = 0; i < N; i++) {
                copy[i] = -copy[i];
            }
            return copy;
        
        }
        // std::string toString() const;
};

template<typename T, int N>
float dot(const Vec<T, N>& a, const Vec<T, N>& b) {
    float dotProduct = 0;
    for (int i = 0; i < N; i++) {
        dotProduct += a[i] * b[i];
    }
    return dotProduct;
}

// Vec<T,N>::Vec(std::array<T,N> const& v) : myArray_(v) {}