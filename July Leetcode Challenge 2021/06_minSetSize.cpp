class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (int x : arr) ++cnt[x];

        vector<int> bucket(1e5 + 1);
        int maxFreq = 1;
        for (auto [_, freq] : cnt) {
            ++bucket[freq];
            maxFreq = max(maxFreq, freq);
        }

        int ans = 0, removed = 0, half = arr.size() / 2, freq = maxFreq;
        while (removed < half) {
            ans += 1;
            while (bucket[freq] == 0) --freq;
            removed += freq;
            --bucket[freq];
        }
        return ans;
    }
};
