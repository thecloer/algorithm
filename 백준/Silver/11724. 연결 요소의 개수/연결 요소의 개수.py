import sys, heapq
input = sys.stdin.readline

if __name__ == "__main__":
    N, M = map(int, input().split())
    visited = [False] * (N+1)
    graph = [[0] for _ in range(N+1)]
    for _ in range(M):
        i, j = map(int, input().split())
        graph[i].append(j)
        graph[j].append(i)
    
    ans = 0 
    queue = []
    for i in range(1, N+1):
        if visited[i]: continue
        ans += 1
        heapq.heappush(queue, i)
        while queue:
            node = heapq.heappop(queue)
            visited[node] = True
            while graph[node]:
                adj = graph[node].pop()
                if not visited[adj]:
                    heapq.heappush(queue, adj)
    print(ans)