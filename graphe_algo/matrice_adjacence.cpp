#include "matrice_adjacence.h"

matrice_Adjacence::matrice_Adjacence():d_matrice{0}
{}

matrice_Adjacence::matrice_Adjacence(fs_aps &graphFsAps) {
    d_nbSommet=graphFsAps.getAps()[0];
    d_nbArcs=graphFsAps.getFs()[0]- d_nbSommet;
    d_matrice.clear();
    d_matrice.resize(d_nbSommet+1);
     for (int i = 0; i < d_nbSommet+1; i++) {
        d_matrice[i].resize(d_nbSommet+1);
        for(int j=1; j<=d_nbSommet;j++) {
            d_matrice[i][j]=0;
        }
    }
    d_matrice[0][0]=d_nbSommet;
    d_matrice[0][1]=d_nbArcs;
    for(int i=1; i<=d_nbSommet;i++) {
        int j;
        for(int k=graphFsAps.getAps()[i];(j=graphFsAps.getFs()[k])!=0;k++){
            d_matrice[i][j]=1;

        }
    }
}
std::vector<std::vector<int>> matrice_Adjacence::getMatrice()
{
    return d_matrice;
}

void matrice_Adjacence::codage_Pruffer(std::vector<int>&P){

    int m =d_matrice[0][0];
    P.clear();
    P.resize(m+1);
    for(int i=1; i<=m; i++){

        for(int j=1; j<=m ; j++){;

            if(d_matrice[i][j]==1){

                d_matrice[i][0]++;
            }
        }
    }
    P[0] = m-2;
    int i=1;

    for(int k=1 ; k<=m-2 ; k++){
        for(int i=1 ; i<=m ; i++){

            if(d_matrice[i][0] == 1){

                d_matrice[i][0] = 0;
            }
        }
        for(int j=1 ; j<=m ; j++){

            if( d_matrice[i][j] ==1){

                P[k] = j;
                 d_matrice[i][j] = 0;
                 d_matrice[j][i] = 0;
                 d_matrice[j][0]--;
            }
        }
        i++;
    }
}

std::vector<std::vector<int>> matrice_Adjacence::calcul_mat_dist(fs_aps &fsAps)
{
    std::vector<std::vector<int>>mat_dist;
    std::vector<int> d;
    std::vector<int> p;
    mat_dist.resize(d_nbSommet+1);

    for(int i=0; i<d_nbSommet+1; i++)
    {
        mat_dist[i].resize(d_nbSommet+1);
    }

    mat_dist[0][0]=d_nbSommet;

    for(int i=1;i<=d_nbSommet;i++)
    {
        fsAps.calcul_dist(i,d,p);
        for(int j=1;j<d_nbSommet;j++)
            mat_dist[i][j]=d[j];
    }
    return mat_dist;
}
