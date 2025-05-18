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

void LZW::compress(const std::string& filename) {
    // Opens the original file if it exists.
    std::fstream f(filename);
    if(!f.is_open()) throw std::runtime_error("Couldn't open file.");

    std::unordered_map<std::string, int> dictionary;
    std::string p;
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
        ch += static_cast<char>(i);
        dictionary[ch] = i;
    }

    // Reads a combination of symbols, if the combination doesn't exist, it is added to the library, and added to the compressed file.
    while(f>>std::noskipws>>c){
        if(dictionary.contains(p + c)){
            p += c;
        }
        else {
            g << std::to_string(dictionary[p]) + " ";
            if (dictionary.size() < 4096) {
                dictionary[p + c] = static_cast<int>(dictionary.size());
            }
            p = c;
        }
    }
    g << std::to_string(dictionary[p]);

    // Outputs a completion message.
    std::cout<<"\nCompression completed\n\n";
}

void LZW::decompress(const std::string& filename){
    // Opens the compressed file if it exists.
    std::ifstream f(filename);
    if(!f.is_open()) throw std::runtime_error("Couldn't open file.");

    std::string extension, p, encoded, OLD, NEW, s, c;
    std::unordered_map<int, std::string> dictionary;

    // Creates the compressed file, adding a suitable extension.
    std::getline(f,extension);
    size_t pos = filename.rfind('.');
    std::ofstream g(filename.substr(0,pos) + extension);

    std::getline(f,encoded);
    std::stringstream iss{encoded};

    // Builds the dictionary, using the 256 characters of the ASCII table.
    for(int i = 0; i <= 255; i++){
        std::string ch;
        ch += static_cast<char>(i);
        dictionary[i] = ch;
    }

    // Decodes by reading codes and translating them through the code table being built.
    iss>>NEW;
    OLD = dictionary[std::stoi(NEW)];
    g << OLD;
    while(iss>>NEW){
        if(!dictionary.contains(std::stoi(NEW))){
            s = OLD;
            s += c;
        }
        else{
            s = dictionary[std::stoi(NEW)];
        }
        g << s;
        c = s[0];
        dictionary[static_cast<int>(dictionary.size())] = OLD + c;
        OLD = dictionary[std::stoi(NEW)];
    }

    std::cout<<"\nDecompression completed\n\n";
}