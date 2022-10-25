#include "../Matrix.hpp"

int main (void) {
    Matrix<> m({{1., -1., 2.}, {0., -3., 1.}});
    Matrix<> res;

    res = m.row_echelon();
    res.print();

    m = Matrix<>({{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}});
    res = m.row_echelon();
    res.print();
    
    m = Matrix<>({{1., 2.}, {3., 4.}});
    res = m.row_echelon();
    res.print();

    m = Matrix<>({{1., 2.}, {2., 4.}});
    res = m.row_echelon();
    res.print();
    return (0);
}