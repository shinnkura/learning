"""
コムソート
- コムは櫛（くし）のこと
    - 櫛は、髪をとかしていくかのようなソート
- コムソートは、櫛の間隔を徐々に狭めていくことで、ソートを行う
    - 櫛の間隔は、1.3倍ずつ狭めていく
    - len / 1.3 = gap 
        - gapの間隔で比較を行う
        - lenは、配列の長さ
        - 比べ終わったら、「gap（前に使用していた間隔） / 1.3」 の間隔で比較を行う
            - これを繰り返し、gapが1になったら、ソートが完了する
            - ソートが完了したら、隣接する数字を比べて、並び替えられたか確認する（swappedがFalseになったら、ソートが完了したと判断して、ループを抜ける）
- 最悪計算量はO(n^2)
- 最良計算量はO(n)
- 平均計算量はO(n^2)
- 安定ソート
"""

from typing import List


def comb_sort(numbers: List[int]) -> List[int]:
    len_numbers = len(numbers)
    gap = len_numbers
    swapped = True

    while gap != 1 or swapped:
        gap = int(gap / 1.3)
        if gap < 1:
            gap = 1

        swapped = False

        for i in range(0, len_numbers - gap):
            if numbers[i] > numbers[i + gap]:
                numbers[i], numbers[i + gap] = numbers[i + gap], numbers[i]
                swapped = True
    return numbers


if __name__ == '__main__':
    import random
    nums = [random.randint(0, 1000) for i in range(10)]
    print(comb_sort(nums))
