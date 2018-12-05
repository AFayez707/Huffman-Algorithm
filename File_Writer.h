//
// Created by ahmedfayez on 12/29/17.
//

#ifndef HUFFMAN_CODING_DECODING_FILE_WRITER_H
#define HUFFMAN_CODING_DECODING_FILE_WRITER_H

#include <iostream>
using namespace std;


class File_Writer {
public:
    void write(string encoded_nodes, string encoded_data, string file_path, int added_zeros, string map);
    void write_string_to_file(string input, string file_path);

};


#endif //HUFFMAN_CODING_DECODING_FILE_WRITER_H
