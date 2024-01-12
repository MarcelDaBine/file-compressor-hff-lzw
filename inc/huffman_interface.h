//
// Created by rafae on 1/12/2024.
//

#include "node_huffman.h"
#include <string>
#include <unordered_map>

#ifndef COMPRESIONE_INTERFACE_HUFFMAN_H
#define COMPRESIONE_INTERFACE_HUFFMAN_H

class huffman_interface{
public:
    virtual std::string encodeMessage(const std::string& message, const std::unordered_map<char, std::string>& huffmanCodes)= 0;
    virtual std::string decodedMessage(Node* root, const std::string& encodedMessage) = 0;
};

#endif //COMPRESIONE_INTERFACE_HUFFMAN_H
