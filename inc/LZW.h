//
// Created by rafae on 12/16/2023.
//

#ifndef COMPRESIONE_LZW_H
#define COMPRESIONE_LZW_H

#include "compressor.h"
#include "iostream"

class LZW: public compressor{
public:
    void compress(std::string& filename) override;
    void decompress(const std::string& filename) override;
};

#endif //COMPRESIONE_LZW_H