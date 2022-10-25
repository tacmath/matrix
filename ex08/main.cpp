#include "../Matrix.hpp"

int main (void) {
    Matrix<> m({{1., -1., 2.}, {0., -3., 1.}});

    std::cout << "trace = " << m.trace() << std::endl << "------------------" << std::endl;

    m =  Matrix<>({{1., 0.}, {0., 1.}});
    std::cout << "trace = " << m.trace() << std::endl << "------------------" << std::endl;

    m =  Matrix<>({{2., -5., 0.}, {4., 3., 7.}, {-2., 3., 4.}});
    std::cout << "trace = " << m.trace() << std::endl << "------------------" << std::endl;

     m =  Matrix<>({{-2., -8., 4.}, {1., -23., 4.}, {0., 6., 4.}});
    std::cout << "trace = " << m.trace() << std::endl;
    return (0);
}