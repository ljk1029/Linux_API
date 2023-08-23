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
function build_processExe()
{
    exe_name=LinuxProcessExe
    build_part
}

# 运行进程
function run_processExe() {
    exe_name=LinuxProcessExe
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

# 构建
function build_thread()
{
    exe_name=LinuxThread
    build_part
}

# 运行
function run_thread() {
    exe_name=LinuxThread
    echo "run $exe_name"
    $out_path/$exe_name.o
}

# 构建
function build_signal()
{
    exe_name=LinuxSignal
    build_part
}

# 运行
function run_signal() {
    exe_name=LinuxSignal
    echo "run $exe_name"
    $out_path/$exe_name.o
}

# 构建
function build_mutex()
{
    exe_name=LinuxMutex
    build_part
}

# 运行
function run_mutex() {
    exe_name=LinuxMutex
    echo "run $exe_name"
    $out_path/$exe_name.o
}

# 构建
function build_IPC()
{
    exe_name=LinuxIPC
    build_part
    exe_name=LinuxIPC_SHMT
    build_part
    exe_name=LinuxIPC_SHMR
    build_part

    exe_name=LinuxIPC_SIGS
    build_part
    exe_name=LinuxIPC_SIGR
    build_part

    exe_name=LinuxIPC_FIFOS
    build_part
    exe_name=LinuxIPC_FIFOR
    build_part
}

# 运行
function run_IPC() {
    exe_name=LinuxIPC
    echo "run $exe_name"
    $out_path/$exe_name.o
}

# 运行
function run_IPC_SHMT() {
    exe_name=LinuxIPC_SHMT
    echo "run $exe_name"
    $out_path/$exe_name.o
}

function run_IPC_SHMR() {
    exe_name=LinuxIPC_SHMR
    echo "run $exe_name"
    $out_path/$exe_name.o
}

function run_IPC_SIGS() {
    exe_name=LinuxIPC_SIGS
    echo "run $exe_name"
    $out_path/$exe_name.o
}

function run_IPC_SIGR() {
    exe_name=LinuxIPC_SIGR
    echo "run $exe_name"
    $out_path/$exe_name.o
}

function run_IPC_FIFOS() {
    exe_name=LinuxIPC_FIFOS
    echo "run $exe_name"
    $out_path/$exe_name.o
}

function run_IPC_FIFOR() {
    exe_name=LinuxIPC_FIFOR
    echo "run $exe_name"
    $out_path/$exe_name.o
}



function usage() {
    echo "[I] Usage: [sh $0 cmd]"
    echo '1   build process'
	echo '2   run   process'
    echo '3   build processExe'
	echo '4   run   processExe'  
    echo '5   build getopt'
	echo '6   run   getopt'
    echo '7   build thread'
	echo '8   run   thread'
    echo '8   run   thread'
    echo '9   build signal'
	echo '10  run   signal'
    echo '11  build mutex'
	echo '12  run   mutex'
    echo '13  build IPC'
	echo '14  run   IPC'
	echo '15  run   IPC_SHMT'
	echo '16  run   IPC_SHMR'
    echo '17  run   IPC_SIGR'
	echo '18  run   IPC_SIGS'
	echo '19  run   IPC_FIFOS'
	echo '20  run   IPC_FIFOR'
  
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
        build_processExe
    elif [ $1 == '4' ];then
        run_processExe
    elif [ $1 == '5' ];then
        build_getopt
    elif [ $1 == '6' ];then
        run_getopt
    elif [ $1 == '7' ];then
        build_thread
    elif [ $1 == '8' ];then
        run_thread
    elif [ $1 == '9' ];then
        build_signal
    elif [ $1 == '10' ];then
        run_signal
    elif [ $1 == '11' ];then
        build_mutex
    elif [ $1 == '12' ];then
        run_mutex
    elif [ $1 == '13' ];then
        build_IPC
    elif [ $1 == '14' ];then
        run_IPC
    elif [ $1 == '15' ];then
        run_IPC_SHMT
    elif [ $1 == '16' ];then
        run_IPC_SHMR
    elif [ $1 == '17' ];then
        run_IPC_SIGR
    elif [ $1 == '18' ];then
        run_IPC_SIGS
    elif [ $1 == '19' ];then
        run_IPC_FIFOS
    elif [ $1 == '20' ];then
        run_IPC_FIFOR
   
    else
        usage
    fi
fi
