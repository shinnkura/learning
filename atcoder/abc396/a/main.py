def has_tree_count(n, a):
    for i in range(n - 2):
        if a[i] == a[i + 1] == a[i + 2]:
            return "Yes"
    return "No"


if __name__ == "__main__":
    n = int(input().strip())
    a = list(map(int, input().split()))
    print(has_tree_count(n, a))