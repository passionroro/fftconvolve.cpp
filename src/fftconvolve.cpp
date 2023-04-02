#include "../inc/fftconvolve.hpp"

///**
// * Convolve constructor for two-dimensional convolution.
// * Initialize two 2D arrays of integers.
// *
// * @param F: numpy array
// * @param G: numpy array
// */
//Convolve::Convolve(np::ndarray F, np::ndarray G) {
//
//}


/**
 * Convolve constructor for one-dimensional convolution.
 * Takes the two strings given in the program parameters.
 *
 * @param s1 f(x): list of numbers (integers)
 * @param s2 g(x): another list of numbers
 */
Convolve::Convolve(char *s1, char *s2) : f(), g() {

    try {
        f = vectorizeSequence(static_cast<std::string>(s1));
        g = vectorizeSequence(static_cast<std::string>(s2));
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
std::vector<int> Convolve::conv_1d() {

    int f_len = f.size();
    int g_len = g.size();
    int conv_size = f_len + g_len - 1;

    std::vector<int> C(conv_size);

    int i = -1;
    while (++i < conv_size) {

        int start = (i >= g_len - 1) ? (i - (g_len - 1)) : 0;
        int stop = (i < f_len - 1) ? i : f_len - 1;

        for (int j = start; j <= stop; j++) {
            C[i] += f[j] * g[i - j];
        }

    }

    return C;
}

std::vector<double> Convolve::fft_1d() {

    unsigned int n = f.size() + g.size() - 1;
    /// Find next power of 2
    double N = pow(2, ceil(log2(n)));

    /// Concatenate f and g vectors
    std::vector<std::complex<double>> X((unsigned long)N);
    for (unsigned int i = 0; (double)i < N; i++) {
        if (i < f.size())
            X[i] = std::complex<double>(f[i], 0.0);
        else if (i - f.size() < g.size())
            X[i] = std::complex<double>(g[i], 0.0);
    }

    fft(X, false);
    /// Compute the inverse FFT to obtain the convolution
    fft(X, true);

    std::vector<double> result(n);
    for (unsigned int i = 0; i < n; i++) {
        result[i] = round(X[i].real() / N);
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return result;
}

/**
 * This function implements the Cooley-Tukey FFT algorithm for a one-dimensional sequence of complex numbers.
 *
 * @param X : a reference to a std::vector of complex numbers
 * @param inverse : inverse FFT (true) or the regular FFT (false).
 * @return returns nothing but modifies the input vector X.
 */
void Convolve::fft(std::vector<std::complex<double>> &X, bool inverse) {

    unsigned int N = X.size();
    if (N <= 1)
        return;

    std::vector<std::complex<double>>   even(N/2);
    std::vector<std::complex<double>>   odd(N/2);
    for (unsigned int i = 0; i < N/2; i++) {
        even[i] = X[2*i];
        odd[i] = X[2*i+1];
    }

    fft(even, inverse);
    fft(odd, inverse);

    double sign = (inverse ? 1 : -1);
    std::complex<double>    w(1);
    std::complex<double>    wn = std::polar(1.0, sign * 2 * M_PI / N);
    for (unsigned int i = 0; i < N/2; i++) {
        X[i] = even[i] + w * odd[i];
        X[i + N/2] = even[i] - w * odd[i];
        w *= wn;
    }

}