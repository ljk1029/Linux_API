
#!/bin/bash
# main build

API_name=""
build_path=../build

function build_part(){
    echo "build $API_name"
    rm $build_path/$API_name.o
    gcc $API_name.c -g -o $API_name.o -lcurses
    if [ ! -d "$build_path" ]; then
        mkdir $build_path
    fi
    mv $API_name.o $build_path
}

# test
function build_test() {
    API_name="LinuxTest"
    gcc LinuxTest.c LinuxError.c  LinuxCTime.c LinuxLog.c -g -o $API_name.o
    mv $API_name.o $build_path
}

function run_test() {
    echo "run test"
    API_name="LinuxTest"
    $build_path/$API_name.o 
}

# gui
function build_gui() {
    API_name="LinuxGui"
    build_part
}

function run_gui() {
    echo "run gui"
    API_name="LinuxGui"
    $build_path/$API_name.o 
}

# key
function build_key() {
    API_name="LinuxKey"
    build_part
}

function run_key() {
    echo "run key"
    API_name="LinuxKey"
    $build_path/$API_name.o 
}



function usage()
{
    echo "usage"
    echo '1  build test'
	echo '2  run   test'
    echo '3  build gui'
	echo '4  run   gui'
    echo '5  build key'
	echo '6  run   key'
}

# 攻击函数
do_build() {
    case $type in
		1)
			build_test
			;;
		2)
			run_test
			;;
        3)
			build_gui
			;;
		4)
			run_gui
			;;
        5)
			build_key
			;;
		6)
			run_key
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


