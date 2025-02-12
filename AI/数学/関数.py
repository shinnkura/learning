import numpy as np
import matplotlib.pyplot as plt
"""
Numpyの配列
・大量のデータを効率よく扱うことができる
"""
a = [0, 1, 2, 3, 4, 5]
b = np.array(a) # リストからNumpyの配列を作成
print(b)


"""
linSpace
・Numpyのメソッド
・値が並んだ配列を作ることができる
・linSpace関数では範囲を指定し、その区間を標準で50に区切る
・このような等間隔の配列は、グラフにおけるX軸の値として使われる
"""

x = np.linspace(-5, 5)
print(x)
print(len(x))


"""
一次関数
・グラフの描画は、matplotlibのpyplotを使う
"""
y = 2 * x + 1

plt.plot(x, y) # x, yをプロット
plt.show() # グラフを表示


"""
グラフの装飾
"""
x = np.linspace(-3, 3)
y_1 = 1.5 * x
y_2 = -2 * x + 1

# 軸のラベル
plt.xlabel("x value", size=14)
plt.ylabel("y value", size=14)

# グラフのタイトル
plt.title("My Graph", size=20)

# グリッド表示
plt.grid()

# グラフの表示
plt.plot(x, y_1, label="y1")
plt.plot(x, y_2, label="y2")
plt.legend() # 凡例を表示

plt.show()



"""
二次関数と三次関数
"""

x = np.linspace(-4, 4)
y_1 = 2*x + 1
y_2 = x**2 - 4
y_3 = 0.5*x**3 - 6*x

plt.plot(x, y_1, label="1st")
plt.plot(x, y_2, label="2nd")
plt.plot(x, y_3, label="3rd")
plt.legend()

plt.xlabel("x value", size=14)
plt.ylabel("y value", size=14)

plt.grid()
plt.show()
