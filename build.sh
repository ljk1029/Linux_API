#!/bin/bash
# main build

exe_name=""
out_path=./build

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


# build main
function build_main() {
    exe_name=main
    build_part
}

# run main
function run_main() {
    exe_name=main
    echo "run $exe_name"
    $out_path/$exe_name.o 
}

# usage
function usage()
{
    echo "usage: $0 [arg]"
    echo 'arg: 1  build'
	echo '     2  run_main'
}

# 功能函数
do_build() {
    case $type in
		1)
			build_main
			;;
		2)
			run_main
			;;
		*)
            usage
            ;;
    esac
}


# 执行
if [ $# = 0 ]; then
    echo "no nothing"
    usage
else
    type=$1
    do_build
fi