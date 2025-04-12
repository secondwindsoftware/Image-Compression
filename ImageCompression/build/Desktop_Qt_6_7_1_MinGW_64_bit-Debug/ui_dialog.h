/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *browseImageButton;
    QLabel *labelImage;
    QPushButton *compressImageButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QProgressBar *progressBar;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(800, 600);
        browseImageButton = new QPushButton(Dialog);
        browseImageButton->setObjectName("browseImageButton");
        browseImageButton->setGeometry(QRect(12, 12, 80, 29));
        browseImageButton->setMaximumSize(QSize(300, 30));
        labelImage = new QLabel(Dialog);
        labelImage->setObjectName("labelImage");
        labelImage->setGeometry(QRect(12, 48, 781, 481));
        compressImageButton = new QPushButton(Dialog);
        compressImageButton->setObjectName("compressImageButton");
        compressImageButton->setGeometry(QRect(710, 10, 80, 29));
        compressImageButton->setMaximumSize(QSize(300, 30));
        widget = new QWidget(Dialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 540, 781, 31));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        progressBar = new QProgressBar(widget);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(0);

        horizontalLayout->addWidget(progressBar);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        browseImageButton->setText(QCoreApplication::translate("Dialog", "Browse", nullptr));
        labelImage->setText(QCoreApplication::translate("Dialog", "TextLabel", nullptr));
        compressImageButton->setText(QCoreApplication::translate("Dialog", "Compress", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
