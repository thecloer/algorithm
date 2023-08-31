import sys
input = sys.stdin.readline

def main():
    N, M = map(int, input().split())
    subSum = [0] * (N+1)
    sum, idx = 0, 1
    for n in map(int, input().split()):
        sum += n
        subSum[idx] = sum
        idx += 1
    
    for _ in range(M):
        i, j = map(int, input().split())
        print(subSum[j]-subSum[i-1])

if __name__ == "__main__":
    main()