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

