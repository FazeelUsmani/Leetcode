import heapq

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:
        graph = collections.defaultdict(set)
        for i,j,w in flights:
            graph[i].add((j, w))
        
        heap = []
        cost = {}
        cost[src] = 0
        
        for j,w in graph[src]:
            heapq.heappush(heap, (0, j, w))
        
        while heap:
            stop, src, c = heapq.heappop(heap)
            if src not in cost or c < cost[src]:
                cost[src] = c
                if stop < K:
                    for j,w in graph[src]:
                        heapq.heappush(heap, (stop+1, j, c+w))
            
        return -1 if dst not in cost else cost[dst]
