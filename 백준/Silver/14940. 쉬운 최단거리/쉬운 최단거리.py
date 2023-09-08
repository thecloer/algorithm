import sys
from collections import deque

def main():
    read = sys.stdin.readline
    N,M = map(int, read().split())
    start = (0,0)
    matrix = [[0]*M for _ in range(N)]
    visited = [[False]*M for _ in range(N)]
    for i in range(N):
        j = -1
        for v in map(int, read().split()):
            j += 1
            if v == 1:
                v = -1
            else:
                visited[i][j] = True
                if v == 2:
                    v = 0
                    start = (i, j)
            matrix[i][j] = v
    
    dxy = [(1,0), (-1,0), (0,1), (0,-1)]
    q = deque()
    q.append(start)
    while q:
        x, y = q.popleft()
        for dx, dy in dxy:
            nx = x + dx
            ny = y + dy
            if not ((0 <= nx < N) and (0 <= ny < M)):
                continue
            if visited[nx][ny]:
                continue
            matrix[nx][ny] = matrix[x][y] + 1
            visited[nx][ny] = True
            q.append((nx,ny))
    
    for i in range(N):
        print(*matrix[i])
main()