#include "../Vector.hpp"

int main (void) {
    Vector<float> v1({2.3, 3.});
    Vector<float> v2({1.0, -6.});
    Vector<> res;
    Vector<Vector<float>> t1({v1, v2});
    Vector<float> t2({0.1f, 5.0f});
    

    v1.print();
    res = linear_combination(t1, t2);
    res.print();
    return (0);
}