global N,M

def dfs(lst:list[int]):
    global N,M
    l = len(lst)
    if l == M:
        print(*lst)
        return
    for i in range(1,N+1):
        if i not in lst:
            lst.append(i)
            dfs(lst)
            lst.pop()

def main():
    global N,M
    N, M = map(int, input().split())
    dfs([])
    
main()