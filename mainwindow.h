#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "adddialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    USM *prof;

public:
    MainWindow(QWidget *parent = nullptr, USM *prof = nullptr);
    void OpenAddDialog();
    ~MainWindow();

private slots:
    void on_addAchie_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
