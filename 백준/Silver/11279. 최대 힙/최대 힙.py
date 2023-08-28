import sys
import heapq

def main():
  input = sys.stdin.readline
  N = int(input())
  heap = []
  for _ in range(N):
    n = int(input())
    if n:
      heapq.heappush(heap, -n)
    else:
      if heap: print(-heapq.heappop(heap))
      else: print(0)

if __name__ == "__main__":
  main()