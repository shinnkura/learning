"""
ボゴソート
- 配列をランダムに並び替えて、ソートされるまで繰り返す
- ジョークとしても有名
- 最悪計算量はO(∞)
- 最悪のアルゴリズムとして有名
"""
import random
from typing import List


def in_order(numbers: List[int]) -> bool:
    return all(numbers[i] <= numbers[i+1] for i in range(len(numbers)-1)) # allメソッドは、引数が全てTrueの場合にTrueを返す
    # 上記の1行と以下の4行は同じ意味
    # for i in range(len(numbers)-1):
    #     if numbers[i] > numbers[i+1]:
    #         return False
    # return True


def bogo_sort(numbers: List[int]) -> List[int]:
    while not in_order(numbers):
        random.shuffle(numbers)
    return numbers


if __name__ == '__main__':
    nums = [random.randint(0, 1000) for _ in range(10)]
    print(bogo_sort(nums))

