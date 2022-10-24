#include "../Vector.hpp"

int main (void) {
    Vector<> u({0., 0., 0.});


    std::cout << "morm_1 = " << u.norm_1() << " morm = " << u.norm() << " morm_inf = " << u.norm_inf() << std::endl;
    std::cout << "------------------" << std::endl;
    u = Vector<>({1., 2., 3.});
    std::cout << "morm_1 = " << u.norm_1() << " morm = " << u.norm() << " morm_inf = " << u.norm_inf() << std::endl;
    std::cout << "------------------" << std::endl;
    u = Vector<>({-1., -2.});
    std::cout << "morm_1 = " << u.norm_1() << " morm = " << u.norm() << " morm_inf = " << u.norm_inf() << std::endl;
    return (0);
}