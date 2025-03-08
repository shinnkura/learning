def main():
    # 最初の行で N, M を受け取る
    N, M = map(int, input().split())

    # 黒色のボールの価値のリスト
    B = list(map(int, input().split()))

    # 白色のボールの価値のリスト
    W = list(map(int, input().split()))

    # 黒いボールを正の値とそれ以外に分ける
    B_pos = [b for b in B if b > 0]
    B_neg = [b for b in B if b <= 0]

    # 降順にソート
    B_pos.sort(reverse=True)
    B_neg.sort(reverse=True)

    # 白いボールの正の値のみを対象
    W_pos = [w for w in W if w > 0]
    W_pos.sort(reverse=True)

    total = sum(B_pos)  # 正の黒いボールの合計
    cnt_black = len(B_pos)

    # 白いボールについて、まずは黒いボールだけでカバーできる分だけ選ぶ
    k = min(cnt_black, len(W_pos))
    total += sum(W_pos[:k])

    # 残りの白い正のボールに対して、0以下の黒いボールとペアにする
    extra_white = W_pos[k:]

    for i in range(min(len(extra_white), len(B_neg))):
        pair_sum = extra_white[i] + B_neg[i]
        if pair_sum > 0:
            total += pair_sum
        else:
            break

    print(max(total, 0))


if __name__ == '__main__':
    main()
