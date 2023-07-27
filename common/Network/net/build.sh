#!/bin/bash

exe_name=""
out_path=../build

# 构建
function build_part() {
    echo "build $exe_name"
    rm $out_path/$exe_name.o 
    gcc  $exe_name.c -g -o $exe_name.o -lpthread
    if [ ! -d "$out_path" ]; then
        mkdir $out_path
    fi
    mv $exe_name.o $out_path/
}

# client
# 构建客户端
function build_common()
{
    exe_name=net_common
    build_part
}

# 运行客户端
function run_common() {
    exe_name=net_common
    echo "run $exe_name"
    $out_path/$exe_name.o  
}

function usage() {
    echo "[I] Usage: [sh $0 cmd]"
    echo 'b-c   build common'
	echo 'r-c   run   common' 
    echo 'x     run   socket' 
}

# main
if [ $# = 0 ]; then
    usage
else
    if [ $1 == 'b-c' ]; then
        build_common
    elif [ $1 == 'r-c' ];then
        run_common
    elif [ $1 == 'x' ];then
        cd ../socket
        ./build.sh
    else
        usage
    fi
fi
