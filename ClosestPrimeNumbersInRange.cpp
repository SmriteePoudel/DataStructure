#include <vector>
#include <cmath>
#include <climits>

class Solution {
public:
    std::vector<int> closestPrimes(int left, int right) {
        // Get all primes in the range [left, right]
        std::vector<int> primes = getPrimesInRange(left, right);
        
        // If we have less than 2 primes, return [-1, -1]
        if (primes.size() < 2) {
            return {-1, -1};
        }
        
        // Find the pair with minimum difference
        int minDiff = INT_MAX;
        std::vector<int> result = {-1, -1};
        
        for (int i = 0; i < primes.size() - 1; i++) {
            int diff = primes[i + 1] - primes[i];
            if (diff < minDiff) {
                minDiff = diff;
                result = {primes[i], primes[i + 1]};
            }
        }
        
        return result;
    }
    
private:
    std::vector<int> getPrimesInRange(int left, int right) {
        std::vector<int> primes;
        
        // Use a Sieve of Eratosthenes approach for the range
        std::vector<bool> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false;
        
        for (int i = 2; i <= std::sqrt(right); i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        // Collect primes in the range [left, right]
        for (int i = std::max(2, left); i <= right; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }
        
        return primes;
    }
};
