class Solution {
private:
    deque<int> S;
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        for (int i=0; i<nums.size(); i++) {
            while (!S.empty() && nums[S.back()] <= nums[i]) {
                S.pop_back();
            }
            while (!S.empty() && S.front() <= i-k) {
                S.pop_front();
            }
            S.push_back(i);
            if (i >= k-1) {
                res.push_back(nums[S.front()]);
            }
        }
        return res;
    }
};
