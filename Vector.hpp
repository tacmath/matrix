#include <iostream>
#include <vector>


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

        Vector operator*(const T & rhs) {
            Vector result(*this);

		    for (unsigned n = 0; n < this->size(); ++n)
			    result[n] *= rhs;
            return (result);
        }

        void print(void) {
            unsigned size = this->size();

            std::cout << "v = [";
            for (int n = 0; n < size - 1; n++) {
                std::cout << (*this)[n] <<  ", ";
            }
            if (size)
                std::cout << (*this)[size - 1];
            std::cout << "]" << std::endl;
        }
};

