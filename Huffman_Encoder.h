//
// Created by ahmedfayez on 12/25/17.
//

#ifndef HUFFMAN_CODING_DECODING_HUFFMAN_ENCODER_H
#define HUFFMAN_CODING_DECODING_HUFFMAN_ENCODER_H


#include <queue>
#include <functional>
#include <map>
#include "Huffman_Node.h"

using namespace std;

class Huffman_Encoder {
public:
    void encode(char *file_arary, streampos file_size, map<char, string> huffman_codes);
    const string &getEncoded_string() const;
    void compress_string(string encoded_string);

private:
    string encoded_string;
    string compressed_encoded_string;
public:
    const string &getCompressed_encoded_string() const;

private:
    int added_zeros=0;
public:
    int getAdded_zeros() const;

};


#endif //HUFFMAN_CODING_DECODING_HUFFMAN_ENCODER_H