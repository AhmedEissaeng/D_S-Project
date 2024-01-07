#ifndef NODE_H
#define NODE_H
using namespace std;
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <cmath>
#include <cstdint>
#include <bitset>
#include<algorithm>>
#include"QInputDialog"
#include <QChar>
#include "QtCore/qchar.h"
#include <QString>
#include <cctype>
struct Node{

    QString name ;
    QString value ;
    vector<Node> children;

};
#endif // NODE_H


