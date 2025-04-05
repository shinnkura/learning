import sys
def main():
    input = sys.stdin.readline
    N, M = map(int, input().split())

    X = 0
    current = 1

    for _ in range(M + 1):
        X += current
        if X > 10**9:
            print('inf')
            break
        current *= N
    else:
        print(X)


if __name__ == '__main__':
    main()