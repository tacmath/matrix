#include "../Vector.hpp"

int main (void) {
    Vector<> u({1., 0.});
    Vector<> v({1., 0.});


    std::cout << "cos_angle = " << angle_cos(u, v) << std::endl << "------------------" << std::endl;

    v = Vector<>({0., 1.});
    std::cout << "cos_angle = " << angle_cos(u, v) << std::endl << "------------------" << std::endl;

    u = Vector<>({-1., 1.});
    v = Vector<>({1., -1.});
    std::cout << "cos_angle = " << angle_cos(u, v) << std::endl << "------------------" << std::endl;

    u = Vector<>({2., 1.});
    v = Vector<>({4., 2.});
    std::cout << "cos_angle = " << angle_cos(u, v) << std::endl << "------------------" << std::endl;

    u = Vector<>({1., 2., 3.});
    v = Vector<>({4., 5., 6.});
    std::cout << "cos_angle = " << angle_cos(u, v) << std::endl;
    return (0);
}