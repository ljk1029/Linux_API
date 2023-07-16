
#!/bin/bash
# file build

API_name=""

function build_part(){
    echo "build $API_name"
    rm ../build/$API_name.o
    gcc $API_name.c -g -o $API_name.o -I../ -I./
    if [ ! -d "../build" ]; then
        mkdir ../build
    fi
    mv $API_name.o ../build/
}

# file
function build_fileIO() {
    API_name="LinuxFileIO"
    build_part
}

function run_fileIO() {
    echo "run fileIO"
    ../build/LinuxFileIO.o 
}

function build_file() {
    API_name="LinuxFile"
    build_part
}

function run_file() {
    echo "run file"
    ../build/LinuxFile.o 
}

function build_dir() {
    API_name="LinuxDir"
    build_part
}

function run_dir() {
    echo "run dir"
    ../build/LinuxDir.o 
}

function build_link() {
    API_name="LinuxLink"
    build_part
}

function run_link() {
    echo "run link"
    ../build/LinuxLink.o 
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