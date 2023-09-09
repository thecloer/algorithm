def products(pool, r):
    if r == 0:
        return []
    if r == 1:
        return [[x] for x in pool]
    result = []
    for x in pool:
        for p in products(pool, r-1):
            result.append([x] + p)
    return result

def main():
    N, M = map(int, input().split())
    pool = list(map(int, input().split()))
    pool.sort()
    for c in products(pool, M):
        print(*c)

main()