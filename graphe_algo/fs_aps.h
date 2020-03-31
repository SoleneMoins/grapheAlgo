#ifndef FSAPS_H
#define FSAPS_H
#include <vector>
#include<iostream>
#include "matrice_adjacence.h"
class fs_aps
{
    public:
        fs_aps();
        fs_aps(int nbS);
        fs_aps(std::vector<int> fs, std::vector<int> aps,int nbSommet,int nbArc);
        //fs_aps(matrice_Adjacence matrice);

        int GetLongAps()const;
        int GetLongFs()const;
        std::vector<int> fs() const;
        std::vector<int> aps()const;
        int nbSommets()const;
        int getNbArc() const;
        std::vector<int>  distance();

        //void ajouterSommet();

    private:

        std::vector<int> d_fs;
        std::vector<int> d_aps;
        int d_nbSommet;
        int d_nbArcs;
};

#endif // GRAPHE_H
