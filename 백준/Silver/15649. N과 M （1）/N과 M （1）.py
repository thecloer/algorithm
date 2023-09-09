global N, M

def dfs(rest: set[int], lst: list[int]):
    global N, M
    if len(lst) == M:
        print(*lst)
        return
    for i in range(1, N+1):
        if i in rest:
            rest.remove(i)
            lst.append(i)
            dfs(rest, lst)
            lst.pop()
            rest.add(i)

def main():
    global N, M
    N, M = map(int, input().split())
    rest = {i for i in range(1, N+1)}
    dfs(rest, [])


main()