class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        
        ans = []
        for i, r in enumerate(mat):
            if r[0] == r[-1] == 0:
                ans.append((-1, i))
                continue
            l, h = 0, len(r) - 1
            while l < h:
                m = (l + h + 1) // 2
                if r[m]:
                    l = m
                else:
                    h = m - 1
            ans.append((l, i))
        return [i for v, i in sorted(ans)[:k]]
