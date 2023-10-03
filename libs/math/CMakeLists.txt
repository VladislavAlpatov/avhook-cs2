project(math)
add_library(math STATIC src/matrix.cpp)

target_include_directories(math PRIVATE include)

target_include_directories(math PRIVATE ../../extlibs/imgui/include)
target_link_libraries(math PRIVATE imgui)

add_subdirectory(src)