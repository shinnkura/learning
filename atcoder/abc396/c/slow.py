import sys


def max_value(N, M, B, W):
    B.sort(reverse=True)
    W.sort(reverse=True)
    # print(B)
    # print(W)
    # print(sum(B))
    # print(sum(W))

    max_sum = 0
    max_black_sum = 0
    max_white_sum = 0

    for i in range(N):
        if B[i] < 0:
            black_sum = sum(B[:i + 1])
            white_sum = sum(W[:i + 1]) if i < len(W) and W[i] > 0 else max_white_sum
            max_black_sum = min(max_black_sum, black_sum)
            max_white_sum = max(max_white_sum, white_sum)
            max_sum = max(max_sum, max_black_sum + max_white_sum)
            # print("if文の中")
            # print("ループ回数：", i)
            # print("black_sum", black_sum)
            # print("white_sum", white_sum)
            # print("max_black_sum", max_black_sum)
            # print("max_white_sum", max_white_sum)
            # print("max_sum", max_sum)
            # print("\n")

            break
        black_sum = sum(B[:i + 1])
        white_sum = sum(W[:i + 1]) if i < len(W) and W[i] > 0 else max_white_sum
        max_black_sum = max(max_black_sum, black_sum)
        max_white_sum = max(max_white_sum, white_sum)
        max_sum = max(max_sum, max_black_sum + max_white_sum)
        # print("ループ回数：", i)
        # print("black_sum", black_sum)
        # print("white_sum", white_sum)
        # print("max_black_sum", max_black_sum)
        # print("max_white_sum", max_white_sum)
        # print("max_sum", max_sum)
        # print("\n")

    return max_sum


if __name__ == "__main__":
    N, M = map(int, sys.stdin.readline().split())
    B = list(map(int, sys.stdin.readline().split()))
    W = list(map(int, sys.stdin.readline().split()))
    print(max_value(N, M, B, W))
