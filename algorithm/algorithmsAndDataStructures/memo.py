memo = [-1] * 50

def fibo(N: int) -> int:
    if N == 0:
        return 0
    elif N == 1:
        return 1
    if memo[N] != -1:
        print(f"{N}の時、{memo[N]}を返す")
        return memo[N]
    print(f"{N}の時、{memo[N]}をmemo化！")
    memo[N] = fibo(N - 1) + fibo(N - 2)
    return memo[N]

if __name__ == "__main__":
    fibo(49)
    for N in range(2, 50):
        print(N, "のフィボナッチ数は", memo[N])