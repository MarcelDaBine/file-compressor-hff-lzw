//
// Created by rafae on 12/16/2023.
//
/**
 * @file compressor.h
 * @brief Contains the compressor interface
 * @author Rafael Costin Balan
 * @date 2024-01-05
 * @version 1.0
 * @details This file contains the compressor class which is a interface for other compressors.
 * @copyright CES Public License
 */

#include <string>

#ifndef COMPRESIONE_COMPRESSOR_H
#define COMPRESIONE_COMPRESSOR_H

class compressor{
public:
    /*
     * A virtual function that makes the classes that inherit need to be able to compress files.
     * @param filename represent the name of the file which is going to be compressed.
     */
    virtual void compress(const std::string& filename) = 0;
    /*
    * A virtual function that makes the classes that inherit need to be able to decompress files.
    * @param filename represent the name of the file which is going to be decompressed.
    */
    virtual void decompress(const std::string& filename) = 0;
    virtual ~compressor() = default;
};

#endif //COMPRESIONE_COMPRESSOR_H