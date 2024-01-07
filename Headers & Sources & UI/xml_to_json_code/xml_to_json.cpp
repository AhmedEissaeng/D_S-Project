#include"xml_to_json.h"

QString xml_to_json(QString filedata) {
    filedata=diff_lines(filedata);
    stack<Node> node_stack;
    Node imaginary_firstnode;
    node_stack.push(imaginary_firstnode);
    int cnt_line_number = 0;
    QTextStream in(&filedata);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) {
            continue;  // Skip empty lines
        }
        cnt_line_number++;

        if (line.contains("<")) {
            QString tag = line.mid(line.indexOf("<") + 1, line.indexOf(">") - line.indexOf("<") - 1);

            if (tag[0] == '/') {

                Node child = node_stack.top();

                node_stack.pop();

                Node& parent = node_stack.top();
                parent.children.push_back(child);
            } else {

                Node node;
                node.name = tag;
                node_stack.push(node);
            }
        } else {
            if (node_stack.size() < 2) {
                qDebug() << "no tags opened" << " at line : " << cnt_line_number;
            }
            Node& node = node_stack.top();
            node.value += line;
        }
    }

    QString outputi;

    QTextStream out(&outputi);
    s(out, node_stack.top(),0,false,false);

    return outputi;
}
