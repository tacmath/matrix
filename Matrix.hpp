#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iostream>
#include <vector>
#include "Vector.hpp"


template <typename T = float>
struct Matrix : public std::vector<Vector<T>>
{
        Matrix(void) {}
        Matrix(size_t height, size_t width) {
            if (!height || !width)
                return;
            this->resize(height);
		    for (unsigned y = 0; y < height; ++y) {
                (*this)[y].resize(width);
                for (unsigned x = 0; x < width; ++x)
			        (*this)[y][x] = 0;
            }
        }
        Matrix(const Matrix<T> & matrix) {
			(*this) = matrix;
        }
        Matrix(const std::vector<std::vector<T>> & matrix) {
			(*this) = matrix;
		}

        Matrix &operator=(const std::vector<std::vector<T>> & rhs) {
            unsigned width;

            this->resize(rhs.size());
            width = rhs[0].size();
		    for (unsigned y = 0; y < this->size(); ++y) {
                if (width != rhs[y].size())
                    throw std::logic_error("Matrix format is invalid");
                (*this)[y].resize(width);
                for (unsigned x = 0; x < width; ++x)
			        (*this)[y][x] = rhs[y][x];
            }
            return (*this);
        }

        Matrix &operator=(const Matrix<T> & rhs) {
            unsigned width;

            width = rhs.width();
            this->resize(rhs.size());
		    for (unsigned y = 0; y < this->size(); ++y) {
                (*this)[y].resize(width);
                for (unsigned x = 0; x < width; ++x)
			        (*this)[y][x] = rhs[y][x];
            }
            return (*this);
        }

        Matrix operator+(const Matrix<T> & rhs) {
            Matrix result(*this);

            if (result.height() != rhs.height() || result.width() != rhs.width())
                    throw std::logic_error("Operation cannot be performed by Matrix of different shapes");
		    for (unsigned y = 0; y < result.height(); ++y)
                for (unsigned x = 0; x < result.width(); ++x)
			        result[y][x] += rhs[y][x];
            return (result);
        }

        Matrix operator-(const Matrix<T> & rhs) {
            Matrix result(*this);

            if (result.height() != rhs.height() || result.width() != rhs.width())
                    throw std::logic_error("Operation cannot be performed by Matrix of different shapes");
		    for (unsigned y = 0; y < result.height(); ++y)
                for (unsigned x = 0; x < result.width(); ++x)
			        result[y][x] -= rhs[y][x];
            return (result);
        }

        Matrix operator*(const T rhs) const {
            Matrix result(*this);

            for (unsigned y = 0; y < result.height(); ++y)
                for (unsigned x = 0; x < result.width(); ++x)
			        result[y][x] *= rhs;
            return (result);
        }

        Matrix operator/(const T rhs) const {
            Matrix result(*this);

            for (unsigned y = 0; y < result.height(); ++y)
                for (unsigned x = 0; x < result.width(); ++x)
			        result[y][x] /= rhs;
            return (result);
        }

        Vector<T> operator*(const Vector<T> & rhs) const {
            Vector<T> result(this->size());

            if (this->width() != rhs.size())
                throw std::logic_error("Matrice width and Vector size are not the same");
            for (unsigned y = 0; y < this->height(); ++y)
                for (unsigned x = 0; x < this->width(); ++x)
			        result[y] += (*this)[y][x] * rhs[x];
            return (result);
        }

        Matrix operator*(const Matrix<T> & rhs) const {
            Matrix result(this->height(), rhs.width());
            
            if (this->width() != rhs.height() || this->height() != rhs.width())
                throw std::logic_error("Matrices shapes are not usable for multiplication");
            for (unsigned v = 0; v < rhs.width(); ++v)
                for (unsigned y = 0; y < this->height(); ++y)
                    for (unsigned x = 0; x < rhs.height(); ++x)
			            result[y][v] += (*this)[y][x] * rhs[x][v];
            return (result);
        }

        T trace(void) {
            T result;
            size_t size;

            size = (this->width() > this->height()) ? this->height() : this->width();
            result = 0;
            for (unsigned n = 0; n < size; ++n)
                result += (*this)[n][n];
            return (result); 
        }

        Matrix transpose(void) {
            Matrix result(this->width(), this->height());

            for (unsigned y = 0; y < this->height(); ++y)
                for (unsigned x = 0; x < this->width(); ++x)
			        result[x][y] += (*this)[y][x];
            return (result); 
        }
        
        void swap_row(unsigned n, unsigned m) {
            std::vector<T> tmp;

            tmp = (*this)[n];
            (*this)[n] = (*this)[m];
            (*this)[m] = tmp;
        }
        
