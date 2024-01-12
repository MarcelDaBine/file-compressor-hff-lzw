//
// Created by smocg on 12/10/2023.
//

#include "../inc/huffman.h"

// minheap
Node* huffman::buildHaffmanTree(std::priority_queue<Node*, std::vector<Node*>, CompareNodes> &pq) {
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* internalNode = new Node('$', left->freq + right->freq);
        internalNode->left = left;
        internalNode->right = right;

        pq.push(internalNode);
    }
    return pq.top();
}

void huffman::generateHuffmanTree(Node *root, const std::string& code,
                                  std::unordered_map<char, std::string> &huffmanCodes) {
    if (root) {
        if (root->data != '$') {
            huffmanCodes[root->data] = code;
        }

        generateHuffmanTree(root->left, code + "0", huffmanCodes);
        generateHuffmanTree(root->right, code + "1", huffmanCodes);
    }
}

std::string huffman::encodeMessage(const std::string &message,
                                   const std::unordered_map<char, std::string> &huffmanCodes) {
    std::string encodedMessage{};
    for (char c : message) {
        encodedMessage += huffmanCodes.at(c);
    }
    return encodedMessage;
}

std::string huffman::decodedMessage(Node *root, const std::string &encodedMessage) {
    std::string decodedMessage{};
    Node* current = root;

    for (char bit : encodedMessage) {
        if (bit == '0') {
            current = current->left;
        }
        else {
            current = current->right;
        }

        if (current->data != '$') {
            decodedMessage += current->data;
            current = root;
        }
    }
    return decodedMessage;
}
