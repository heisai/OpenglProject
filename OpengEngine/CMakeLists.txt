﻿cmake_minimum_required(VERSION 3.5)

project(opengl_engine LANGUAGES  C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2 /Ob2")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /DEBUG")
add_compile_options(/utf-8)


#设置库路径
set(LIBDIR  ./OpenGl/glfw/lib)
#设置头文件路径
set(INCLUDEDIR  ./OpenGl/glad/include ./OpenGl/glfw/include ./OpenGl/glm)

# 加载库路径
link_directories(${LIBDIR})
# 加载头文件路径
include_directories(${INCLUDEDIR})


# 添加 .cpp
file(GLOB_RECURSE SOURCE_FILES  ./src/*.cpp  ./src/Utils/*.cpp ./src/Graphics/*.cpp  ./src/ImGui/*.cpp )

# 添加 .h
file(GLOB_RECURSE HEADER_FILES  ./src/*.h  ./src/Utils/*.h  ./src/Graphics/*.h  ./src/ImGui/*.h)
# 将源代码添加到此项目的可执行文件。
add_executable (${PROJECT_NAME} main.cpp ${HEADER_FILES} ${SOURCE_FILES} )

# 编译glad 库
add_library(GLAD ./OpenGl/glad.c )
set(LIBS glfw3 opengl32 GLAD)
# 链接 可执行文件 所需库
target_link_libraries(${PROJECT_NAME} ${LIBS})
