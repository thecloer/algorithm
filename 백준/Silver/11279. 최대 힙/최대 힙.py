import sys, heapq
readline = sys.stdin.readline
N = int(readline())
heap = []
while N > 0:
  N -= 1
  n = int(readline())
  if n == 0:
    if heap: print(-heapq.heappop(heap))
    else: print(0)
  else:
    heapq.heappush(heap, -n)