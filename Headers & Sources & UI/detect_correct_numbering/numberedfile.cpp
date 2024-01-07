#include "numberedfile.h"

QString numberedfile(QString filedata){
    QTextStream in(&filedata);
    QString line="";
    int cnt=0;
    while (!in.atEnd()) {
        cnt++;
        line =  line +QString::number(cnt)+")  "+in.readLine()+'\n';
    }
  return line;
}
