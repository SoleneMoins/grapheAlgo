#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "matrice_adjacence.h"
#include "fs_aps.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
