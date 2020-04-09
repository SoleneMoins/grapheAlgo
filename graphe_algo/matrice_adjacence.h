#ifndef MATRICE_ADJACENCE_H
#define MATRICE_ADJACENCE_H
#include "fs_aps.h"
#include <vector>
#include <iostream>
class fs_aps;
class matrice_Adjacence {
    public:
        matrice_Adjacence();
        matrice_Adjacence(fs_aps & graphFsAps); //constuire la matrice à partir de fs et aps
        std::vector<std::vector<int>> getMatrice();
        //voici des surcharge d'operateur a faire:
        //numero1 operator[][]
        //numero2 operator==
        void codage_Pruffer(std::vector<int> & prufer);
        std::vector<std::vector<int>> calcul_mat_dist(fs_aps &fsAps) ;



    private:
        std::vector<std::vector<int>> d_matrice; //vecteur de vecteur
        int d_nbSommet;
        int d_nbArcs;
};

#endif // MATRICE_ADJACENCE_H
