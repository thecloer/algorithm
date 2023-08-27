import sys 
readline = sys.stdin.readline

def search(exp, n, row, col):
    if exp == 0: return n

    w = 2**(exp-1)
    size = w**2
    
    if row >= w:
        n += 2*size
        row -= w
    if col >= w:
        n+= size
        col -= w
    return search(exp-1, n, row, col)
    
N, r, c = map(int, readline().split())
print(search(N, 0, r, c))