project(sig_scanner)
add_library(sig_scanner STATIC src/SignatureScanner.cpp)
target_include_directories(sig_scanner PRIVATE include/sigscanner)
add_subdirectory(src)