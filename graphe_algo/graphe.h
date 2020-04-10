#ifndef GRAPHE_H
#define GRAPHE_H


#include <QLine>
#include <QRectF>
#include <vector>
#include "fs_aps.h"



class graphe {
public:
    graphe();
    graphe(std::vector<sommet>&sommet, std::vector<arc>&arcs);
    graphe(std::vector<int>&fs,int nbsommet);
    graphe(fs_aps fsaps);


    fs_aps getfsAps();

    std::vector<sommet> getSommet();
    std::vector<arc> getArc();
    std::vector<QLineF> getLine();
    std::vector<QRectF> getRectangle();
    std::vector<int> getCFC();

    sommet getS(int i);
    arc getA(int i);
    QRectF getR(int i);
    QLineF getL(int i);


    void ajouterSommet(sommet&s);
    void ajouterArc(arc&a);
    void ajouterLigne(QLineF&l);
    void ajouterRectangle(QRectF&r);

    void effacerSommet(int i);
    void effacerArc(int i);

    void construitVectorLine(std::vector<arc>&arcs);
    void construitVectorRectangle(std::vector<sommet>&s);

    bool estValide();
    void clean();
    void save(std::ostream&ost);
    void open(std::istream&ist);
    void calcul_dist(int s, std::vector<int>& dist);


private:
    std::vector<sommet> d_sommet;
    std::vector<arc> d_arc;
    std::vector<QLineF> d_line;
    std::vector<QRectF> d_rectangle;
    fs_aps d_fsaps;

};

#endif // GRAPHE_H
