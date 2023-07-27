#!/bin/bash

exe_name=client
out_path=../../build

# 构建
function build_part() {
    echo "build $exe_name"
    rm ../$out_path/$exe_name.o 
    gcc  $exe_name.c  -I ../tcp -g -o $exe_name.o -lpthread
    if [ ! -d "../$out_path" ]; then
        mkdir ../$out_path
    fi
    mv $exe_name.o ../$out_path/
}

# client
# 构建客户端
function build_client()
{
    cd ./tcp
    exe_name=client
    build_part
}

# 运行客户端
function run_client() {
    exe_name=client
    echo "run $exe_name"
    $out_path/$exe_name.o  
}

# 构建客户端
function build_client_fork()
{
    cd ./tcp
    exe_name=client_fork
    build_part
}

# 运行客户端
function run_client_fork() {
    exe_name=client_fork
    echo "run $exe_name"
    $out_path/$exe_name.o  
}

# server
# 构建服务端
function build_server()
{
    cd ./tcp
    exe_name=server
    build_part
}

# 运行服务端
function run_server() {
    exe_name=server
    echo "run $exe_name"
    $out_path/$exe_name.o  
}

# epoll
# 构建服务端epoll
function build_epoll()
{
    cd ./epoll
    exe_name=epoll
    build_part
}

# 运行服务端epoll
function run_epoll() {
    exe_name=epoll
    echo "run $exe_name"
    $out_path/$exe_name.o  
}

# select
# 构建服务端
function build_select()
{
    cd ./select
    exe_name=select
    build_part
}

# 运行服务端
function run_select() {
    exe_name=select
    echo "run $exe_name"
    $out_path/$exe_name.o  
}

# poll
# 构建服务端
function build_poll()
{
    cd ./poll
    exe_name=poll
    build_part
}

# 运行服务端
function run_poll() {
    exe_name=poll
    echo "run $exe_name"
    $out_path/$exe_name.o  
}

# 构建服务端
function build_poll_thread()
{
    cd ./poll
    exe_name=poll_thread
    build_part
}

# 运行服务端
function run_poll_thread() {
    exe_name=poll_thread
    echo "run $exe_name"
    $out_path/$exe_name.o  
}

# 构建UDP服务端
function build_udp_server()
{
    cd ./udp
    exe_name=udpserver
    build_part
}

# 运行UDP服务端
function run_udp_server() {
    exe_name=udpserver
    echo "run $exe_name"
    $out_path/$exe_name.o  
}


# 构建UDP客户端
function build_udp_client()
{
    cd ./udp
    exe_name=udpclient
    build_part
}

# 运行UDP客户端
function run_udp_client() {
    exe_name=udpclient
    echo "run $exe_name"
    $out_path/$exe_name.o  
}

function usage() {
    echo "[I] Usage: [sh $0 cmd]"
    echo 'b-c   build client'
	echo 'r-c   run   client'  
    echo 'b-cf  build client_fork'
	echo 'r-cf  run   client_fork' 
    echo 'b-s   build server'
	echo 'r-s   run   server'
    echo 'b-se  build select'
	echo 'r-se  run   select'
    echo 'b-p   build poll'
	echo 'r-p   run   poll'
    echo 'b-pt  build poll_thread'
	echo 'r-pt  run   poll_thread'
    echo 'b-e   build epoll'
	echo 'r-e   run   epoll'
    echo 'b-us  build UDP server'
	echo 'r-us  run   UDP server'
    echo 'b-uc  build UDP client'
	echo 'r-uc  run   UDP client'
}

# main
if [ $# = 0 ]; then
    usage
else
    if [ $1 == 'b-c' ]; then
        build_client
    elif [ $1 == 'r-c' ];then
        run_client
    elif [ $1 == 'b-cf' ]; then
        build_client_fork
    elif [ $1 == 'r-cf' ];then
        run_client_fork
    elif [ $1 == 'b-s' ]; then
        build_server
    elif [ $1 == 'r-s' ];then
        run_server
    elif [ $1 == 'b-e' ]; then
        build_epoll
    elif [ $1 == 'r-e' ];then
        run_epoll
    elif [ $1 == 'b-se' ]; then
        build_select
    elif [ $1 == 'r-se' ];then
        run_select
    elif [ $1 == 'b-p' ]; then
        build_poll
    elif [ $1 == 'r-p' ];then
        run_poll
    elif [ $1 == 'b-pt' ]; then
        build_poll_thread
    elif [ $1 == 'r-pt' ];then
        run_poll_thread
    elif [ $1 == 'b-us' ]; then
        build_udp_server
    elif [ $1 == 'r-us' ];then
        run_udp_server
    elif [ $1 == 'b-uc' ]; then
        build_udp_client
    elif [ $1 == 'r-uc' ];then
        run_udp_client
    else
        usage
    fi
fi
