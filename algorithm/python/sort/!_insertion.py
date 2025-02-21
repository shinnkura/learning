"""
挿入ソート
- 前から順番に、隣接する数字を比べて、隣の方が小さければ入れ替える
    - 入れ替えたら、前に戻る
    - 前に戻る時は、一つ前の値と比べて、小さければ入れ替える。入れ替えなくて良い場合は終了
    - また前から後ろに順番に比べていく
    - これを繰り返し、ソートが完了する
- 最悪計算量はO(n^2)
- 最良計算量はO(n)
- 平均計算量はO(n^2)
- 安定ソート
"""
from typing import List


def insertion_sort(numbers: List[int]) -> List[int]:
    len_numbers = len(numbers)
    for i in range(1, len_numbers):
        temp = numbers[i]
        j = i - 1

        while j >= 0 and numbers[j] > temp:
            numbers[j + 1] = numbers[j]
            j -= 1

        numbers[j + 1] = temp

    return numbers


if __name__ == '__main__':
    import random
    nums = [random.randint(0, 1000) for _ in range(10)]
    print(insertion_sort(nums))
