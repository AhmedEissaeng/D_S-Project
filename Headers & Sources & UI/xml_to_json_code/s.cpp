using namespace std;
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include"QInputDialog"
#include <QChar>
#include "QtCore/qchar.h"
#include <QString>

#include"s.h"

void s(QTextStream& outfile, Node& node, int cnt = 0, bool same = false, bool flag = false) {
    bool h = false;
    if (flag == false) {
        for (Node child : node.children) {
            s(outfile, child, cnt, same, true);
        }
        return;
    }
    if (node.children.size() > 0) {
        if (same) {
            for (int i = 0; i < cnt; i++) {
                outfile << "    ";
            }
        } else {
            for (int i = 0; i < cnt; i++) {
                outfile << "    ";
            }
            outfile << node.name << ": ";
            h = true;
        }
        bool k = true;
        for (Node child : node.children) {
            k = same_node(node, child);
            if (k == false) {
                break;
            }
        }
        if (k == false) {
            cnt++;
            outfile << "{" << '\n';
            for (int i = 0; i < node.children.size(); i++) {
                s(outfile, node.children[i], cnt, k, flag);
                if (i != node.children.size() - 1) {
                    outfile << "," << '\n';
                } else {
                    outfile << '\n';
                }
            }
            for (int i = 0; i < cnt - 1; i++) {
                outfile << "    ";
            }
            outfile << "}";
            cnt--;
        } else {
            cnt++;
            outfile << "[" << '\n';
            for (int i = 0; i < node.children.size(); i++) {
                s(outfile, node.children[i], cnt, k, flag);
                if (i != node.children.size() - 1) {
                    outfile << "," << '\n';
                } else {
                    outfile <<'\n';
                }
            }
            for (int i = 0; i < cnt - 1; i++) {
                outfile << "    ";
            }
            outfile << "]";
            cnt--;
        }
    } else {
        if (same) {
            for (int i = 0; i < cnt; i++) {
                outfile << "    ";
            }
            outfile << char(34) << node.value << char(34);
        } else {
            for (int i = 0; i < cnt; i++) {
                outfile << "    ";
            }
            outfile << char(34) << node.name << char(34) << ": " << char(34) << node.value << char(34);
        }
    }
}
