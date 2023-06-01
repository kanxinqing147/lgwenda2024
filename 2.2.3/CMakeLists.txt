# 指定include路径
include_directories(../include)

# 指定依赖文件
set(SRC_LIST ${PROJECT_SOURCE_DIR}/include/SqList.cpp)

# 指定编译文件
add_executable(demo ./04.cpp ${SRC_LIST})

# 设置输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)