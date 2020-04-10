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

 //**************************************************************************************************************************************
 //Text Dijkstra

  /*std::vector<std::vector<int>>matD{{0,0,0,0,0,0,0},{0,0,10,3,MAXPOIDS,6,MAXPOIDS},{0,0,0,MAXPOIDS,MAXPOIDS,MAXPOIDS,MAXPOIDS},
                                  {0,MAXPOIDS,4,0,MAXPOIDS,2,MAXPOIDS},{0,MAXPOIDS,MAXPOIDS,1,0,3,MAXPOIDS},{0,MAXPOIDS,0,MAXPOIDS,MAXPOIDS,0,1},
                                  {0,2,1,MAXPOIDS,MAXPOIDS,MAXPOIDS,0}}; // Matrice de distance

   std::vector<int>fs{18,2,3,5,0,1,0,2,5,0,3,5,0,2,6,0,1,2,0};
   std::vector<int>aps{6,1,5,7,10,13,16};
   fs_aps g(fs,aps);
   
   

  QTextStream(stdout)<<"Dijkstra :\n";
  for(int i=1; i<= aps[0]; i++)
  {    for(int j=1; j<= aps[0]; j++)
        QTextStream(stdout)<<g.Dijkstra(matD)[i][j]<<" ";

      QTextStream(stdout)<<"\n";
  }*/


w.show();
   a.exec();
   //return 0;


}
