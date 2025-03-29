import sys
def main():
    input = sys.stdin.readline
    n = int(input())
    s = input().strip()
    t = input().strip()

    count = 0
    for i in range(n):
        if s[i] != t[i]:
            count += 1
    print(count)

if __name__ == '__main__':
    main()