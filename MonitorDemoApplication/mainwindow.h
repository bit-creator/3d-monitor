#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QTextStream"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void set_model(QTextStream& in);

private slots:
    void on_action_open_triggered();

    void on_action_save_as_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
