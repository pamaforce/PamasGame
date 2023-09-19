/********************************************************************************
** Form generated from reading UI file 'namedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAMEDIALOG_H
#define UI_NAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_NameDialog
{
public:
    QLabel *label;
    QLabel *label0;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *NameDialog)
    {
        if (NameDialog->objectName().isEmpty())
            NameDialog->setObjectName(QStringLiteral("NameDialog"));
        NameDialog->resize(400, 180);
        label = new QLabel(NameDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 400, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(18);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(255, 0, 127);"));
        label0 = new QLabel(NameDialog);
        label0->setObjectName(QStringLiteral("label0"));
        label0->setGeometry(QRect(0, 0, 400, 300));
        label0->setFrameShape(QFrame::NoFrame);
        lineEdit = new QLineEdit(NameDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 90, 261, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font1.setPointSize(12);
        lineEdit->setFont(font1);
        lineEdit->setContextMenuPolicy(Qt::CustomContextMenu);
        lineEdit->setFrame(false);
        lineEdit->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(NameDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 90, 71, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\347\220\245\347\217\200"));
        font2.setPointSize(12);
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QStringLiteral("color: rgb(85, 0, 127);"));
        label0->raise();
        label->raise();
        lineEdit->raise();
        pushButton->raise();

        retranslateUi(NameDialog);

        QMetaObject::connectSlotsByName(NameDialog);
    } // setupUi

    void retranslateUi(QDialog *NameDialog)
    {
        NameDialog->setWindowTitle(QApplication::translate("NameDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("NameDialog", "\347\273\231\350\207\252\345\267\261\345\217\226\344\270\200\344\270\252\346\230\265\347\247\260\345\220\247\340\270\205\312\225\342\200\242\315\241\314\253\342\200\242\312\224\340\270\205\357\274\201", Q_NULLPTR));
        label0->setText(QString());
        lineEdit->setText(QString());
        pushButton->setText(QApplication::translate("NameDialog", "\347\241\256\345\256\232\345\225\246", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NameDialog: public Ui_NameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAMEDIALOG_H
