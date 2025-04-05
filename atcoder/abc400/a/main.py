import sys
def main():
    input = sys.stdin.readline
    a = int(input())

    if 400 % a != 0:
        print(-1)
    else:
        print(400 // a)

if __name__ == '__main__':
    main()