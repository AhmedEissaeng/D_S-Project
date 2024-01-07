#include "newNode.h"

huffman_Node* newNode(QChar data, int frequency) {
    huffman_Node* node = new huffman_Node;
    node->data = data;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}
