#include "buildHuffmanTree.h"

struct Compare {
    bool operator()(huffman_Node* left, huffman_Node* right) {
        return (left->frequency > right->frequency);
    }
};

huffman_Node* buildHuffmanTree(QMap<QChar, int> frequencyTable) {
    priority_queue<huffman_Node*, vector<huffman_Node*>, Compare> pq;
    for (auto it = frequencyTable.begin(); it != frequencyTable.end(); it++) {
        pq.push(newNode(it.key(), it.value()));
    }
    while (pq.size() > 1) {
        huffman_Node* left = pq.top();
        pq.pop();
        huffman_Node* right = pq.top();
        pq.pop();
        huffman_Node* node = newNode('$', left->frequency + right->frequency);
        node->left = left;
        node->right = right;
        pq.push(node);
    }
    return pq.top();
}
