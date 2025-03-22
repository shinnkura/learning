import sys
def main():
    input = sys.stdin.readline
    # TODO:なぜこちらのコードではいけないのか？

    # n = int(input())
    # if n % 2 == 1:
    #     # 奇数の場合
    #     k = n // 2
    #     if k == 1:
    #         ans = '-' * k + '-' + '-' * k
    #     elif n == 1:
    #         ans = '-'
    #     else:
    #         ans = '-' * k + '=' + '-' * k
    # else:
    #     # 偶数の場合
    #     if n == 2:
    #         ans = '--'
    #     else:
    #         k = (n - 2) // 2
    #         ans = '-' * k + '==' + '-' * k
    # print(ans)


    N = int(input().strip())

    if N % 2 == 1:
        # 奇数の場合
        result = "-" * (N // 2) + "=" + "-" * (N // 2)
    else:
        # 偶数の場合
        result = "-" * ((N // 2) - 1) + "==" + "-" * ((N // 2) - 1)

    print(result)


if __name__ == '__main__':
    main()