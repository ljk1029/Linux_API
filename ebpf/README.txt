## 学习url

https://gitcode.com/eunomia-bpf/bpf-developer-tutorial/tree/main/src

### 工具安装步骤

```console
$ wget https://aka.pw/bpf-ecli -O ecli && chmod +x ./ecli
$ ./ecli -h
Usage: ecli [--help] [--version] [--json] [--no-cache] url-and-args
```

```console
$ wget https://github.com/eunomia-bpf/eunomia-bpf/releases/latest/download/ecc && chmod +x ./ecc
$ ./ecc -h
eunomia-bpf compiler
Usage: ecc [OPTIONS] <SOURCE_PATH> [EXPORT_EVENT_HEADER]
....

```shell
sudo apt install clang llvm
sudo apt install fuse3
```

使用 ecc 编译程序：

```console
$ ./ecc minimal.bpf.c
Compiling bpf object...
Packing ebpf object and config into package.json...
```

然后使用 ecli 运行编译后的程序：

```console
$ sudo ./ecli run package.json
Runing eBPF program...
```

