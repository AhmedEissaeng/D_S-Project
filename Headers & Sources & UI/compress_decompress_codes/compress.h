#ifndef COMPRESS_H
#define COMPRESS_H
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include"QInputDialog"
#include <QChar>
#include "QtCore/qchar.h"
#include <QString>

using namespace std;
#include "minify_xml.h"
#include "convertDecimalToBinary.h"
#include "generateHuffmanCodes.h"
QString compress(QString);
#endif // COMPRESS_H


