#include "../Matrix.hpp"

int main (void) {
    Matrix<> m({{1., -1., 2.}, {0., -3., 1.}});
    m.print();
    std::cout << "rank = " <<  m.rank() << std::endl << "-----------------" << std::endl;

    m = Matrix<>({{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}});
    m.print();
    std::cout << "rank = " <<  m.rank() << std::endl << "-----------------" << std::endl;
    
    m = Matrix<>({{1., 2.}, {3., 4.}});
    m.print();
    std::cout << "rank = " <<  m.rank() << std::endl << "-----------------" << std::endl;

    m = Matrix<>({{1., 2.}, {2., 4.}});
    m.print();
    std::cout << "rank = " <<  m.rank() << std::endl << "-----------------" << std::endl;

    m = Matrix<>({{8., 5., -2., 4., 28.}, {4., 2.5, 20., 4., -4.}, {8., 5., 1., 4., 17.}});
    m.print();
    std::cout << "rank = " <<  m.rank() << std::endl << "-----------------" << std::endl;

    m = Matrix<>({{8., 5.}, {4., 2.5}, {8., 5.}, {2., 9.}});
    m.print();
    std::cout << "rank = " <<  m.rank() << std::endl << "-----------------" << std::endl;

    m = Matrix<>({{1., 2., 0., 0.}, { 2., 4., 0., 0.}, {-1., 2., 1., 1.}});
    m.print();
    std::cout << "rank = " <<  m.rank() << std::endl << "-----------------" << std::endl;

    m = Matrix<>({{8., 5., -2.}, {4., 7., 20.}, {7., 6., 1.}, {21., 18., 7.}});
    m.print();
    std::cout << "rank = " <<  m.rank() << std::endl;
    return (0);
}