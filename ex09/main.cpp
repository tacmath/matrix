#include "../Matrix.hpp"

int main (void) {
    Matrix<> m({{1., -1., 2.}, {0., -3., 1.}});
    Matrix<> res;

    m.print();
    res = m.transpose();
    std::cout << "transpose :" << std::endl;
    res.print();
    std::cout << "------------------" << std::endl;

    m = Matrix<>({{1., 6., 8.}, {3., 2., 9.}, {20, 60, 3}});
    m.print();
    res = m.transpose();
    std::cout << "transpose :" << std::endl;
    res.print();
    std::cout << "------------------" << std::endl;

    m = Matrix<>({{1., 6.}, {3., 2.}});
    m.print();
    res = m.transpose();
    std::cout << "transpose :" << std::endl;
    res.print();


    return (0);
}