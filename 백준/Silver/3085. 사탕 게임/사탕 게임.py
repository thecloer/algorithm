import sys
In = sys.stdin.readline
N = int(In())
graph = [list(In().rstrip()) for _ in range(N)]

def checkRow(row):
    result = cnt = 1
    for col in range(1, N):
        cnt = cnt+1 if graph[row][col-1] == graph[row][col] else 1
        result = max(result, cnt)
    return result

def checkCol(col):
    result = cnt = 1
    for row in range(1, N):
        cnt = cnt+1 if graph[row-1][col] == graph[row][col] else 1
        result = max(result, cnt)
    return result

def swap(row1, col1, row2, col2):
    graph[row1][col1], graph[row2][col2] = graph[row2][col2], graph[row1][col1]

ans = 1
for i in range(N):
    ans = max(ans, checkCol(i), checkRow(i))

if(ans < N):
    for i in range(N):
        for j in range(N):
            if i<N-1 and graph[i][j] != graph[i+1][j]:
                swap(i,j, i+1,j)
                ans = max(ans, checkRow(i), checkRow(i+1), checkCol(j))
                swap(i,j, i+1,j)
            if j<N-1 and graph[i][j] != graph[i][j+1]:
                swap(i,j, i,j+1)
                ans = max(ans, checkCol(j), checkCol(j+1), checkRow(i))
                swap(i,j, i,j+1)
print(ans)