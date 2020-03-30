#ifndef MATRICE_ADJACENCE_H
#define MATRICE_ADJACENCE_H
#include "fs_aps.h"
#include <vector>
#include <iostream>

class matrice_Adjacence
{
    public:
        matrice_Adjacence();
        matrice_Adjacence(int *fs,int*aps); //constuire la matrice à partir de fs et aps
        //voici des surcharge d'operateur a faire:
        //numero1 operator[][]
        //numero2 operator==
        void matriceDistance(int *fa, std::vector<int> aps, int **&mat);

    private:
        std::vector<std::vector<int>> d_matrice; //vecteur de vecteur
        fs_aps d_fsAps;
        int d_nbSommet;
        int d_nbArcs;
};

#endif // MATRICE_ADJACENCE_H
