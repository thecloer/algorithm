from collections import deque
import sys
read = sys.stdin.readline

N = int(read())
tree = [0] * (N + 1)
tree[1] = 1
graph = [set() for _ in range(N + 1)]
for _ in range(N - 1):
    a, b = map(int, read().split())
    graph[a].add(b)
    graph[b].add(a)

q = deque([1])
while q:
    root = q.popleft()
    children = graph[root]
    for child in children:
        if tree[child] == 0:
            tree[child] = root
            q.append(child)

for i in range(2, N + 1):
    print(tree[i])