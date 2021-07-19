from sortedcontainers import SortedList

class Solution:
    def createSortedArray(self, instructions):
        SList = SortedList()
        ans = 0
        for num in instructions:
            ans += min(SList.bisect_left(num), len(SList) - SList.bisect_right(num))
            ans %= (10**9 + 7)
            SList.add(num)

        return ans
