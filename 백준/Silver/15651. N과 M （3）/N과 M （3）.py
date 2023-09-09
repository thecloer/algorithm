def product(pool: tuple[int], r: int):
    if r == 0:
        return []
    if r == 1:
        return [[x] for x in pool]
    result = []
    for x in pool:
        for p in product(pool, r - 1):
            result.append([x] + p)
    return result

def main():
    N, M = map(int, input().split())
    for p in product(tuple(range(1, N+1)), M):
        print(*p)

main()