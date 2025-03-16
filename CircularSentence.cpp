class Solution {
    public:
        bool isCircularSentence(string sentence) {
            int n = sentence.length();
            
            // Check if first and last characters match
            if (sentence[0] != sentence[n - 1]) {
                return false;
            }
            
            // Iterate through the sentence
            for (int i = 0; i < n; i++) {
                if (sentence[i] == ' ') {
                    // If there's a space, check if characters on both sides match
                    if (sentence[i - 1] != sentence[i + 1]) {
                        return false;
                    }
                }
            }
            
            return true;
        }
    };