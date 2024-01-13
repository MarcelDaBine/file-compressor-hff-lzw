//
// Created by rafae on 12/16/2023.
//
/**
 * @file LZW.cpp
 * @brief Contains the implementations of the LZW class.
 * @author Rafael Costin Balan.
 * @date 2024-01-05
 * @version 1.0
 * @details It compresses and decompresses file, using the LZW method.
 * @copyright CES Public License
 */
#include "../inc/LZW.h"
#include <unordered_map>
#include <fstream>
#include <sstream>

//usually the limit to the dictionary is 4096.

void LZW::compress(std::string& filename) {
    // Opens the original file if it exists.
    std::fstream f(filename);
    if(!f.is_open()) throw std::runtime_error("Couldn't open file.");

    std::unordered_map<std::string, int> dictionary;
    std::string p, encoded;
    char c;

    // Creates the compressed file, adding a suitable extension.
    size_t pos = filename.rfind('.');
    std::ofstream g;
    if(pos != std::string::npos) {
        g.open(filename.substr(0,pos) + ".lzw");
        g<<filename.substr(pos)<<std::endl;
    }
    else {
        g.open(filename + ".lzw");
        g<<std::endl;
    }

    // Builds the dictionary, using the 256 characters of the ASCII table.
    for(int i = 0; i <= 255; i++){
        std::string ch;
        ch += char(i);
        dictionary[ch] = i;
    }

    // Reads a combination of symbols, if the combination doesn't exist, it is added to the library, and added to the compressed file.
    while(f>>std::noskipws>>c){
        if(dictionary.find(p + c) != dictionary.end()){
            p += c;
        }
        else {
            encoded += std::to_string(dictionary[p]) + " ";
            dictionary[p + c] = (int) dictionary.size();
            p = c;
        }
    }
    encoded += std::to_string(dictionary[p]);
    g<<encoded;

    // Outputs a completion message.
    std::cerr<<"\nCompression completed\n\n";
}

void LZW::decompress(const std::string& inputFile){
    // Opens the compressed file if it exists.
    std::ifstream f(inputFile);
    if(!f.is_open()) throw std::runtime_error("Couldn't open file.");

    std::string extension, p, decoded, encoded, OLD, NEW, s, c;
    std::unordered_map<int, std::string> dictionary;

    std::getline(f,encoded);
    std::stringstream iss{encoded};

    // Creates the compressed file, adding a suitable extension.
    std::getline(f,extension);
    size_t pos = inputFile.rfind('.');
    std::ofstream g(inputFile.substr(0,pos) + extension);

    // Builds the dictionary, using the 256 characters of the ASCII table.
    for(int i = 0; i <= 255; i++){
        std::string ch;
        ch += char(i);
        dictionary[i] = ch;
    }

    // Decodes by reading codes and translating them through the code table being built.
    iss>>NEW;
    OLD = dictionary[std::stoi(NEW)];
    decoded = OLD;
    while(iss>>NEW){
        if(dictionary.find(std::stoi(NEW)) == dictionary.end()){
            s = OLD;
            s += c;
        }
        else{
            s = dictionary[std::stoi(NEW)];
        }
        decoded += s;
        c = s[0];
        dictionary[int(dictionary.size())] = OLD + c;
        OLD = dictionary[std::stoi(NEW)];
    }
    g<<decoded;

    std::cerr<<"\nDecompression completed\n\n";
}