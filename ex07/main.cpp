#include "../Matrix.hpp"

int main (void) {
    Matrix<> u({{1., -1., 2.}, {0., -3., 1.}});
    Vector<> v({2., 1., 0.5});
    Vector<> res;

    res = u * v;
    res.print();
    std::cout << "------------------" << std::endl;

    u = Matrix<>({{1., 0.}, {0., 1.}});
    v = Vector<>({4., 2.});
    res = u * v;
    res.print();
    std::cout << "------------------" << std::endl;

    u = Matrix<>({{2., 0.}, {0., 2.}});
    res = u * v;
    res.print();
    std::cout << "------------------" << std::endl;

    u = Matrix<>({{2., -2.}, {-2., 2.}});
    res = u * v;
    res.print();
    std::cout << "------------------" << std::endl;

    u = Matrix<>({{0., 4., -2}, {-4., -3., 0.}});
    Matrix<> m({{0., 1.}, {1., -1.}, {2., 3.}});
    Matrix<> rem;
    rem = u * m;
    rem.print();
    std::cout << "------------------" << std::endl;

    u *= m;
    u *= u * u * u;
    u.print();
    std::cout << "------------------" << std::endl;

    u = Matrix<>({{1., 0.}, {0., 1.}});
    m = Matrix<>({{1., 0.}, {0., 1.}});
    rem = u * m;
    rem.print();
    std::cout << "------------------" << std::endl;

    m = Matrix<>({{2., 1.}, {4., 2.}});
    rem = u * m;
    rem.print();
    std::cout << "------------------" << std::endl;

    u = Matrix<>({{3., -5.}, {6., 8.}});
    rem = u * m;
    rem.print();


    return (0);
}