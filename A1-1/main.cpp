#include <iostream>

#include "vec3f.h"

int main() {
    Vec3f a{1, 2, 3};
    a[1] = 5;
    std::cout << a[1] << std::endl;

    Vec3f b{};
    std::cout << b[1] << std::endl;

    const Vec3f c{1, 2, 3};
    auto f = c[1];
    std::cout << f << std::endl;

    std::cout << (a == c) << std::endl;
    std::cout << (a != c) << std::endl;
    a[1] = 2;
    std::cout << (a == c) << std::endl;
    std::cout << (a != c) << std::endl;

    return 0;
}