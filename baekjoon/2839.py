# https://www.acmicpc.net/problem/2839
# Greedy - 설탕 배달

# My solution
n = int(input())
bags = (5,3)
bag0_max = n // bags[0]

result = -1
for bag0_num in range(bag0_max,-1,-1):
    rest = n - bag0_num * bags[0]
    if rest % bags[1] == 0:
        result = bag0_num + rest // bags[1]
        break
print(result)

""" Note
## Summary Problem.
input N
N = 5x + 3y, return max(x + y)
if no (x, y), return -1
N, x, y: natural number

## Proof
let N = 5x + 3y be True, let's find (x, y)

case 1) N = 5i + 0  -> (i, 0)
case 2) N = 5i + 1
          = 5(i - 1) + 3 * 2  -> (i - 1, 2)
case 3) N = 5i + 2
          = 5(i - 2) + 3 * 4  -> (i - 2, 4)
case 4) N = 5i + 3  -> (i, 1)
case 5) N = 5i + 4 
          = 5(i - 1) + 3 * 3  -> (i - 1, 3)

thus, when N = 5x + 3y be True, y can be [0, 2, 4, 1, 3]
(in case 2, 3, 5, x could be negative.)

## Code
n = int(input())
map = [0, 2, 4, 1, 3]
y = map[N % 5]
x = (N - 3 * y) // 5   # in case (2, 3, 5), x could be negative.
result = x + y if x >= 0 else -1 
"""