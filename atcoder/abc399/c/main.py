class UnionFind:
    def __init__(self, dot):
        self.parent = list(range(dot))  # 最初はみんな自分自身が親
        self.size = [1] * dot           # 各グループのサイズ
        self.edge_count = [0] * dot     # 各グループに含まれる辺の数

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])  # 経路圧縮
        return self.parent[x]

    # 2つのグループを統合し、辺の数を1つ増やす
    # また親を更新する
    def unite(self, x, y):
        rx = self.find(x)
        ry = self.find(y)
        if rx == ry:
            self.edge_count[rx] += 1  # 同じグループなので、ループになる（辺だけ増える）
            return
        # 小さい方を親にする（サイズの大きさでマージ）
        if self.size[rx] < self.size[ry]:
            rx, ry = ry, rx
        self.parent[ry] = rx
        self.size[rx] += self.size[ry]
        self.edge_count[rx] += self.edge_count[ry] + 1


def main():
    import sys
    sys.setrecursionlimit(10**6)

    dot, edge = map(int, input().split())
    uf = UnionFind(dot)

    for _ in range(edge):
        u, v = map(int, input().split())
        uf.unite(u - 1, v - 1)

    seen = set()
    result = 0
    for i in range(dot):
        root = uf.find(i)
        if root not in seen:
            seen.add(root)
            # ループになる余分な辺の数 = 線の数 - (点の数 - 1)
            extra_edges = uf.edge_count[root] - (uf.size[root] - 1)
            result += extra_edges

    print('親: {}'.format(uf.parent))
    print('サイズ: {}'.format(uf.size))
    print('辺の数: {}'.format(uf.edge_count))
    print('--------------------------------')

    print(result)


if __name__ == "__main__":
    main()
