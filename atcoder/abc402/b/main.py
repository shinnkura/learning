from collections import deque

def main():
    Q = int(input())
    que = deque()
    for _ in range(Q):
        query = input().split()
        if query[0] == '1':
            x = int(query[1])
            que.append(x)
        else:
            served = que.popleft()
            print(served)

if __name__ == '__main__':
    main()
