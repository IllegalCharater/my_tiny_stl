cmake_minimum_required(VERSION 3.10)

# 项目名称和使用的语言
project(My_tiny_STL LANGUAGES CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加 my_library 目录作为子目录
add_subdirectory(my_library)

# 添加可执行文件，假设 main.cpp 位于项目根目录
add_executable(My_tiny_STL main.cpp)

# 链接 my_library 库到可执行文件
target_link_libraries(My_tiny_STL PRIVATE my_library)

# 可选：为编译器启用更多警告
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(My_tiny_STL PRIVATE -Wall -Wextra -pedantic)
elseif (MSVC)
    target_compile_options(My_tiny_STL PRIVATE /W4)
endif()
