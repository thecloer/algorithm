import sys
from collections import deque

def main():
    read = sys.stdin.readline
    M, N, H = map(int, read().split())
    box = [[None for _ in range(N)] for _ in range(H)]
    q = deque()
    unripe = 0
    for h in range(H):
        for n in range(N):
            box[h][n] = list(map(int, read().split()))
            for m in range(M):
                if box[h][n][m] == 1:
                    q.append((h,n,m))
                elif box[h][n][m] == 0:
                    unripe += 1
    if unripe == 0:
        print(0)
        return
    
    ans = 0
    dxyz = ((1,0,0),(-1,0,0),(0,1,0),(0,-1,0),(0,0,1),(0,0,-1))    
    while q:
        h, n, m = q.popleft()
        for dx, dy, dz in dxyz:
            x, y, z = m+dx, n+dy, h+dz
            if not (0 <= z < H and 0 <= y < N and 0 <= x < M):
                continue
            if box[z][y][x] == 0:
                ans = box[z][y][x] = box[h][n][m] + 1
                unripe -= 1
                q.append((z, y, x))
    if unripe > 0:
        print(-1)
    else:
        print(ans-1)

main()