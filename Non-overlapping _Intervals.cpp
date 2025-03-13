#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        // Sort intervals by end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int count = 1;  // Count of non-overlapping intervals we keep
        int end = intervals[0][1];  // End time of the last selected interval
        
        // Greedily select non-overlapping intervals
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= end) {  // Current interval doesn't overlap with the last selected one
                count++;
                end = intervals[i][1];  // Update end time
            }
        }
        
        // Return number of intervals to remove
        return intervals.size() - count;
    }
};
