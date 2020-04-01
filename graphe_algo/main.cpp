#include "mainwindow.h"
#include "zone_dessin.h"

#include <QApplication>
#include <iostream>
#include "fs_aps.h"
#include<stack>
#include <QDebug>
#include "graphenonoriente.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    sommet A(0,0,1);
    sommet B(0,0,2);
    sommet C(0,0,3);
    sommet D(0,0,4);
    sommet E(0,0,5);
    sommet F(0,0,6);


    arc ab(A,B,6);
    arc ac(A,C,1);
    arc ad(A,D,5);
    arc bc(B,C,5);
    arc be(B,E,3);
    arc cf(C,F,4);
    arc cd(C,D,5);
    arc ce(C,E,6);
    arc df(D,F,2);
    arc ef(E,F,6);
    std::vector<arc>arett{ab,ac,ad,bc,be,cf,cd,ce,df,ef};



    GrapheNonOriente gn(6,10,arett);
    GrapheNonOriente t;

    QTextStream(stdout)<<"\nKruskal :\n";
    gn.trier();
    gn.kruskal(t);
    t.affichage();

    w.show();
    return a.exec();
}
