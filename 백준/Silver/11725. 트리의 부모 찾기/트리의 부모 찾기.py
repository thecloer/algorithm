import sys
sys.setrecursionlimit(100_000)
read = sys.stdin.readline

N = int(read())
parent = [0] * (N + 1)
parent[1] = 1


def union(a, b):
    if parent[a] == 0:
        parent[a] = b
        if parent[b] == 0:
            parent[b] = a
    elif parent[b] == 0:
        parent[b] = a
    elif parent[b] != a:
        union(b, parent[b])
        parent[b] = a


ancestor = []
for _ in range(N-1):
    a, b = map(int, read().split())
    if a == 1:
        ancestor.append(b)
    elif b == 1:
        ancestor.append(a)
    union(a, b)

for anc in ancestor:
    union(1, anc)

for i in range(2, N + 1):
    print(parent[i])
