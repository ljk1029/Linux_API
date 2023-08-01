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
function build_process()
{
    exe_name=LinuxProcess
    build_part
}

# 运行进程
function run_process() {
    exe_name=LinuxProcess
    echo "run $exe_name"
    $out_path/$exe_name.o
}

# 构建进程
function build_processEx()
{
    exe_name=LinuxProcessEx
    build_part
}

# 运行进程
function run_processEx() {
    exe_name=LinuxProcessEx
    echo "run $exe_name"
    $out_path/$exe_name.o
}

# 构建
function build_getopt()
{
    exe_name=LinuxGetopt
    build_part
}

# 运行
function run_getopt() {
    exe_name=LinuxGetopt
    echo "run $exe_name"
    $out_path/$exe_name.o
}


function usage() {
    echo "[I] Usage: [sh $0 cmd]"
    echo '1   build process'
	echo '2   run   process'
    echo '3   build processEx'
	echo '4   run   processEx'  
    echo '5   build getopt'
	echo '6   run   getopt'
}

# main
if [ $# = 0 ]; then
    usage
else
    if [ $1 == '1' ]; then
        build_process
    elif [ $1 == '2' ];then
        run_process
    elif [ $1 == '3' ]; then
        build_processEx
    elif [ $1 == '4' ];then
        run_processEx
    elif [ $1 == '5' ];then
        build_getopt
    elif [ $1 == '6' ];then
        run_getopt
    else
        usage
    fi
fi
