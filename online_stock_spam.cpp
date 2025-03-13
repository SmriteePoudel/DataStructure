#include <stack>
#include <vector>
using namespace std;

class StockSpanner {
private:
    // Stack to store pairs of (price, span)
    stack<pair<int, int>> priceStack;
    
public:
    StockSpanner() {
        // No initialization needed
    }
    
    int next(int price) {
        int span = 1; // At minimum, the span is 1 (today)
        
        // Pop elements from the stack as long as they are less than or equal to current price
        // Add their spans to current span
        while (!priceStack.empty() && priceStack.top().first <= price) {
            span += priceStack.top().second;
            priceStack.pop();
        }
        
        // Push the current price and its span onto the stack
        priceStack.push({price, span});
        
        return span;
    }
};
