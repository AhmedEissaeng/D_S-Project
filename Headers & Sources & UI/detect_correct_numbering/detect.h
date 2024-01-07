#ifndef DETECT_H
#define DETECT_H
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include"QInputDialog"
#include <QChar>
#include "QtCore/qchar.h"
#include <QString>
#include "Node.h"
#include "diff_lines.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

struct err_data{
    string err_type;
    int err_loc;
};

static inline void ltrim(string& s);

static inline void rtrim(string& s);

static inline void trim(string& s);

string replace_st(string str, const string& toReplace, const string& replaceWith);

string getOpenTa(string t);

string getClosedTa(string t);

string getTagValu(string t);

vector<string> file_to_vecto(string file_data);

bool error_detecto(string opent, string closedt, stack <string>& s, string& error_type);

vector <err_data> detect_erro(vector <string> xml_vector);

QString printErro (vector <err_data> error_vector);


#endif // DETECT_H
