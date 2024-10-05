import sys
import heapq
readline = sys.stdin.readline

V, E = map(int, readline().split())
adj = [[] for _ in range(V + 1)]

for _ in range(E):
    a, b, c = map(int, readline().split())
    adj[a].append((c, b))
    adj[b].append((c, a))

ans = cnt = 0
vis = [False] * (V + 1)
heap = [(0, 1)]
while cnt < V:
    w, x = heapq.heappop(heap)
    if vis[x]:
        continue
    vis[x] = True
    cnt += 1
    ans += w
    for pair in adj[x]:
        if not vis[pair[1]]:
            heapq.heappush(heap, pair)

print(ans)