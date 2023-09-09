def combinations(pool: tuple[int], r: int):
    if r == 0 or len(pool) < r:
        return []
    if r == 1:
        return [[x] for x in pool]

    result = []
    for i, x in enumerate(pool):
        nextPool = pool[i+1:]
        for c in combinations(nextPool, r - 1):
            result.append([x] + c)
    return result

def main():
    N, M = map(int, input().split())
    result = combinations(tuple(range(1, N+1)), M)
    for c in result:
        print(*c)

main()