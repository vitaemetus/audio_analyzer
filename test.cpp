#include <iomanip>
#include "dft.h"

int main(){
    // Create a test signal.
    int N = 20000;
    std::vector<std::complex<float>> signal;
    signal.reserve (N);

    float sigK = 3.5;
    float sigPhase = 1.0;

    for (int x=0; x<N; x++)
    {
        auto currentSample = std::complex<float>
            (cos((2*M_PI/static_cast<float> (N)) *
                sigK * static_cast<float> (x) + sigPhase), 0.0);
        signal.push_back(currentSample);
    }

    // Compute the DFT
    auto begin = std::chrono::steady_clock::now();
    std::vector<std::complex<float>> Fx = dft(signal);
    auto end = std::chrono::steady_clock::now();
    auto time_span_bin = (end - begin);
    std::cout<<std::chrono::duration_cast<std::chrono::microseconds>((end-begin)).count();



    // Display the first six values (real and imaginary components). std: cout <<"****" << std:: endl:
    std::cout<<"\n"<<"Freq\t"<<std::setw(12)
        <<"Real\t"<<std::setw(12)<<"Imag\t"<<std::setw(12)<<"Magn"<<std::endl;

    for (int i=0; i<10; ++i)
    {
    std::cout << i << "\t"
        <<std::setw(12)<<Fx[i].real() / static_cast<float> (N) << "\t"
        <<std::setw(12)<<Fx[i].imag() / static_cast<float> (N) << "\t"
        <<std::setw(12)<<sqrt(pow((Fx[i].real() / static_cast<float> (N)), 2) + pow((Fx[i].imag() / static_cast<float> (N)), 2)) << std::endl
        <<std::endl;
    }

    return 0;
}