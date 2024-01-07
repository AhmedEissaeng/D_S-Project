#include "no_Users.h"
#include <QTextStream>
#include <QString>

int no_Users(QString filename) {
    int no_Users = 0;
    QTextStream file(&filename);
    QString line;
    while (!file.atEnd()) {
        line = file.readLine();
        if (line.contains("<user>")) {
            no_Users++;
        }
    }
    return no_Users;
}

