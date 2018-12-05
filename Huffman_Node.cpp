//
// Created by ahmedfayez on 12/25/17.
//

#include "Huffman_Node.h"

Huffman_Node::Huffman_Node(char data, unsigned int frequency, Huffman_Node *left_node, Huffman_Node *right_node){
    this->data=data;
    this->frequency=frequency;
    this->left_node=left_node;
    this->right_node=right_node;
}


char Huffman_Node::getData() const {
    return data;
}


unsigned int Huffman_Node::getFrequency() const {
    return frequency;
}

Huffman_Node *Huffman_Node::getLeft_node() const {
    return left_node;
}

void Huffman_Node::setLeft_node(Huffman_Node *left_node) {
    Huffman_Node::left_node = left_node;
}

Huffman_Node *Huffman_Node::getRight_node() const {
    return right_node;
}

void Huffman_Node::setRight_node(Huffman_Node *right_node) {
    Huffman_Node::right_node = right_node;
}

void Huffman_Node::setIs_ignored(bool is_ignored) {
    Huffman_Node::is_ignored = is_ignored;
}

bool Huffman_Node::getIs_ignored() const {
    return is_ignored;
}



