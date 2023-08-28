import sys, heapq
readline = sys.stdin.readline
def main():
  N = int(readline())
  heap = []
  for _ in range(N):
    n = int(readline())
    if n:
      heapq.heappush(heap, -n)
    else:
      if heap: print(-heapq.heappop(heap))
      else: print(0)

if __name__ == "__main__":
  main()