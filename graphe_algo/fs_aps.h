#ifndef FSAPS_H
#define FSAPS_H
#include <vector>
#include<iostream>
#include "matrice_adjacence.h"
class fs_aps
{
    public:
        fs_aps(int nbS);
        fs_aps(std::vector<int> fs, std::vector<int> aps,int nbSommet,int nbArc);
        fs_aps(matrice_Adjacence matriceAdj);// fs aps a partir de matrice d'adjacence

        int GetLongAps()const;
        int GetLongFs()const;
        int nbSommets()const;
        int getNbArc() const;

        //void ajouterSommet();
        void fs_aps2fp_app(std::vector<int> &fp,std::vector<int> &app); //Passe de fs aps a fp app
        void chemin_critique(std::vector<std::vector<int>> fp, std::vector<int> app, std::vector<int> &fpc, std::vector<int>&appc, std::vector<int>&lc);
        void ordonnancement(std::vector<int>d, std::vector<int>&lc, std::vector<int>&fpc, std::vector<int>&appc);

    private:

        std::vector<int> d_fs;
        std::vector<int> d_aps;
        int d_nbSommet;
        int d_nbArcs;
};

#endif // GRAPHE_H
