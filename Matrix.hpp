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
            unsigned pivot;
            
            pivot = 0;
            for (unsigned n = 0; n < this->width(); n++) {
                if (result[pivot][n] == 0)
                    for (unsigned m = pivot; m < this->height(); m++)
                        if (result[m][n]) {
                            result.swap_row(pivot, m);             //swap row for a pivot
                            break ;
                        }    
                if (!result[pivot][n])
                    continue;
                result[pivot] *= 1.0f / result[pivot][n];       // scale by the inverse to make pivot = 1       |       maybe change to prevent -0
                for (unsigned m = 0; m < this->height(); m++)
                    if (result[m][n] && m != pivot) {
                        result[m] -=  result[pivot] * result[m][n];    // make everything around the pivot = 0
                        result[m][n] = 0;                              // for the evil floating point 
                    }
                pivot++;
                if (pivot == this->height())
                    break;
            }
            return (result);
        }

        T determinant(void) {
            T result;
            size_t size;
            Matrix matrix(*this);
            unsigned pivot;

            if (this->width() != this->height())
                throw std::logic_error("Matrice shape is not a square");
            size = this->height();
            if (!size)
                return (0);
            pivot = 0;
            result = 1;
            for (unsigned n = 0; n < size - 1; n++) {
                if (matrix[pivot][n] == 0)
                    for (unsigned m = pivot; m < size; m++)
                        if (matrix[m][n]) {
                            matrix.swap_row(pivot, m);             //swap row for a pivot
                            result *= -1;
                            break ;
                        }    
                if (!matrix[pivot][n])
                    return (0);
                result *= matrix[pivot][n];
                matrix[pivot] *= 1.0f / matrix[pivot][n];       // scale by the inverse to make pivot = 1
                for (unsigned m = pivot + 1; m < size; m++)
                    if (matrix[m][n]) {
                        matrix[m] -=  matrix[pivot] * matrix[m][n];    // make everything under the pivot = 0
                        matrix[m][n] = 0;
                    }
                pivot++;
            }
            return (result * matrix[size - 1][size - 1]);
        }

        Matrix augmented(void) {
            size_t size = this->height();
            Matrix result(size, size * 2);

            for (unsigned y = 0; y < size; y++) {
                for (unsigned x = 0; x < size; x++) {
                    if (x == y)
                        result[y][x + size] = 1;
                    result[y][x] = (*this)[y][x];
                }
            }
            return(result);
        }

        Matrix inverse(void) {
            size_t size = this->height();
            Matrix result(size, size);
            Matrix reduced;

            if (this->width() != this->height())
                throw std::logic_error("Matrice shape is not a square");
            reduced = this->augmented().row_echelon();
            for (unsigned y = 0; y < size; y++) {
                if (!reduced[y][y])
                    throw std::logic_error("Matrice determinant is 0");
                for (unsigned x = 0; x < size; x++)
                        result[y][x] = reduced[y][x + size];
            }
            return (result);
        }

        unsigned rank(void) {
            unsigned result;
            Matrix row_echelon;

            result = 0;
            row_echelon = this->row_echelon();
            for (unsigned y = 0; y < this->height(); y++)
                for (unsigned x = 0; x < this->width(); x++) {
                    if (row_echelon[y][x]) {
                        result++;
                        break;
                    }
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
            std::cout << *this << std::endl;
        }

        void operator+=(const Matrix<T> & rhs) {*this = *this + rhs;};
        void operator-=(const Matrix<T> & rhs) {*this = *this - rhs;};
        void operator*=(const T rhs) {*this = *this * rhs;};
        void operator*=(const Matrix<T> & rhs) {*this = *this * rhs;};
        void operator/=(const T rhs) {*this = *this / rhs;};
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T> &matrix) {
    unsigned height = matrix.height();
    unsigned width = matrix.width();

    for (int y = 0; y < height; y++) {
        os << "[";
        if (width) {
            for (int x = 0; x < width - 1; x++)
                os << matrix[y][x] <<  ", ";
            os << matrix[y][width - 1];
        }
        os << "]" << std::endl;
    }
    return (os);
}

template <typename T>
Matrix<T> lerp(const Matrix<T> &u, const Matrix<T> &v, const float t) {
    Matrix<T> result;

    if (u.size() != v.size())
        throw std::logic_error("Matrices are of different size");
    result = u * (1 - t) + v * t;
    return (result);
}

Matrix<float> perspective(float fov, float ratio, float near, float far) {
    float   scale = 1.0f / tanf((fov / 2.0f) * (3.14159265358979323846 / 180.0f));
    Matrix<float>  projection({ {scale / ratio,     0,      0,      0}
                                ,{0,                scale,  0,      0}
                                ,{0,                0,      -((far + near) / (far - near)),     -1}
                                ,{0,                0,      -((2 * far * near) / (far - near)), 0}});
    return (projection);
}

#endif
