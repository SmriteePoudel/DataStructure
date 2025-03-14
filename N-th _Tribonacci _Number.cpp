class Solution {
public:
    int tribonacci(int n) {
        // Handle base cases
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        
        // Initialize the first three numbers
        int t0 = 0, t1 = 1, t2 = 1;
        int result = 0;
        
        // Calculate Tribonacci numbers iteratively
        for (int i = 3; i <= n; i++) {
            result = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = result;
        }
        
        return result;
    }
};
