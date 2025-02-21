"""
選択ソート
- 前から順番に、一番小さい数字を探して、その数字を先頭に配置する
- 先頭の数字を除いた配列の中で、最小値を探して、その数字を先頭に配置する
- これを繰り返し、配列が空になるまで繰り返す
- 最悪計算量はO(n^2)
- 最良計算量はO(n^2)
- 平均計算量はO(n^2)
- 安定ソート
"""
from typing import List


def selection_sort(numbers: List[int]) -> List[int]:
    for i in range(len(numbers)):
        min_idx = i
        for j in range(i+1, len(numbers)):
            if numbers[min_idx] > numbers[j]:
                min_idx = j

        numbers[i], numbers[min_idx] = numbers[min_idx], numbers[i]
    return numbers


if __name__ == '__main__':
    import random
    nums = [random.randint(0, 1000) for _ in range(10)]
    print(selection_sort(nums))
