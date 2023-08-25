import sys
readline = sys.stdin.readline

h, m = map(int, readline().split())
m += int(readline())
h= (h + m//60) % 24
m%=60
print(f'{h} {m}')