#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>

#include "USM/USM.h"
#include <QListWidget>

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT
    USM *prof;
    QListWidget *list;

public:
    explicit AddDialog(QWidget *parent = nullptr, USM *prof = nullptr, QListWidget *list = nullptr);
    ~AddDialog();

private slots:
    void on_OKBtn_clicked();

private:
    Ui::AddDialog *ui;
};

#endif // ADDDIALOG_H
