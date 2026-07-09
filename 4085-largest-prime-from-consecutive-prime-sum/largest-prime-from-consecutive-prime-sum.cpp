#include <vector>
#include <cmath>

class Solution {
public:
    int largestPrime(int n) {
        // Find all primes up to n using a simple Sieve
        // We need a boolean array to check if a sum is prime quickly later.
        if (n < 2) return 0;
        
        std::vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        
        for (int p = 2; p * p <= n; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i <= n; i += p)
                    isPrime[i] = false;
            }
        }
        
        // Calculate consecutive sums starting from 2
        // We iterate through primes, adding them one by one to a running sum.
        int currentSum = 0;
        int maxPrimeSum = 0;
        
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                currentSum += i;
                
                // If the sum exceeds n, we can stop early
                if (currentSum > n) {
                    break;
                }
                
                // If the sum is prime, update our max
                if (isPrime[currentSum]) {
                    maxPrimeSum = currentSum;
                }
            }
        }
        
        return maxPrimeSum;
    }
};
