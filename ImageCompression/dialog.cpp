#include "dialog.h"
#include "ui_dialog.h"
#include <QFileDialog>
#include <QBuffer>
#include <QImage>
#include <QThread>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->compressImageButton->setEnabled(false);

    connect(ui->browseImageButton, &QPushButton::clicked, this, [&]()
            {
                imagePath = QFileDialog::getOpenFileName(this, tr("Browse Image to Compare"), QDir::homePath(), "Images (*.png, *.jpg");
                ui->labelImage->setPixmap(QPixmap(imagePath).scaled(ui->labelImage->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
                ui->compressImageButton->setEnabled(true);
            }
            );

    connect(ui->compressImageButton, &QPushButton::clicked, this, &compressImage);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::compressImage()
{
    showProgressBar();

    QString newPath = QFileDialog::getSaveFileName(this, "Save Compressed Image", QDir::homePath(), "Images (*.jpg, *.png)");
    QString format;

    if( newPath.endsWith(".jpg"), Qt::CaseInsensitive || newPath.endsWith(".jpeg", Qt::CaseInsensitive))
        format = "JPEG";
    else if( newPath.endsWith(".png"), Qt::CaseInsensitive)
        format = "PNG";
    else
    {
        format = "JPEG";
        newPath += ".jpg";
    }

    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);

    QImage compressImage(imagePath);
    compressImage.save(newPath, format.toStdString().c_str(), 50);

}

void Dialog::showProgressBar()
{
    for(int i=10; i<=100; i+=10)
    {
        ui->progressBar->setValue(i);
        QThread::msleep(1000);
    }
}
