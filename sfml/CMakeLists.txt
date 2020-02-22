# 最低CMake版本要求
cmake_minimum_required(VERSION 3.10.0)

# 项目名称
project(Cpp)

# 设置C/C++标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 头文件路径
include_directories("Include")

# 枚举头文件
file(GLOB_RECURSE INCLUDES "Include/*.h" "Include/*.hpp" "Include/SFML/*.hpp")



# 枚举源文件
aux_source_directory("Src" SOURCES)

# 输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib) 

file(GLOB_RECURSE DLL "lib/*.dll")
file(COPY ${DLL} DESTINATION ${PROJECT_BINARY_DIR}/bin)
file(COPY "./Resources" DESTINATION ${PROJECT_BINARY_DIR})
# 生成可执行的文件
add_executable(${PROJECT_NAME} ${SOURCES} ${INCLUDES})

target_link_libraries(${PROJECT_NAME} sfml-graphics-d sfml-window-d sfml-system-d) 