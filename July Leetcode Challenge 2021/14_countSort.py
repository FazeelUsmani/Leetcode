class Solution:
    def customSortString(self, order: str, str: str) -> str:
        cnt = Counter(str)
        ans = ""
        for c in order:
            if cnt[c] > 0:
                ans += cnt[c] * c
                del cnt[c]
        for c, v in cnt.items():
            ans += v * c
        return ans
