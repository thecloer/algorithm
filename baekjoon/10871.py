# https://www.acmicpc.net/problem/10871
# 구현 - k보다 작은 수 

# My solution
import sys
Io = sys.stdin.readline
n, x = map(int, Io().split())
a = list(map(int, Io().rstrip().split()))

result = []
for i in a:
    if i < x: result.append(i)
print(*result)