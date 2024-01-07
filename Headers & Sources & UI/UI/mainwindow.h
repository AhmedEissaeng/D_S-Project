#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked(); //minify

    void on_pushButton_2_clicked(); //format

    void on_pushButton_3_clicked(); //convert to json

    void on_actionOpen_triggered(); //open

    void on_pushButton_4_clicked(); //compress(xml)

    void on_pushButton_5_clicked(); //decompress(xml)

    void on_pushButton_6_clicked(); //correct

    void on_pushButton_9_clicked(); //post search

    void on_actionRedo_triggered(); //redo

    void on_actionUndo_triggered(); //undo

    void on_actionSave_triggered(); //save as

    void on_pushButton_13_clicked();//network info

    void on_pushButton_12_clicked();//suggest

    void on_pushButton_10_clicked();//graph

    void on_pushButton_11_clicked();//mutual

    void on_pushButton_7_clicked();//detect

    void on_pushButton_14_clicked();//compress(json)

    void on_pushButton_15_clicked();//decompress(json)

    void on_pushButton_8_clicked();//check consistency

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
