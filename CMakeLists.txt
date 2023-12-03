#设置版本 
cmake_minimum_required(VERSION 3.4.1) 
project(myapp)

#根路径
#CMAKE_SOURCE_DIR
#当前路径
#CMAKE_CURRENT_SOURCE_DIR}

#设置目录-以此目录为基准设置下面编译的头，源，库位置、CMakeLists.txt所在目录 
set(CURRENT_DIR ${CMAKE_SOURCE_DIR}) 
#设置编译器 
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu99") 
#生成gdb的调试信息和不进行代码优化 
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g") 


# 开源库
#include_directories(./thirdparty/protobuf/include)
#link_directories(./thirdparty/protobuf/lib)

# 搜索指定的库文件
#find_library(LIB_PROTOBUF protobuf HINTS ./thirdparty/protobuf/lib)


#包含源文件 ，aux_source_directory将目录所有源文件自动加入 
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/) 



# clock 模块
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/clock/) 

#生成IDPS可执行，这里直接放源文件也行如main.c；太多话，可以设置目录例如SOURCE_COMMON。 
add_executable(LinuxTime 
        ${CMAKE_CURRENT_SOURCE_DIR}/clock/LinuxTime.c 
    ) 

#链接我们需要的库，如lpthread系统库，预编译好的库lspdlog，需要2.5设置好路径 
target_link_libraries(LinuxTime 
#        -lpthread 
    ) 

add_executable(LinuxTimeOS 
        ${CMAKE_CURRENT_SOURCE_DIR}/clock/LinuxTimeOS.c 
    ) 



    # 设置输出路径
set_target_properties(LinuxTime PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set_target_properties(LinuxTimeOS PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)







