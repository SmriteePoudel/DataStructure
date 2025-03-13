#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        int n = temperatures.size();
        std::vector<int> answer(n, 0);
        
        // Use a stack to keep track of indices of temperatures
        std::stack<int> st;
        
        for (int i = 0; i < n; i++) {
            // While the stack is not empty and the current temperature is higher
            // than the temperature at the index at the top of the stack
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                
                // Calculate the number of days to wait
                answer[prevIndex] = i - prevIndex;
            }
            
            // Push the current index onto the stack
            st.push(i);
        }
        
        return answer;
    }
};
