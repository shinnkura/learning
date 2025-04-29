ホストマシンから
```
mysql -h 127.0.0.1 -u root -p sampledb
```

コンテナ内から
```
docker compose exec mysql mysql -u root -p sampledb
```