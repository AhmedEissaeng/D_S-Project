#include"convertDecimalToBinary.h"

void convertDecimalToBinary(int decimalNum, int& num1, int& num2) {
    std::bitset<16> binaryNum(decimalNum);
    QString binaryString = QString::fromStdString(binaryNum.to_string());
    QString binaryNum1 = binaryString.mid(0, 8);
    QString binaryNum2 = binaryString.mid(8, 8);
    num1 = static_cast<int>(std::bitset<8>(binaryNum1.toStdString()).to_ulong());
    num2 = static_cast<int>(std::bitset<8>(binaryNum2.toStdString()).to_ulong());
}
