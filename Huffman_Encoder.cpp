//
// Created by ahmedfayez on 12/25/17.
//

#include <iostream>
#include <sstream>
#include <bitset>
#include "Huffman_Encoder.h"

void Huffman_Encoder::encode(char *file_arary, streampos file_size, map<char, string> huffman_codes) {
    for(unsigned long long i=0; i<file_size; i++){
        encoded_string+=huffman_codes[file_arary[i]];
    }

    if(encoded_string.size() % 8 == 0){
        added_zeros=0;
    }
    else{
        added_zeros= 8 - encoded_string.size() % 8;
        for(int i=0; i < added_zeros; i++){
            encoded_string+='0';
        }
    }
}

const string &Huffman_Encoder::getEncoded_string() const {
    return encoded_string;
}

void Huffman_Encoder::compress_string(string encoded_string) {
    istringstream in(encoded_string);
    bitset<8> bs;
    while(in >> bs)
        compressed_encoded_string += char(bs.to_ulong());
}

const string &Huffman_Encoder::getCompressed_encoded_string() const {
    return compressed_encoded_string;
}

int Huffman_Encoder::getAdded_zeros() const {
    return added_zeros;
}
