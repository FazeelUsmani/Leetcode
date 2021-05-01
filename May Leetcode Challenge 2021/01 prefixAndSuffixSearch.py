Trie = lambda: collections.defaultdict(Trie)
WEIGHT = False

class WordFilter(object):
    def __init__(self, words):
        self.trie = Trie()

        for weight, word in enumerate(words):
            word += '#'
            for i in xrange(len(word)):
                cur = self.trie
                cur[WEIGHT] = weight
                for j in xrange(i, 2 * len(word) - 1):
                    cur = cur[word[j % len(word)]]
                    cur[WEIGHT] = weight

    def f(self, prefix, suffix):
        cur = self.trie
        for letter in suffix + '#' + prefix:
            if letter not in cur:
                return -1
            cur = cur[letter]
        return cur[WEIGHT]
