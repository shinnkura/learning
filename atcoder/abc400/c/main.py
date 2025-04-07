import math

def count_good_integers(N):
    count = 0
    # e = 1 から、2^e が N 以下となる最大の e までループ
    e = 1
    while 2**e <= N:
        print(f"e: {e}")
        # T = N / 2^e の整数部分
        T = N // (2**e)
        print(f"T: {T}")
        # m^2 <= T となる最大の m を整数で求める（m は正の整数）
        m_max = math.isqrt(T)
        print(f"m_max: {m_max}")
        # m が奇数である条件を満たすものの個数は、1 から m_max までの奇数の個数
        # 奇数の個数 = (m_max + 1) // 2
        count += (m_max + 1) // 2
        print(f"count: {count}")
        e += 1
        print("--------------------------------")
    return count

# 入力の読み込み
N = int(input().strip())
print(count_good_integers(N))
