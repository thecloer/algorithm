A, B = map(int, input().split())
count = 1

while B > A:
    if B & 1 == 0:
        B //= 2
    elif B % 10 == 1:
        B //= 10
    else:
        break
    count += 1

if A != B:
    count = -1

print(count)