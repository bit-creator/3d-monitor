#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"

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
    QFileDialog::getOpenFileName(this, "", "", "STL (*.stl)");
}
