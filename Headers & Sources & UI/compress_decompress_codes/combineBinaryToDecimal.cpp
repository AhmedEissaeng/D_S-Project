#include"combineBinaryToDecimal.h"
int combineBinaryToDecimal(int num1, int num2) {
    std::bitset<8> binaryNum1(num1);
    std::bitset<8> binaryNum2(num2);

    QString combinedBinary = QString::fromStdString(binaryNum1.to_string() + binaryNum2.to_string());

    int decimalNum = static_cast<int>(std::bitset<16>(combinedBinary.toStdString()).to_ulong());

    return decimalNum;
}
