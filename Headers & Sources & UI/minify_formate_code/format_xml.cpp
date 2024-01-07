using namespace std;
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <stack>
#include"QInputDialog"
#include <QChar>
#include "QtCore/qchar.h"
#include <QString>

#include "format_xml.h"

QString format_xml(QString filedata) {
    filedata=diff_lines(filedata);

    QString outfile;
    QTextStream in(&filedata);
    QTextStream out(&outfile);

    stack<QString> tag_stack;
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.contains("<")) {
            QString tag = line.mid(line.indexOf("<") + 1, line.indexOf(">") - line.indexOf("<") - 1);
            if (tag[0] == '/') {
                tag_stack.pop();
            }
            for (int i = 0; i < tag_stack.size(); i++) {
                out << "    ";
            }
            out << line <<'\n';
            if (tag[0] != '/') {
                tag_stack.push(tag);
            }
        } else {
            for (int i = 0; i < tag_stack.size(); i++) {
                out << "    ";
            }
            out << line <<'\n';
        }
    }

    return outfile;
}
