# ディープラーニング

ニューラルネットワークの層が深くなったもの

# ニューラルネットワーク（教師あり学習）

教師あり学習２つある
ー　回帰（連続値）：数値の予測（家賃や株価）
ー　分類（離散値）：犬か猫か

## 回帰

ノードを重ねることで、入力層から出力層までのパスを作る

- バイアス項：ノードの入力に加算される定数
  　　　- ノードは別に存在し、値は「１」

ノードを重ねる際は、重みつけて、次のノードに渡す

- この重みのことを「パラメータ」という
- エッジ：ノードとノードをつなぐ線

順番にノードを重ねていき、最終的に一つのノードを出力する（予測値）
このノードの重なり全体を「全結合層」という

## 全結合層

３つの層がある

- 入力層
  - データの入り口
  - ここには複数のノードが入る
  - 住居の場合、「部屋の広さ」や「築年数」「駅からの距離」などがノードに当たる
  - また、このようなノードのことを「入力変数」と言ったりもする
- 中間層
  - データの加工
  - 隠れ層(hidden layer)ともいい、よく「h」で表記される
- 出力層
  - 出力結果を目的変数ともいう
  - 住居の場合、「家賃」が目的変数に当たる

Pytorch で全結合層のノードの重ね方

```python
nn.Linear(入力ノード数, 出力ノード数)

# 入力層が３つで、中間層が２つ、出力層が一つの場合
nn.Linear(3, 2)
nn.Linear(2, 1)
```

# ニューラルネットワーク内の計算

Step1: 線形変換（ノードを重ねる際に、ウェイトをかける）
Step2: 非線形変換（中間層と出力層のノード内で使用）
※ Step1 と Step2 を繰り返す（次の中間層へ線形変換し、ノード内で非線形変換を行う）
Step3: 目的関数（損失関数）の計算（予測値と正解値の誤差を計算）

順伝播

- 入力層から出力層までのデータの流れ

逆伝播

- 出力層から入力層までのデータの流れ

ニューラールネットワークの目的は、Step ３。つまり、予測値と目標値の誤差を最小化すること。
そのために、順伝播と逆伝播を繰り返し、ウェイトを更新する。

## 線形変換

ノードを重ねる際に、ウェイト（パラメータ）をかけること。
計算式：y = Wx + b

- y：出力値
- W：ウェイト（パラメータ）
- x：入力値
- b：バイアス項

一つの線で表現できる一次関数に変換できるために、線形変換という。

## 非線形変換

データに対するモデルの表現力を高める

- 複数のデータがあった際に、一次関数のようなグラフで、データを表現しきれない
- そのため、非線形変換を使用する
  - 多次元配列のようなグラフで、データを表現する
- 活性化関数：非線形変換を行う関数

活性化関数にはたくさんのものがある

シグモイド関数

- 現在はほとんど使われていない
- 勾配消失の問題があるため
- ニューラルネットワークの層が深くなると、勾配がどんどん小さくなっていく。しかし、シグモイド関数を使用すると勾配が 0 になってしまう。

正規化線形関数（ReLU 関数）

- 現在は最もよく使われている
- 微分しても勾配が消失しない

ソフトマックス関数

- 出力層で使用される
- 確率分布を出力する
- 出力層のノードが３つの場合、それぞれのノードの出力値を足すと１になる

## 目的関数(損失関数・コスト関数)

- 予測値と目標値の差
- 回帰と分類で使う手法が異なる

回帰の場合

- 平均二乗誤差（MSE: Mean Squared Error）

分類の場合

- 交差エントロピー誤差(Cross Entropy Error)

# 逆伝播

- パラメータの更新

最急降下法（SGD：確率的勾配降下法）

- 勾配を求め、その勾配に応じてパラメータを更新する
- 勾配が 0 になるところで、パラメータの更新が止まる

誤差逆伝播法(連鎖律)

- 勾配を求めるために、誤差を逆伝播させる

## 再急降下法

1. ランダムに初期値 w を求める
2. 勾配(傾き) を求める
3. 勾配分だけ w を動かす
4. 2 に戻る

勾配爆発

- 勾配が大きすぎて、パラメータの更新がうまくいかない
- 勾配が 0 になってしまう
- そのために、勾配を小さくする工夫が必要
- 学習係数（0.01）を勾配にかけてあげることで、勾配を小さくすることができる

大域的最適解

- 勾配が０になる点が複数存在する場合、その中で最も小さい点を大域的最適解という
- 普通に再急降下法を行うと、局所最適解に陥ることが多い

# Pytorch

3 ノード -> ２ノードの全結合層（fully-connected layer）

```python
fc = nn.Linear(3, 2)
fc.weight # 重み
fc.bias # バイアス
```

重みやバイアスといったパラメータは、最初はランダムに設定される

乱数のシードを固定

```python
torch.manual_seed(0)
```

- pytorch での計算は、テンソルというものを使用する
  - テンソルは、多次元配列のこと
  - テンソルの計算は、ベクトルや行列の計算と同じように行うことができる

```python
x = torch.tensor([1., 2., 3.])
x # 出力: tensor([1., 2., 3.])
type(x) # 出力: torch.Tensor
x.dtype # 出力: torch.float32
```

線形変換の計算

```python
fc = nn.Linear(3, 2)
u = fc(x)
u # 出力: tensor([-0.1261, -0.1261], grad_fn=<AddBackward0>)
```

非線形変換の計算

```python
import torch.nn.functional as F

fc = nn.Linear(3, 2)
u = fc(x)
h = F.relu(u)
h # 出力: tensor([0.00000, 0.0526], grad_fn=<ReluBackward0>)
```

Relu 関数は、0 以下の値を 0 に変換し、0 より大きい値をそのままの値に変換する
つまり、`max(0, x)`を計算している

目的関数

```python
# 目標値
t = torch.tensor([1., 3.])

# 予測値
y = torch.tensor([2., 4.])

# 平均二乗誤差
mse = F.mse_loss(y, t)
mse # 出力: tensor(1.0000)
```