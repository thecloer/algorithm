import sys
read = sys.stdin.readline

def product(pool: list[int], n: int, r: int):
    if r == 0:
        return []
    if r == 1:
        return [[x] for x in pool]

    result = []
    for x in pool:
        for p in product(pool, n - 1, r - 1):
            result.append([x] + p)
    return result

def main():
    N, M = map(int, input().split())
    pool = list(range(1, N+1))
    for p in product(pool, N, M):
        print(*p)

main()