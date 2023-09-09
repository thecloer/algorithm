def combinations_with_replacement(pool: tuple[int], r: int):
    if r == 0:
        return []
    if r == 1:
        return [[x] for x in pool]

    result = []
    for i, x in enumerate(pool):
        for cwr in combinations_with_replacement(pool[i:], r - 1):
            result.append([x] + cwr)
    return result

def main():
    N, M = map(int, input().split())
    for cwr in combinations_with_replacement(tuple(range(1, N + 1)), M):
        print(*cwr)

main()