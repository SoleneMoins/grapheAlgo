#ifndef FSAPS_H
#define FSAPS_H
#include <vector>
#include<iostream>
#include "matrice_adjacence.h"
#include<stack>

#include"sommet.h"
#include "arc.h"

const int MAXPOIDS=10000;

class fs_aps
{
    public:
        //Constructeurs 
        fs_aps();
        fs_aps(int nbS);
        fs_aps(std::vector<sommet>&d_sommet,std::vector<arc>&d_arc);
        fs_aps(std::vector<int>&fs, std::vector<int>&aps,int nbSommet,int nbArc);
        fs_aps(matrice_Adjacence matriceAdj);
        fs_aps(std::vector<int> &fs, std::vector<int> &aps);
        
        //fs_aps(matrice_Adjacence matriceAdj);
        //void ajouterSommet();
        
        std::vector<int> getFs();
        std::vector<int> getAps();
        int GetLongAps()const;
        int GetLongFs()const;
        std::vector<int> fs() const;
        std::vector<int> aps()const;
        int nbSommets()const;
        int getNbArc() const;
        int getAps(int i) const;
        int getFs(int i) const;

        void determiner_rang(int *&rang, int *&num) const ;
        std::vector<int>  distance();
  
        void Tarjan()const;
        void Dijkstra(const std::vector<std::vector<int>>&C,std::vector<int> &d, std::vector<int> &pred,std::vector<bool> &S)const;

       

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
