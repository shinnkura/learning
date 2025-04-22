def main():
    N, v = map(int, input().split())
    a = list(map(int, input().split()))
    exist = False
    for i in range(N):
        if(a[i] == v):
            exist = True

    if(exist):
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()