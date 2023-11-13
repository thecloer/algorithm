import sys
import heapq
import math
readline = sys.stdin.readline

N, M, X = map(int, readline().split())
graph = [[] for _ in range(N+1)]
for _ in range(M):
  st, en, t = map(int, readline().split())
  graph[st].append((en, t))

def dijkstra(start, end):
  costs = [math.inf] * (N+1)
  costs[start] = 0
  heap = []
  heapq.heappush(heap, (0, start))
  while heap:
    cost, node = heapq.heappop(heap)
    for adj_node, adj_cost in graph[node]:
      if costs[adj_node] > cost + adj_cost:
        costs[adj_node] = cost + adj_cost
        heapq.heappush(heap, (costs[adj_node], adj_node))
  return costs[end]

ans = 0
for node in range(1, N+1):
  ans = max(ans, dijkstra(node, X) + dijkstra(X, node))
print(ans)