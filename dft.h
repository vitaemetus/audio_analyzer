#pragma once

#include <vector>
#include <complex>
#include <iostream>

std::vector<std::complex<float>> dft (std::vector<std::complex<float>> X){
    int N = X.size();

    std::vector<float> bins =  {5.0, 13.0, 32.0,
                                79.0, 200.0, 500.0,
                                1255.0, 3155.0, 7920.0, 
                                20000.0};

    std::vector<std::complex<float>> output;
    output.reserve(bins.size());

    std::complex<float> sum;

    for (float freq : bins){
        sum = std::complex<float>(0, 0);
        for (int n  = 0; n < N; n++){
            float Real = cos(2 * M_PI * freq * (static_cast<float> (n) / static_cast<float> (N)));
            float Imag = sin(2 * M_PI * freq * (static_cast<float> (n) / static_cast<float> (N)));
            sum += X[n] * std::complex<float>(Real, -Imag);
        }
        output.push_back(sum);
    }

    return output;
}



