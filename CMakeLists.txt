cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_TOOLCHAIN_FILE "C:/Users/Vlad/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../../../out/${CMAKE_BUILD_TYPE}")
set(CMAKE_PDB_OUTPUT_DIRECTORY "../../../out/${CMAKE_BUILD_TYPE}")
set(VCPKG_TARGET_TRIPLET "x64-windows-static")


if (CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebug")
else ()
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded")
endif ()

project(avhook)

add_compile_definitions(WIN32_LEAN_AND_MEAN)


add_library(avhook MODULE avh/main.cpp)

add_subdirectory(extlibs)
add_subdirectory(libs)
add_subdirectory(avh)


find_package(minhook CONFIG REQUIRED)
target_link_libraries(avhook PRIVATE minhook::minhook)


target_include_directories(avhook PRIVATE "libs/sigscanner/include")
target_link_libraries(avhook PRIVATE sig_scanner)

target_include_directories(avhook PRIVATE "libs/cs2sdk/include")
target_link_libraries(avhook PRIVATE cs2sdk)

target_include_directories(avhook PRIVATE "extlibs/imgui/include" "avh")
target_link_libraries(avhook PRIVATE imgui)

message(STATUS "Direct3D 11 SDK path: '$ENV{DXSDK_DIR}'")


link_directories("$ENV{DXSDK_DIR}Lib/x64")
include_directories("$ENV{DXSDK_DIR}Include")