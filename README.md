# mindows
## 開発環境
### Windows
コンパイルはWSL(Windows Subsystem for Linux)を使用．
必要なツールは以下のLinuxを参照．

QEMUはWindows上で実行．
QEMUのダウンロードは[ここ](https://www.qemu.org)

### Mac
そんなもの知らない

### Linux
クロスコンパイラ環境が必要．

```
$ sudo apt-get install git
$ sudo apt-get install gcc-mingw-w64-x86-64
$ sudo apt-get install make
$ sudo apt-get install nasm
```

ただし，WSLではなく，Linux上で開発を行う場合，エミュレータとしてQEMUが必要．
```
$ sudo apt-get install qemu
```

## コンパイル
Linux及びWSL環境下で以下のコマンドを実行
```
$ make
```

## 実行
### Windows
run.batを実行することで，QEMUが動作する

### Linux
```
$ qemu-system-x86_64 -bios tools\OVMF.fd -drive file=fat:rw:image,format=raw -m 6G
```

## バージョン情報
### mindows01a
・UEFIのプログラムを実行する

・UEFIを利用して画面描画（文字）を行う

### mindows01b
・UEFIのグラフィック情報を読み込む

・UEFIを利用してカーネルファイルを読み込み

・その他，UEFIの構造体を作成

### mindows02a
・カーネルのコンパイル環境の構築

・画面描画


### mindows02b
・画面情報の初期化関数を追加

・基本描画関数（線，四角形，円）の追加

