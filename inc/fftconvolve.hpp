#ifndef FFT_CONVOLVE_HPP
# define FFT_CONVOLVE_HPP

/// Includes
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <complex>
//#include <boost/python/numpy.hpp>

/// Functions prototypes
int p(const char *s);
bool isseparator(char c);

//namespace np = boost::python::numpy;

/**
 * Convolve performs a convolution on two given sequences.
 */
class Convolve{
public:
//    Convolve(np::ndarray F, np::ndarray G);
    Convolve(char *s1, char *s2);
    std::vector<int>    conv_1d(void);
    std::vector<double> fft_1d(void);

    class WrongSequenceException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return ("Parsing error.");
        }
    };

protected:
    std::vector<int>    vectorizeSequence(std::string str);
    void                fft(std::vector<std::complex<double>>& x, bool inverse);

private:
    /// conv1D Sequences
    std::vector<int>    f;
    std::vector<int>    g;

    /// conv2D Sequences
//    np::ndarray F;
//    np::ndarray G;
};



#endif