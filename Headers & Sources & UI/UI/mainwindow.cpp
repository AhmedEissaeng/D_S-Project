#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <stack>
#include <vector>
#include "QInputDialog"
#include <QChar>
#include "QtCore/qchar.h"
#include <QString>
#include <QLabel>
#include <QPixmap>
#include "graph.h"
#include "no_Users.h"
#include "Post.h"
#include "User.h"
#include "buildHuffmanTree.h"
#include "checkconsistency.h"
#include "combineBinaryToDecimal.h"
#include "convertDecimalToBinary.h"
#include "compress.h"
#include "compressJSON.h"
#include "correct.h"
#include "decompress.h"
#include "decompressJSON.h"
#include "detect.h"
#include "diff_lines.h"
#include "format_xml.h"
#include "generateHuffmanCodes.h"
#include "get_8_bit_representation.h"
#include "huffman_Node.h"
#include "minify_xml.h"
#include "newNode.h"
#include "numberedfile.h"
#include "s.h"
#include "same_node.h"
#include "xml_to_json.h"

#define NULL_EDGE 0

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

stack<QString> undo_stack;
stack<QString> redo_stack;

bool flag = false; //For Undo operation, every button makes flag false

void MainWindow::on_pushButton_clicked() //Minify button
{
    flag = false;
    QString myString = ui->textEdit->toPlainText();
    if(myString.isEmpty()){
        QMessageBox::warning(this,"Warning","There is no input!");
        return;
    }
    undo_stack.push(minify_xml(myString));
    ui->textBrowser_2->setText(undo_stack.top());
}

void MainWindow::on_pushButton_2_clicked() //Format button
{
    flag = false;
    QString myString = ui->textEdit->toPlainText();
    if(myString.isEmpty()){
        QMessageBox::warning(this,"Warning","There is no input!");
        return;
    }
    undo_stack.push(format_xml(myString));
    ui->textBrowser_2->setText(undo_stack.top());
}

void MainWindow::on_pushButton_3_clicked() //Convert to JSON button
{
    flag = false;
    QString myString = ui->textEdit->toPlainText();
    if(myString.isEmpty()){
        QMessageBox::warning(this,"Warning","There is no input!");
        return;
    }
    undo_stack.push(xml_to_json(myString));
    ui->textBrowser_2->setText(undo_stack.top());
}

void MainWindow::on_pushButton_4_clicked() //Compress XML button
{
    flag = false;
    QString myString = ui->textEdit->toPlainText();
    if(myString.isEmpty()){
        QMessageBox::warning(this,"Warning","There is no input!");
        return;
    }
    undo_stack.push(compress(minify_xml(myString)));
    ui->textBrowser_2->setText(undo_stack.top());
}

void MainWindow::on_pushButton_5_clicked() //Decompress XML button
{
    flag = false;
    QString myString = ui->textEdit->toPlainText();
    if(myString.isEmpty()){
        QMessageBox::warning(this,"Warning","There is no input!");
        return;
    }
    undo_stack.push(decompress(myString));
    ui->textBrowser_2->setText(undo_stack.top());
}

void MainWindow::on_pushButton_6_clicked() //Correct button
{
    flag = false;
    QString myString = ui->textEdit->toPlainText();
    if(myString.isEmpty()){
        QMessageBox::warning(this,"Warning","There is no input!");
        return;
    }
    QString error = printErro(detect_erro(file_to_vecto(myString.toStdString())));
    if(error.isEmpty()){
        QMessageBox::information(this,"Info","There are no errors in this file.");
        return;
    }
    undo_stack.push(correct(myString));
    ui->textBrowser_2->setText(undo_stack.top());
}

void MainWindow::on_pushButton_7_clicked() //Detect button
{
    flag = false;
    QString myString = ui->textEdit->toPlainText();
    if(myString.isEmpty()){
        QMessageBox::warning(this,"Warning","There is no input!");
        return;
    }
    QString error = printErro(detect_erro(file_to_vecto(myString.toStdString())));
    if(error.isEmpty()){
        QMessageBox::information(this,"Info","There are no errors in this file.");
        return;
    }
    //myString = diff_lines(myString);
    //myString = format_xml(myString);
    undo_stack.push(error + "\n\n" + numberedfile(myString));
    ui->textBrowser_2->setText(undo_stack.top());
}

