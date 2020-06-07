class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        
        ans = [1] + [0]*amount
        
        for coin in coins:
            for i in range(coin, amount+1):
                ans[i] += ans[i-coin]
                
        return ans[-1]
        
