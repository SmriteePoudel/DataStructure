#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        
        // Sort balloons by their end coordinates
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int arrows = 1;  // Start with one arrow
        int arrowPos = points[0][1];  // Position of the first arrow
        
        // Iterate through all balloons
        for (int i = 1; i < points.size(); i++) {
            // If the current balloon starts after the arrow position,
            // we need a new arrow
            if (points[i][0] > arrowPos) {
                arrows++;
                arrowPos = points[i][1];  // Update arrow position
            }
            // Otherwise, the current balloon is burst by the existing arrow
        }
        
        return arrows;
    }
};
