#include "adddialog.h"
#include "ui_adddialog.h"

AddDialog::AddDialog(QWidget *parent, USM *prof, QListWidget *list) :
    QDialog(parent),
    prof(prof),
    list(list),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
    ui->dateFld->setDate(QDate::QDate::currentDate());
}

AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::on_OKBtn_clicked()
{
    auto dateTime = ui->dateFld->dateTime();
    long time = dateTime.toMSecsSinceEpoch();
    std::string object = ui->objectFld->text().toStdString();
    std::string type = ui->typeFld->text().toStdString();
    std::string measure = ui->measureFld->text().toStdString();
    long count = ui->countFld->value();
    prof->geti("date").add(time);
    prof->gets("object").add(object);
    prof->gets("type").add(type);
    prof->gets("measure").add(measure);
    prof->geti("count").add(count);
    prof->gets("photo").add("");
    prof->to_file();
    list->addItem(dateTime.date().toString(Qt::DateFormat::ISODate) + "    " + QString(object.c_str()));
    this->close();
}

