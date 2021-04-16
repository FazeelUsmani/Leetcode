class Solution {
public:
    string removeDuplicates(string s, int k) {
        // support variables
        string res;
        int counter, tot = s.size(), pos = 0, prevPos;
        pair<char, int> stack[tot];
        // parsing s
        for (char c: s) {
            prevPos = pos - 1;
            // case 1: new insertion for empty stack or different char
            if (!pos || stack[prevPos].first != c) {
                stack[pos++] = {c, 2};
            }
            // case 2: same character found
            else {
                counter = stack[prevPos].second;
                if (counter == k) tot -= k, pos--;
                else stack[prevPos].second++;
            }
        }
        // properly sizing res
        res.resize(tot);
        // building res
        for (int i = 0, j = 0; i < pos; i++) {
            auto [c, freq] = stack[i];
            while (--freq) res[j++] = c;
        }
        return res;
    }
};
