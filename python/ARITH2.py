  
n = int(input())
for i in range(n):
    input()
    l = list(map(str, input().split()))
    result = int(l[0])
    for j in range(2, len(l) - 1, 2):
        if l[j - 1] == "+":
            result += int(l[j])
        elif l[j - 1] == "-":
            result -= int(l[j])
        elif l[j - 1] == "*":
            result *= int(l[j])
        else:
            result //= int(l[j])
    print(result)