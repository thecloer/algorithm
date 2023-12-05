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