//
// Created by ahmedfayez on 12/25/17.
//

#ifndef HUFFMAN_CODING_DECODING_FILE_READER_H
#define HUFFMAN_CODING_DECODING_FILE_READER_H

#include <iostream>
#include <fstream>
#include <map>
#include "Huffman_Tree.h"

using namespace std;


class File_Reader {
public:
    void read_file(string input_file_path);
    string read_huffman_file(string input_file_path, Huffman_Tree* tree, int *zeros);
private:
    map<char, unsigned long long> frequencies;
    streampos file_size;
    char *file_arary;
    ofstream outFile;
public:
    const map<char, unsigned long long int> &getFrequencies() const;

    const streampos &getFile_size() const;

    char *getFile_arary() const;
};


#endif //HUFFMAN_CODING_DECODING_FILE_READER_H
