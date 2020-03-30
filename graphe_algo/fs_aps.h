#ifndef FSAPS_H
#define FSAPS_H
#include <vector>
#include<iostream>
#include "matrice_adjacence.h"
#include "sommet.h"
#include "arc.h"

class fs_aps
{
    public:

        fs_aps();
        fs_aps(int nbS);
        fs_aps(std::vector<sommet>&d_sommet,std::vector<arc>&d_arc);
        fs_aps(std::vector<int>&fs, std::vector<int>&aps,int nbSommet,int nbArc);
        fs_aps(matrice_Adjacence matriceAdj);

        std::vector<int> getFs();
        std::vector<int> getAps();
        int GetLongAps()const;
        int GetLongFs()const;
        int nbSommets()const;
        int getNbArc() const;

        //void ajouterSommet();

    private:

        std::vector<int> d_fs;
        std::vector<int> d_aps;
        int d_nbSommet;
        int d_nbArcs;
};

#endif // GRAPHE_H
