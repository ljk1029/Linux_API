#设置版本 
cmake_minimum_required(VERSION 3.4.1) 
project(base_process)

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

set(TARGET1 "LinuxGetopt")
set(TARGET2 "LinuxIPC_FIFOR")
set(TARGET3 "LinuxIPC_FIFOS")
set(TARGET4 "LinuxIPC_SHMR")
set(TARGET5 "LinuxIPC_SHMT")
set(TARGET6 "LinuxIPC_SMGR")
set(TARGET7 "LinuxIPC_SMGS")
set(TARGET8 "LinuxIPC")
set(TARGET9 "LinuxMutex")
set(TARGET10 "LinuxProcess")
set(TARGET11 "LinuxProcessExe")
set(TARGET12 "LinuxSignal")
set(TARGET13 "LinuxThread")


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/) 

add_executable(${TARGET1} 
    ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET1}.c 
) 
add_executable(${TARGET2} 
    ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET2}.c 
) 
add_executable(${TARGET3} 
    ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET3}.c 
) 
add_executable(${TARGET4} 
    ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET4}.c 
) 
add_executable(${TARGET5} 
    ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET5}.c 
) 
add_executable(${TARGET6} 
    ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET6}.c 
) 
add_executable(${TARGET7} 
    ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET7}.c 
) 
add_executable(${TARGET8} 
    ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET8}.c 
) 
add_executable(${TARGET9} 
    ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET9}.c 
) 
add_executable(${TARGET10} 
    ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET10}.c 
) 
add_executable(${TARGET11} 
    ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET11}.c 
) 
add_executable(${TARGET12} 
    ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET12}.c 
) 
add_executable(${TARGET13} 
    ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET13}.c 
) 
target_link_libraries(${TARGET13} 
    -lpthread
)  

# cmake阶段设置输出路径
set_target_properties(${TARGET1} ${TARGET2} ${TARGET3} ${TARGET4} ${TARGET5} ${TARGET6} 
    ${TARGET7} ${TARGET8} ${TARGET9} ${TARGET10} ${TARGET11} ${TARGET12} ${TARGET13}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin)

# 生成执行文件阶段放入可执行目录
#install(TARGETS  ${TARGET1} ${TARGET2} ${TARGET3} ${TARGET4} ${TARGET5} ${TARGET6}
#    RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)









