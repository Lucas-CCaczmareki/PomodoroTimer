/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *labelStatus;
    QLabel *labelTempo;
    QPushButton *btnPausar;
    QPushButton *btnReset;
    QPushButton *btnIniciar;
    QMenuBar *menubar;
    QMenu *menuPomodoro;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1269, 678);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(410, 240, 166, 280));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelStatus = new QLabel(widget);
        labelStatus->setObjectName("labelStatus");
        QFont font;
        font.setPointSize(48);
        labelStatus->setFont(font);

        verticalLayout->addWidget(labelStatus);

        labelTempo = new QLabel(widget);
        labelTempo->setObjectName("labelTempo");
        labelTempo->setFont(font);

        verticalLayout->addWidget(labelTempo);

        btnPausar = new QPushButton(widget);
        btnPausar->setObjectName("btnPausar");

        verticalLayout->addWidget(btnPausar);

        btnReset = new QPushButton(widget);
        btnReset->setObjectName("btnReset");

        verticalLayout->addWidget(btnReset);

        btnIniciar = new QPushButton(widget);
        btnIniciar->setObjectName("btnIniciar");

        verticalLayout->addWidget(btnIniciar);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1269, 23));
        menuPomodoro = new QMenu(menubar);
        menuPomodoro->setObjectName("menuPomodoro");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuPomodoro->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelStatus->setText(QCoreApplication::translate("MainWindow", "Foco", nullptr));
        labelTempo->setText(QCoreApplication::translate("MainWindow", "25:00", nullptr));
        btnPausar->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        btnReset->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        btnIniciar->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        menuPomodoro->setTitle(QCoreApplication::translate("MainWindow", "Pomodoro", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
