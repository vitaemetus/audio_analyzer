#include <iomanip>
#include <cmath>
#include <numeric>
#include <algorithm>

#include "dft.h"

int main(){
    //Number of bins
    int n_bins = 10;


    // Create a test signal.
    int N = 1000;
    std::vector<std::complex<float>> signal;
    signal.reserve (N);

    float sigK = 450.0;
    float sigPhase = 0.0;

    for (int x=0; x<N; x++)
    {
        auto currentSample = std::complex<float>
            (cos((2*M_PI/static_cast<float> (N)) *
                sigK * static_cast<float> (x) + sigPhase), 0.0);
        signal.push_back(currentSample);
    }

    // Compute the DFT
    auto begin = std::chrono::steady_clock::now();
    std::vector<float> Fx = dft(signal);
    auto end = std::chrono::steady_clock::now();
    auto time_span_bin = (end - begin);
    std::cout<<std::chrono::duration_cast<std::chrono::microseconds>((end-begin)).count();


    std::cout<<"\n"<<"Freq\t"<<std::setw(12)
        <<"Magn"<<std::endl;

    for (int i=5; i<15; ++i)
    {
    std::cout << i << "\t"
        <<std::setw(12)<<Fx[i] << std::endl
        <<std::endl;
    }


    //Mean by bin:
    float max = *std::max_element(Fx.begin(), Fx.end());

    for (int i = 0; i < n_bins; i++){
        std::vector<float>::const_iterator first = Fx.begin() + i*50;
        std::vector<float>::const_iterator last = Fx.begin() + (i+1)*50;

        std::vector<float> sliced_Fx(first, last);

        float average = 10 * (*std::max_element(sliced_Fx.begin(), sliced_Fx.end())) / (max);

        for (int b = 0; b < average; b++){
            std::cout<<"#";
        }
        std::cout<<"\n";
    }
    



    return 0;
}