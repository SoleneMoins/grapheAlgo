#ifndef ARC_H
#define ARC_H
#include "sommet.h"

class arc
{
    public:
        arc(sommet s1, sommet s2,int valeur);
        sommet getSommetDepart() const;
        sommet getSommetArrive()const ;
        int getValeur()const ;



    private:
        sommet d_sommetDepart;
        sommet d_sommetArrive;
        int d_valeur;

};

#endif // ARC_H
