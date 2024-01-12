//
// Created by rafae on 1/8/2024.
//
#include "../inc/huffman_compressor.h"

void huffman_compressor::compress(std::string& filename) {
    std::fstream f(filename);
    if(!f.is_open()) throw std::runtime_error("Couldn't open file.");

    size_t pos = filename.rfind('.');
    std::ofstream g;
    if(pos != std::string::npos) {
        g.open(filename.substr(0,pos) + ".hff");
        g<<filename.substr(pos)<<std::endl;
    }
    else {
        g.open(filename + ".hff");
        g<<std::endl;
    }

    std::string temp, message;
    std::unordered_map<char, int> freqMap;
    while(getline(f,temp)) {
        message += temp;
        for (char c: temp) {
            freqMap[c]++;
        }
    }

    std::priority_queue<Node*, std::vector<Node*>, CompareNodes> pq;
    for (auto entry : freqMap) {
        pq.push(new Node(entry.first, entry.second));
    }

    Node* root = m_huffman.buildHaffmanTree(pq);

    std::unordered_map<char, std::string> huffmanCode;
    m_huffman.generateHuffmanTree(root, "", huffmanCode);

    std::string encodedMessage;

    for(const auto& pair: huffmanCode){
        encodedMessage+=pair.first;
        encodedMessage+=":";
        encodedMessage+=pair.second;
        encodedMessage+="\n";
    }
    encodedMessage += "delim\n";

    encodedMessage += m_huffman.encodeMessage(message, huffmanCode);
    g<<encodedMessage;
    std::cerr<<"\nCompression completed\n\n";
}

void huffman_compressor::decompress(const std::string &filename) {
    std::ifstream f(filename);
    if(!f.is_open()) throw std::runtime_error("Couldn't open file.");

    std::string extension;
    std::getline(f,extension);
    size_t pos_file = filename.rfind('.');
    std::ofstream g(filename.substr(0,pos_file) + extension);
    std::unordered_map<std::string, std::string> myMap;
    std::string item, first, second, encoded;
    char c;

    while (std::getline(f, item)){
        if(item != "delim"){
            size_t pos = item.rfind(':');
            if(pos == std::string::npos){
                std::getline(f,item);
                first = "\n";
                second = item.substr(1);
            }
            else {
                first = item.substr(0, pos);
                second = item.substr(pos + 1);
            }
            myMap[second] = first;
        }
        else break;
    }

    while(f.get(c)){
        encoded+=c;
        if(myMap.find(encoded) != myMap.end()){
            g<<myMap[encoded];
            encoded = "";
        }
    }
    std::cerr<<"\nDecompression completed\n\n";
}