class Solution:
    def findLUSlength(self, words):
        def isSubsequence(s, t):
            t = iter(t)
            return all(c in t for c in s)
 
        words.sort(key = lambda x:-len(x))
        for i, word in enumerate(words):
            if all(not isSubsequence(word, words[j]) for j in range(len(words)) if j != i): 
                return len(word)
        
        return -1
