import sys
read = sys.stdin.readline

def combinations_with_repetitions(pool: list[int], n: int, r: int):
    if r == 0 or r > n:
        return []

    keys = []
    for x in pool:
        if x not in keys:
            keys.append(x)

    if r == 1:
        return [[x] for x in keys]

    result = []
    for x in keys:
        nextPool = []
        once = True
        for y in pool:
            if y < x:
                continue
            elif once and y == x:
                once = False
                continue
            nextPool.append(y)
        for cwr in combinations_with_repetitions(nextPool, n - 1, r - 1):
            result.append([x] + cwr)
    return result

def main():
    N, M = map(int, read().split())
    pool = list(map(int, read().split()))
    pool.sort()
    for cwr in combinations_with_repetitions(pool, N, M):
        print(*cwr)

main()