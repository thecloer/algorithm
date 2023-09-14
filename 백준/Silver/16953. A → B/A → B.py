from collections import deque

A, B = map(int, input().split())

hash = dict()
hash[A] = 0
q = deque([A])
ans = -1
while q and ans < 0:
    x = q.popleft()
    for y in [2*x, 10*x+1]:
        if (y > B) or (y in hash):
            continue
        if y == B:
            ans = hash[x] + 1
            break
        hash[y] = hash[x] + 1
        q.append(y)

if ans < 0:
    print(-1)
else:
    print(ans+1)