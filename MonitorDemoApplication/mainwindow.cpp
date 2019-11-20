#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QMessageBox"
#include "triangle.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("3d monitor");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_open_triggered()
{
    QString model_name = QFileDialog::getOpenFileName(this, "", "", "STL (*.stl)");
    if(model_name != "")
    {
        QFile model(model_name);
        if(!model.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this, tr("error"), tr("could not open file"));
            return;
        }
        else
        {
            triangle Triangle;
            QTextStream in(&model);
//            double x;
//            in >> x;
        }
    }
}
