"""
ノームソート
- 前から順番に、隣接する数字を比べて、隣の方が小さければ入れ替える
    - 入れ替えたら、前に戻る。
    - 前に戻る時は、一つ前の値と比べて、小さければ入れ替える。入れ替えなくて良い場合は終了
    - また前から後ろに順番に比べていく
    - これを繰り返し、ソートが完了する

- 最悪計算量はO(n^2)
- 最良計算量はO(n)
- 平均計算量はO(n^2)
- 安定ソート
"""
from typing import List


def gnome_sort(numbers: List[int]) -> List[int]:
    len_numbers = len(numbers)
    index = 0
    while index < len_numbers:
        if index == 0:
            index += 1
        if numbers[index] >= numbers[index-1]:
            index += 1
        else:
            numbers[index], numbers[index-1] = numbers[index-1], numbers[index]
            index -= 1

    return numbers


if __name__ == '__main__':
    import random
    nums = [random.randint(0, 1000) for i in range(10)]
    print(gnome_sort(nums))
