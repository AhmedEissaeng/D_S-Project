#include "checkconsistency.h"
QString checkconsistency(QString filedata) {
    filedata=diff_lines(filedata);

    QTextStream in(&filedata);
    QString line;
    stack<Node> node_stack;
    Node imaginary_firstnode;
    node_stack.push(imaginary_firstnode);
    int cnt_line_number=0;
    while (in.readLineInto(&line)) {
        line = line.trimmed();
        if (line.isEmpty()) {
            continue;
        }
        cnt_line_number++;
        if (line.contains("<")) {
            QString tag = line.mid(line.indexOf("<") + 1, line.indexOf(">") - line.indexOf("<") - 1);
            if (tag[0] == '/') {
                if (node_stack.size()<2) {
                    return "not consistent";
                } else {
                    Node child = node_stack.top();
                    if (child.name != tag.mid(1)) {
                        return "not consistent";
                    } else {
                        node_stack.pop();
                        Node& parent = node_stack.top();
                        parent.children.push_back(child);
                    }
                }
            } else {
                Node node;
                node.name = tag;
                node_stack.push(node);
            }
        } else {
            if(node_stack.size()<2){
                return "not consistent";
            } else {
                Node& node = node_stack.top();
                node.value += line;
            }
        }
    }
    if (node_stack.size() > 1) {
        return "not consistent";
    }


    return "consistent";
}
