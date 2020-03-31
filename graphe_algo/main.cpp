#include "mainwindow.h"
#include "zone_dessin.h"
#include <iostream>
#include <QApplication>
#include <iostream>
#include "fs_aps.h"
#include<stack>
#include <QDebug>


using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
