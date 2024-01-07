#include "decompress.h"

QString decompress(QString filedata) {
    //QString decompressedfile="";
    QString input = filedata;
    QMap<QChar, int> frequencyTable;
    int count_unique = input[0].unicode() - 33;
    for (int i = 1; i <= count_unique * 3; i = i + 3) {
        int num1 = input[i + 1].unicode() - 33;

        int mask = 1 << 7;
        int g = (num1 & mask) >> 7;
        int num2 = input[i + 2].unicode();
        if (g == 1) {
            num2 = num2 - 33;
        }
        mask = (1 << 7);
        mask = ~mask;
        num1 = num1 & mask;
        int x = combineBinaryToDecimal(num1, num2);
        QChar z = input[i].unicode();
        frequencyTable[z] = x;
    }

    huffman_Node* root = buildHuffmanTree(frequencyTable);
    QMap<QString, QChar> opphuffmanTable;
    QMap<QChar,QString > huffmanTable;
    generateHuffmanCodes(root, "", huffmanTable, opphuffmanTable, true);
    int padded = input[count_unique * 3 + 1].unicode() - 33;
    if (padded < 0) {
        padded = 0;
    }
    QString decompressed = "";
    for (int i = count_unique * 3 + 2; i < input.length(); i++) {
        unsigned int x = input[i].unicode() - 33;
        decompressed += get_8_bit_representation(x);
    }
    // qDebug()<<opphuffmanTable["00"];
    QString decompressedunpadded = "";
    QString semi="";
    for (int i = 0; i < decompressed.length()-padded; i++) {
        semi =semi+decompressed[i];
        if (opphuffmanTable.find(semi) != opphuffmanTable.end()) {
            QChar w;
            char32_t intValue = opphuffmanTable[semi].unicode()-33; // Integer value for the hand symbol
            if (intValue <= 0xFFFF) {
                w = QChar(static_cast<ushort>(intValue));
            } else {
                ushort surrogate1 = 0xD800 + ((intValue - 0x10000) >> 10);
                ushort surrogate2 = 0xDC00 + ((intValue - 0x10000) & 0x3FF);
                w = QChar(surrogate1, surrogate2);
            }
            decompressedunpadded = decompressedunpadded+w ;
            semi="";
        }
    }
    decompressedunpadded=diff_lines(decompressedunpadded);
    decompressedunpadded=format_xml(decompressedunpadded);

    return decompressedunpadded;
}
