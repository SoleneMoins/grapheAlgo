#ifndef GRAPHE_H
#define GRAPHE_H

#include "sommet.h"
#include "arc.h"
#include "fs_aps.h"
#include <QLine>
#include <QrectF>
#include <vector>


class graphe
{
public:
    graphe();
    graphe(std::vector<sommet> sommet, std::vector<arc> arcs);
    graphe(std::vector<int>fs,int nbsommet);
    std::vector<sommet> getSommet()const;
    std::vector<arc> getArc()const;
    std::vector<QLineF> getLine()const;
    std::vector<QRectF> getRectangle()const;
    void construitFs(std::vector<sommet>d_sommet,std::vector<arc>d_arc);
    void construitVectorLine(std::vector<arc>&arcs);
    void construitVectorRectangle(std::vector<sommet>&s);


    void save(std::ostream&ost);

    void open(std::istream&ist);

private:
    std::vector<sommet> d_sommet;
    std::vector<arc> d_arc;
    std::vector<QLineF> d_line;
    std::vector<QRectF> d_rectangle;
    //fs_aps d_fsaps;

};

#endif // GRAPHE_H
