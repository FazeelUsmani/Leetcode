class Solution:
    def maximumUniqueSubarray(self, nums):
        beg, end, S, n, sm = 0, 0, set(), len(nums), 0
        ans = 0
        while end < n:
            if nums[end] not in S:
                sm += nums[end]
                S.add(nums[end])
                end += 1
                ans = max(ans, sm)
            else:
                sm -= nums[beg]
                S.remove(nums[beg])
                beg += 1
        
        return ans 
