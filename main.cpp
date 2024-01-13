//
// Created by rafae on 1/8/2024.
//

#include "inc/huffman_compressor.h"
#include "inc/LZW.h"
#include <algorithm>
#include <string>

/**
 * @file main.cpp
 * @brief The main of this project.
 * @author Rafael Costin Balan
 * @date 2024-01-05
 * @version 1.0
 * @details It first creates the compressors, and compresses/decompresses, based on the inputs, while showing informative data.
 * @copyright Rafael Public License
 */

int main(int argc, char* argv[]){
    // Creates the compressors.
    LZW lzwCompressor;
    huffman_compressor huffmanCompressor;
    std::string file, compressor_name, suffix;

    // If the user chooses to compress, they must also choose a compression method.
    if(argc == 3){
        file = argv[1];
        suffix = (file.size() > 4) ? file.substr(file.size() - 4): "";
        compressor_name = argv[2];
        std::transform(compressor_name.begin(), compressor_name.end(), compressor_name.begin(), [](char c){return std::tolower(c);});

        if(suffix == ".lzw" || suffix ==".hff")std::cerr<<"\nNot a good idea to compress already compressed files.\n\n";

        if(compressor_name == "lzw") {
            lzwCompressor.compress(file);
        }
        else if(compressor_name == "huffman" || compressor_name == "hff"){
            huffmanCompressor.compress(file);
        }
        else std::cerr<<"\nNo available compression typed, input should be 'filename compression_method'(LZW/Huffman)\n\n";
    }
    // If the user chooses to decompress
    else if(argc == 2){
        file = argv[1];
        suffix = (file.size() > 4) ? file.substr(file.size() - 4): "";
        if(suffix == ".lzw")lzwCompressor.decompress(file);
        else if (suffix == ".hff")huffmanCompressor.decompress(file);
        else std::cerr<<"\nFile not suitable for decompression, if you wish to compress please also specify the desired compressing method (LZW/Huffman)\n\n";
    }
    else{
        std::cerr<<"\nIf you wish to decompress, put just the file name.\nIf you want to compress, put the file name and the compression method (LZW/Huffman), in this order\n\n";
    }
    return 0;
}