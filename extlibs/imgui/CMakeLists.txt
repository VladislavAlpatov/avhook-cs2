project(imgui)
add_library(imgui STATIC src/imgui.cpp)
target_include_directories(imgui PRIVATE include/imgui)

add_subdirectory(src)
find_package(Freetype REQUIRED)

target_link_libraries(imgui PRIVATE Freetype::Freetype)
