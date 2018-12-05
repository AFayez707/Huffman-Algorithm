//
// Created by ahmedfayez on 12/25/17.
//

#ifndef HUFFMAN_CODING_DECODING_NODE_H
#define HUFFMAN_CODING_DECODING_NODE_H


class Huffman_Node {
public:
    Huffman_Node(char data, unsigned int frequency, Huffman_Node *left_node, Huffman_Node *right_node);

    char getData() const;

    unsigned int getFrequency() const;

    Huffman_Node *getLeft_node() const;

    void setLeft_node(Huffman_Node *left_node);

    Huffman_Node *getRight_node() const;

    void setRight_node(Huffman_Node *right_node);

    bool getIs_ignored() const;

    void setIs_ignored(bool is_ignored);

    struct compare_nodes{
        bool operator()(Huffman_Node *first, Huffman_Node *second){
            return first->getFrequency() > second->getFrequency();
        }
    };

private:
    char data;
    unsigned int frequency;
    Huffman_Node *left_node;
    Huffman_Node *right_node;
    bool is_ignored = false;

};


#endif //HUFFMAN_CODING_DECODING_NODE_H
