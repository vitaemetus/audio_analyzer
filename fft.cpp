#include <iostream>
#include "../../../kissfft/kiss_fft.h"

int main() {
    // Define the size of the input data
    const int N = 8;

    // Input and output arrays
    kiss_fft_cpx in[N], out[N];

    // Initialize input array (example data)
    for (int i = 0; i < N; ++i) {
        in[i].r = i;  // Real part
        in[i].i = 0;  // Imaginary part
    }

    // Create FFT configuration
    kiss_fft_cfg cfg = kiss_fft_alloc(N, 0, nullptr, nullptr);

    // Perform FFT
    kiss_fft(cfg, in, out);

    // Output the results
    for (int i = 0; i < N; ++i) {
        std::cout << "FFT[" << i << "] = " << out[i].r << " + " << out[i].i << "i\n";
    }

    // Free the allocated resources
    free(cfg);

    return 0;
}

