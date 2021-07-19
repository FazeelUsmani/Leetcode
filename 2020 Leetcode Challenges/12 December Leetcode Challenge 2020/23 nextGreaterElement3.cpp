class Solution {
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);
        if (next_permutation(num.begin(), num.end())) {
            long res = stol(num);
            return res > INT_MAX ? -1 : res;
        } else {
            return -1;
        }
    }
};
