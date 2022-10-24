#include "../Vector.hpp"
#include "../Matrix.hpp"

int main (void) {
    Vector<> v1({2.3, 3.});
    Vector<> v2({1.0, -6.});
    Vector<> t1(1);
    Vector<> t2(1);
    Vector<> res;

    res = lerp(v1, v2, 0.5);
    res.print();
    std::cout << "------------------" << std::endl;
    t1[0] = 0;
    t2[0] = 1;
    res = lerp(t1, t2, 0.);
    res.print();
    std::cout << "------------------" << std::endl;
    res = lerp(t1, t2, 1.);
    res.print();
    std::cout << "------------------" << std::endl;
    res = lerp(t1, t2, 0.5);
    res.print();
    std::cout << "------------------" << std::endl;
    t1[0] = 21.;
    t2[0] = 42.;
    res = lerp(t1, t2, 0.3);
    res.print();
    std::cout << "------------------" << std::endl;
    res = lerp(Vector<>({2., 1.}), Vector<>({4., 2.}), 0.3);
    res.print();
    std::cout << "------------------" << std::endl;
    Matrix<> mat;
    mat = lerp(Matrix<>({{2., 1.}, {3., 4.}}), Matrix<>({{20., 10.}, {30., 40.}}), 0.5);
    mat.print();
    return (0);
}