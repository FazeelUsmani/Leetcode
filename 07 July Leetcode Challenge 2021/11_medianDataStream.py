from sortedcontainers import SortedList
class MedianFinder:

    def __init__(self):
        self.arr = SortedList()

    def addNum(self, num: int) -> None:
        self.arr.add(num)

    def findMedian(self) -> float:
        n = len(self.arr)
        if n % 2 == 1:
            return self.arr[n//2]
        return (self.arr[n//2] + self.arr[n//2-1]) / 2
