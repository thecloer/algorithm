def combinations(pool: list[int], r: int):
    if r == 0 or r > len(pool):
        return []
    if r == 1:
        return [[x] for x in pool]

    result = []
    for i, x in enumerate(pool):
        for c in combinations(pool[i+1:], r - 1):
            result.append([x] + c)
    return result

def main():
    N, M = map(int, input().split())
    pool = list(map(int, input().split()))
    pool.sort()
    for c in combinations(pool, M):
        print(*c)

main()