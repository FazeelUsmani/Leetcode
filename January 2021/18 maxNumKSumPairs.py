class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        
        cnt, ans = Counter(nums), 0
        for val in cnt:
            ans += min(cnt[val], cnt[k - val])
            
        return ans//2
