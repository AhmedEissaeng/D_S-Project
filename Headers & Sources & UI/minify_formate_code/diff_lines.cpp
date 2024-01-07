using namespace std;
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include"QInputDialog"
#include <QChar>
#include "QtCore/qchar.h"
#include <QString>


QString diff_lines(QString filedata){
    QString output="";
    QString line="";
    QString line2;
    QString buffer="";
    QTextStream in(&filedata);


    bool inside_tag = false;

    while (!in.atEnd()) {

        line = in.readLine().trimmed();

        for (int i = 0; i < line.length(); i++) {
            if (line[i] != '\n' && line[i] != '\r' && line[i] != '\t' && line[i] != '\0') {
                line2 += line[i];
            }
        }
    }

    for (size_t i = 0; i < line2.length(); i++) {
        if (line2[i] == '<') {
            if (buffer.length() != 0) {
                output=output+ buffer + '\n';
                buffer = "";
            }
            buffer += line2[i];
            inside_tag = true;
        } else {
            buffer += line2[i];
        }
        if (line2[i] == '>') {
            inside_tag = false;
            output=output + buffer + '\n';
            buffer = "";
        }
    }
    return output;
}
