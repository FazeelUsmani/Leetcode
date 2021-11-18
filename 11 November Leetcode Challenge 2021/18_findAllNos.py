class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        
        ans = []
        n = len(nums)        
        x = set(nums)
        
        for i in range(1, n+1, 1):
            if (i not in x):
                ans.append(i)
                
        return ans
        
