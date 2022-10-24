#include "../Vector.hpp"

int main (void) {
    Vector<> u({0., 0., 1.});
    Vector<> v({1., 0., 0.});
    Vector<> res;


    res = cross_product(u, v);
    res.print();
    std::cout << "------------------" << std::endl;

    u = Vector<>({1., 2., 3.});
    v = Vector<>({4., 5., 6.});
    res = cross_product(u, v);
    res.print();
    std::cout << "------------------" << std::endl;

    u = Vector<>({4., 2., -3.});
    v = Vector<>({-2., -5., 16.});
     res = cross_product(u, v);
    res.print();
    std::cout << "------------------" << std::endl;
    return (0);
}