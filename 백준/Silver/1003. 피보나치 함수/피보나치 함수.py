import sys
readline = sys.stdin.readline
t = int(readline())
inputs = [int(readline()) for _ in range(t)]
for n in inputs:
  if n == 0:
    print('1 0')
  elif n == 1:
    print('0 1')
  else:
    zeros, ones = [1, 0], [0, 1]
    for _ in range(n-1):
      zeros.append(zeros[-2]+zeros[-1])
      ones.append(ones[-2]+ones[-1])
    print(f'{zeros[-1]} {ones[-1]}')