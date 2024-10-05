import sys
from collections import deque
readline = sys.stdin.readline

dxy = ((1,0), (-1,0), (0,1), (0,-1))

N, M = map(int, readline().split())
board = [readline().strip() for _ in range(N)]
dist = [[[0, 0] for _ in range(M)] for _ in range(N)] 
# dist[N][M][2]

ans = -1
dist[0][0][0] = dist[0][0][1] = 1
queue = deque([(0, 0, 0)])

while queue:
    x, y, broken = queue.popleft()
    if (x, y) == (N - 1, M - 1):
        ans = dist[x][y][broken]
        break
      
    nd = dist[x][y][broken] + 1
    for dx, dy in dxy:
        nx, ny = x + dx, y + dy
        if not (0 <= nx < N and 0 <= ny < M):
            continue
          
        if board[nx][ny] == '0' and dist[nx][ny][broken] == 0:
            dist[nx][ny][broken] = nd
            queue.append((nx, ny, broken))
        elif board[nx][ny] == '1' and broken == 0 and dist[nx][ny][1] == 0:
            dist[nx][ny][1] = nd
            queue.append((nx, ny, 1))

print(ans)