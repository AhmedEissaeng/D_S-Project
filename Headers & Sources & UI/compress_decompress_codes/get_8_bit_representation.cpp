#include"get_8_bit_representation.h"

QString get_8_bit_representation(unsigned int num) {
    QString bits = "";
    for (int i = 7; i >= 0; --i) {
        bits += ((num >> i) & 1) ? '1' : '0';
    }
    return bits;
}
