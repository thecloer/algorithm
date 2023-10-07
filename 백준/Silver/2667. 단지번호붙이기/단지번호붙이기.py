import sys
In = sys.stdin.readline
n = int(In())
g = [list(map(int, In().rstrip())) for _ in range(n)]
visited = [[False] * n for _ in range(n)]
d = [(-1,0),(1,0),(0,-1),(0,1)]

def dfs(x, y, visited):
    visited[x][y] = True
    if g[x][y] == 0: return 0
    s = 0
    for dx, dy in d:
        nx = x + dx
        ny = y + dy
        if 0 <= nx < n and 0 <= ny < n:
            if not visited[nx][ny]:
                s += dfs(nx, ny, visited)
    return s + 1

result = []
for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            c = dfs(i,j, visited)
            if c:
                result.append(c)
result.sort()
print(len(result))
for i in result: print(i)