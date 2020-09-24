from collections import Counter
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        d1 = Counter(secret)
        a, b = 0, 0
        n = len(secret)
        diff = []
        for i in range(n):
            if secret[i] == guess[i]:
                a += 1
                d1[secret[i]] -= 1
            else:
                diff.append(guess[i])
        for j in diff:
            if d1[j] > 0:
                b += 1
                d1[j] -= 1
        return '{}A{}B'.format(a,b)
