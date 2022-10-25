#include "../Matrix.hpp"

int main (void) {
    Matrix<> m({{1., -1.}, {0., -3.}});

    std::cout << "determinant : " << m.determinant() << std::endl << "------------------" << std::endl;

    m = Matrix<>({{1., 6., 8.}, {3., 2., 9.}, {20, 60, 3}});

    std::cout << "determinant : " << m.determinant() << std::endl << "------------------" << std::endl;

    m = Matrix<>({{1., -1.}, {-1., 1.}});
    std::cout << "determinant : " << m.determinant() << std::endl << "------------------" << std::endl;

    m = Matrix<>({{2., 0., 0.}, {0., 2., 0.}, {0., 0., 2}});
    std::cout << "determinant : " << m.determinant() << std::endl << "------------------" << std::endl;

    m = Matrix<>({{8., 5., -2.}, {4., 7., 20.}, {7., 6., 1.}});
    std::cout << "determinant : " << m.determinant() << std::endl << "------------------" << std::endl;

    m = Matrix<>({{8., 5., -2., 4.}, {4., 2.5, 20., 4.}, {8., 5., 1., 4.}, {28., -4., 17., 1.}});
    std::cout << "determinant : " << m.determinant() << std::endl << "------------------" << std::endl;

    m = Matrix<>(0, 0);
    std::cout << "determinant : " << m.determinant() << std::endl << "------------------" << std::endl;;

    m = Matrix<>(1, 1);
    m[0][0] = 10;
    std::cout << "determinant : " << m.determinant() << std::endl;
    return (0);
}