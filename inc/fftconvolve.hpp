#ifndef FFT_CONVOLVE_HPP
# define FFT_CONVOLVE_HPP

#include <iostream>
#include <vector>
#include <cstdlib>

class Convolve{
public:
    Convolve(char *s1, char *s2);
    std::vector<int>    conv1d(void);
private:
    std::vector<int>    _A;
    std::vector<int>    _B;
};

int p(const char *s);

#endif