#ifndef BUILDHUFFMANTREE_H
#define BUILDHUFFMANTREE_H
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <queue>
#include "QInputDialog"
#include <QChar>
#include "QtCore/qchar.h"
#include <QString>
#include <QMap>
using namespace std;
#include "newNode.h"
#include "huffman_Node.h"

huffman_Node* buildHuffmanTree(QMap<QChar, int> );
#endif // BUILDHUFFMANTREE_H


