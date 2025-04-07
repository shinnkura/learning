import sys
def main():
    input = sys.stdin.readline

    n = int(input())
    s = set()
    b = 1


    while b * b <= n:
        x = b * b
        while x <= n:
            x *= 2
            if x <= n:
                s.add(x)
        b += 1

    print(len(s))

if __name__ == '__main__':
    main()