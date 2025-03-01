//Apply Operations to an Array 

class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            int n = nums.size();
            
            // Apply operations
            for (int i = 0; i < n - 1; i++) {
                if (nums[i] == nums[i + 1]) {
                    nums[i] *= 2;
                    nums[i + 1] = 0;
                }
            }
            
            // Shift all zeros to the end
            vector<int> result(n, 0);
            int index = 0;
            
            // Copy all non-zero elements
            for (int i = 0; i < n; i++) {
                if (nums[i] != 0) {
                    result[index++] = nums[i];
                }
            }
            
            return result;
        }
    };