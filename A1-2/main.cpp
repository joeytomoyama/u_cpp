#include <iostream>
#include <string>
#include <cassert>

#include "vec.h"
#include "test11.h"

int main() {

    Vec<int, 2> a{{1, 2}};
    assert(a[0] == 1);

    Vec<double, 10> b{{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0}};
    assert(b[9] == 10.0);

    // std::cout << "Program ended succesfully." << std::endl;

    test_Vec();

    return 0;
} 