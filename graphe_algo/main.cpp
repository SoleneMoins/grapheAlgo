#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include <iostream>
#include<stack>
#include <QDebug>
#include "graphenonoriente.h"


using namespace std;

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   MainWindow w;
   w.show();
   a.exec();
}
