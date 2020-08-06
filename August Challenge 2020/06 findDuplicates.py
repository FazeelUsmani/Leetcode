class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        
        dict = {}
        for i in nums:
            if i in dict:
                dict[i] += 1
            else:
                dict[i] = 1
            
            
        ans = []
        for x in dict:
            if dict[x] > 1:
                ans.append(x)
                
        return ans
        
