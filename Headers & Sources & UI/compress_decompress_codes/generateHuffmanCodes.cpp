#include "generateHuffmanCodes.h"

void generateHuffmanCodes(huffman_Node* root, QString code, QMap<QChar, QString>& huffmanTable, QMap<QString, QChar>& opphuffmanTable, bool opposite = false) {
    if (root == NULL) {
        return;
    }
    if (root->data != '$') {
        huffmanTable[root->data] = code;
        if (opposite == true) {
            opphuffmanTable[code] = root->data;
        }
    }
    generateHuffmanCodes(root->left, code + '0', huffmanTable, opphuffmanTable, opposite);
    generateHuffmanCodes(root->right, code + '1', huffmanTable, opphuffmanTable, opposite);
}
