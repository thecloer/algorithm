import sys

if __name__ == '__main__':
    read = sys.stdin.readline
    N = int(read())
    dp = [0]*(N+1)
    for i in range(N-1, 0, -1):
        x = dp[i+1]
        if i*3 <= N:
            x = min(x, dp[i*3])
        if i*2 <= N:
            x = min(x, dp[i*2])
        dp[i] = x + 1
    print(dp[1])