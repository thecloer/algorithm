import sys
readline = sys.stdin.readline
zeros, ones = [1, 0], [0, 1]
for _ in range(41):
  zeros.append(zeros[-2]+zeros[-1])
  ones.append(ones[-2]+ones[-1])

t = int(readline())
inputs = [int(readline()) for _ in range(t)]
for n in inputs:
  print(f'{zeros[n]} {ones[n]}')