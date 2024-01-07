#include "correct.h"

QString correct(QString filedata) {
    filedata= diff_lines(filedata);
    stack<Node> node_stack;
    QString line;
    Node imaginary_firstnode;
    node_stack.push(imaginary_firstnode);
    int cnt_line_number=0;
    QVector<QPair<int,QString>> solved;
    QTextStream stream(&filedata);
    while (!stream.atEnd()) {
        line = stream.readLine().trimmed();
        if (line.isEmpty()) {
            continue;
        }
        cnt_line_number++;
        if (line.contains("<")) {
            QString tag = line.mid(line.indexOf("<") + 1, line.indexOf(">") - line.indexOf("<") - 1);
            QString s='<'+tag+'>';
            solved.push_back({cnt_line_number,s});

            if (tag[0] == '/') {
                if (node_stack.size()<2) {
                    //   cout << "Error: Closing tag without opening tag: " << tag <<" at line : "<<cnt_line_number<< endl;
                    if(solved.size()==1){
                        solved[solved.size()-1].first++;

                        solved.push_back({cnt_line_number,'<'+tag.mid(1)+'>'});
                        cnt_line_number++;
                        Node node;
                        node.name=tag.mid(1);
                        node_stack.push(node);

                    }else{

                        QString q=solved[solved.size()-2].second;
                        if (q[0]!='<'){
                            solved[solved.size()-2].first++;
                            solved[solved.size()-1].first++;

                            solved.push_back({cnt_line_number-1,'<'+tag.mid(1)+'>'});
                            cnt_line_number++;
                            Node node;
                            node.name=tag.mid(1);
                            node_stack.push(node);
                            //	continue;
                        }else{
                            solved[solved.size()-1].first++;
                            solved.push_back({cnt_line_number,'<'+tag.mid(1)+'>'});
                            cnt_line_number++;
                            Node node;
                            node.name=tag.mid(1);
                            node_stack.push(node);
                        }
                    }
                }else{
                    Node child = node_stack.top();
                    if (child.name != tag.mid(1)) {
                        //cout << "Error: Mismatched tags: " << child.name << " and " << tag <<" at line : "<<cnt_line_number<< endl;
                        QString q=solved[solved.size()-2].second;
                        if (q[0]!='<'){
                            solved[solved.size()-2].first++;
                            solved[solved.size()-1].first++;
                            solved.push_back({cnt_line_number-1,'<'+tag.mid(1)+'>'});
                            cnt_line_number++;
                            Node node;
                            node.name=tag.mid(1);
                            node_stack.push(node);
                            child=node_stack.top();
                        }else{
                            solved[solved.size()-1].first++;
                            solved.push_back({cnt_line_number,'<'+tag.mid(1)+'>'});
                            cnt_line_number++;
                            Node node;
                            node.name=tag.mid(1);
                            node_stack.push(node);
                            child=node_stack.top();
                        }
                    }
                    node_stack.pop();
                    Node& parent = node_stack.top();
                    parent.children.push_back(child);
                }

            }else{
                Node node;
                node.name = tag;
                node_stack.push(node);
            }
        }else {
            solved.push_back({cnt_line_number,line});
            if(node_stack.size()<2){
                //cout<<"no tags opened"<<" at line : "<<cnt_line_number<< endl;
            }
            Node& node = node_stack.top();
            node.value +=line;
        }
    }


    while (node_stack.size() > 1) {
        //cout << "Error: Unclosed tag: " << node_stack.top().name <<" at line : "<<cnt_line_number<< endl;
        Node node=node_stack.top();
        QString s="</"+node.name+'>';
        cnt_line_number++;
        solved.push_back({cnt_line_number,s});
        node_stack.pop();
    }
    sort(solved.begin(),solved.end());
    QString st;
    for(int i=0;i<solved.size();i++){
        st=st+solved[i].second+'\n';
    }
    st=format_xml(st);
    return st;

}