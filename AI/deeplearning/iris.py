import torch
import torch.nn as nn
import torch.nn.functional as F
from sklearn.datasets import load_iris

iris = load_iris()

# 入力値と目標値
x = iris['data']
t = iris['target']

print(type(x), type(t))  # 出力: (numpy.ndarray, numpy.ndarray)

# pytorchのテンソルに変換
x = torch.tensor(x, dtype=torch.float32)
t = torch.tensor(t, dtype=torch.int64)

# データの形状を確認
print(x.shape)  # 出力: torch.Size([150, 4])
print(t.shape)  # 出力: torch.Size([150])

"""
torch.Size([150, 4])
150: データの数
4: パラメータ数

今回は、
がく片の長さ (sepal length)
がく片の幅 (sepal width)
花びらの長さ (petal length)
花びらの幅 (petal width)
の４つのパラメータを使用して、どの品種に分類されるかを予測する
"""

# DataLoaderの作成
# 入力値と目標値をまとめる
dataset = torch.utils.data.TensorDataset(x, t)
print(dataset[0])  # 出力: TensorDataset(tensor([5.1000, 3.5000, 1.4000, 0.2000]), tensor(0)) <- ([入力値],[目標値])
len(dataset)  # 出力: 150

# データセットの分割
# データ全体を6対2対2に分割
# 訓練（学習）データ: 60%
# 検証（バリデーション）データ：20%
# テストデータ：20%
"""
訓練データ：モデルのパラメータを最適化
検証データ：モデルのハイパーパラメータを最適化
テストデータ：学習済みのモデルを評価
"""
# tarin : val : test = 6 : 2 : 2
n_train = int(0.6 * len(dataset))
n_val = int(0.2 * len(dataset))
n_test = len(dataset) - n_train - n_val

print(n_train, n_val, n_test)  # 出力: 90 30 30

torch.manual_seed(0)
# データセットの分割
train, val, test = torch.utils.data.random_split(dataset, [n_train, n_val, n_test])

"""
ミニバッチ
"""
# ミニバッチのサイズ
batch_size = 10

# データローダーの作成
train_loader = torch.utils.data.DataLoader(train, batch_size=batch_size, shuffle=True, drop_last=True)
val_loader = torch.utils.data.DataLoader(val, batch_size=batch_size)
test_loader = torch.utils.data.DataLoader(test, batch_size=batch_size)

x, t = next(iter(train_loader))  # 一つ分だけ取り出す
print(x)
# 出力: tensor([[5.1000, 3.5000, 1.4000, 0.2000],
#         [5.1000, 3.5000, 1.4000, 0.2000],
#         [5.1000, 3.5000, 1.4000, 0.2000],
#         [5.1000, 3.5000, 1.4000, 0.2000],
#         [5.1000, 3.5000, 1.4000, 0.2000],
#         [5.1000, 3.5000, 1.4000, 0.2000],
#         [5.1000, 3.5000, 1.4000, 0.2000],
#         [5.1000, 3.5000, 1.4000, 0.2000],
#         [5.1000, 3.5000, 1.4000, 0.2000],
#         [5.1000, 3.5000, 1.4000, 0.2000],
#         [5.1000, 3.5000, 1.4000, 0.2000],
#         [5.1000, 3.5000, 1.4000, 0.2000]])
print(t)  # 出力: tensor([0, 0, 0, 0, 0, 0, 0, 0, 0, 0])


"""
ニューラルネットワークの定義
"""
# 4->4->3　の全結合層を作成


class Net(nn.Module):
    def __init__(self):
        super().__init__()
        self.fc1 = nn.Linear(4, 4)
        self.fc2 = nn.Linear(4, 3)

    # 順伝搬
    def forward(self, x):
        h = self.fc1(x)
        h = F.relu(x)  # 活性化関数
        h = self.fc2(x)
        return h


torch.manual_seed(0)
# インスタンス化
net = Net()

print(net)
# 出力: Net(
#   (fc1): Linear(in_features=4, out_features=4, bias=True)
#   (fc2): Linear(in_features=4, out_features=3, bias=True)
# )

optimizer = torch.optim.SGD(net.parameters(), lr=0.01)  # lrは学習係数

batch = next(iter(train_loader))
x, t = batch

# 予測値
y = net(x)
print(y)

# 損失関数
loss = F.cross_entropy(y, t)
print(loss)

# 勾配の計算
loss.backward()

# パラメータの更新
optimizer.step()


# GPUを使用できるかどうか
torch.cuda.is_available()  # 出力: False

# GPUを使用できる場合は、デバイスを指定.できない場合は、CPUを使用
device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")

# モデルをGPUに移動
net.to(device)

# GPU（ない場合はCPU）にデータを転送
x = x.to(device)
t = t.to(device)

# 勾配の初期化
optimizer.zero_grad()

# エポック数
max_epoch = 1

torch.manual_seed(0)

# モデルのインスタンス化とデバイスへの転送
net = Net().to(device)

# 最適化手法
optimizer = torch.optim.SGD(net.parameters(), lr=0.1)

# 学習のループ
for epoch in range(max_epoch):
    for batch in train_loader:
        x, t = batch
        x = x.to(device)
        t = t.to(device)

        loss = F.cross_entropy(net(x), t)
        print(loss)

        optimizer.zero_grad()
        loss.backward()
        optimizer.step()


"""
評価指標の追加
"""
x, t = next(iter(test_loader))
x = x.to(device)
t = t.to(device)

# 予測値
y = net(x)

y_label = torch.argmax(y, dim=1)  # 最大値を取得
print(y_label)

y_label == t

# 正解率
accuracy = (y_label == t).sum().float() / len(t)  # 出力: tensor(0.9667)
print(accuracy)





# 正解率を含んだ学習のループ
for epoch in range(max_epoch):
    for batch in train_loader:
        x, t = batch
        x = x.to(device)
        t = t.to(device)

        y = net(x)

        loss = F.cross_entropy(y, t)

        # 正解率の計算
        y_label = torch.argmax(y, dim=1)
        accuracy = (y_label == t).sum().float() / len(t)
        print(f" accuracy: {accuracy:.2f}")

        optimizer.zero_grad()
        loss.backward()
        optimizer.step()





