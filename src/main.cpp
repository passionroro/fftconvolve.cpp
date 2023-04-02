#include "../inc/fftconvolve.hpp"

int main(int argc, char **argv) {

    if (argc != 3)
		return p("error: wrong arguments\nUsage: ") &
			p(argv[0]) & p(" \"1 2 3\" \"4 5 6\"\n");

    Convolve convolution(argv[1], argv[2]);

    std::vector<int>    result = convolution.conv1d();

    return 0;
}
