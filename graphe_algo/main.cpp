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
   std::vector<std::vector<int>>C{{0,0,0,0,0,0,0},{0,0,10,3,MAXPOIDS,6,MAXPOIDS},{0,0,0,MAXPOIDS,MAXPOIDS,MAXPOIDS,MAXPOIDS},{0,MAXPOIDS,4,0,MAXPOIDS,2,MAXPOIDS},{0,MAXPOIDS,MAXPOIDS,1,0,3,MAXPOIDS},{0,MAXPOIDS,0,MAXPOIDS,MAXPOIDS,0,1},{0,2,1,MAXPOIDS,MAXPOIDS,MAXPOIDS,0}};
   std::vector<int>fs{19,2,3,5,0,1,0,2,5,0,3,5,0,2,6,0,1,2,0};
   std::vector<int>aps{6,1,5,7,10,13,16};
   std::vector<std::vector<int>> matD(7,std::vector<int>(7,0));
   fs_aps g(fs,aps);
   matD=g.Dijkstra(C);

   std::vector<int>fss{21,2,3,0,4,0,5,8,0,6,2,0,3,7,0,1,8,0,8,0,7,0};
   std::vector<int>apss{8,1,4,6,9,12,15,18,20};
   fs_aps h(fss,apss);
   std::vector<int>t(9,0);
   t=h.Tarjan();


   for(int i=0; i<9; i++)
   {
       QTextStream(stdout)<<"CFC :"<<t[i]<<" ";
   }
   QTextStream(stdout)<<"\n";

   w.show();
   a.exec();
}
