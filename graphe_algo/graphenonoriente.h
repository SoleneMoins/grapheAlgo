#ifndef GRAPHENONORIENTE_H
#define GRAPHENONORIENTE_H
#include<vector>
#include"sommet.h"
#include"arc.h"


class GrapheNonOriente
{
public:
    GrapheNonOriente();
    GrapheNonOriente(const std::vector<sommet> &sommets, const std::vector<arc> &aret);
    void affichage()const;
    GrapheNonOriente kruskal();

    //void affiche()const;


private:
    int d_n; //nombre de sommet
    int d_m; //nombre d'arc
    std::vector<sommet> d_sommet;
    std::vector<arc> d_aret;
    void trier();
    void fusionner(int i, int j, std::vector<int> prem, std::vector<int> pilch, std::vector<int> cfc, std::vector<int> NbElem);

};

#endif // GRAPHENONORIENTE_H
