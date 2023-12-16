#include <iomanip>
#include <cmath>
#include <numeric>
#include <algorithm>

#include "dft.h"
#include "print.h"

int main(){
    //Number of bins
    int n_bins = 10;

    // Create a test signal.
    int N = 1000;
    std::vector<std::complex<float>> signal;
    signal.reserve (N);

    float sigK = 100.0;
    float sigPhase = 0.0;

    for (int x=0; x<N; x++)
    {
        auto currentSample = std::complex<float>
            (cos((2*M_PI/static_cast<float> (N)) *
                sigK * static_cast<float> (x) + sigPhase), 0.0);
        signal.push_back(currentSample);
    }

    print(signal);

    return 0;
}