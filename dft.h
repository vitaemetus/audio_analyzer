#pragma once

#include <vector>
#include <complex>
#include <iostream>

std::vector<std::complex<float>> dft (std::vector<std::complex<float>> X){
    int N = X.size();
    int bins = 10;

    std::vector<std::complex<float>> output;
    output.reserve(bins);

    std::complex<float> sum;

    for (int freq = 20; freq < 20000; freq++){
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



