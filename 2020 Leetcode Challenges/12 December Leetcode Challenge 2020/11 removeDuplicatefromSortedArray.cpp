class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        if (n < 2)    return n;
        int slow = 2, fast = 2;
        
        while (fast < n) {
            if (nums[slow-2] != nums[fast]) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        
        return slow;
    }
};
