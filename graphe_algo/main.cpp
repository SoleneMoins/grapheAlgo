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
   /*std::vector<std::vector<int>>C{{0,0,0,0,0,0,0},{0,0,10,3,MAXPOIDS,6,MAXPOIDS},{0,0,0,MAXPOIDS,MAXPOIDS,MAXPOIDS,MAXPOIDS},{0,MAXPOIDS,4,0,MAXPOIDS,2,MAXPOIDS},{0,MAXPOIDS,MAXPOIDS,1,0,3,MAXPOIDS},{0,MAXPOIDS,0,MAXPOIDS,MAXPOIDS,0,1},{0,2,1,MAXPOIDS,MAXPOIDS,MAXPOIDS,0}};
   std::vector<int>fs{19,2,3,5,0,1,0,2,5,0,3,5,0,2,6,0,1,2,0};
   std::vector<int>aps{6,1,5,7,10,13,16};
   std::vector<std::vector<int>> matD(7,std::vector<int>(7,0));
   fs_aps g(fs,aps);
   matD=g.Dijkstra(C);
   for(int i=0; i<g.getAps()[0];i++)
       for(int j=0;i<g.getAps()[0];j++)
       cout<<matD[i][j];

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
   std::vector<int>fss{21,2,3,0,4,0,5,8,0,6,2,0,3,7,0,1,8,0,8,0,7,0};
   std::vector<int>apss{8,1,4,6,9,12,15,18,20};
   std::vector<int>fsss{12,4,0,4,4,0,4,0,4,0,5,0,6,0,0};
   std::vector<int>apsss{6,1,3,5,7,9,11};


   fs_aps g(fss,apss);
   std::vector<int> dist;
   std::vector<int> pred;

   g.calcul_dist(2,dist,pred);

   for(int i=0;i<dist.size();i++)
       std::cout<<dist[i]<<"!";
   std::cout<<endl;

   for(int i=0;i<pred.size();i++)
       std::cout<<pred[i]<<"!";
*/
   std::vector<int>fsss{12,4,0,4,0,4,0,5,0,6,0,0};
   std::vector<int>apsss{6,1,3,5,7,9,11};
   fs_aps h(fsss,apsss);
   matrice_Adjacence m(h);
   std::vector<int> d;

   m.codage_Pruffer(d);
   for(int i=0;i<m.getMatrice()[0][0];i++){
       cout<<d[i]<<"//";
   }




   w.show();
   a.exec();
   return 0;
}
