//
// Created by smocg on 12/10/2023.
//

#ifndef COMPRESSION_HUFFMAN_H
#define COMPRESSION_HUFFMAN_H

#include "node_huffman.h"
#include "huffman_interface.h"
#include <iostream>
#include <queue>
#include <unordered_map>

class huffman: public huffman_interface{
public:
    static Node* buildHaffmanTree(std::priority_queue<Node*, std::vector<Node*>, CompareNodes> &pq);

    static void generateHuffmanTree(Node* root, const std::string& code, std::unordered_map<char, std::string>& huffmanCodes);

    std::string encodeMessage(const std::string& message, const std::unordered_map<char, std::string>& huffmanCodes) override;
    std::string decodedMessage(Node* root, const std::string& encodedMessage) override;
};


#endif //COMPRESSION_HUFFMAN_H
