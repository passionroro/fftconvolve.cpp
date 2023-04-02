#include "../inc/fftconvolve.hpp"

Convolve::Convolve(char *s1, char *s2) : _A(), _B() {

    int i = -1;
    while (s1[++i] ) {

        try {
            if (isdigit(s1[i]))
                _A.push_back(s1[i] - 48);
            if (s2)
                if (isdigit(s2[i]))
                    _B.push_back(s2[i] - 48);
        }
        catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

    }

    return ;
}

std::vector<int> Convolve::conv1d() {

    int elements = _A.size();
    std::cout << elements * elements - 1 << std::endl;
            //
//    for (int i: elements) {
//
//    }
    std::vector<int> tmp;
    return (tmp);
}
