n = int(input())
result = 0
for i in range(max(1, n-len(str(n))*9),n):
    if sum(map(int, str(i))) + i == n:
        result = i
        break
print(result)