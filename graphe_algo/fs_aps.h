#ifndef FSAPS_H
#define FSAPS_H
#include <vector>
#include<iostream>
#include"sommet.h"
#include "matrice_adjacence.h"
#include<stack>

const int MAXPOIDS=10000;

class fs_aps
{
    public:
        //fs_aps(int nbS);
        fs_aps(std::vector<int> &fs, std::vector<int> &aps);
        fs_aps(matrice_Adjacence matriceAdj);
        void ajouterSommet();

        int GetLongAps()const;
        int GetLongFs()const;
        int nbSommets()const;
        int getNbArc() const;
        int getAps(int i) const;
        int getFs(int i) const;

        void Tarjan()const;
        void Dijkstra(const std::vector<std::vector<int>>&C,std::vector<int> &d, std::vector<int> &pred,std::vector<bool> &S)const;


        //void ajouterSommet();

    private:

        std::vector<int> d_fs;
        std::vector<int> d_aps;
        int d_nbSommet;
        int d_nbArcs;

        void traverse(int s, std::vector<int>& num,
                        std::vector<int> &mu,
                        std::vector<int> &prem,
                        std::vector<int> &pilch,
                        std::vector<int> &cfc,
                        std::stack<int> &tarj,
                        std::vector<bool> &entarj,
                        int &p, int &nbr) const;

        void neoDijkstra(const std::vector<std::vector<int>>&C,std::vector<int> &d, std::vector<int> &pred,std::vector<bool> &S, int s)const;
};

#endif // GRAPHE_H
