class Solution(object):

    def makesquare(self, nums):
        if not nums:
            return False

        L = len(nums)
        perimeter = sum(nums)

        possible_side = perimeter // 4

        if possible_side * 4 != perimeter:
            return False

        memo = {}

        def recurse(mask, sides_done):

            total = 0
            for i in range(L - 1, -1, -1):
                if not (mask & (1 << i)):
                    total += nums[L - 1 - i]

            if total > 0 and total % possible_side == 0:
                sides_done += 1

            if sides_done == 3:
                return True

            if (mask, sides_done) in memo:
                return memo[(mask, sides_done)]

            ans = False

            c = int(total / possible_side)
            rem = possible_side * (c + 1) - total

            # Iterate over all the matchsticks
            for i in range(L - 1, -1, -1):

                if nums[L - 1 - i] <= rem and mask & (1 << i):
                    if recurse(mask ^ (1 << i), sides_done):
                        ans = True
                        break
            memo[(mask, sides_done)] = ans
            return ans

        return recurse((1 << L) - 1, 0)
