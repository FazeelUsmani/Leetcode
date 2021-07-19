class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (char x: s)
            res = res*26 + (x-65) + 1;
        return res;
    }
};
