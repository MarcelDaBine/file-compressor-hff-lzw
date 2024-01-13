//
// Created by rafae on 1/5/2024.
//

#ifndef COMPRESIONE_NODE_HUFFMAN_H
#define COMPRESIONE_NODE_HUFFMAN_H

struct Node {
    char data;
    int freq;

    Node *left;
    Node *right;

    Node(char data_, int freq_) {
        left = nullptr;
        right = nullptr;
        this->data = data_;
        this->freq = freq_;
    }
};

struct CompareNodes {
    bool operator()(Node *lhs, Node *rhs) {
        return (lhs->freq > rhs->freq);
    }
};
#endif //COMPRESIONE_NODE_HUFFMAN_H
