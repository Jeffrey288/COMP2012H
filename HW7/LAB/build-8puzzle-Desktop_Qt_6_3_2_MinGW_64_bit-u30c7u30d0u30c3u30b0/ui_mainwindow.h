/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "numcell.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    NumCell *pushButton_7;
    NumCell *pushButton_1;
    NumCell *pushButton_3;
    NumCell *pushButton_2;
    NumCell *pushButton_5;
    NumCell *pushButton_6;
    NumCell *pushButton_9;
    NumCell *pushButton_4;
    NumCell *pushButton_8;
    QPushButton *generate;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(255, 327);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_7 = new NumCell(centralWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Adobe Devanagari")});
        font.setPointSize(36);
        pushButton_7->setFont(font);

        gridLayout->addWidget(pushButton_7, 2, 0, 1, 1);

        pushButton_1 = new NumCell(centralWidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        sizePolicy.setHeightForWidth(pushButton_1->sizePolicy().hasHeightForWidth());
        pushButton_1->setSizePolicy(sizePolicy);
        pushButton_1->setFont(font);

        gridLayout->addWidget(pushButton_1, 0, 0, 1, 1);

        pushButton_3 = new NumCell(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setFont(font);

        gridLayout->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_2 = new NumCell(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setFont(font);

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_5 = new NumCell(centralWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        pushButton_5->setFont(font);

        gridLayout->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton_6 = new NumCell(centralWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
        pushButton_6->setFont(font);

        gridLayout->addWidget(pushButton_6, 1, 2, 1, 1);

        pushButton_9 = new NumCell(centralWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);
        pushButton_9->setFont(font);

        gridLayout->addWidget(pushButton_9, 2, 2, 1, 1);

        pushButton_4 = new NumCell(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setFont(font);

        gridLayout->addWidget(pushButton_4, 1, 0, 1, 1);

        pushButton_8 = new NumCell(centralWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);
        pushButton_8->setFont(font);

        gridLayout->addWidget(pushButton_8, 2, 1, 1, 1);

        generate = new QPushButton(centralWidget);
        generate->setObjectName(QString::fromUtf8("generate"));

        gridLayout->addWidget(generate, 3, 0, 1, 3);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        generate->setText(QCoreApplication::translate("MainWindow", "Generate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
