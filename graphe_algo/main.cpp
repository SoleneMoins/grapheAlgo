#include "mainwindow.h"
#include "zone_dessin.h"

#include <QApplication>
#include <iostream>
#include "fs_aps.h"
#include<stack>
#include <QDebug>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    std::vector<int>fs{18,2,3,5,0,1,0,2,5,0,3,5,0,2,6,0,1,2,0};
    std::vector<int>aps{6,1,5,7,10,13,16};

    std::vector<int> d;//pour la fonction de dijkstra
    std::vector<int> pred;//pour la fonction de dijkstra
    std::vector<bool> S;//pour la fonction de dijkstra

    std::vector<std::vector<int>> dist{{0,0,0,0,0,0,0},{0,0,10,3,MAXPOIDS,6,MAXPOIDS},{0,0,0,MAXPOIDS,MAXPOIDS,MAXPOIDS,MAXPOIDS},
                                       {0,MAXPOIDS,4,0,MAXPOIDS,2,MAXPOIDS},{0,MAXPOIDS,MAXPOIDS,1,0,3,MAXPOIDS},{0,MAXPOIDS,0,MAXPOIDS,MAXPOIDS,0,1},
                                       {0,2,1,MAXPOIDS,MAXPOIDS,MAXPOIDS,0}};//Matricede distance pour la fonction de dijkstra
    fs_aps g(fs,aps);

    QTextStream(stdout)<<"Tarjan :\n";
    g.Tarjan();

    QTextStream(stdout)<<"\nDijkstra :\n";
    g.Dijkstra(dist,d,pred,S);

    w.show();
    return a.exec();
}
