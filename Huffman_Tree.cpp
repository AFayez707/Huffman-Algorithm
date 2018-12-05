//
// Created by ahmedfayez on 12/25/17.
//

#include <iostream>
#include "Huffman_Tree.h"
#include <sstream>

void Huffman_Tree::build_huffman_tree(map<char, unsigned long long> frequencies) {

    for(map<char, unsigned long long>::iterator it=frequencies.begin(); it!=frequencies.end(); ++it){
        heap.push(new Huffman_Node(it->first, it->second, nullptr, nullptr));
    }

    Huffman_Node *root_node;

    while(heap.size() > 1){
        Huffman_Node *first_node = heap.top();
        heap.pop();
        Huffman_Node *second_node = heap.top();
        heap.pop();

        Huffman_Node *merged_node = new Huffman_Node('@', first_node->getFrequency()+second_node->getFrequency(), first_node, second_node);
        merged_node->setIs_ignored(true);

        root_node = merged_node;

        heap.push(root_node);
    }

    generate_huffman_codes(root_node, "");
    encode_nodes(root_node);
}


void Huffman_Tree::generate_huffman_codes(Huffman_Node *root, string code) {
    if(!root){
        return;
    }

    if(!root->getIs_ignored()){
        huffman_codes[root->getData()]=code;
        inverted_huffman_codes[code]=root->getData();
    }

    generate_huffman_codes(root->getLeft_node(), code + "0");
    generate_huffman_codes(root->getRight_node(), code + "1");
}

void Huffman_Tree::print_huffman_codes(map<char, string> huffman_codes) {
    for(auto it = huffman_codes.cbegin(); it != huffman_codes.cend(); ++it)
    {
        std::cout << it->first << " " << it->second << endl;
    }
}

void Huffman_Tree::encode_nodes(Huffman_Node *node){
    if (node->getRight_node()== nullptr && node->getLeft_node()== nullptr){
        encoded_nodes+='1';
        encoded_nodes+=node->getData();
    }
    else{
        encoded_nodes+='0';
        encode_nodes(node->getLeft_node());
        encode_nodes(node->getRight_node());
    }

}

string Huffman_Tree::map_to_string(){

    string output = "";
    string convrt = "";
    string result = "";
    for (auto it = inverted_huffman_codes.cbegin(); it != inverted_huffman_codes.cend(); it++) {
        convrt = std::to_string(it->second);
        output += (it->first) + ":" + (convrt) + ",";
    }

    result = output.substr(0, output.size() - 1 );

    return result;
}

void Huffman_Tree::destroy_codes(){
    inverted_huffman_codes.clear();
}

void Huffman_Tree::set_inverted_codes(vector<string> v){

    string code = v[0];
    string chr = v[1];

    int x = 0;
    stringstream character(chr);
    character >> x;

    inverted_huffman_codes[code]= (char) x;

}


const map<char, string> &Huffman_Tree::getHuffman_codes() const {
    return huffman_codes;
}

const string &Huffman_Tree::getEncoded_nodes() const {
    return encoded_nodes;
}

map<string, char> Huffman_Tree::get_huffman_inverted_codes() {
    return inverted_huffman_codes;

}