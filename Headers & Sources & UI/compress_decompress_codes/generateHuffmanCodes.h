#ifndef GENERATEHUFFMANCODES_H
#define GENERATEHUFFMANCODES_H

using namespace std;
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include"QInputDialog"
#include <QChar>
#include "QtCore/qchar.h"
#include <QString>
#include "buildHuffmanTree.h"

void generateHuffmanCodes(huffman_Node* , QString , QMap<QChar, QString>& , QMap<QString, QChar>& , bool );
#endif // GENERATEHUFFMANCODES_H

