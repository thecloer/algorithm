from collections import deque
import math
import sys
read = sys.stdin.readline

primes = [2]
for i in range(3, 100000, 2):
    r = math.sqrt(i)
    for p in primes:
        if p > r:
            primes.append(i)
            break
        if i % p == 0:
            break
    else:
        primes.append(i)

T = int(read())
for _ in range(T):
    N, A, B = map(int, read().split())
    primesBetweenAB = set()
    for p in primes:
        if p < A:
            continue
        if p > B:
            break
        primesBetweenAB.add(p)
    if len(primesBetweenAB) == 0:
        print(-1)
        continue

    dp = {N: 0}
    q = deque([N])
    ans = -1
    while q:
        n = q.popleft()
        if n in primesBetweenAB:
            ans = dp[n]
            break

        jumpTo = list(filter(lambda x: not (
            x < 0 or x in dp), [n//2, n//3, n+1, n-1]))
        for next in jumpTo:
            dp[next] = dp[n] + 1
            q.append(next)
    print(ans)
