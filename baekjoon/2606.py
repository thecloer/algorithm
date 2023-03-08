# https://www.acmicpc.net/problem/2606
# 그래프, DFS, BFS

# My solution
def dfs(graph, visited, node):
    count = 1
    visited[node] = True
    for next_node in graph[node]:
        if not visited[next_node]: 
            count += dfs(graph, visited, next_node)
    return count

import sys
Io = sys.stdin.readline
n = int(Io())
m = int(Io())
graph = [[] for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, Io().rstrip().split())
    graph[a].append(b)
    graph[b].append(a)

visited = [False] * (n + 1)
result = dfs(graph, visited, 1)
print(result - 1)
