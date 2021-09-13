class Solution {
public:
    int findMaxNumberofPattern(string text, string pattern) {
        int n = text.length(), m = pattern.length(), answer = INT_MAX;
        int freqInText[26] = {0}, freqInPattern[26] = {0};
        
        // Frequency of characters in text.
        for (int i = 0; i < n; i++) {
            freqInText[text[i] - 'a']++;
        }
        // Frequency of characters in pattern.
        for (int i = 0; i < m; i++) {
            freqInPattern[pattern[i] - 'a']++;
        }
        
        // Compare the maximum string that can be produced
        // considering one character at a time.
        for (int i = 0; i < 26; i++) {
            // Do not divide by zero.
            if (freqInPattern[i]) {
                answer = min(answer, freqInText[i] / freqInPattern[i]);
            }
        }
        
        return answer;
    }
    
    int maxNumberOfBalloons(string text) {
        // Any string made up of lowercase English letters.
        string pattern = "balloon";
        return findMaxNumberofPattern(text, pattern);
    }
};
