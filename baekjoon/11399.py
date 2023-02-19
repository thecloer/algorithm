# https://www.acmicpc.net/problem/11399
# Greedy, sort - ATM

# My solution
n = int(input())
p = list(map(int, input().split()))
p.sort()

result = 0
for i in range(n):
    result += p[i] * (n - i)
print(result)

""" Note
## Summary Problem.
input N , [p1, p2, ..., pn]
output min(p1 + (p1 + p2) + (p1 + p2 + p3) + ... + (p1 + ... + pn))
N, pi: natural number

## Proof
p1 + (p1 + p2) + (p1 + p2 + p3) + ... + (p1 + ... + pn)
= p1
+ p1 + p2
+ p1 + p2 + p3
+ ...
+ p1 + p2 + p3 + ... + p(n-1)
+ p1 + p2 + p3 + ... + p(n-1) + pn

= n*pn + (n - 1)*pn + ... + 2*p(n-1) + 1*pn

when a > b, let's compare "(n + 1)*a + n*b" to "n*a + (n + 1)*b"
{(n + 1)*a + n*b} - {n*a + (n + 1)*b}
= a - b > 0

thus, (n + 1)*a + n*b > n*a + (n + 1)*b

therefore it's minimum when p1 <= p2 <= ... <= pn
"""