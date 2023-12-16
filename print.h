#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
#include <algorithm>

#include "dft.h"

void print (std::vector<std::complex<float>> signal){
    //Number of bins
    int n_bins = 10;

    // Compute the DFT
    std::vector<float> Fx = dft(signal);

    //Mean by bin:
    std::cout<<"\n"<<"Freq\t"<<std::setw(6)<<"Magn"<<std::endl;

    float max = *std::max_element(Fx.begin(), Fx.end());

    for (int i = 0; i < n_bins; i++){
        std::vector<float>::const_iterator first = Fx.begin() + i*50;
        std::vector<float>::const_iterator last = Fx.begin() + (i+1)*50;

        std::vector<float> sliced_Fx(first, last);

        float average = 10 * (*std::max_element(sliced_Fx.begin(), sliced_Fx.end())) / (max);

        std::cout<<i*50<<":\t"<<std::setw(6);
        for (int b = 0; b < average; b++){
            std::cout<<"#";
        }
        std::cout<<"\n";
    }
}