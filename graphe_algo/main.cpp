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


 //**************************************************************************************************************************************
  std::vector<std::vector<int>>matD{{0,0,0,0,0,0,0},{0,0,10,3,MAXPOIDS,6,MAXPOIDS},{0,0,0,MAXPOIDS,MAXPOIDS,MAXPOIDS,MAXPOIDS},
                                  {0,MAXPOIDS,4,0,MAXPOIDS,2,MAXPOIDS},{0,MAXPOIDS,MAXPOIDS,1,0,3,MAXPOIDS},{0,MAXPOIDS,0,MAXPOIDS,MAXPOIDS,0,1},
                                  {0,2,1,MAXPOIDS,MAXPOIDS,MAXPOIDS,0}}; // Matrice de distance

  /* std::vector<std::vector<int>>C{{0,0,0,0,0,0,0},{0,0,10,3,MAXPOIDS,6,MAXPOIDS},{0,0,0,MAXPOIDS,MAXPOIDS,MAXPOIDS,MAXPOIDS},{0,MAXPOIDS,4,0,MAXPOIDS,2,MAXPOIDS},{0,MAXPOIDS,MAXPOIDS,1,0,3,MAXPOIDS},{0,MAXPOIDS,0,MAXPOIDS,MAXPOIDS,0,1},{0,2,1,MAXPOIDS,MAXPOIDS,MAXPOIDS,0}};
   std::vector<int>fs{19,2,3,5,0,1,0,2,5,0,3,5,0,2,6,0,1,2,0};
   std::vector<int>aps{6,1,5,7,10,13,16};
   fs_aps g(fs,aps);
   matD=g.Dijkstra(C);
   for(int i=0; i<g.getAps()[0];i++)
       for(int j=0;i<g.getAps()[0];j++)
       cout<<matD[i][j];
   matD=g.Dijkstra(C);*/

  /* std::vector<int>fss{21,2,3,0,4,0,5,8,0,6,2,0,3,7,0,1,8,0,8,0,7,0};
   std::vector<int>apss{8,1,4,6,9,12,15,18,20};
   fs_aps h(fss,apss);


   //Text Dijkstra
  QTextStream(stdout)<<"Dijkstra :\n";
  for(int i=1; i<= aps[0]; i++)
  {    for(int j=1; j<= aps[0]; j++)
        QTextStream(stdout)<<g.Dijkstra(matD)[i][j]<<" ";

      QTextStream(stdout)<<"\n";
  }
//**************************************************************************************************************************

   std::vector<int>fss{31, 2, 3, 0, 4, 9, 0, 4, 6, 8, 0, 8, 9, 11, 0, 3, 6, 0, 7, 8, 0, 8, 0, 10, 0, 0, 11, 0, 10, 12, 0, 0};
   std::vector<int>apss{12, 1, 4, 7, 11, 15, 18, 21, 23, 25, 26, 28, 31};
   fs_aps h(fss,apss);
   std::vector<int>t(9,0);
   t=h.Tarjan();

  /* std::vector<int>t;
   std::vector<int>pred;
   h.calcul_dist(2,t,pred);


   for(int i=0; i<t.size(); i++)
   {
       std::cout<<t[i]<<"|";
   }*/


   //Test Tarjan
   /*QTextStream(stdout)<<"\nTarjan :\n";
   for(int i=0; i<9; i++)
   {
       QTextStream(stdout)<<t[i]<<" ";
   }
   QTextStream(stdout)<<"\n";
   std::vector<int>fss{21,2,3,0,4,0,5,8,0,6,2,0,3,7,0,1,8,0,8,0,7,0};

   QTextStream(stdout)<<"\n";*/

  /* std::vector<int>fss{21,2,3,0,4,0,5,8,0,6,2,0,3,7,0,1,8,0,8,0,7,0};

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

   std::vector<int>fsss{12,4,0,4,0,4,0,5,0,6,0,0};
   std::vector<int>apsss{6,1,3,5,7,9,11};
   fs_aps h(fsss,apsss);
   matrice_Adjacence m(h);
   std::vector<int> d;


m.codage_Pruffer(d);
   for(int i=0;i<m.getMatrice()[0][0];i++){
       cout<<d[i]<<"//";
   }

/*matrice_Adjacence m(g);
   pred=m.codage_Pruffer();
   for(int i=0;i<m.getMatrice()[0][0];i++){
       cout<<pred[i]<<"//";

   }


   //Test rang
   QTextStream(stdout)<<"Rang :\n";

   for(int i=1; i<= apss[0]; i++)
       QTextStream(stdout)<<h.Rang()[i]<<" ";

   QTextStream(stdout)<<"\n";


   //Test Kruskal
    sommet A(0,0,1,"a") ,B(0,0,2,"b") ,C(0,0,3,"c") ,D(0,0,4,"d") ,E(0,0,5,"e") ,F(0,0,6,"f");
   std::vector<sommet> sommets{A ,B ,C ,D ,E ,F};

   arc ab(A,B,6), ac(A,C,1), ad(A,D,5), bc(B,C,5), be(B,E,3), cd(C,D,5), ce(C,E,6), cf(C,F,4), df(D,F,2) ,ef(E,F,6);
   std::vector<arc> ars{ab,ac,ad,bc,be,cd,ce,cf,df,ef};

   GrapheNonOriente gno(sommets,ars);

   GrapheNonOriente gKruskal = gno.kruskal();
   gKruskal.affichage();
*/


   w.show();
   a.exec();
   //return 0;


}
