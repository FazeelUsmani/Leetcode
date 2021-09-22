class Solution {
public:
    int maxLength(vector<string>& arr) {        
        // Pre-process arr with an optimizing helper
        // which converts each word to its character bitset
        // and then uses a set to prevent duplicate results
        unordered_set<int> optSet;
        for (auto& word : arr) 
            wordToBitSet(optSet, word);
        
        // Convert the set back to an array for iteration
        // then start up the recursive helper
        vector<int> optArr(optSet.begin(), optSet.end());
        return dfs(optArr, 0, 0);
    }
    
private:    
    void wordToBitSet(unordered_set<int>& optSet, string& word) {        
        // Initialize an empty int to use as a character bitset
        int charBitSet = 0;
        for (char& c : word) {
            // If the bitset contains a duplicate character
            // then discard this word with an early return
            // otherwise add the character to the bitset
            int mask = 1 << c - 'a';
            if (charBitSet & mask)
                return;
            charBitSet += mask;
        }
        
        // Store the length of the word in the unused space
        // then add the completed bitset to our optimized set
        optSet.insert(charBitSet + (word.length() << 26));
    }
    
    int dfs(vector<int>& optArr, int pos, int res) {
        // Separate the parts of the bitset res
        int oldChars = res & ((1 << 26) - 1);
        int oldLen = res >> 26;
        int best = oldLen;
        
        // Iterate through the remaining results
        for (int i = pos; i < optArr.size(); i++) {
            int newChars = optArr[i] & ((1 << 26) - 1);
            int newLen = optArr[i] >> 26;
            
            // If the two bitsets overlap, skip to the next result
            if (newChars & oldChars)
                continue;
            
            // Combine the two results and trigger the next recursion
            int newRes = newChars + oldChars + (newLen + oldLen << 26);
            best = max(best, dfs(optArr, i + 1, newRes));
        }
        return best;
    }
};
