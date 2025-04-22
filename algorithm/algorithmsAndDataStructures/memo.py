INF = 20000000
def main():
    N, W = map(int, input().split())
    a = list(map(int, input().split()))
    
    exit = False
    for bit in range(1 << N):
        sum = 0
        for i in range(N):
            if bit & (1 << i):
                sum += a[i]
        if sum == W:
            exit = True
            break
    print("Yes" if exit else "No")

if __name__ == "__main__":
    main()