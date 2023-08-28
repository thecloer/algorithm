import sys, heapq
input = sys.stdin.readline

def main():
    heap = []
    N = int(input())
    for _ in range(N):
        n = int(input())
        if n:
            heapq.heappush(heap, -n)
        else:
            if heap: print(-heapq.heappop(heap))
            else: print(0)

if __name__ == "__main__":
    main()