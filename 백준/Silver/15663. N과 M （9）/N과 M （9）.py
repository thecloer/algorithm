import sys
read = sys.stdin.readline

def permutations(pool, n, r):
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
        nextPool = pool[:]
        nextPool.remove(x)
        for p in permutations(nextPool, n - 1, r - 1):
            result.append([x] + p)
    return result

def main():
    N, M = map(int, read().split())
    pool = list(map(int, read().split()))
    pool.sort()
    for p in permutations(pool, N, M):
        print(*p)

main()