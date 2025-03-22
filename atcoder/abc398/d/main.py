import sys


def main():
    input = sys.stdin.readline

    N, R, C = map(int, input().split())
    S = input().strip()

    move = {
        'N': (-1, 0),
        'S': (1, 0),
        'W': (0, -1),
        'E': (0, 1)
    }

    px, py = 0, 0

    B = set()
    B.add((0, 0))

    res = []

    for ch in S:
        dx, dy = move[ch]
        px += dx
        py += dy
        if (px - R, py - C) in B:
            res.append('1')
        else:
            res.append('0')
        if (px, py) not in B:
            B.add((px, py))

    print("".join(res))


if __name__ == '__main__':
    main()
