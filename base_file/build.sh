
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

# file
function build_fileIO() {
    API_name="LinuxFileIO"
    build_part
}

function run_fileIO() {
    echo "run fileIO"
    $build_path/LinuxFileIO.o 
}

function build_file() {
    API_name="LinuxFile"
    build_part
}

function run_file() {
    echo "run file"
    $build_path/LinuxFile.o 
}

function build_dir() {
    API_name="LinuxDir"
    build_part
}

function run_dir() {
    echo "run dir"
    $build_path/LinuxDir.o 
}

function build_link() {
    API_name="LinuxLink"
    build_part
}

function run_link() {
    echo "run link"
    $build_path/LinuxLink.o 
}

# 构建
function build_fcntl()
{
    API_name=LinuxFcntl
    build_part
}

# 运行
function run_fcntl() {
    API_name=LinuxFcntl
    echo "run $API_name"
    $build_path/$API_name.o
}

# 构建
function build_temp()
{
    API_name=LinuxTemp
    build_part
}

# 运行
function run_temp() {
    API_name=LinuxTemp
    echo "run $API_name"
    $build_path/$API_name.o
}


function usage()
{
    echo "usage"
    echo '1  build_fileIO'
	echo '2  run_fileIO'
	echo '3  build_file'
	echo '4  run_file'
	echo '5  build_dir'
	echo '6  run_dir'
	echo '7  build_link'
	echo '8  run_link'
    echo '9  build_fcntl'
	echo '10 run_fcntl'
	echo '11 build_temp'
	echo '12 run_temp'
}

# 攻击函数
do_build() {
    case $type in
		1)
			build_fileIO
			;;
		2)
			run_fileIO
			;;
		3)
			build_file
			;;
        4)
			run_file
			;;
        5)
			build_dir
			;;
        6)
			run_dir
			;;
        7)
			build_link
			;;
        8)
			run_link
			;;
        9)
			build_fcntl
			;;
        10)
			run_fcntl
			;;
        11)
			build_temp
			;;
        12)
			run_temp
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