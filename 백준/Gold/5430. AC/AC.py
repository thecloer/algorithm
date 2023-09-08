import sys
from collections import deque

def test(p, n, q):
    isReverse = False
    for cmd in p:
        if cmd == 'R':
            isReverse = not isReverse
        elif cmd == 'D':
            if n == 0:
                return 'error'
            elif isReverse:
                q.pop()
            else:
                q.popleft()
            n -= 1
    result = []
    for _ in range(n):
        if isReverse:
            result.append(q.pop())
        else:
            result.append(q.popleft())
    return '[' + ','.join(result) + ']'
    
def main():
    read = sys.stdin.readline
    T = int(read())
    for _ in range(T):
        p = read().rstrip()
        n = int(read())
        q = deque(read()[1:-2].split(','))
        print(test(p, n, q))

main()