struct Node {
    string word;
    int index;
    Node(const string &word, int index) : word(word), index(index) {}
};
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<Node>> buckets;
        for (string& word : words) {
            char startingChar = word[0];
            buckets[startingChar].push_back(Node(word, 0));
        }
        int ans = 0;
        for (char c : s) {
            auto currBucket = buckets[c];
            buckets[c] = {};
            for (Node& node : currBucket) {
                node.index += 1; // Point to next character of node.word
                if (node.index == node.word.size()) {
                    ans += 1;
                } else {
                    buckets[node.word[node.index]].push_back(node);
                }
            }
        }
        return ans;
    }
};
