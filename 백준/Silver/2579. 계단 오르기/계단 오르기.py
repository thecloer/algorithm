import sys

if __name__ == '__main__':
    read = sys.stdin.readline
    N = int(read())
    steps = [int(read()) for _ in range(N)]
    
    if N < 3:
        print(sum(steps))
    else:
        scores = [0] * N
        scores[0] = steps[0]
        scores[1] = steps[0] + steps[1]
        scores[2] = max(steps[0]+steps[2], steps[1]+steps[2])
        for i in range(3, N):
            scores[i] = steps[i] + max(scores[i-2], scores[i-3] + steps[i-1])
        print(scores[N-1]) 