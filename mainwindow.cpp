#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_textEdit_textChanged(const QString &arg1) {
    if (ui->twoRadio->isChecked()) {
        ui->resultLabel->setText(QString::number(ui->textEdit->text().toInt(), 2));
    } else if (ui->eightRadio->isChecked()) {
        ui->resultLabel->setText(QString::number(ui->textEdit->text().toInt(), 8));
    } else if (ui->sixtRadio->isChecked()) {
        ui->resultLabel->setText(QString::number(ui->textEdit->text().toInt(), 16));
    }

    QFont *font = new QFont(ui->resultLabel->font());
    if (ui->boldBox->isChecked()) {
        font->setBold(true);
    } else {
        font->setBold(false);
    }

    if (ui->italicBox->isChecked()) {
        font->setItalic(true);
    } else {
        font->setItalic(false);
    }
    font->setPointSize(ui->sizeSlider->value());

    ui->resultLabel->setFont(*font);
}
