# https://www.acmicpc.net/problem/11047
# Greedy - 동전 0

# My solution
n, k = map(int, input().split())
values = []
for _ in range(n):
    values.append(int(input()))
values.reverse()

result = 0
for value in values:
    num = k // value
    if num > 0:
        result += num
        k -= value * num
print(result)

""" Note
## Summary Problem.
input: n , K, values = [A1, A2, ..., An]
output: when K = a*A1 + b*A2 + ... + c*An, min(a + b + ... + c)
A(n+1) = a*An ,a is a natural number
"""