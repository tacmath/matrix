#include "../Vector.hpp"
#include "../Matrix.hpp"

int main (void) {
    Vector<> v1({2.3, 3.});
    Vector<> v2(v1);
    Matrix<> m1({{2.3, 3., 5.}, {2.3, 3., 0.}});
    Matrix<> m2(m1);
    

    v1.print();
    v1 += v1 + v2 - v1;
    v1.print();
    v1 /= 2;
    v1.print();
    v1 *= 2;
    v1.print();
    m1.print();
    m2[1][2] = 3;
    m1 += m1 + m2 - m1;
    m1.print();
    m1 /= 2;
    m1.print();
    m1 *= 2;
    m1.print();
    return (0);
}