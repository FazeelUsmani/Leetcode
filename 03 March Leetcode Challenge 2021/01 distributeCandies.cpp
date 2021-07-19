class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        
        unordered_map <int, int> freq;
        for (int x: candyType)
            freq[x]++;
        
        int freqSize = freq.size();
        int n = candyType.size()/2;
        
        if (n > freqSize)
            return freqSize;
        else
            return n;
        
        
    }
};
