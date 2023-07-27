#!/bin/bash

exe_name=LinuxProcess
out_path=../build

# 构建
function build_part() {
    echo "build $exe_name"
    rm $out_path/$exe_name.o 
    gcc  $exe_name.c  -I ../ -g -o $exe_name.o -lpthread
    if [ ! -d "$out_path" ]; then
        mkdir $out_path
    fi
    mv $exe_name.o $out_path/
}

# 构建进程
function build_mmap()
{
    exe_name=LinuxMmap
    build_part
}

# 运行进程
function run_mmap() {
    exe_name=LinuxMmap
    echo "run $exe_name"
    $out_path/$exe_name.o
}

function usage() {
    echo "[I] Usage: [sh $0 cmd]"
    echo '1   build mmap'
	echo '2   run   mmap'  
}

# main
if [ $# = 0 ]; then
    usage
else
    if [ $1 == '1' ]; then
        build_mmap
    elif [ $1 == '2' ];then
        run_mmap
    else
        usage
    fi
fi
