#ifndef FFT_CONVOLVE_HPP
# define FFT_CONVOLVE_HPP

/// Includes
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <chrono>

/// Functions prototypes
int p(const char *s);
bool isseparator(char c);

/**
 * Convolve performs a convolution on two given sequences.
 */
class Convolve{
public:
    Convolve(char *s1, char *s2);
    std::vector<int>    conv1d(void);

    class WrongSequenceException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return ("Parsing error.");
        }
    };

protected:
    std::vector<int>    vectorizeSequence(std::string str);

private:
    std::vector<int>    _f;
    std::vector<int>    _g;
};



#endif