#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.empty()) return 0;
        
        int n = prices.size();
        
        // hold: maximum profit if we are holding a stock at the end of day i
        // notHold: maximum profit if we are not holding a stock at the end of day i
        int hold = -prices[0]; // initial state: buy stock on day 0
        int notHold = 0;       // initial state: do nothing on day 0
        
        for (int i = 1; i < n; i++) {
            // Two options for hold:
            // 1. Continue holding the stock from previous day
            // 2. Buy stock today after selling previously
            int prevHold = hold;
            hold = max(hold, notHold - prices[i]);
            
            // Two options for notHold:
            // 1. Continue not holding stock from previous day
            // 2. Sell the stock today (and pay the fee)
            notHold = max(notHold, prevHold + prices[i] - fee);
        }
        
        // Final answer is notHold because we want maximum profit without holding stock
        return notHold;
    }
};
