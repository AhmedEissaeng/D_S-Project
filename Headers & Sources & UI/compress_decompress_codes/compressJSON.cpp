#include "compressJSON.h"
QString compressJSON(QString filedata) {
    QString compressedfile="";
    QString input = filedata;

    QMap<QChar, int> frequencyTable;
    for (int i = 0; i < input.length(); i++) {
        frequencyTable[input[i]]++;
    }
    int x =frequencyTable.size() + 33;
    compressedfile=compressedfile+QChar(x);

    //QMap<QChar, bool> visited;
    bool ivisited[2000] = {false};
    for (int i = 0; i < input.length(); i++) {
        if (!ivisited[input[i].toLatin1()]) {
            ivisited[input[i].toLatin1()] = true;

            compressedfile=compressedfile+QChar(input[i].unicode() + 33);

            int x = frequencyTable[input[i]];
            int num1, num2;
            convertDecimalToBinary(x, num1, num2);
            if (num2 <= 33) {
                num2 = num2 + 33;
                num1 = num1 | (1 << 7);
            }
            compressedfile=compressedfile+ QChar(num1 + 33)+QChar(num2);

        }
    }
    huffman_Node* root = buildHuffmanTree(frequencyTable);
    QMap<QChar, QString> huffmanTable;
    QMap<QString, QChar> opphuffmanTable;
    generateHuffmanCodes(root, "", huffmanTable, opphuffmanTable,false);
    QString compressedInput = "";
    for (int i = 0; i < input.length(); i++) {
        compressedInput += huffmanTable[input[i]];

    }

    int appended_pad_zeros = 0;

    for(int i=0;i<compressedInput.length();i=i+8){
        for (int j = 0; j < 8; j++) {
            bool k = false;
            if (i + j == compressedInput.length() - 1 && k == false) {
                appended_pad_zeros = 7 - j;

            }
        }
    }
    compressedfile=compressedfile+ QChar(appended_pad_zeros+33);


    for (int i = 0; i < compressedInput.length(); i = i + 8) {
        bool k = false;

        //out<<QChar(appended_pad_zeros+33);
        int ans = 0;
        QString an = "";
        for (int j = 0; j < 8; j++) {
            if (i + j == compressedInput.length() - 1 && k == false) {
                appended_pad_zeros = 7 - j;
                k = true;
            }
            char z = compressedInput.mid(i + j, 1).toInt();
            ans = ans | (z << (7 - j));
            an = an + z;

            if (k==true){
                for (int f=0;f<appended_pad_zeros;f++){
                    z=0;
                    j++;
                    //cout<<(int)z;
                    ans=ans|(z<<(7-j));
                    an=an+'0';
                }
                break;
            }



        }
        //qDebug()<<QChar(ans + 33)<<" ";



        compressedfile=compressedfile+ QChar(ans + 33);

    }



    return compressedfile;


}
