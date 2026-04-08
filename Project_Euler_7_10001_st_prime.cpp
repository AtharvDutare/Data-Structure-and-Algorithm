#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    
    vector<int> queries(t);
    int max_n = 0;
    for (int i = 0; i < t; i++) {
        cin >> queries[i];
        if (queries[i] > max_n) {
            max_n = queries[i];
        }
    }
    
    // Calculate a safe upper bound
    int limit;
    if (max_n < 6) {
        limit = 15;
    } else {
        limit = max_n * (log(max_n) + log(log(max_n))) + 100;
    }
    
    // Sieve of Eratosthenes
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    vector<int> primes;
    primes.reserve(max_n); // Pre-allocate memory for performance
    
    for (int p = 2; p <= limit; p++) {
        if (is_prime[p]) {
            primes.push_back(p);
            if (primes.size() == max_n) break;
            
            // Mark multiples as false
            for (long long i = (long long)p * p; i <= limit; i += p) {
                is_prime[i] = false;
            }
        }
    }
    
    // Answer queries
    for (int i = 0; i < t; i++) {
        cout << primes[queries[i] - 1] << "\n";
    }
    
    return 0;
}