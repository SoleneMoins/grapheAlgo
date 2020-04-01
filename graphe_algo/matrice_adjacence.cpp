#include "matrice_adjacence.h"

matrice_Adjacence::matrice_Adjacence():d_matrice{0}
{}

matrice_Adjacence::matrice_Adjacence(fs_aps &graphFsAps)
{
    d_nbSommet=graphFsAps.aps()[0];
    d_nbArcs=graphFsAps.fs()[0]- d_nbSommet;
    d_matrice.clear();
    d_matrice.resize(d_nbSommet+1);
     for (int i = 0; i < d_nbSommet+1; i++)
    {
        d_matrice[i].resize(d_nbSommet+1);
        for(int j=1; j<=d_nbSommet;j++)
            d_matrice[i][j]=0;
    }
    d_matrice[0][0]=d_nbSommet;
    d_matrice[0][1]=d_nbArcs;
    for(int i=1; i<=d_nbSommet;i++)
    {
        int j;
    for(int k=graphFsAps.aps()[i];(j=graphFsAps.fs()[k])!=0;j++)
            d_matrice[i][j]=1;
    }
}

void matrice_Adjacence::matriceDistance(int *fa, fs_aps& graph, int **&mat)
{
    int n=graph.aps()[0];
   for(int i=1; i<=n; i++) {
        mat[i]=new int[n+1];
        graph.distance();
    }
}

