//
// Created by rafae on 12/16/2023.
//

/**
 * @file LZW.h
 * @brief Contains the LZW compressor that inherits from the 'compressor' class.
 * @author Rafael Costin Balan
 * @date 2024-01-05
 * @version 1.0
 * @details Contains the class LZW that compresses/decompresses files using the LZW algorithm.
 * @copyright CES Public License
 */

#ifndef COMPRESIONE_LZW_H
#define COMPRESIONE_LZW_H

#include "compressor.h"
#include "iostream"

/**
 * This file contains LZW class, which inherits from the compressor interface, to compress/decompress files.
 */
class LZW: public compressor{
public:
    /*
    * Compresses the file using the LZW method to another file.
    * @param Name of the file to be compressed.
    */
    void compress(std::string& filename) override;
    /*
    * Decompresses the file by reading the dictionary to another file.
    * @param Name of the file to be decompressed.
    */
    void decompress(const std::string& filename) override;
};

#endif //COMPRESIONE_LZW_H