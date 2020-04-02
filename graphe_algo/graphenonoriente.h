#ifndef GRAPHENONORIENTE_H
#define GRAPHENONORIENTE_H
#include<vector>
#include"sommet.h"
#include"arc.h"


class GrapheNonOriente {
public:
    GrapheNonOriente();
    GrapheNonOriente(int n, int m, const std::vector<arc> &aret);

    void affichage()const;
    void kruskal(GrapheNonOriente &t);
    void trier();
    void affiche()const;


private:
    int d_n;
    int d_m;
    std::vector<arc> d_aret;

    void fusionner(int i, int j, std::vector<int> prem, std::vector<int> pilch, std::vector<int> cfc, std::vector<int> NbElem);

};

#endif // GRAPHENONORIENTE_H
