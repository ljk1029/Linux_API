#设置版本 
cmake_minimum_required(VERSION 3.4.1) 
project(base_network)

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

set(TARGET1 "client")
set(TARGET2 "server")
set(TARGET3 "epoll")
set(TARGET4 "select")
set(TARGET5 "poll")
set(TARGET6 "poll_thread")
set(TARGET7 "udpserver")
set(TARGET8 "udpclient")
set(TARGET9 "net_common")


# clock 模块
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/socket/tcp) 

add_executable(${TARGET1} 
    ${CMAKE_CURRENT_SOURCE_DIR}/socket/tcp/${TARGET1}.c 
) 
add_executable(${TARGET2} 
    ${CMAKE_CURRENT_SOURCE_DIR}/socket/tcp/${TARGET2}.c 
) 
add_executable(${TARGET3} 
    ${CMAKE_CURRENT_SOURCE_DIR}/socket/epoll/${TARGET3}.c 
) 
add_executable(${TARGET4} 
    ${CMAKE_CURRENT_SOURCE_DIR}/socket/select/${TARGET4}.c 
) 
add_executable(${TARGET5} 
    ${CMAKE_CURRENT_SOURCE_DIR}/socket/poll/${TARGET5}.c 
) 
add_executable(${TARGET6} 
    ${CMAKE_CURRENT_SOURCE_DIR}/socket/poll/${TARGET6}.c 
) 
add_executable(${TARGET7} 
    ${CMAKE_CURRENT_SOURCE_DIR}/socket/udp/${TARGET7}.c 
) 
add_executable(${TARGET8} 
    ${CMAKE_CURRENT_SOURCE_DIR}/socket/udp/${TARGET8}.c 
) 
add_executable(${TARGET9} 
    ${CMAKE_CURRENT_SOURCE_DIR}/net/${TARGET9}.c 
) 


# cmake阶段设置输出路径
set_target_properties(${TARGET1} ${TARGET2} ${TARGET3} ${TARGET4} ${TARGET5} ${TARGET6} 
    ${TARGET7} ${TARGET8} ${TARGET9}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin)

# 生成执行文件阶段放入可执行目录
#install(TARGETS  ${TARGET1} ${TARGET2} ${TARGET3} ${TARGET4} ${TARGET5} ${TARGET6}
#    RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)









