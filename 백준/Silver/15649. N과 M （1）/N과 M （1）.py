from itertools import permutations

N, M = map(int, input().split())
for c in permutations(range(1, N+1), M):
    print(*c)

