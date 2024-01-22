#设置版本 
cmake_minimum_required(VERSION 3.4.1) 
project(app_demo)

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

# 模块
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/) 

#生成可执行文件，这里直接放源文件也行如main.c；太多话，可以设置目录例如SOURCE_COMMON。 
add_executable(myapp 
        ${CMAKE_CURRENT_SOURCE_DIR}/main.c 
    ) 

#链接我们需要的库，如lpthread系统库，预编译好的库lspdlog，需要2.5设置好路径 
target_link_libraries(myapp 
#        -lpthread 
    ) 

# 设置输出路径
set_target_properties(myapp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)


# 添加子目录，包含 gtest 的构建
add_subdirectory(base_file)
add_subdirectory(base_process)
add_subdirectory(base_resource)
add_subdirectory(base_network)
add_subdirectory(clock)
add_subdirectory(common)







