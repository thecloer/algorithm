import sys
global ans, btns, N

def diff(n):
    global N
    return abs(N-n)

def dfs(n_str):
    global ans, btns, N
    for btn in btns:
        tmp = n_str + btn
        ans = min(ans, len(tmp) + diff(int(tmp)))
        if len(tmp) < 6:
            dfs(tmp)

def main():
    global ans, btns, N
    read = sys.stdin.readline
    
    N_str = read().rstrip()
    N = int(N_str)
    M = int(read())
    ans = diff(100)
    btns = set(map(str,range(10)))
    if M: 
        btns -= set(read().split())
    if M < 10 and len(N_str) < ans:
        dfs('')
    
    print(ans)

main()