import sys
from collections import Counter


def main():
    input = sys.stdin.readline
    N = int(input().strip())
    A = list(map(int, input().split()))

    cnt = Counter(A)

    max_value = -1
    ans = -1

    for i in range(N):
        if cnt[A[i]] == 1:
            if A[i] > max_value:
                max_value = A[i]
                ans = i + 1

    print(ans)


if __name__ == '__main__':
    main()
