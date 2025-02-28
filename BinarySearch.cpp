//Guess Number Higher or Lower

class Solution {
    public:
        int guessNumber(int n) {
            int left = 1;
            int right = n;
            
            while (left <= right) {
                // Use int mid = (left + right) / 2 might cause overflow
                // when left + right > INT_MAX
                int mid = left + (right - left) / 2;
                
                int result = guess(mid);
                
                if (result == 0) {
                    return mid;  // We found the number
                } else if (result == -1) {
                    right = mid - 1;  // Number is lower than our guess
                } else {
                    left = mid + 1;  // Number is higher than our guess
                }
            }
            
            return left;  // This line won't be reached given the constraints
        }
    };