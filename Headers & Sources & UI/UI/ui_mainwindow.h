/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionDelete;
    QAction *actionOpen;
    QAction *actionUndo;
    QAction *actionRedo;
    QWidget *centralwidget;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *textEdit;
    QTextEdit *textEdit_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QTextEdit *textEdit_2;
    QPushButton *pushButton_15;
    QPushButton *pushButton_14;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1166, 705);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName("actionDelete");
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName("actionUndo");
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName("actionRedo");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 0, 1141, 651));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 5, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 0, 8, 1, 1);

        textEdit = new QTextEdit(widget);
        textEdit->setObjectName("textEdit");

        gridLayout->addWidget(textEdit, 1, 0, 1, 4);

        textEdit_3 = new QTextEdit(widget);
        textEdit_3->setObjectName("textEdit_3");

        gridLayout->addWidget(textEdit_3, 1, 8, 1, 2);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 176, 67);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 5px;\n"
"box-shadow: none;"));

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 176, 67);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 5px;\n"
"box-shadow: none;"));

        gridLayout->addWidget(pushButton_2, 2, 1, 1, 1);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 176, 67);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 5px;\n"
"box-shadow: none;"));

        gridLayout->addWidget(pushButton_3, 2, 2, 1, 1);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 176, 67);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 5px;\n"
"box-shadow: none;"));

        gridLayout->addWidget(pushButton_5, 2, 6, 1, 1);

        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 176, 67);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 5px;\n"
"box-shadow: none;"));

        gridLayout->addWidget(pushButton_6, 2, 7, 1, 1);

        pushButton_7 = new QPushButton(widget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 176, 67);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 5px;\n"
"box-shadow: none;"));

        gridLayout->addWidget(pushButton_7, 2, 8, 1, 1);

        pushButton_8 = new QPushButton(widget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 176, 67);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 5px;\n"
"box-shadow: none;"));

        gridLayout->addWidget(pushButton_8, 2, 9, 1, 1);

        pushButton_9 = new QPushButton(widget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 176, 67);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 5px;\n"
"box-shadow: none;"));

        gridLayout->addWidget(pushButton_9, 3, 0, 1, 1);

        pushButton_10 = new QPushButton(widget);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 176, 67);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 5px;\n"
"box-shadow: none;"));

        gridLayout->addWidget(pushButton_10, 3, 1, 1, 1);

        pushButton_11 = new QPushButton(widget);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 176, 67);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 5px;\n"
"box-shadow: none;"));

        gridLayout->addWidget(pushButton_11, 3, 2, 1, 1);

        pushButton_12 = new QPushButton(widget);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 176, 67);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 5px;\n"
"box-shadow: none;"));

        gridLayout->addWidget(pushButton_12, 3, 8, 1, 1);

        pushButton_13 = new QPushButton(widget);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 176, 67);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 5px;\n"
"box-shadow: none;"));

        gridLayout->addWidget(pushButton_13, 3, 9, 1, 1);

        textEdit_2 = new QTextEdit(widget);
        textEdit_2->setObjectName("textEdit_2");

        gridLayout->addWidget(textEdit_2, 1, 4, 1, 4);

        pushButton_15 = new QPushButton(widget);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 176, 67);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 5px;\n"
"box-shadow: none;"));

        gridLayout->addWidget(pushButton_15, 3, 6, 1, 2);

        pushButton_14 = new QPushButton(widget);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 176, 67);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 5px;\n"
"box-shadow: none;"));

        gridLayout->addWidget(pushButton_14, 3, 3, 1, 3);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 176, 67);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 5px;\n"
"box-shadow: none;"));

        gridLayout->addWidget(pushButton_4, 2, 3, 1, 3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1166, 26));
        menubar->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 176, 67); color: rgb(255, 255, 255);"));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuFile->setStyleSheet(QString::fromUtf8(""));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        menuEdit->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionDelete);
        menuFile->addAction(actionOpen);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionDelete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionUndo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        actionRedo->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Input", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Output", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Errors", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Minify", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Format", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "-> JSON", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Decompress XML", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Correct", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Detect", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Check", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Graph", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Mutual", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "Suggest", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "Net Info", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "Decompress JSON", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "Compress JSON", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Compress XML", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
