# https://www.acmicpc.net/problem/1260
# dp - 연속합

# My solution
import sys
In = sys.stdin.readline
n = int(In())
ns = list(map(int, In().split()))

for i in range(1,n):
    ns[i] = max(ns[i], ns[i-1] + ns[i] )
    
print(max(ns))