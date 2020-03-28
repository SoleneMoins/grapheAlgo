#include "mainwindow.h"
#include "zone_dessin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
    MainWindow w;
    w.show();
    a.exec();

}