        Matrix row_echelon(void) {
            Matrix result(*this);
            unsigned row;
            
            for (unsigned n = 0; n < this->height(); n++) {
                row = n;
                if (result[row][n] != 1)
                    for (unsigned m = 0; m < this->height(); m++)
                        if (result[m][n]) {
                            swap_row(0, m);
                            break ;
                        }
                result[row] *= 1.0f / result[row][n];

                for (unsigned m = row + 1; m < this->height(); m++) {
                    if (result[m][n])
                        result[m] -=  result[row] * result[m][n];
                }
            }
            return (result);
        }

        T determinant(void) {           //change it
            T result;
            size_t size;

            if (this->width() != this->height() || this->height() > 4)
                throw std::logic_error("Matrice shape is not a square or its dimention is higher than 4");
            size = this->height();
            if (!size)
                return (0);
            if (size == 1)
                return ((*this)[0][0]);
            if (size == 2)
                return ((*this)[0][0] * (*this)[1][1] - (*this)[1][0] * (*this)[0][1]);
            if (size == 3)
                return (mat3Determinant(*this));
            result = 0;
            Matrix test({{(*this)[1][1], (*this)[1][2], (*this)[1][3]}, {(*this)[2][1], (*this)[2][2], (*this)[2][3]}, {(*this)[3][1], (*this)[3][2], (*this)[3][3]}});
            result += (*this)[0][0] * mat3Determinant(test);
            test = Matrix({{(*this)[1][0], (*this)[1][2], (*this)[1][3]}, {(*this)[2][0], (*this)[2][2], (*this)[2][3]}, {(*this)[3][0], (*this)[3][2], (*this)[3][3]}});
            result += -(*this)[0][1] * mat3Determinant(test);
            test = Matrix({{(*this)[1][0], (*this)[1][1], (*this)[1][3]}, {(*this)[2][0], (*this)[2][1], (*this)[2][3]}, {(*this)[3][0], (*this)[3][1], (*this)[3][3]}});
            result += (*this)[0][2] * mat3Determinant(test);
            test = Matrix({{(*this)[1][0], (*this)[1][1], (*this)[1][2]}, {(*this)[2][0], (*this)[2][1], (*this)[2][2]}, {(*this)[3][0], (*this)[3][1], (*this)[3][2]}});
            result += -(*this)[0][3] * mat3Determinant(test);
            return (result);
        }

        Matrix inverse(void) {                  // besoin de creer une matrice de cofactor
            size_t size = this->height();
            Matrix result(size, size);
            T determinant;
            float determinantInverse;

            if (!(determinant = this->determinant()))
                throw std::logic_error("Matrice determinant is 0");
            determinantInverse = 1.0f / determinant;
            for (unsigned y = 0; y < size; y++)
                for (unsigned x = 0; x < size; x++) {
                    if (x != y)
                        result[y][x] = -(*this)[y][x] * determinantInverse;
                    else
                        result[size - y - 1][size - x - 1] = (*this)[y][x] * determinantInverse;
                }
            return (result);
        }

        unsigned width(void) const {
            if (!this->size())
                return (0);
            return ((*this)[0].size());
        }

        unsigned height(void) const {
            return (this->size());
        }

        void print(void) {
            unsigned height = this->height();
            unsigned width = this->width();

            for (int y = 0; y < height; y++) {
                std::cout << "[";
                if (width) {
                    for (int x = 0; x < width - 1; x++)
                        std::cout << (*this)[y][x] <<  ", ";
                    std::cout << (*this)[y][width - 1];
                }
                std::cout << "]" << std::endl;
            }
            std::cout << std::endl;
        }

        void operator+=(const Matrix<T> & rhs) {*this = *this + rhs;};
        void operator-=(const Matrix<T> & rhs) {*this = *this - rhs;};
        void operator*=(const T rhs) {*this = *this * rhs;};
        void operator*=(const Matrix<T> & rhs) {*this = *this * rhs;};
        void operator/=(const T rhs) {*this = *this / rhs;};
};

template <typename T>
Matrix<T> lerp(const Matrix<T> &u, const Matrix<T> &v, const float t) {
    Matrix<T> result;

    if (u.size() != v.size())
        throw std::logic_error("Matrices are of different size");
    result = u * (1 - t) + v * t;
    return (result);
}

template <typename T>
T mat3Determinant(const Matrix<T> &matrix) {
    T result;

    result = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]);
    result -= matrix[0][1] * (matrix[1][0] * matrix[2][2] -  matrix[2][0] * matrix[1][2]);
    result += matrix[0][2] * (matrix[1][0] * matrix[2][1] -  matrix[2][0] * matrix[1][1]);
    return (result);
}

#endif
