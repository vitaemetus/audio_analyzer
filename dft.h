#pragma once

#include <vector>
#include <complex>
#include <iostream>

std::vector<float> dft (std::vector<float> & X){
    int N = X.size();
    int K = round(N / 2);

    std::vector<float> output;
    output.reserve(K);

    std::complex<float> sum;

    for (int k = 1; k < K; k++){
        sum = std::complex<float>(0, 0);
        for (int n  = 0; n < N; n++){
            float Real = cos(2 * M_PI * k * (static_cast<float> (n) / static_cast<float> (N)));
            float Imag = sin(2 * M_PI * k * (static_cast<float> (n) / static_cast<float> (N)));
            sum += std::complex<float>(Real * X[n], -Imag);
        }
        output.push_back(sqrt(pow(sum.real()/N, 2) + pow(sum.imag()/N, 2)));
    }

    return output;
}



