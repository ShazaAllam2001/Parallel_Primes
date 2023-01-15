#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

#include "Sequential_Primes.cpp"
#include "Parallel_Primes.cpp"

using namespace std;

int main()
{
    int n = 100;
    // Sequential Algorithm
    auto start_seq = std::chrono::high_resolution_clock::now();
    bool* primes_seq = SieveOfEratosthenes_sequential(n);
    auto finish_seq = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seq = finish_seq - start_seq;
    std::cout << "Elapsed time (sequential): " << elapsed.count() << " s\n";

    // Parallel Algorithm
    auto start_par = std::chrono::high_resolution_clock::now();
    bool* primes_par = SieveOfEratosthenes_parallel(n);
    auto finish_par = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seq = finish_seq - start_seq;
    std::cout << "Elapsed time (parallel): " << elapsed.count() << " s\n";

    return 0;
}
