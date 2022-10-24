#include "../Vector.hpp"

int main (void) {
    Vector<float> v1({2.3, 3.});
    Vector<float> v2({1.0, -6.});
    Vector<> res;
    Vector<Vector<float>> t1({v1, v2});
    Vector<float> t2({0.1f, 5.0f});

    res = linear_combination(t1, t2);
    res.print();

    std::cout << "------------------" << std::endl;
    Vector<> e1({1., 0., 0.});
    Vector<> e2({0., 1., 0.});
    Vector<> e3 ({0., 0., 1.});
    Vector<Vector<float>> list({e1, e2, e3});
    res = linear_combination(list, Vector<>({10., -2., 0.5}));
    res.print();
    std::cout << "------------------" << std::endl;
    v1 = {1., 2., 3.};
    v2 = {0., 10., -100.};
    list = {v1, v2};
    res = linear_combination(list, Vector<>({10., -2.}));
    res.print();
    list.resize(0);
    try {
    res = linear_combination(list, Vector<>({10., -2.}));
    res.print();
    }
    catch (std::logic_error error) {
        std::cout << "error catched" << std::endl;
    }
    return (0);
}