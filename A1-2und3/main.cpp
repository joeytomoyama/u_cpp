#include <iostream>
#include <string>
#include <cassert>
#include <random>

#include "vec.h"
#include "test11.h"

int main() {

    Vec<int, 2> a{{1, 2}};
    assert(a[0] == 1);

    Vec<double, 10> b{{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0}};
    assert(b[9] == 10.0);

    test_Vec();

    // Aufgabe 3:
    std::cout << "Aufgabe 3: " << std::endl;
    std::random_device rd;

    std::mt19937 e2(rd());

    std::uniform_real_distribution<float> dist(0.0, 100.0);

    std::vector<Vec<float, 3>> vectors(10);

    for (Vec<float, 3>& vec : vectors) {
        vec = Vec<float, 3> {{ dist(e2), dist(e2), dist(e2) }};
    }
    vecPrinter(vectors);
    std::cout << std::endl;

    // Aufgabe 4:
    std::cout << "Aufgabe 4: " << std::endl;
    std::transform(
        vectors.begin(),
        vectors.end(),
        vectors.begin(),
        [](Vec<float, 3>& vec) { return Vec<float, 3> {{ vec[0] + 1, vec[1] + 1, vec[2] + 1 }}; }
    );
    vecPrinter(vectors);
    std::cout << std::endl;

    // Aufgabe 5:
    std::cout << "Aufgabe 5: " << std::endl;
    std::stable_partition(
        vectors.begin(),
        vectors.end(),
        [](auto& val) {
            return val.length() < 90.0;
        }
    );
    vecPrinter(vectors);
    std::cout << std::endl;

    // Aufgabe 6:
    std::cout << "Aufgabe 6: " << std::endl;
    std::sort(
        vectors.begin(),
        vectors.end(),
        [](auto& val1, auto& val2) {
            return val1.length() < val2.length();
        }
    );
    vecPrinter(vectors);
    std::cout << std::endl;

    // Aufgabe 7:
    std::cout << "Aufgabe 7: " << std::endl;
    std::cout << vectors[vectors.size() / 2][0] << std::endl;

    // Aufgabe 8:
    std::cout << "Aufgabe 8: " << std::endl;
    std::vector<Vec<float, 3>> vectorsCopy;
    vectorsCopy.reserve(10);

    std::copy_if(
        vectors.begin(),
        vectors.end(),
        std::back_inserter(vectorsCopy),
        [](auto& val) { return val.length() < 80; }
    );

    // std::cout << vectorsCopy[0][0] << std::endl;

    vecPrinter(vectorsCopy);

    // Aufgabe 9:
    std::cout << "Aufgabe 9: " << std::endl;
    auto to_be_erased = std::remove_if(
        vectors.begin(),
        vectors.end(),
        [](auto& val) { return val.length() > 90 && val.length() < 120; }
    );

    vectors.erase(to_be_erased, vectors.end());
    vecPrinter(vectors);

    return 0;
} 