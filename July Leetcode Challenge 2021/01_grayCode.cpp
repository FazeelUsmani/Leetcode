class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        grayCodeHelper(result, n);
       
        return result;
    }

    void grayCodeHelper(vector<int>& result, int n) {
        if (n == 0) {
            result.push_back(0);
            return;
        }
        // we derive the n bits sequence from the (n - 1) bits sequence.
        grayCodeHelper(result, n - 1);
        int currentSequenceLength = result.size();
        // Set the bit at position n - 1 (0 indexed) and assign it to mask.
        int mask = 1 << (n - 1);
        for (int i = currentSequenceLength - 1; i >= 0; i--) {
            // mask is used to set the (n - 1)th bit from the LSB of all the numbers present in the current sequence.
            result.push_back(result[i] | mask);
        }
        return;
    }
};
