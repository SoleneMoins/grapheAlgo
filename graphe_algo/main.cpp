#include "mainwindow.h"
#include "zone_dessin.h"
#include <iostream>

#include <QApplication>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    a.exec();
    return 0;
}
