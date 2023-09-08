import sys
from collections import deque

def main():
    read = sys.stdin.readline
    M, N = map(int, read().split())
    box = [None] * N
    q = deque()
    unripe = 0
    for y in range(N):
        box[y] = list(map(int, read().split()))
        for x in range(M):
            if box[y][x] == 1:
                q.append((x, y))
            elif box[y][x] == 0:
                unripe += 1
    if unripe == 0:
        print(0)
        return
    
    ans = 0
    dxy = ((1,0),(-1,0),(0,1),(0,-1))
    while q:
        x, y = q.popleft()
        for dx, dy in dxy:
            nx, ny = x+dx, y+dy
            if not (0 <= nx < M and 0 <= ny < N):
                continue
            if box[ny][nx] == 0:
                ans = box[ny][nx] = box[y][x] + 1
                unripe -= 1
                q.append((nx, ny))
    if unripe > 0:
        print(-1)
    else:
        print(ans-1)

main()