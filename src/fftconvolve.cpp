#include "../inc/fftconvolve.hpp"

/**
 * Convolve default constructor.
 * Takes the two strings given in the program parameters.
 *
 * @param s1 f(x): list of numbers (integers)
 * @param s2 g(x): another list of numbers
 */
Convolve::Convolve(char *s1, char *s2) : _f(), _g() {

    try {
        _f = vectorizeSequence(static_cast<std::string>(s1));
        _g = vectorizeSequence(static_cast<std::string>(s2));
    }
    catch (WrongSequenceException &e) {
        std::cerr << e.what() << std::endl;
    }

    return ;
}

/**
 * Convert the string of numbers into a vector of integers.
 * Throws an error of the format is incorrect.
 *
 * @param str the list of numbers to convert.
 * @return vector of integers
 */
std::vector<int> Convolve::vectorizeSequence(std::string str) {
    std::vector<int>            v_int;

    int i = -1;
    while (str[++i]) {
        int len = 0;
        while (isdigit(str[i])) {
            i++;
            len++;
        }
        if (str[i] && !isseparator(str[i]))
            throw (Convolve::WrongSequenceException());
        int tmp = stoi(str.substr(i - len, len));
        v_int.push_back(tmp);
    }

    return v_int;
}

/**
 * One-dimensional convolution of two vectors.
 * Computes the convolution of the two vectors passed in the constructor.
 *
 * @return vector of integers after the convolution
 */
std::vector<int> Convolve::conv1d() {

    int f_len = _f.size();
    int g_len = _g.size();
    int conv_size = f_len + g_len - 1;

    std::vector<int> C(conv_size);

    int i = -1;
    while (++i < conv_size) {

        int start = (i >= g_len - 1) ? (i - (g_len - 1)) : 0;
        int stop = (i < f_len - 1) ? i : f_len - 1;

        for (int j = start; j <= stop; j++) {
            C[i] += _f[j] * _g[i - j];
        }

    }

    return C;
}
