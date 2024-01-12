//
// Created by rafae on 12/16/2023.
//
#include "../inc/LZW.h"
#include <unordered_map>
#include <fstream>
#include <sstream>

//usually the

void LZW::compress(std::string& filename) {
    std::fstream f(filename);
    if(!f.is_open()) throw std::runtime_error("Couldn't open file.");

    std::unordered_map<std::string, int> dictionary;
    std::string p, encoded;
    char c;

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

    for(int i = 0; i <= 255; i++){
        std::string ch;
        ch += char(i);
        dictionary[ch] = i;
    }

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

    std::cerr<<"\nCompression completed\n\n";
}

void LZW::decompress(const std::string& inputFile){
    std::ifstream f(inputFile);
    if(!f.is_open()) throw std::runtime_error("Couldn't open file.");

    std::string extension, p, decoded, encoded, OLD, NEW, s, c;
    std::unordered_map<int, std::string> dictionary;
    size_t pos = inputFile.rfind('.');

    std::getline(f,encoded);
    std::stringstream iss{encoded};

    std::getline(f,extension);
    std::ofstream g(inputFile.substr(0,pos) + extension);

    for(int i = 0; i <= 255; i++){
        std::string ch;
        ch += char(i);
        dictionary[i] = ch;
    }

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