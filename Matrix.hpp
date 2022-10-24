#include <iostream>
#include <vector>


template <typename T = float>
struct Matrix : public std::vector<std::vector<T>>
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
