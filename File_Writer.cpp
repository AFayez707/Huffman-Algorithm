//
// Created by ahmedfayez on 12/29/17.
//

#include <fstream>
#include <bitset>
#include "File_Writer.h"

void File_Writer::write(string encoded_nodes, string encoded_data, string file_path, int added_zeros, string map) {
    fstream output_file(file_path + ".huffman", ios::out|ios::binary);
    int encoded_nodes_size = encoded_nodes.size();
    if (output_file.is_open())
    {
        int ss = map.size();
        output_file.write(reinterpret_cast<const char *>(&added_zeros), 4);
        output_file.write(reinterpret_cast<const char *>(&ss), 4);
        output_file.write(map.c_str(), map.size());
        for(int i=0; i< encoded_data.size(); i+=8){
            string byte = encoded_data.substr(i, 8);
            bitset<8> b(byte);
            unsigned char c = ( b.to_ulong() & 0xFF);
            int x = static_cast<int>(c);
            output_file.write(reinterpret_cast<const char *>(&x), 1);
        }

        output_file.close();
    }
    else cout << "Unable to open file" << endl;

}

void File_Writer::write_string_to_file(string input, string file_path){
    fstream output_file(file_path + ".decompressed", ios::out|ios::binary);
    int encoded_nodes_size = input.size();
    if (output_file.is_open())
    {
        output_file.write(input.c_str(), input.size());
        output_file.close();
    }
    else cout << "Unable to open file" << endl;
}