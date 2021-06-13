class Solution:
    def stoneGameVII(self, S: List[int]) -> int:
        N = len(S)
        dpCurr, dpLast = [0] * N, [0] * N
        for i in range(N - 2, -1, -1):
            total = S[i]
            dpLast, dpCurr = dpCurr, dpLast
            for j in range(i + 1, N):
                total += S[j]
                dpCurr[j] = max(total - S[i] - dpLast[j], total - S[j] - dpCurr[j-1])
        return dpCurr[-1]
