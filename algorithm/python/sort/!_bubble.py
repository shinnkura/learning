"""
バブルソート
- 隣り合う要素を比較して、大小関係が逆であれば入れ替える
    - 一番後ろまで行ったら、limitを減らして、同じように比較を繰り返す
- 最悪計算量はO(n^2)
- 安定ソート
- 比較回数はn(n-1)/2回
- 交換回数はn(n-1)/2回
"""
from typing import List

def bubble_sort(numbers: List[int]) -> List[int]:
    len_numbers = len(numbers)
    for i in range(len_numbers):
        for j in range(len_numbers - 1 - i): # 一番後ろまで行ったら、limitを１減らして、同じように比較を繰り返す
            if numbers[j] > numbers[j + 1]:
                numbers[j], numbers[j + 1] = numbers[j + 1], numbers[j]

    return numbers


if __name__ == '__main__':
    import random
    nums = [random.randint(0, 1000) for i in range(10)]
    print(bubble_sort(nums))
