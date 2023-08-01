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
    exe_name=LinuxMemory
    build_part
}

# 运行进程
function run_mmap() {
    exe_name=LinuxMemory
    echo "run $exe_name"
    $out_path/$exe_name.o
}

# 构建
function build_syslog()
{
    exe_name=LinuxSyslog
    build_part
}

# 运行
function run_syslog() {
    exe_name=LinuxSyslog
    echo "run $exe_name"
    $out_path/$exe_name.o
}

# 构建
function build_resource()
{
    exe_name=LinuxResource
    build_part
}

# 运行
function run_resource() {
    exe_name=LinuxResource
    echo "run $exe_name"
    $out_path/$exe_name.o
}

# 构建
function build_env()
{
    exe_name=LinuxEnv
    build_part
}

# 运行
function run_env() {
    exe_name=LinuxEnv
    echo "run $exe_name"
    $out_path/$exe_name.o
}

# 构建
function build_passwd()
{
    exe_name=LinuxPasswd
    build_part
}

# 运行
function run_passwd() {
    exe_name=LinuxPasswd
    echo "run $exe_name"
    $out_path/$exe_name.o
}


function usage() {
    echo "[I] Usage: [sh $0 cmd]"
    echo '1   build mmap'
	echo '2   run   mmap' 
    echo '3   build syslog'
	echo '4   run   syslog' 
    echo '5   build resource'
	echo '6   run   resource' 
    echo '7   build env'
	echo '8   run   env'
	echo '9   build passwd'
	echo '10  run   passwd'
}

# main
if [ $# = 0 ]; then
    usage
else
    if [ $1 == '1' ]; then
        build_mmap
    elif [ $1 == '2' ];then
        run_mmap
    elif [ $1 == '3' ]; then
        build_syslog
    elif [ $1 == '4' ];then
        run_syslog
    elif [ $1 == '5' ]; then
        build_resource
    elif [ $1 == '6' ];then
        run_resource
    elif [ $1 == '7' ];then
        build_env
    elif [ $1 == '8' ];then
        run_env
    elif [ $1 == '9' ];then
        build_passwd
    elif [ $1 == '10' ];then
        run_passwd
    else
        usage
    fi
fi
