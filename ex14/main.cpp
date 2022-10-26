#include "../Matrix.hpp"

int main (void) {
    Matrix<> proj;

    proj = perspective(45.0f, 1.2f, 0.1f, 100.0f);
    std::cout << "projection:" << std::endl << proj;
    return (0);
}