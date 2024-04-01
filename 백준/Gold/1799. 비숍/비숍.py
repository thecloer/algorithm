import sys
readline = sys.stdin.readline

N = int(readline())
board = [list(map(int, readline().split())) for _ in range(N)]
diagonals = [[[False] * (2 * N) for _ in range(2)] for _ in range(2)]

ans = [0, 0]
candidates = [[], []]
for i in range(N):
    for j in range(N):
        if board[i][j] == 1:
            candidates[(i ^ j) & 1].append((i, j))

def backtracking(color, cur, cnt):
    if cur == len(candidates[color]):
        ans[color] = max(ans[color], cnt)
        return
    
    if cnt + len(candidates[color]) - cur <= ans[color]:
        return
    
    x, y = candidates[color][cur]
    if diagonals[color][0][x + y] or diagonals[color][1][x - y + N]:
        backtracking(color, cur + 1, cnt)
        return
    
    diagonals[color][0][x + y] = diagonals[color][1][x - y + N] = True
    backtracking(color, cur + 1, cnt + 1)
    diagonals[color][0][x + y] = diagonals[color][1][x - y + N] = False
    backtracking(color, cur + 1, cnt)

backtracking(0, 0, 0)
backtracking(1, 0, 0)
print(ans[0] + ans[1])