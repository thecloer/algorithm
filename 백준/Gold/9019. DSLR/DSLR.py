import sys
from collections import deque

global dp

def test(A:int, B:int):
    global dp
    dp[A] = ''
    q = deque([A])
    while q:
        i = q.popleft()
        for cmd in 'DSLR':
            n = i
            if cmd == 'D':
                n = (n * 2) % 10000
            elif cmd == 'S':
                n = 9999 if (n==0) else n-1
            elif cmd == 'L':
                n = (n % 1000) * 10 + (n // 1000)
            elif cmd == 'R':
                n = (n % 10) * 1000 + (n // 10)
            
            cmd = dp[i] + cmd
            if n == B:
                print(cmd)
                return 
            if dp[n] is None:
                dp[n] = cmd
                q.append(n)
    print(dp[B])

def main():
    global dp
    read = sys.stdin.readline
    T = int(read())
    for _ in range(T):
        dp = [None] * 10000
        A, B = map(int, read().split())
        test(A,B)

main()