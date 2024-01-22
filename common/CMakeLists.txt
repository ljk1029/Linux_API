#设置版本 
cmake_minimum_required(VERSION 3.4.1) 
project(common)

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

set(TARGET1 "LinuxTest")
set(TARGET2 "LinuxGui")
set(TARGET3 "LinuxKey")
set(TARGET4 "Log")


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/) 

add_executable(${TARGET1} 
    ${CMAKE_CURRENT_SOURCE_DIR}/LinuxTest.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/LinuxError.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/LinuxCTime.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/LinuxLog.c 
) 
add_executable(${TARGET2} 
    ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET2}.c 
) 
target_link_libraries(${TARGET2}
    -lcurses 
) 
add_executable(${TARGET3} 
    ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET3}.c 
) 
add_executable(${TARGET4} 
    ${CMAKE_CURRENT_SOURCE_DIR}/log/${TARGET4}.c 
) 

# cmake阶段设置输出路径
set_target_properties(${TARGET1} ${TARGET2} ${TARGET3} ${TARGET4} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin)









