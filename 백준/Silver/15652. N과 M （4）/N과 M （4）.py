import sys
read = sys.stdin.readline

def combinations_with_replacement(pool: list[int], n: int, r: int):
    if r == 0:
        return []
    if r == 1:
        return [[x] for x in pool]

    result = []
    for i, x in enumerate(pool):
        nextPool = pool[i:]
        for cwr in combinations_with_replacement(nextPool, n - 1, r - 1):
            result.append([x] + cwr)
    return result

def main():
    N, M = map(int, read().split())
    pool = list(range(1, N + 1))
    for cwr in combinations_with_replacement(pool, N, M):
        print(*cwr)

main()