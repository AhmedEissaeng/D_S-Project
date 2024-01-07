#ifndef HUFFMAN_NODE_H
#define HUFFMAN_NODE_H

#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include"QInputDialog"
#include <QChar>
#include "QtCore/qchar.h"
#include <QString>

using namespace std;
struct huffman_Node {
    QChar data;
    int frequency;
    huffman_Node* left;
    huffman_Node* right;
};
#endif // HUFFMAN_NODE_H

