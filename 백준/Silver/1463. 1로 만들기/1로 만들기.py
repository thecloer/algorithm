import sys

def steps(dp, n):
    if dp[n] == -1:
        isEven = ((n & 1) == 0)
        isMultipleOfThree = (n % 3 == 0)
        if isEven and isMultipleOfThree:
            dp[n] = 1 + min(steps(dp, n//3), steps(dp, n//2))
        elif isEven:
            dp[n] = 1 + min(steps(dp, n//2), steps(dp, n-1))
        elif isMultipleOfThree:
            dp[n] = 1 + min(steps(dp, n//3), steps(dp, n-1))
        else:
            dp[n] = 1 + steps(dp, n-1)
    return dp[n]

if __name__ == '__main__':
    read = sys.stdin.readline
    N = int(read())
    dp = [-1] * (N+1)
    dp[1] = 0
    print(steps(dp, N))