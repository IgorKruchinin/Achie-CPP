#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "firststart.h"
#include <QDate>

MainWindow::MainWindow(QWidget *parent, USM *prof)
    : QMainWindow(parent),
      prof(prof),
      ui(new Ui::MainWindow)
{
    if (prof != NULL) {
        ui->setupUi(this);
        std::vector<long> dates = prof->geti("date").get_objects();
        std::vector<std::string> objects = prof->gets("object").get_objects();
        for (int i = 0; i < dates.size(); ++i) {
            QDateTime *date = new QDateTime();
            date->setMSecsSinceEpoch(dates[i]);
            ui->achiesList->addItem(date->date().toString(Qt::DateFormat::ISODate) + "    " + QString(objects[i].c_str()));
            delete date;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OpenAddDialog() {
    AddDialog *addDialog = new AddDialog(nullptr, prof, ui->achiesList);
    addDialog->show();
}


void MainWindow::on_addAchie_clicked()
{
    OpenAddDialog();
}

