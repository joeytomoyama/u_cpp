#include <iostream>
#include <string>
#include <cassert>

#include "vec3f.h"
#include "test11.h"

int main() {
    Vec3f a{1, 2, 3};
    a[1] = 5;
    // std::cout << a[1] << std::endl;
    assert(a[1] == 5);

    Vec3f b{};
    // std::cout << b[1] << std::endl;
    assert(b[1] == 0);

    const Vec3f c{1, 2, 3};
    auto f = c[1];
    // std::cout << f << std::endl;
    assert(f == 2);

    assert((a == c) == 0);
    assert((a != c) == 1);
    a[1] = 2;
    assert((a == c) == 1);
    assert((a != c) == 0);

    // + and +=
    Vec3f d = a + c;
    assert((d == Vec3f{2, 4, 6}) == 1);
    a += c;
    assert((a == Vec3f{2, 4, 6}) == 1);

    // unary -
    Vec3f e = -d;
    assert((e == Vec3f{-2, -4, -6}) == 1);

    std::cout << dot(a, b) << std::endl;

    test_Vec3f();

    return 0;
} 