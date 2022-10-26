#include "../Matrix.hpp"

int main (void) {
    Matrix<> m({{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}});
    Matrix<> res;

    m.print();
    res = m.inverse();
    std::cout << "inverse :" << std::endl;
    res.print();
    std::cout << "------------------" << std::endl;

    m = Matrix<>({{2., 0., 0.}, {0., 2., 0.}, {0., 0., 2.}});
    m.print();
    res = m.inverse();
    std::cout << "inverse :" << std::endl;
    res.print();
    std::cout << "------------------" << std::endl;

    m = Matrix<>({{8., 5., -2.}, {4., 7., 20.}, {7., 6., 1.}});
    m.print();
    res = m.inverse();
    std::cout << "inverse :" << std::endl;
    res.print();
    std::cout << "------------------" << std::endl;

    m = Matrix<>({{4., 7.}, {2., 6.}});
    m.print();
    res = m.inverse();
    std::cout << "inverse :" << std::endl;
    res.print();
    std::cout << "------------------" << std::endl;



    m = Matrix<>({{8., 5., -2.}, {4., 7., 20.}, {7., 6., 1.}});
    m.print();
    res = m.augmented();
    std::cout << "augmented :" << std::endl;
    res.print();

    std::cout << "reduced row echelon :" << std::endl << res.row_echelon() << std::endl;
    return (0);
}