class Solution:

    def __init__(self, w: List[int]):
        self.nums = [w[0]]
        
        for i in range(1, len(w)):
            self.nums.append(self.nums[-1] + w[i])
        

    def pickIndex(self) -> int:
        val = random.randrange(1, self.nums[-1] + 1)
        return self.getPos(val)
        
    #Technically, find insert position of val
    
    def getPos(self, val):
        l = 0
        r = len(self.nums) - 1
        
        while l < r:
            mid = l + (r - l) // 2
            
            if self.nums[mid] < val:
                l = mid + 1
            else:
                r = mid
                
        return l