void MainWindow::on_pushButton_8_clicked() //Check Consistency button
{
    QString myString = ui->textEdit->toPlainText();
    if(myString.isEmpty()){
        QMessageBox::warning(this,"Warning","There is no input!");
        return;
    }
    QMessageBox::information(this,"Info","This file is " + checkConsistency(myString));
}

void MainWindow::on_pushButton_9_clicked() //Post Search button
{
    flag = false;
    QString text = QInputDialog::getText(this, "Post Search", "Enter word or topic:");
    QString myString = ui->textEdit->toPlainText();
    if(myString.isEmpty()){
        QMessageBox::warning(this,"Warning","There is no input!");
        return;
    }
    QString outfile;
    myString = diff_lines(myString);
    int s = no_Users(myString);
    Graph graph(s);
    graph.build_graph(myString);
    QTextStream out(&outfile);
    vector<Post> p = graph.post_search(text);
    for(auto i:p)
    {
        out << i.getBody() << '\n';
        for(auto j:i.getTopic())
        {
            out << j << " ";
        }
        out << "\n\n";
    }
    if(outfile.isEmpty()){
        QMessageBox::information(this,"Info","There are no posts include this word or posts about this topic!");
        return;
    }
    undo_stack.push(outfile);
    ui->textBrowser_2->setText(undo_stack.top());
}

void MainWindow::on_actionOpen_triggered() //Open file
{
    QString filename = QFileDialog::getOpenFileName(this,tr("open file"),"c://", "All Files (*) ;; Text File (*.txt) ;; XML File (*.xml)");
    QFile  file(filename);
    if (!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0,"info",file.errorString());
    }
    QTextStream input(&file);
    ui->textEdit->setText(input.readAll());
}

void MainWindow::on_actionRedo_triggered() //Redo
{
    if(!redo_stack.empty()){
        undo_stack.push(ui->textBrowser_2->toPlainText());
        ui->textBrowser_2->setText(redo_stack.top());
        redo_stack.pop();
    }
    else
        return;
}


void MainWindow::on_actionUndo_triggered() //Undo
{
    if(!flag){ //If this is the first time to do Undo operation after pressing one of the buttons, you must remove the current top of undo stack to get the previous output
        if(!undo_stack.empty()){
                redo_stack.push(ui->textBrowser_2->toPlainText());
                undo_stack.pop();
                if(!undo_stack.empty()){
                    ui->textBrowser_2->setText(undo_stack.top());
                    undo_stack.pop();
                    flag = true;
                }
                else
                    ui->textBrowser_2->clear();
        }
        else
            return;
    }
    else{
        if(!undo_stack.empty()){
            redo_stack.push(ui->textBrowser_2->toPlainText());
            ui->textBrowser_2->setText(undo_stack.top());
            undo_stack.pop();
        }
        else
            return;
    }
}


void MainWindow::on_actionSave_triggered() //Save as
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save File as", "/path/to/file/", "All Files (*)");
    QString myString = ui->textBrowser_2->toPlainText();
    if(myString.isEmpty()){
        QMessageBox::warning(this,"Warning","There is no input!");
        return;
    }
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << myString;
        file.close();
    }
}


void MainWindow::on_pushButton_12_clicked() //Suggest button
{
    flag = false;
    QString myString = ui->textEdit->toPlainText();
    if(myString.isEmpty()){
        QMessageBox::warning(this,"Warning","There is no input!");
        return;
    }
    QString outfile;
    myString = diff_lines(myString);
    int s = no_Users(myString);
    Graph graph(s);
    graph.build_graph(myString);
    QString id = QInputDialog::getText(this,"Suggest Followers","Enter ID:");
    if(id == "")
        return;
    int i = graph.getIndex(id);
    if(i == -1){
        QMessageBox::warning(this,"Unavailable ID","There is no user with such id.");
        return;
    }
    QTextStream out(&outfile);
    vector<User> Friends = graph.followSuggestion(id);
    for(auto z : Friends){
        out << z.getId() << " " << z.getName() << '\n';
    }
    if(outfile.isEmpty()){
        ui->textBrowser_2->setText("The followers of this user whose id is " + id + " are the rest of the users in the input file.");
        return;
    }
    undo_stack.push(outfile);
    ui->textBrowser_2->setText(undo_stack.top());
}


