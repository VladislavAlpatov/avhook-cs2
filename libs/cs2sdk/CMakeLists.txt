project(cs2sdk)
add_library(cs2sdk STATIC src/Player.cpp)

target_include_directories(cs2sdk PRIVATE include)

target_include_directories(cs2sdk PRIVATE ../sigscanner/include)
target_link_libraries(cs2sdk PRIVATE sig_scanner)

target_include_directories(cs2sdk PRIVATE ../../extlibs/imgui/include)
target_link_libraries(cs2sdk PRIVATE imgui)

target_include_directories(cs2sdk PUBLIC ../math/include)
target_link_libraries(cs2sdk PUBLIC math)

add_subdirectory(src)