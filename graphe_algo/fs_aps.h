#ifndef FSAPS_H
#define FSAPS_H
#include <vector>
#include<iostream>
#include "matrice_adjacence.h"
#include<stack>

#include"sommet.h"
#include "arc.h"

const int MAXPOIDS=10000;

class fs_aps {
    public:
        //Constructeurs 
        fs_aps();
        fs_aps(int nbS);

        fs_aps(std::vector<sommet>&d_sommet,std::vector<arc>&d_arc);
        fs_aps(std::vector<int>&fs, std::vector<int>&aps,int nbSommet,int nbArc);
        fs_aps(std::vector<int> &fs, std::vector<int> &aps);
        
        //fs_aps(matrice_Adjacence matriceAdj);
        //void ajouterSommet();
        
        std::vector<int> getFs();
        std::vector<int> getAps();
        int GetLongAps()const;
        int GetLongFs()const;
        int nbSommets()const;
        int getNbArc() const;

        //void determiner_rang(int *&rang, int *&num) const ;
       // std::vector<int> det_rang() const;
        std::vector<int> Rang();
        std::vector<int>  distance();
  
        void determiner_rang(int *&rang, int *&num) const ;
        void calcul_dist(int s,std::vector<int>&d,std::vector<int>& pred );

        std::vector<int> Tarjan()const;
        std::vector<std::vector<int>> Dijkstra(const std::vector<std::vector<int>>&C)const;

       
        void fs_aps2fp_app(std::vector<int> &fp,std::vector<int> &app); //Passage de fs aps à fp app
        void chemin_critique(std::vector<std::vector<int>> fp, std::vector<int> app, std::vector<int> &fpc, std::vector<int>&appc, std::vector<int>&lc);
        void ordonnancement(std::vector<int>d, std::vector<int>&lc, std::vector<int>&fpc, std::vector<int>&appc);
    
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

        std::vector<int> neoDijkstra(const std::vector<std::vector<int>>&C,std::vector<int> &d, std::vector<int> &pred,std::vector<bool> &S, int s)const;
        void empiler (int x, std::vector<int> &pilch);
};

#endif // GRAPHE_H
