import sys
readline = sys.stdin.readline
N, M = map(int, readline().split())
dic = dict()
for _ in range(N):
  email, pw = readline().split()
  dic[email] = pw
for _ in range(M):
  email = readline().rstrip()
  print(dic[email])