#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

#include "Sequential_Primes.hpp"
#include "Parallel_Primes.hpp"

using namespace std;

int main()
{
    for(int n=50; n<=500; n+=50) {
        // Sequential Algorithm
        auto start_seq = std::chrono::high_resolution_clock::now();
        bool* primes_seq = SieveOfEratosthenes_sequential(n);
        auto finish_seq = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seq = finish_seq - start_seq;
        std::cout << "Elapsed time (sequential): " << elapsed_seq.count() << " s\n";
        printArray(prime_seq, n);

        // Parallel Algorithm
        auto start_par = std::chrono::high_resolution_clock::now();
        bool* primes_par = SieveOfEratosthenes_parallel(n);
        auto finish_par = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_par = finish_par - start_par;
        std::cout << "Elapsed time (parallel): " << elapsed_par.count() << " s\n";
        printArray(prime_par, n);
    }
    return 0;
}
