#include <iostream>
#include <bitset>
#include "Huffman_Node.h"
#include "File_Reader.h"
#include "Huffman_Encoder.h"
#include "Huffman_Tree.h"
#include "File_Writer.h"

using namespace std;


int main(int argc, char** argv) {

    if(argc != 3){
        exit(1);
    }

    string compress = "compress";
    string decompress = "decompress";
    string method = argv[1];
    string file_path = argv[2];
    File_Reader x;
    Huffman_Tree y;
    File_Writer w;

    if(compress.compare(method) == 0){
        Huffman_Encoder z;
        x.read_file(file_path);
        y.build_huffman_tree(x.getFrequencies());
        z.encode(x.getFile_arary(), x.getFile_size(), y.getHuffman_codes());
        z.compress_string(z.getEncoded_string());
        w.write(y.getEncoded_nodes(), z.getEncoded_string(), file_path, z.getAdded_zeros(), y.map_to_string());
    } else if (decompress.compare(method) == 0){

        int addedzeros;
        string binary_string = x.read_huffman_file(file_path, &y, &addedzeros);

        binary_string = binary_string.substr(0, binary_string.size()-addedzeros);

        map<string, char> inverted_map = y.get_huffman_inverted_codes();

        string code;
        string decompressed_string;

        for(int i=0; i<binary_string.size(); i++){
            code+=binary_string[i];
            if(inverted_map.find(code) != inverted_map.cend()){
                decompressed_string += inverted_map[code];
                code="";
            }
        }

        w.write_string_to_file(decompressed_string, file_path);

    } else {
        cout << "Invalid method.. please try again.";
        exit(1);
    }
}