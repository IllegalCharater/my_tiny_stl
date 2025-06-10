# my_library/CMakeLists.txt
# 创建静态库，包含该目录下的所有 .cpp 文件
add_library(my_library STATIC
        my_template.cpp
        my_operator.cpp
        my_reference.cpp
)

# 可选：为库设置包含目录（如果库有头文件）
target_include_directories(my_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
