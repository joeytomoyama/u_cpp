#pragma once

#include <array>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iostream>
#include <iterator>

// using namespace std;

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
            int i = 0;
            return std::all_of(myArray_.begin(), myArray_.end(), [&rhs, &i](T val) {
                return val == rhs[i++];
            });
        }

        bool operator!=(const Vec& rhs) const {
            return !(*this == rhs);
        }

        Vec operator+=(const Vec& rhs) {
            std::transform(
                myArray_.begin(),
                myArray_.end(),
                rhs.begin(),
                myArray_.begin(),
                [](T lhs, T rhs) { return lhs + rhs; }
            );
            return *this;
        }

        Vec operator+(const Vec& rhs) const {
            Vec copy{*this};
            copy += rhs;
            return copy;
        }

        Vec operator-() const {
            Vec copy{*this};
            std::transform(
                copy.begin(),
                copy.end(),
                copy.begin(),
                [](T val){ return -val; }
            );
            return copy;
        
        }

        auto begin() { return myArray_.begin(); }
        auto end() { return myArray_.end(); }

        auto begin() const { return myArray_.begin(); }
        auto end() const { return myArray_.end(); }
        // std::string toString() const;

        double length() const {
            std::array<T, N> squares;
            std::transform(
                myArray_.begin(),
                myArray_.end(),
                squares.begin(),
                [](T val) { return val * val; }
            );
            return std::sqrt(
                std::accumulate(squares.begin(), squares.end(), T(0))
            );
        }
};

template<typename T, int N>
float dot(const Vec<T, N>& a, const Vec<T, N>& b) {
    return std::inner_product(a.begin(), a.end(), b.begin(), 0.0f);
}

template<typename Container>
void vecPrinter(const Container& vecs) {
    for (const auto& vec : vecs) {
        std::cout <<
            vec[0] <<
            ", " <<
            vec[1] <<
            ", " <<
            vec[2] <<
            ", l: " <<
            vec.length() <<
        std::endl;
    }
}