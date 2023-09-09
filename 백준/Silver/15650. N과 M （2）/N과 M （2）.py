global N, M, pool

def dfs(lst: list[int], poolStart: int):
    global N, M, pool
    depth = len(lst)
    if depth == M:
        print(*lst)
        return
    for i in range(poolStart, N):
        if depth + N - i < M:
            continue
        lst.append(pool[i])
        dfs(lst, i + 1)
        lst.pop()

def main():
    global N, M, pool
    N, M = map(int, input().split())
    pool = tuple(range(1, N+1))
    dfs([], 0)

main()