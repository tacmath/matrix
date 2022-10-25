#include "../Matrix.hpp"

int main (void) {
    Matrix<> m({{1., -1., 2.}, {0., -3., 1.}});
    Matrix<> res;

    res = m.row_echelon();
    res.print();
    std::cout << "-----------------" << std::endl;

    m = Matrix<>({{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}});
    res = m.row_echelon();
    res.print();
    std::cout << "-----------------" << std::endl;
    
    m = Matrix<>({{1., 2.}, {3., 4.}});
    res = m.row_echelon();
    res.print();
    std::cout << "-----------------" << std::endl;

    m = Matrix<>({{1., 2.}, {2., 4.}});
    res = m.row_echelon();
    res.print();
    std::cout << "-----------------" << std::endl;

    m = Matrix<>({{8., 5., -2., 4., 28.}, {4., 2.5, 20., 4., -4.}, {8., 5., 1., 4., 17.}});
    res = m.row_echelon();
    res.print();
    std::cout << "-----------------" << std::endl;

    m = Matrix<>({{8., 5.}, {4., 2.5}, {8., 5.}, {2., 9.}});
    res = m.row_echelon();
    res.print();
    return (0);
}