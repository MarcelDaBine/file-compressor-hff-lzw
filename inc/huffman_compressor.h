//
// Created by rafae on 1/4/2024.
//
/**
 * @file huffman_compressor.h
 * @brief Contains the huffman_compressor that inherits from the 'compressor' class.
 * @author Rafael Costin Balan
 * @date 2024-01-05
 * @version 1.0
 * @details Contains the adapter huffman_compressor that compresses/decompresses files using a slightly modified version of the Huffman compression algorithm.
 * @copyright CES Public License
 */

#ifndef COMPRESIONE_HUFFMAN_COMPRESSOR_H
#define COMPRESIONE_HUFFMAN_COMPRESSOR_H

#include "compressor.h"
#include "huffman.h"
#include "node_huffman.h"
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <queue>
#include <memory>

/**
 * This file contains the huffman_compressor class, which inherits from the compressor interface, to compress/decompress files.
 */

class huffman_compressor : public compressor{
     huffman m_huffman;
public:
    /*
    * Compresses the file using the Huffman method to another file, it also adds the dictionary for decompressing purposes.
    * @param Name of the file to be compressed.
    */
    void compress(std::string& filename) override;
    /*
    * Decompresses the file by reading the dictionary to another file.
    * @param Name of the file to be decompressed.
    */
    void decompress(const std::string& filename) override;
};

#endif //COMPRESIONE_HUFFMAN_COMPRESSOR_H