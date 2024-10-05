import sys
readline = sys.stdin.readline

def find(x):
    if parents[x] == x:
        return x
    parents[x] = find(parents[x])
    return parents[x]

V, E = map(int, readline().split())
edges = [tuple(map(int, readline().split())) for _ in range(E)]
edges.sort(key= lambda x : x[2])

parents = [i for i in range(V+1)]
cnt = 0
ans = 0
for a, b, w in edges:
    A, B = find(a), find(b)
    if A == B:
        continue
    parents[A] = B
    cnt += 1
    ans += w
    if cnt == V - 1:
        break

print(ans)