#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    // Solution 1: Using min-heap
    int findKthLargestHeap(std::vector<int>& nums, int k) {
        // Create a min heap
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        
        // Add elements to the heap
        for (int num : nums) {
            minHeap.push(num);
            // Keep heap size as k
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        // Top element is the kth largest
        return minHeap.top();
    }
    
    // Solution 2: Using QuickSelect algorithm
    int findKthLargest(std::vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
    
private:
    int quickSelect(std::vector<int>& nums, int left, int right, int k_smallest) {
        // If the list contains only one element, return that element
        if (left == right) return nums[left];
        
        // Select a random pivot_index between left and right
        int pivot_index = left + rand() % (right - left + 1);
        
        // Put the pivot at its final sorted position
        pivot_index = partition(nums, left, right, pivot_index);
        
        // The pivot is in its final sorted position
        if (k_smallest == pivot_index) {
            return nums[k_smallest];
        } else if (k_smallest < pivot_index) {
            // Continue searching in the left subarray
            return quickSelect(nums, left, pivot_index - 1, k_smallest);
        } else {
            // Continue searching in the right subarray
            return quickSelect(nums, pivot_index + 1, right, k_smallest);
        }
    }
    
    int partition(std::vector<int>& nums, int left, int right, int pivot_index) {
        int pivot_value = nums[pivot_index];
        
        // Move pivot to the end
        std::swap(nums[pivot_index], nums[right]);
        
        // Move all elements smaller than pivot to the left
        int store_index = left;
        
        for (int i = left; i < right; i++) {
            if (nums[i] < pivot_value) {
                std::swap(nums[i], nums[store_index]);
                store_index++;
            }
        }
        
        // Move pivot to its final place
        std::swap(nums[right], nums[store_index]);
        
        return store_index;
    }
};
