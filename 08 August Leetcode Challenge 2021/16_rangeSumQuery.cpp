class NumArray { // 12 ms, faster than 99.87%
public:
    vector<int>& preSum; // `preSum` will reference to `nums` array, no copy at all!
    
    NumArray(vector<int>& nums) : preSum(nums) {
        for (int i = 1; i < preSum.size(); ++i)
            preSum[i] += preSum[i-1]; 
    }
    
    int sumRange(int left, int right) {
        if (left == 0) return preSum[right];
        return preSum[right] - preSum[left-1];
    }
};
