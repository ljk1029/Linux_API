
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


# main
function build_main() {
    exe_name=main
    build_part
}

function run_main() {
    exe_name=main
    echo "run $exe_name"
    $out_path/$exe_name.o 
}



function usage()
{
    echo "usage"
    echo '1  build'
	echo '2  run_main'
}

# 攻击函数
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


if [ $# = 0 ]; then
    echo "no nothing"
    usage
else
    type=$1
    do_build
fi