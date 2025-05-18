# File Compressor - Huffman & LZW

This project implements two file compression algorithms: **LZW** and **Huffman**. It can compress and decompress files using either method.

### Requirements

- A C++20-compatible compiler

### Build Example

Open a terminal in the root of the project and run:

```bash
g++ -std=c++20 main.cpp src/*.cpp -Iinc -o compressor
```

### USAGE

Compressing a file

```bash
./compressor filename.txt lzw
./compressor filename.txt hff
```

Decompressing a file

```bash
./compressor filename.lzw
./compressor filename.hff
```
The program auto-detects the compression method for decompression based on the file extension.


