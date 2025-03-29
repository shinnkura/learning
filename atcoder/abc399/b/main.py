import sys


def main():
    input = sys.stdin.readline
    n = int(input())
    p = list(map(int, input().split()))

    p_with_index = [(x, i) for i, x in enumerate(p)]
    # print(p_with_index)

    p_with_index.sort(key=lambda x: x[0], reverse=True)
    # print(p_with_index)

    rank = [0] * n
    # print(rank)
    current_rank = 1
    prev_value = p_with_index[0][0]

    for i, (value, original_index) in enumerate(p_with_index):
        # print('i:{}'.format(i))
        # print('value:{}'.format(value))
        # print('original_index:{}'.format(original_index))
        # print('prev_value:{}'.format(prev_value))
        if value != prev_value:
            current_rank = i + 1
        rank[original_index] = current_rank
        prev_value = value
        # print('current_rank:{}'.format(current_rank))
        # print('rank:{}'.format(rank))
        # print('--------------------------------')

    print(*rank, end=' ')


if __name__ == '__main__':
    main()
