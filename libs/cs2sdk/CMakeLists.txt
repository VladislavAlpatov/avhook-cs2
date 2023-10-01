project(cs2sdk)
add_library(cs2sdk STATIC src/Player.cpp)
target_include_directories(cs2sdk PRIVATE include)

add_subdirectory(src)