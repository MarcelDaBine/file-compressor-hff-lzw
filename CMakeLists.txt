cmake_minimum_required(VERSION 3.22)
project(compresione)

set(CMAKE_CXX_STANDARD 23)

add_executable(compresione main.cpp
        inc/compressor.h
        inc/compressor.h
        src/LZW.cpp
        inc/huffman.h
        src/huffman.cpp
        inc/huffman_compressor.h
        inc/huffman_compressor.h
        inc/huffman_compressor.h
        inc/huffman_compressor.h
        inc/huffman_compressor.h
        src/huffman_compressor.cpp
        inc/node_huffman.h
        inc/huffman_interface.h
)

target_include_directories(compresione PRIVATE inc)


