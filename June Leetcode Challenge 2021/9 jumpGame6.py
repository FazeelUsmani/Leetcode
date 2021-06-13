class Solution:
    def maxResult(self, nums: List[int], k: int) -> int:
        n = len(nums)
        dq = deque([0])  # store index of `nums` elements, elements is in decreasing order, the front is the maximum element.
        for i in range(1, n):
            # nums[i] = max(nums[i-k], nums[i-k+1],.., nums[i-1]) + nums[i] = nums[dq.front()] + nums[i]
            nums[i] = nums[dq[0]] + nums[i]

            # Add a nums[i] to the deq
            while dq and nums[dq[-1]] <= nums[i]: dq.pop()  # Eliminate elements less or equal to nums[i], which will never be chosen in the future
            dq.append(i)

            # Remove if the last element is out of window size k
            if i - dq[0] >= k: dq.popleft()

        return nums[n - 1]
