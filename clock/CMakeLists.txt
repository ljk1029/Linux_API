#设置版本 
cmake_minimum_required(VERSION 3.4.1) 
project(base_clock)

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

set(TARGET1 "LinuxTime")
set(TARGET2 "LinuxTimeOS")


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/) 

add_executable(${TARGET1} 
    ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET1}.c 
) 
add_executable(${TARGET2} 
    ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET2}.c 
) 


# cmake阶段设置输出路径
set_target_properties(${TARGET1} ${TARGET2} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin)

# 生成执行文件阶段放入可执行目录
#install(TARGETS  ${TARGET1} ${TARGET2} ${TARGET3} ${TARGET4} ${TARGET5} ${TARGET6}
#    RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)









