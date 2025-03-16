#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        // Binary search for the minimum time
        long long left = 1;
        long long right = (long long)(*min_element(ranks.begin(), ranks.end())) * (long long)cars * cars;
        
        while (left < right) {
            long long mid = left + (right - left) / 2;
            
            if (canRepairAllCars(ranks, cars, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
private:
    bool canRepairAllCars(vector<int>& ranks, int cars, long long time) {
        long long totalCarsRepaired = 0;
        
        for (int rank : ranks) {
            // For each mechanic, calculate how many cars they can repair within the given time
            // A mechanic with rank r can repair n cars in r * n^2 minutes.
            // So within 'time' minutes, they can repair sqrt(time / r) cars.
            long long carsRepairedByMechanic = sqrt(time / rank);
            totalCarsRepaired += carsRepairedByMechanic;
            
            // If we've repaired enough cars, return true
            if (totalCarsRepaired >= cars) {
                return true;
            }
        }
        
        return false;
    }
};