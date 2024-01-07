#ifndef DECOMPRESSJSON_H
#define DECOMPRESSJSON_H

#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include"QInputDialog"
#include <QChar>
#include "QtCore/qchar.h"
#include <QString>
using namespace std;
#include "combineBinaryToDecimal.h"
#include "get_8_bit_representation.h"
#include "minify_xml.h"
#include "format_xml.h"
#include "generateHuffmanCodes.h"

QString decompressJSON(QString );
#endif // DECOMPRESSJSON_H
