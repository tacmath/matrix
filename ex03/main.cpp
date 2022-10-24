#include "../Vector.hpp"

int main (void) {
    Vector<> u({0., 0.});
    Vector<> v({1., 1.});


    std::cout << "dot = " << u.dot(v) << std::endl;
    std::cout << "------------------" << std::endl;
    u = Vector<>({1., 1.});
    std::cout << "dot = " << u.dot(v) << std::endl;
    std::cout << "------------------" << std::endl;
    u = Vector<>({-1., 6.});
    v = Vector<>({3., 2.});
    std::cout << "dot = " << u.dot(v) << std::endl;
    return (0);
}