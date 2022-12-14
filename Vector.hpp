#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <vector>
#include <math.h>

#define VECTOR_ABS(x) ((x > 0) ? x : -x)


template <typename T = float>
struct Vector : public std::vector<T>
{
        Vector(void) {}
        Vector(size_t size) {
            this->resize(size);
		    for (unsigned n = 0; n < size; ++n)
			    (*this)[n] = 0;
        }
        Vector(const Vector<T> & vector) {
			(*this) = vector;
        }
        Vector(const std::vector<T> & vector) {
			(*this) = vector;
		}

        Vector &operator=(const std::vector<T> & rhs) {
            this->resize(rhs.size());
		    for (unsigned n = 0; n < this->size(); ++n)
			    (*this)[n] = rhs[n];
            return (*this);
        }
        
        Vector &operator=(const Vector<T> & rhs) {
            this->resize(rhs.size());
		    for (unsigned n = 0; n < this->size(); ++n)
			    (*this)[n] = rhs[n];
            return (*this);
        }

        Vector operator+(const Vector<T> & rhs) {
            Vector result(*this);

            if (this->size() != rhs.size())
                throw std::logic_error("Vectors are of different size");
		    for (unsigned n = 0; n < this->size(); ++n)
			    result[n] += rhs[n];
            return (result);
        }

        Vector operator-(const Vector<T> & rhs) {
            Vector result(*this);

            if (this->size() != rhs.size())
                throw std::logic_error("Vectors are of different size");
		    for (unsigned n = 0; n < this->size(); ++n)
			    result[n] -= rhs[n];
            return (result);
        }

        Vector operator*(const T rhs) const {
            Vector result(*this);

		    for (unsigned n = 0; n < this->size(); ++n)
			    result[n] *= rhs;
            return (result);
        }

        Vector operator/(const T rhs) const {
            Vector result(*this);

		    for (unsigned n = 0; n < this->size(); ++n)
			    result[n] /= rhs;
            return (result);
        }

        T dot(const Vector<T> & vector) const {
            T result;
            
            if (this->size() != vector.size())
                throw std::logic_error("Vectors are of different size");
            result = 0;
            for (int n = 0; n < this->size(); n++)
                result += (*this)[n] * vector[n];
            return (result);
        }

        float norm_1() const {
            float result;

            result = 0.0f;
            for (int n = 0; n < this->size(); n++)
                result += VECTOR_ABS((*this)[n]);
            return (result);
        }

        float norm() const {
            float result;

            result = 0.0f;
            for (int n = 0; n < this->size(); n++)
                result += (*this)[n] * (*this)[n];
            return (pow(result, 0.5f));
        }

        float norm_inf() const {
            float result;

            result = 0;
            for (int n = 0; n < this->size(); n++)
                if (VECTOR_ABS((*this)[n]) > result)
                    result = VECTOR_ABS((*this)[n]);
            return (result);
        }

        void print(void) {std::cout << *this << std::endl;}

        void operator+=(const Vector<T> & rhs) {*this = *this + rhs;};
        void operator-=(const Vector<T> & rhs) {*this = *this - rhs;};
        void operator*=(const T rhs) {*this = *this * rhs;};
        void operator/=(const T rhs) {*this = *this / rhs;};
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T> &vector) {
    unsigned size = vector.size();

    os << "v = [";
    for (int n = 0; n < size - 1; n++) {
        os << vector[n] <<  ", ";
    }
    if (size)
        os << vector[size - 1];
    os << "]";
    return (os);
}

template <typename T>
Vector<T> linear_combination(const Vector<Vector<T>> &vectors, const Vector<T> &coefs) {

    Vector<T> result((vectors.size()) ? vectors[0].size() : 0);
  //  Vector<T> result(vectors[0].size());   the ternaire might not be needed

    if (vectors.size() != coefs.size())
        throw std::logic_error("Vectors are of different size");
    for (unsigned n = 0; n < vectors.size(); n++)
        result += vectors[n] * coefs[n];
    return (result);
}

template <typename T>
Vector<T> lerp(const Vector<T> &u, const Vector<T> &v, const float t) {
    Vector<T> result;

    if (u.size() != v.size())
        throw std::logic_error("Vectors are of different size");
    result = u * (1 - t) + v * t;
    return (result);
}

template <typename T>
float angle_cos(const Vector<T> &u, const Vector<T> &v) {
    float result;

    result = u.dot(v) / (u.norm() * v.norm());
    return (result);
}

template <typename T>
 Vector<T> cross_product(const Vector<T> &u, const Vector<T> &v) {
    Vector<T> result(3);

    if (u.size() != 3 ||  v.size() != 3)
        throw std::logic_error("Vectors are not of size 3");
    result[0] = u[1] * v[2] - u[2] * v[1];
    result[1] = -u[0] * v[2] + u[2] * v[0];
    result[2] = u[0] * v[1] - u[1] * v[0];
    return (result);
 }
#endif
