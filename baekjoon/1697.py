# https://www.acmicpc.net/problem/1697
# 그래프, BFS - 숨박꼭질

# My solution
import sys
n, k = map(int, sys.stdin.readline().split())

def f(n,k):
  if n>=k:return n-k
  if k==1:return 1
  if k%2:return min(f(n,k+1),f(n,k-1))+1     
  return min(k-n,f(n,k//2)+1)

print(f(n,k))

'''
# f(n,k): n에서 k로 가는 최단 횟수
def f(n,k):
    if n >= k: return n - k # n>=k 일 경우, n-k번 (-1,0)
    if k == 1: return 1 # n=0, k=1일 경우 1번
    if k % 2: # k가 홀수면 마지막 한 칸은 반드시 걸어가야함
        # n에서 k+1을 간뒤 k로 오는 경우와 n에서 k-1로 간 뒤 k로 오는 값 중 작은 값
        # f(n, k+1): n에서 k+1로 가는경우
        # f(n, k-1): n에서 k-1로 가는경우
        # +1 마지막 한칸 걸어가기
        return min(f(n, k+1), f(n, k-1)) + 1
    
    # k가 짝수라면, 순간이동으로 오거나 걸어오거나
    # 걸어가는 경우와 n에서 순간이동 전(k//2)까지 간 후 순간이동하는 경우중 작은 값
    # Ex) n=15, k=20
    # 그냥 걸어가는 경우: 5
    # 20으로 순간이동하는 10을 가는 경우에서 순간이동 +1: f(15,10) + 1 = 6
    # Ex) n=5, k=16
    # 1. 그냥 걸어가는 경우: 11
    # 2. 8까지 간 후 순간이동: f(5, 8) + 1
    # 2.1. 그냥 걸어가는 경우: 3 => 3 + 1 = 4
    $ 2.2. 4까지 간 후 순간이동: f(5, 4) + 1 => 1 + 1 + 1 = 3
    return min(k-n, f(n, k//2) + 1)

    
- k가 짝수인 경우 순간이동 후 걸어가는 경우는 고려하지 않는가?
k가 홀수인 경우 걸어간 후 순간이동은 3번째 분기(k % 2 == 1)에 포함.
k가 짝수인 경우 걸어간 뒤 순간이동하는 경우가 순간이동 한 뒤 걸어가는 것보다 빠거나 같다.
따라서 k가 짝수인 경우 순간이동 후 걸어가는 경우는 고려할 필요 없다.

proof)
let both integer p and q that 2 * (n + p) = k, 2 * n + q = k
p.s.) 2 * (n + p) = k means walk-teleport case
      2 * n + q = k means teleport-walk case

2n + 2p = 2n + q
2p = q 
thus, abs(p) <= abs(q)

therefore, walk-teleport case is always faster than teleport-walk case or same.
'''