cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../../../out/${CMAKE_BUILD_TYPE}")
set(CMAKE_PDB_OUTPUT_DIRECTORY "../../../out/${CMAKE_BUILD_TYPE}")

if (CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebug")
else ()
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded")
endif ()

project(avhook)

add_compile_definitions(WIN32_LEAN_AND_MEAN)


add_library(avhook MODULE avh/main.cpp)

target_compile_definitions(avhook PRIVATE UNICODE)
target_compile_options(avhook PRIVATE /utf-8 /W4 /WX)

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

find_package(Boost REQUIRED)
target_link_libraries(avhook PRIVATE ${Boost_LIBRARIES})