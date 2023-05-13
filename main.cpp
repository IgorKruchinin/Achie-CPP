#include "mainwindow.h"

#include <QApplication>
#include "USM/USM.h"
#include "firststart.h"
#include <vector>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::vector<USM> profiles = USM::get_profiles();
    auto *prof = &profiles[0];
    prof->create_isec("count");
    prof->create_isec("date");
    prof->create_ssec("measure");
    prof->create_ssec("object");
    prof->create_ssec("type");
    prof->create_ssec("photo");
    prof->to_file();
    MainWindow w(nullptr, prof);
    w.show();
    return a.exec();
}
