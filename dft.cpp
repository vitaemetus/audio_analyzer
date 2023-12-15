#include <vector>
#include <complex>
#include <iostream>
#include <iomanip>

std::vector<std::complex<double>> dft (std::vector<std::complex<double>> X){
    int N = X.size();
    int K = N;

    std::vector<std::complex<double>> output;
    output.reserve(K);

    std::complex<double> sum;

    for (int k = 0; k < K; k++){
        sum = std::complex<double>(0, 0);
        for (int n  = 0; n < N; n++){
            double Real = cos(2 * M_PI * k * (static_cast<double> (n) / static_cast<double> (N)));
            double Imag = sin(2 * M_PI * k * (static_cast<double> (n) / static_cast<double> (N)));
            sum += X[n] * std::complex<double>(Real, -Imag);
        }
        output.push_back(sum);
    }

    return output;
}

int main(){
    // Create a test signal.
    int N = 1000;
    std::vector<std::complex<double>> signal;
    signal.reserve (N);

    double sigK = 3.5;
    double sigPhase = 1.0;

    for (int x=0; x<N; x++)
    {
        auto currentSample = std::complex<double>
            (cos((2*M_PI/static_cast<double> (N)) *
                sigK * static_cast<double> (x) + sigPhase), 0.0);
        signal.push_back(currentSample);
    }

    // Compute the DFT
    std::vector<std::complex<double>> Fx = dft(signal);

    // Display the first six values (real and imaginary components). std: cout <<"****" << std:: endl:
    std::cout<<"****"<<std::endl;
    std::cout<<"\n"<<"Freq\t"<<std::setw(12)
        <<"Real\t"<<std::setw(12)<<"Imag\t"<<std::setw(12)<<"Magn"<<std::endl;

    for (int i=0; i<10; ++i)
    {
    std::cout << i << "\t"
        <<std::setw(12)<<Fx[i].real() / static_cast<double> (N) << "\t"
        <<std::setw(12)<<Fx[i].imag() / static_cast<double> (N) << "\t"
        <<std::setw(12)<<sqrt(pow((Fx[i].real() / static_cast<double> (N)), 2) + pow((Fx[i].imag() / static_cast<double> (N)), 2)) << std::endl
        <<std::endl;
    }
    return 0;
}