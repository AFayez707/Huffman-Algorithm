//
// Created by ahmedfayez on 12/25/17.
//

#include <cstring>
#include <bitset>
#include "File_Reader.h"
#include "Huffman_Encoder.h"
#include "Huffman_Tree.h"

void File_Reader::read_file(string input_file_path){

    ifstream file(input_file_path, ios::in|ios::binary|ios::ate);
    if (file.is_open())
    {
        file_size = file.tellg();
        file_arary = new char [file_size];
        file.seekg (0, ios::beg);
        file.read (file_arary, file_size);
        file.close();

        outFile.open("/home/ahmedfayez/CLionProjects/Huffman-Coding-Decoding/test/out.txt", ios::binary | ios::app);

        for(unsigned long long i=0 ;i< file_size; i++){
            frequencies[file_arary[i]]++;
        }

        outFile.write(file_arary, file_size);
        outFile.close();

    }
    else cout << "Unable to open file" << endl;

}

const map<char, unsigned long long int> &File_Reader::getFrequencies() const {
    return frequencies;
}

const streampos &File_Reader::getFile_size() const {
    return file_size;
}

char *File_Reader::getFile_arary() const {
    return file_arary;
}

vector<string> split_str(string str, string sep){
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    vector<std::string> arr;
    current=strtok(cstr,sep.c_str());
    while(current != NULL){
        arr.push_back(current);
        current=strtok(NULL, sep.c_str());
    }
    return arr;
}


string File_Reader::read_huffman_file(string input_file_path, Huffman_Tree* tree, int *zeros) {
    ifstream file(input_file_path, ios::in|ios::binary);

    file.seekg (0, file.end);
    int length = file.tellg();
    file.seekg (0, file.beg);

    int added_zeros;
    file.read(reinterpret_cast<char *>(&added_zeros), 4);

    *zeros = added_zeros;

    int ss;
    file.read(reinterpret_cast<char *>(&ss), 4);
    cout << "SS " << ss <<endl;

    length-=8;
    length-=ss;

    char* map = new char[ss];
    file.read(map, ss);
    string map2(map);
    map2 = map2.substr(0, ss);
    vector<std::string> v;
    vector<std::string> v1;
    v = split_str(map2,",");

    tree->destroy_codes();

    for(int i = 0;i<v.size(); i++){
        v1 = split_str(v[i], ":");
        tree->set_inverted_codes(v1);
    }

    char * file_array = new char [length];

    file.read (file_array, length);
    file.close();

    string file_string (file_array);

    string output_string;
    for(int i=0; i<length; i++){
        bitset<8> b(file_array[i]);
        output_string+=b.to_string();
    }

    return output_string;

}
