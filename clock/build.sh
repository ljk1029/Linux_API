
#!/bin/bash
# file build

API_name=""
build_path=../build

function build_part(){
    echo "build $API_name"
    rm $build_path/$API_name.o
    gcc $API_name.c -g -o $API_name.o -I../ -I./
    if [ ! -d "$build_path" ]; then
        mkdir $build_path
    fi
    mv $API_name.o $build_path/
}

# Time
function build_Time() {
    API_name="LinuxTime"
    build_part
}

function run_Time() {
    echo "run Time"
    $build_path/LinuxTime.o 
}

# TimeOS
function build_TimeOS() {
    API_name="LinuxTimeOS"
    build_part
}

function run_TimeOS() {
    echo "run TimeOS"
    $build_path/LinuxTimeOS.o 
}

function usage()
{
    echo "usage"
    echo '1  build_Time'
	echo '2  run_Time'
	echo '3  build_TimeOS'
	echo '4  run_TimeOS'
}

# 执行函数
do_build() {
    case $type in
		1)
			build_Time
			;;
		2)
			run_Time
			;;
		3)
			build_TimeOS
			;;
        4)
			run_TimeOS
			;;
		*)
            usage
            ;;
    esac
}


if [ $# = 0 ]; then
    echo "no nothing"
    usage
else
    type=$1
    do_build
fi