def permutations(pool: list[int], r: int):
    if r == 0 or r > len(pool):
        return []
    if r == 1:
        return [[x] for x in pool]

    result = []
    for x in pool:
        nextPool = list(filter(lambda y: y != x, pool))
        for p in permutations(nextPool, r - 1):
            result.append([x]+p)
    return result

def main():
    N, M = map(int, input().split())
    pool = list(map(int, input().split()))
    pool.sort()
    for cwr in permutations(pool, M):
        print(*cwr)

main()