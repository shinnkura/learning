import sys
from collections import Counter


def main():
    input = sys.stdin.readline
    cards = list(map(int, input().split()))
    count = Counter(cards)
    print(count)

    found = False

    for x in count:
        if count[x] >= 3:
            for y in count:
                if x != y and count[y] >= 2:
                    found = True
                    break
        if found:
            break

    print("Yes" if found else "No")


if __name__ == '__main__':
    main()
