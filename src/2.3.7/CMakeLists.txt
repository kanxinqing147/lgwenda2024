# 指定include路径
include_directories(${PROJECT_SOURCE_DIR}/include)

# 指定依赖文件
aux_source_directory(${PROJECT_SOURCE_DIR}/include SRC_LIST)

# 指定编译文件
add_executable(main ./13.cpp ${SRC_LIST})

# 设置输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)