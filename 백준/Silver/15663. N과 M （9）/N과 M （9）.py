from collections import Counter
import sys
read = sys.stdin.readline

def permutations(pool, n, r):
    if r == 0 or r > n:
        return []

    keys = list(pool.keys())
    keys.sort()
    if r == 1:
        return [[x] for x in keys]

    result = []
    for x in keys:
        pool[x] -= 1
        if pool[x] == 0:
            pool.pop(x)

        for p in permutations(pool, n - 1, r - 1):
            result.append([x] + p)

        if x in pool:
            pool[x] += 1
        else:
            pool[x] = 1
    return result

def main():
    N, M = map(int, read().split())
    pool = Counter(map(int, read().split()))
    for p in permutations(pool, N, M):
        print(*p)

main()