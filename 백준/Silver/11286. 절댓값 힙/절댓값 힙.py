import sys
import heapq
readline = sys.stdin.readline
N = int(readline())
heap = []
for _ in range(N):
  n = int(readline())
  if n == 0:
    if heap:
      print(heapq.heappop(heap)[1])
    else:
      print(0)
  else:
    heapq.heappush(heap, (abs(n),n))