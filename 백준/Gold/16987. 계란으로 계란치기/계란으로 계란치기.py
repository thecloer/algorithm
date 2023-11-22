import sys
readline = sys.stdin.readline

N = int(readline())
eggs = [list(map(int, readline().split())) for _ in range(N)]

def backTracking(picked):
  global ans
  if picked == N:
    cnt = 0
    for hp, _ in eggs:
      if hp <= 0:
        cnt += 1
    ans = max(ans, cnt)
    return
  
  if eggs[picked][0] <= 0:
    return backTracking(picked + 1)
  
  hasCrashed = False
  for selected in range(N):
    if selected == picked:
      continue
    if eggs[selected][0] <= 0:
      continue
    eggs[selected][0] -= eggs[picked][1]
    eggs[picked][0] -= eggs[selected][1]
    backTracking(picked + 1)
    eggs[selected][0] += eggs[picked][1]
    eggs[picked][0] += eggs[selected][1]
    if not hasCrashed:
      hasCrashed = True
  
  if not hasCrashed:
    backTracking(picked + 1)

ans = 0
backTracking(0)
print(ans)