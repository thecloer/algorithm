import sys
from collections import deque

def dfs(node):
    visited[node] = True
    dfs_result.append(node)
    for next in sorted(graph[node]): 
        if not visited[next]: dfs(next)

def bfs(start):
    visited[start] = True
    queue = deque([start])
    while queue:
        node = queue.popleft()
        bfs_result.append(node)
        for next in sorted(graph[node]): 
            if not visited[next]: 
                visited[next] = True
                queue.append(next)

Io = sys.stdin.readline
n, m, v = map(int,Io().split())
graph = [[] for _ in range(n+1)]

for i in range(m):
    s, e = map(int, Io().split())
    graph[s].append(e)
    graph[e].append(s)

dfs_result =[]
bfs_result =[]

visited = [False]*(n+1)
dfs(v)
visited = [False]*(n+1)
bfs(v)

print(*dfs_result)
print(*bfs_result)