import sys
read = sys.stdin.readline

def combinations(pool: list[int], r: int):
    if r == 0:
        return []
    if r == 1:
        return [[x] for x in pool]

    result = []
    for i, x in enumerate(pool):
        nextPool = pool[i:]
        for c in combinations(nextPool, r - 1):
            result.append([x] + c)
    return result

def main():
    N, M = map(int, read().split())
    pool = list(set(map(int, read().split())))
    pool.sort()
    for c in combinations(pool, M):
        print(*c)

main()