void MainWindow::on_pushButton_13_clicked() //Network info button (returns most influencer user and most active user)
{
    flag = false;
    QString myString = ui->textEdit->toPlainText();
    if(myString.isEmpty()){
        QMessageBox::warning(this,"Warning","There is no input!");
        return;
    }
    QString outfile;
    myString = diff_lines(myString);
    int s = no_Users(myString);
    Graph graph(s);
    graph.build_graph(myString);
    QTextStream out(&outfile);
    out << "Most influencer: " << graph.mostInfluencerUser().getName() << '\n';
    out << "Most active: " << graph.mostActiveUser().getName() << '\n';
    undo_stack.push(outfile);
    ui->textBrowser_2->setText(undo_stack.top());
}


void MainWindow::on_pushButton_11_clicked() //Mutual button
{
    flag = false;
    QString myString = diff_lines(ui->textEdit->toPlainText());
    if(myString.isEmpty()){
        QMessageBox::warning(this,"Warning","There is no input!");
        return;
    }
    QString outfile;
    myString = diff_lines(myString);
    int s = no_Users(myString);
    Graph graph(s);
    graph.build_graph(myString);
    QString text = QInputDialog::getText(this, "Mutual Followers", "Enter ID1:");
    if(text == "")
        return;
    int i_1 = graph.getIndex(text);
    if(i_1 == -1){
        QMessageBox::warning(this,"Unavailable ID","There is no user with such id.");
        return;
    }
    QString text2 = QInputDialog::getText(this, "Mutual Followers", "Enter ID2:");
    if(text2 == "")
        return;
    int i_2 = graph.getIndex(text2);
    if(i_2 == -1){
        QMessageBox::warning(this,"Unavailable ID","There is no user with such id.");
        return;
    }
    QTextStream out(&outfile);
    vector<User> friends = graph.mutualFollowers(text, text2);
    for(auto z:friends){
        out << z.getId() << " " << z.getName() << '\n';
    }
    if(friends.size() == 0){
        out << "User: " << graph.getUser(text).getName() << " has no mutual followers with " << "User: " <<graph.getUser(text2).getName() << '\n';
    }
    undo_stack.push(outfile);
    ui->textBrowser_2->setText(undo_stack.top());
}


void MainWindow::on_pushButton_10_clicked() //Graph button
{
    QString myString = ui->textEdit->toPlainText();
    if(myString.isEmpty()){
        QMessageBox::warning(this,"Warning","There is no input!");
        return;
    }
    myString = diff_lines(myString);
    int s = no_Users(myString);
    Graph graph(s);
    graph.build_graph(myString);
    QString dotFileName = "graph.dot";
    graph.generateDOT(dotFileName);
    system(".\\GraphVizLite\\GraphVizLite\\dot.exe -Tpng graph.dot -o graph.png");
    QLabel* label = new QLabel();
    QPixmap pixmap(".\\graph.png");
    label->setPixmap(pixmap);
    label->show();
}


void MainWindow::on_pushButton_14_clicked() //Compress JSON button
{
    flag = false;
    QString myString = ui->textEdit->toPlainText();
    if(myString.isEmpty()){
        QMessageBox::warning(this,"Warning","There is no input!");
        return;
    }
    undo_stack.push(compressJSON(myString));
    ui->textBrowser_2->setText(undo_stack.top());
}


void MainWindow::on_pushButton_15_clicked() //Decompress JSON button
{
    flag = false;
    QString myString = ui->textEdit->toPlainText();
    if(myString.isEmpty()){
        QMessageBox::warning(this,"Warning","There is no input!");
        return;
    }
    undo_stack.push(decompressJSON(myString));
    ui->textBrowser_2->setText(undo_stack.top());
}
