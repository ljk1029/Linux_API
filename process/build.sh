#!/bin/bash

exe_name=LinuxProcess
out_path=../build

# 构建
function build_part() {
    echo "build $exe_name"
    rm $out_path/$exe_name.o 
    gcc  $exe_name.c  -I ../tcp -g -o $exe_name.o -lpthread
    if [ ! -d "$out_path" ]; then
        mkdir $out_path
    fi
    mv $exe_name.o $out_path/
}

# client
# 构建客户端
function build_process()
{
    exe_name=LinuxProcess
    build_part
}

# 运行客户端
function run_process() {
    exe_name=LinuxProcess
    echo "run $exe_name"
    $out_path/$exe_name.o
}


function usage() {
    echo "[I] Usage: [sh $0 cmd]"
    echo 'b-p   build process'
	echo 'r-p   run   process'  
}

# main
if [ $# = 0 ]; then
    usage
else
    if [ $1 == 'b-p' ]; then
        build_process
    elif [ $1 == 'r-p' ];then
        run_process
    else
        usage
    fi
fi
