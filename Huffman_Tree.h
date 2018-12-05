//
// Created by ahmedfayez on 12/25/17.
//

#ifndef HUFFMAN_CODING_DECODING_HUFFMAN_TREE_H
#define HUFFMAN_CODING_DECODING_HUFFMAN_TREE_H

#include <map>
#include <vector>
#include <queue>
#include "Huffman_Node.h"
using namespace std;


class Huffman_Tree {
public:
    void build_huffman_tree(map<char, unsigned long long> frequencies);
    void generate_huffman_codes(Huffman_Node *root, string code);
    const map<char, string> &getHuffman_codes() const;
    void print_huffman_codes(map<char, string> huffman_codes);
    map<string, char> get_huffman_inverted_codes();
    void encode_nodes(Huffman_Node *node);
    string map_to_string();
    const string &getEncoded_nodes() const;
    void set_inverted_codes(vector<string> v);
    void destroy_codes();

        private:
    priority_queue<Huffman_Node*, vector<Huffman_Node*>, Huffman_Node::compare_nodes> heap;
    map<char, string> huffman_codes;
    map<string, char> inverted_huffman_codes;
    string encoded_nodes;
};


#endif //HUFFMAN_CODING_DECODING_HUFFMAN_TREE_H
