#ifndef DECOMPRESS_H
#define DECOMPRESS_H

using namespace std;
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include "QInputDialog"
#include <QChar>
#include "QtCore/qchar.h"
#include <QString>
#include "combineBinaryToDecimal.h"
#include "get_8_bit_representation.h"
#include "minify_xml.h"
#include "format_xml.h"
#include "generateHuffmanCodes.h"


QString decompress(QString );
#endif // DECOMPRESS_H
