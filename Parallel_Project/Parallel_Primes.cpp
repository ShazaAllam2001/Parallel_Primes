#include <pthread.h>
#include <vector>

#include "thread_struct.h"

void* SieveOfEratosthenes_func(void* args) {
    thread_struct* thread_args = (thread_struct*) args;
    // Update all multiples of p greater than or equal to the square of p
    // numbers which are multiple of p and are less than p^2 are already been marked
    for(int i = thread_args->p*thread_args->p; i <= thread_args->n; i += thread_args->p) {
        thread_args->prime[i] = false;
    }
}

bool* SieveOfEratosthenes_parallel(int n) {
    // create a boolean array for prime numbers
    // initialize it with true
    std::vector<pthread_t> threads;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for(int p = 2; p*p <= n; p++) {
        // check the unchanged values of primes
        if(prime[p] == true) {
            pthread_t thread;
            threads.push_back(thread);
            thread_struct* args = (thread_struct*) malloc(sizeof(thread_struct));
            args->n = n;
            args->p = p;
            args->prime = &prime;
            if(pthread_create(&thread.at(threads.size()-1), NULL, SieveOfEratosthenes_func, (void*) args) != 0) {
                perror("Can not create thread!");
            }
        }
    }

    for(int thread : threads) {
        pthread_join(thread, NULL);
    }
    return prime;
}
