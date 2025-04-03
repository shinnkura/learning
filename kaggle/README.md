```shell
docker compose up -d
```


```shell
docker exec -it kaggle /bin/bash
jupyter notebook --ip=0.0.0.0 --port=8888 --allow-root --NotebookApp.token=''
# --ip=0.0.0.0 : すべてのIPからのアクセスを許可
# --port=8888 : ポート番号を指定
# --allow-root : ルートユーザーでの起動を許可（Dockerでは必要）
# --NotebookApp.token='' : 認証トークンなしでアクセス可（セキュリティ注意）
```

## コンペデータのダウンロード
```shell
kaggle competitions download -c <コンペ名> -p <保存先パス>
kaggle competitions download -c titanic -p /kaggle/input/titanic
unzip ファイル名.zip -d 解凍先パス
```

## コンペに提出
```shell
kaggle competitions submit -c <コンペ名> -f <提出ファイル> -m "<コメント>"
kaggle competitions submit -c titanic -f submission.csv -m "1st submission"
```

## 提出履歴
```shell
kaggle competitions submissions -c <コンペ名>
```

## ノートブックの取得コマンド
```shell
kaggle kernels pull <username>/<notebook-name>
```

## ノートブックを提出
```shell
kaggle kernels init

# 生成されたファイルを修正後、以下のコマンドを実行
kaggle kernels push -p .
```