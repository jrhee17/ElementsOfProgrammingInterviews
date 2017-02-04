//
//Write a function that takes a single positive integer argument(n >= 2) and returns all the primes between 1 and n
//
#include <vector>
#include <deque>
#include <math.h> 
#include <stdio.h>
#include <iostream>

using namespace std;

vector<int> generate_primes_from_1_to_n(int n) {
    int size = floor(0.5 * (n - 3)) + 1;
    vector<int> primes;
    primes.emplace_back(2);

    deque<bool> is_prime(size, true);
    for(long i = 0; i < size; ++i) {
        if(is_prime[i]) {
            int p = (i * 2) + 3;
            primes.emplace_back(p);
            for(long j = ((i * i) * 2) + 6 * i + 3; j < size; j += p) {
                is_prime[j] = false;
            }
        }
    }

    return primes;
}

int main(int argc, char** args) {
    int input = atoi(args[1]);
    printf("Generating prime number of %d\n", input);

    vector<int> primes = generate_primes_from_1_to_n(input);

    for(std::vector<int>::iterator it = primes.begin(); it != primes.end(); ++it)
        printf("%d,", *it);
    printf("\n");
}
