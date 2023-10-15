project(imgui)
add_library(imgui STATIC src/imgui.cpp)
target_include_directories(imgui PRIVATE include/imgui)

add_subdirectory(src)
find_package(Freetype REQUIRED)



target_link_libraries(imgui      PRIVATE Freetype::Freetype)
target_link_directories(imgui    PRIVATE "$ENV{DXSDK_DIR}Lib/x64")
target_include_directories(imgui PRIVATE "$ENV{DXSDK_DIR}Include")

target_link_libraries(imgui PRIVATE d3d11 d3dx11)
