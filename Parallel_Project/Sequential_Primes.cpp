#include "Sequential_Primes.hpp"

/*
    Sequential implementation
    For Sieve of Eratosthenes (determining prime numbers from 2 to n)
    works on O(n log log n)
*/
bool* SieveOfEratosthenes_sequential(int n) {
    // create a boolean array for prime numbers
    // initialize it with true
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for(int p = 2; p*p <= n; p++) {
        // check the unchanged values of primes
        if(prime[p] == true) {
            // Update all multiples of p greater than or equal to the square of p
            // numbers which are multiple of p and are less than p^2 are already been marked
            for(int i = p*p; i <= n; i += p) // this loop can be parallelized
                prime[i] = false;
        }
    }
    return prime;
}

void printArray(bool* prime, int n) {
    for(int i=2; i<n; i++) {
        if(prime[i] == true)
            std::cout << i << ", ";
    }
    std::cout << "\n";
}
