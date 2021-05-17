
class Solution {

public :

    int longestStrChain(vector<string> &words) {
        unordered_map<string, int> dp;

        // Sorting the list in terms of the word length.
        std::sort(words.begin(), words.end(), [](const std::string &word1, const std::string &word2) {
            return word1.size() < word2.size();
        });

        int longestWordSequenceLength = 1;

        for (const string &word : words) {
            int presentLength = 1;
            // Find all possible predecessors for the current word by removing one letter at a time.
            for (int i = 0; i < word.length(); i++) {
                string predecessor = word.substr(0, i) + word.substr(i + 1, word.length() + 1);
                if (dp.find(predecessor) != dp.end()) {
                    int previousLength = dp[predecessor];
                    presentLength = max(presentLength, previousLength + 1);
                }
            }
            dp[word] = presentLength;
            longestWordSequenceLength = max(longestWordSequenceLength, presentLength);
        }
        return longestWordSequenceLength;
    }
};
