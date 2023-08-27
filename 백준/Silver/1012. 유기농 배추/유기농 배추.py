from collections import deque
import sys
readline = sys.stdin.readline

d = ((1,0),(-1,0),(0,1),(0,-1))
def bfs(graph, M, N, x, y):
    graph[y][x] = 0
    queue = deque([(x,y)])
    while queue:
        x, y = queue.popleft()
        for dx, dy in d:
            nx, ny = x+dx, y+dy
            if (0 <= nx < M) and (0 <= ny < N) and graph[ny][nx] == 1:
                graph[ny][nx] = 0
                queue.append((nx,ny))

T = int(readline())
for _ in range(T):
    M, N, K = map(int, readline().split())
    graph = [[0]*M for _ in range(N)]
    points = []
    for _ in range(K):
        x, y = map(int, readline().split())
        points.append((x, y))
        graph[y][x] = 1
    
    ans = 0
    for x, y in points:
        if graph[y][x] == 1:
            bfs(graph,M,N,x,y)
            ans += 1
    print(ans)