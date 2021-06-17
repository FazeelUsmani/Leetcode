class Solution:
    def numSubarrayBoundedMax(self, nums: List[int], left: int, right: int) -> int:
        ans, low, mid = 0, 0, 0
        for num in nums:
            if num > right: mid = 0
            else:
                mid += 1
                ans += mid
            if num >= left: low = 0
            else:
                low += 1
                ans -= low
        return ans
