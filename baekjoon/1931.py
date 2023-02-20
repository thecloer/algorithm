# https://www.acmicpc.net/problem/1931
# Greedy, sort - 회의실 배정

# My solution
from operator import itemgetter
from sys import stdin
In = stdin.readline
n = int(In())
schedules = sorted([tuple(map(int, In().split())) for _ in range(n)], key = lambda x: (x[1],x[0]))

result = last = 0
for start, end in schedules:
    if start >= last: 
        result += 1
        last = end
print(result)


""" Note
## Summary Problem.
input: n, schedules = [(x1, y1), (x2, y2), ..., (xn, yn)]
output: max(count([(xa, ya), (xb, yb), ..., (xc, yc)])) (ya <= xb, yb <= ... xc)
n, x, y: natural number
"""