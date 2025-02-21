"""
コックテイルソート（シェーカーソート）
- バブルソートの改良版
- バブルソートは、隣り合う要素を比較して、大小関係が逆であれば入れ替える
- コックテイルソートは、隣り合う要素を比較して、大小関係が逆であれば入れ替える
    - 先頭から、隣り合う要素を比較して、大小関係が逆であれば入れ替える。この時、入れ替えたらswappedをTrueにする
    - 一番後ろまで行ったら、limitを減らして、同じように比較を繰り返す
    - 先頭から、隣り合う要素を比較して、大小関係が逆であれば入れ替える。この時、入れ替えたらswappedをTrueにする
    - 一番前まで行ったら、limitを減らして、同じように比較を繰り返す
    - これを繰り返し、swappedがFalseになったら、ソートが完了したと判断して、ループを抜ける
- バブルソートとの違い
    - バブルソートは、前から後ろへ比べていたが、コックテイルソートは、前から後ろへ比べたあとに、後ろから前へ比べる
    - コックテイルソートは、ソートしたかどうかをフラグ（swapped）で管理しているので、最後までソートする必要がない
- 最悪計算量はO(n^2)
- 最良計算量はO(n)
- 平均計算量はO(n^2)
- 安定ソート
"""
from typing import List


def cocktail_sort(numbers:List[int]) -> List[int]:
    len_numbers = len(numbers)
    swapped = True
    start = 0
    end = len_numbers - 1
    while swapped:
        swapped = False

        for i in range(start, end):
            if numbers[i] > numbers[i+1]:
                numbers[i], numbers[i+1] = numbers[i+1], numbers[i]
                swapped = True

        if not swapped:
            break

        swapped = False
        end = end - 1 # 一番後ろまで行ったら、limitを減らして、同じように比較を繰り返す

        for i in range(end-1, start-1, -1):
            if numbers[i] > numbers[i+1]:
                numbers[i], numbers[i+1] = numbers[i+1], numbers[i]
                swapped = True

        start = start + 1 # 一番前まで行ったら、limitを減らして、同じように比較を繰り返す

    return numbers


if __name__ == '__main__':
    import random
    nums = [random.randint(0, 1000) for i in range(10)]
    print(cocktail_sort(nums))
