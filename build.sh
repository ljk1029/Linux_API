#!/bin/bash

# 使用说明
usage() {
    echo "Usage: $0 {b|r|clean}"
    echo "  b     - 建立项目"
    echo "  r     - 重新建立项目"
    echo "  clean - 清空项目"
    exit 1
}

# 创建或清空 build 目录
prepare_build_dir() {
    if [ -d "build" ]; then
        echo "清空 build 目录"
        rm -rf build/*
        rm -rf bin/*
    else
        echo "创建 build 目录"
        mkdir build
    fi
}

# 建立项目
build_project() {
    prepare_build_dir
    cd build || exit
    cmake ..
    make
}

# 清空项目
clean_project() {
    if [ -d "build" ]; then
        echo "清空 build 目录"
        rm -rf build/*
        rm -rf bin/*
    else
        echo "build 目录不存在"
    fi
}

# 重新建立项目
rebuild_project() {
    clean_project
    build_project
}

# 检查输入参数
if [ $# -eq 0 ]; then
    usage
fi

# 根据输入参数执行相应操作
case "$1" in
    b)
        build_project
        ;;
    r)
        rebuild_project
        ;;
    clean)
        clean_project
        ;;
    *)
        usage
        ;;
esac