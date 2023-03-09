# https://www.acmicpc.net/problem/2178
# graph, BFS - 미로탐색

# My solution
import sys
from collections import deque
Io = sys.stdin.readline

n,m = map(int, Io().split())
graph = [list(map(int,list(Io().rstrip()))) for _ in range(n)]
d = [(1,0),(-1,0),(0,1),(0,-1)]
def bfs(x,y):
    queue = deque([(x,y)])
    while queue:
        x, y = queue.popleft()
        for dx, dy in d:
            xn = x + dx
            yn = y + dy
            if xn < 0 or xn >=n or yn <0 or yn >= m: continue
            if graph[xn][yn] == 1:
                graph[xn][yn] = graph[x][y] + 1
                queue.append((xn,yn))
    return graph[n-1][m-1]

print(bfs(0,0))
