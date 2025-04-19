from collections import deque


def main():
    N, M = map(int, input().split())
    cnt = [0] * M
    ing_to_dish = [[] for _ in range(N + 1)]
    for i in range(M):
        data = list(map(int, input().split()))
        k = data[0]
        cnt[i] = k
        for a in data[1:]:
            ing_to_dish[a].append(i)
    B = list(map(int, input().split()))
    eatable = 0
    ans = []
    for b in B:
        for d in ing_to_dish[b]:
            cnt[d] -= 1
            if cnt[d] == 0:
                eatable += 1
        ans.append(eatable)

    print("\n".join(map(str, ans)))


if __name__ == "__main__":
    main()
