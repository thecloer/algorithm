import sys
n, k = map(int, sys.stdin.readline().split())

def bfs(n,k):
    visited = set()
    pl = [(n,k)]
    sec = 0
    while True:
        xpl = []
        for n, k in pl:
            if n in visited: continue
            visited.add(n)
            if n == k:
                return sec
            elif n > k:
                xpl.append((n - 1, k))
            else:
                xpl.extend([(n - 1, k), (n + 1, k), (2 * n, k)])
        sec += 1
        pl = xpl
        
print(bfs(n,k))