import sys
read = sys.stdin.readline

def products(pool: list[int], n: int, r: int):
    if r == 0 or n == 0:
        return []
    if r == 1:
        return [[x] for x in pool]

    result = []
    for x in pool:
        for p in products(pool, n - 1, r - 1):
            result.append([x] + p)
    return result

def main():
    N, M = map(int, read().split())
    pool = list(set(map(int, read().split())))
    pool.sort()
    for p in products(pool, N, M):
        print(*p)

main()