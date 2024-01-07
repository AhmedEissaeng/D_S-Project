#include "minify_xml.h"
QString minify_xml(QString filedata) {
    QString outfile;
    QTextStream in(&filedata);
    QTextStream out(&outfile);

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        for (int i = 0; i < line.length(); i++) {
            if (line[i] != '\n' && line[i] != '\r' && line[i] != '\t') {
                out << line[i];
            }
        }
    }
    return outfile;

}

