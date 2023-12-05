import sys
readline = sys.stdin.readline
n, k = map(int, readline().split())
coins = [int(readline()) for _ in range(n)]

ans, idx = 0, n
while k > 0:
    idx -= 1
    ans += k // coins[idx]
    k %= coins[idx]
print(ans)