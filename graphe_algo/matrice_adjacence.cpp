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

std::vector<int> matrice_Adjacence::codage_Pruffer() {
    int m=d_nbSommet;
    std::vector<int> prufer(m-1,0);
    prufer[0]=m-2;
    int A[m+1][m+1];
    for (int i = 0; i <= m; ++i){
        for (int j = 0; j <= m; ++j){
            A[i][j] = d_matrice[i][j];
        }
    }
    int compteur;
    for (int i = 1; i <= m; ++i){
       compteur = 0;
       for (int j = 1; j <=m; ++j){
           if (A[i][j] == 1){
               compteur++;
           }
        }
             A[i][0] = compteur;
    }
    for (int i = 1; i <= m-2; ++i){
       int j = 1;
       while (j <= m && A[j][0] != 1){
           ++j;
           A[j][0] = 0; int k = 1;
           while (k <= m && A[j][k] != 1){
                  ++k;
             A[j][k] = 0; A[k][j] = 0; A[k][0]--;
             prufer[i] = k;
           }
       }
    }
    return prufer;
}

