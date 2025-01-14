# https://atcoder.jp/contests/abc384/tasks/abc384_c
a, b, c, d, e = map(int, input().split())
A = [a, b, c, d, e]

lst = []
for bit in range(1, 32):
    tot = 0
    S = ""
    for i in range(5):
        if bit & (1 << i): # TODO：ここで何をしている？
            tot += A[i]
            S += chr(i + 65)
    lst.append((-tot, S))

lst.sort()

for _, S in lst:
    print(S)
