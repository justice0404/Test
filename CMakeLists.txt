# 构建方式1
# #规定最小的版本
# cmake_minimum_required(VERSION 4.1.2)

# #工程名称
# project(Test)
# #C++标准
# set(CMAKE_CXX_STANDARD 17)

# #设置可执行文件的导出目录,放在当前工程目录的bin文件夹下
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# #将当前文件夹下所有的.cpp文件打包放在SRC_LISTS变量下
# aux_source_directory(. SRC_LISTS)

# #生成可执行文件,可执行文件名为main，依赖为SRC_LISTS
# add_executable(main ${SRC_LISTS})

# 构建方式2
#规定最小的版本
cmake_minimum_required(VERSION 3.10)
project(Test)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# 分别收集不同目录的源文件
aux_source_directory(. APP_SRCS)        # 根目录的源文件（如main.cpp）
aux_source_directory(Src LIB_SRCS)      # Src目录的源文件（包含函数实现）

# 生成动态库（只包含Src目录的实现文件）
add_library(common SHARED ${LIB_SRCS})
target_include_directories(common PUBLIC ${PROJECT_SOURCE_DIR}/Inc)

# 生成可执行文件（只包含main.cpp）
add_executable(main ${APP_SRCS})
target_include_directories(main PUBLIC ${PROJECT_SOURCE_DIR}/Inc)
target_link_libraries(main common)