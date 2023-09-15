A, B = map(int, input().split())
count = 1

while A < B:
    if B % 2 == 0:
        B = B//2
    elif B % 10 == 1:
        B = B//10
    else:
        break
    count += 1

if A == B:
    print(count)
else:
    print(-1)