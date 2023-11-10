class DSU:
    def __init__(self, graph):
        self.p = {i:i for i in graph}

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, x, y):
        self.p[self.find(x)] = self.find(y)
        
    def groups(self):
        ans = defaultdict(list)
        for el in self.p.keys():
            ans[self.find(el)].append(el)
        return ans
        
class Solution:
    def matrixRankTransform(self, M):
        n, m = len(M), len(M[0])
        rank = [0] * (m + n)
        d = defaultdict(list)
        
        for i, j in product(range(n), range(m)):
            d[M[i][j]].append([i, j])

        for a in sorted(d):
            graph = [i for i, j in d[a]] + [j + n for i, j in d[a]]
            dsu = DSU(graph)
            for i, j in d[a]: dsu.union(i, j + n)

            for group in dsu.groups().values():
                mx = max(rank[i] for i in group)
                for i in group: rank[i] = mx + 1
                    
            for i, j in d[a]: M[i][j] = rank[i]
            
        return M
