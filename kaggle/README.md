```
docker compose up -d
```


```
docker exec -it kaggle /bin/bash
```

## コンペデータのダウンロード
```
kaggle competitions download -c <コンペ名> -p <保存先パス>
kaggle competitions download -c titanic -p /kaggle/input/titanic
unzip ファイル名.zip -d 解凍先パス
```

## コンペに提出
```
kaggle competitions submit -c <コンペ名> -f <提出ファイル> -m "<コメント>"
kaggle competitions submit -c titanic -f submission.csv -m "1st submission"
```

## 提出履歴
```
kaggle competitions submissions -c <コンペ名>
```

## ノートブックの取得コマンド
```
kaggle kernels pull <username>/<notebook-name>
```
