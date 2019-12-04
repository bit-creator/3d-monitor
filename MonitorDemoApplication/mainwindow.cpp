#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QMessageBox"
#include "documentmanager.h"

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
    if(!model_name.isEmpty())
    {
        if(!DocumentManager::GetInstance().OpenDocument(model_name, Document::DocumentType::STL))
        {
            QMessageBox::critical(this, tr("error"), tr("could not open file"));
        }
    }
}

void MainWindow::on_action_save_as_triggered()
{
    QString model_name = QFileDialog::getSaveFileName(this, tr("Save File"), "",
        tr("STL (*.stl);;"));

    if(!model_name.isEmpty())
    {
        QFile model(model_name);
        if(!model.open(QIODevice::WriteOnly))
        {
            QMessageBox::critical(this, tr("error"), tr("could not open file"));
        }
        else
        {
            DocumentManager::GetInstance().SaveDocumentAs(DocumentManager::GetInstance().GetActiveDocument(), model_name);
        }
    }
}
