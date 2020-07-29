class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        
        cnt = [0]*26
        for i in tasks:
            cnt[ord(i)-65] += 1
            
        maxCnt = 0
        for i in range(26):
            maxCnt = max(maxCnt, cnt[i])
            
        e = 0
        for i in range(26):
            if (cnt[i] == maxCnt):
                e += 1
        
        return max(len(tasks), (maxCnt-1)*(n+1)+e);
                
            
        
