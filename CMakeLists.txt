#规定最小的版本
cmake_minimum_required(VERSION 4.1.2)

#工程名称
project(Test)
#C++标准
set(CMAKE_CXX_STANDARD 17)

#设置可执行文件的导出目录,放在当前工程目录的bin文件夹下
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#将当前文件夹下所有的.cpp文件打包放在SRC_LISTS变量下
aux_source_directory(. SRC_LISTS)

#生成可执行文件,可执行文件名为main，依赖为SRC_LISTS
add_executable(main ${SRC_LISTS})